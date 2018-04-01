#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <iomanip>
#include "sprite.h"
#include "multisprite.h"
#include "player.h"
#include "gamedata.h"
#include "engine.h"
#include "frameGenerator.h"
#include "collisionStrategy.h"

Engine::~Engine() {
  delete player;
  for( Drawable* d : sprites ){
    delete d;
  }
  for ( CollisionStrategy* strategy : strategies ) {
    delete strategy;
  }
  std::cout << "Terminating program" << std::endl;
}

Engine::Engine() :
  rc( RenderContext::getInstance() ),
  io( IoMod::getInstance() ),
  clock( Clock::getInstance() ),
  renderer( rc->getRenderer() ),
  sky("sky", Gamedata::getInstance().getXmlInt("sky/factor") ),
  bamboo4("bamboo4", Gamedata::getInstance().getXmlInt("bamboo4/factor") ),
  bamboo3("bamboo3", Gamedata::getInstance().getXmlInt("bamboo3/factor") ),
  bamboo2("bamboo2", Gamedata::getInstance().getXmlInt("bamboo2/factor") ),
  grass("grass", Gamedata::getInstance().getXmlInt("grass/factor") ),
  viewport( Viewport::getInstance() ),
  player( new Player("Player") ),
  sprites(), currentSprite(0),
  strategies(), currentStrategy(0),
  collision(false),
  makeVideo( false )
{
  Vector2f pos = player->getPosition();
  int w = player->getScaledWidth();

  int h = player->getScaledHeight();
  int n = Gamedata::getInstance().getXmlInt("Blade/quantity");
  sprites.reserve(n);
  for (int i = 0; i < n; ++i) {
    sprites.push_back( new Rival("Blade", pos, w, h) );
    player->attach( static_cast<Rival*>(sprites[i]) );
  }

  strategies.push_back( new RectangularCollisionStrategy );
  strategies.push_back( new PerPixelCollisionStrategy );
  strategies.push_back( new MidPointCollisionStrategy );

  Viewport::getInstance().setObjectToTrack(player);
  std::cout << "Loading complete" << std::endl;
}

void Engine::draw() const {
  sky.draw();
  bamboo4.draw();
  // cloudFar->draw();
  bamboo3.draw();
  bamboo2.draw();

  io.writeText("Press m to change strategy", 500, 60);
  for( Drawable* d : sprites ){
      d->draw();
  }

  strategies[currentStrategy]->draw();
  if ( collision ) {
    io.writeText("Oops: Collision", 500, 90);
  }

  player->draw();
  grass.draw();
  // cloud->draw();

  viewport.draw();
  SDL_RenderPresent(renderer);
}

void Engine::checkForCollisions() {
  auto it = sprites.begin();
  while ( it != sprites.end() ) {
    Rival* doa = static_cast<Rival*>(*it);
    if ( strategies[currentStrategy]->execute(*player, **it) ) {
      if( doa->getMode() != 1)  doa->attacking();
      // player->detach(doa);
      // delete doa;
      // it = sprites.erase(it);
    }
    else {
      if( doa->getMode() != 0)
        doa->walking();
    }
    ++it;
  }
}

void Engine::update(Uint32 ticks) {
  sky.update();
  bamboo4.update();
  // cloudFar->update(ticks);
  bamboo3.update();
  bamboo2.update();

  checkForCollisions();
  for( Drawable* d : sprites ) {
      d->update(ticks);
  }
  player->update(ticks);
  grass.update();
  // cloud->update(ticks);

  viewport.update(); // always update viewport last
}

void Engine::switchSprite(){
  if( currentSprite == sprites.size()) {
    Viewport::getInstance().setObjectToTrack(player);
    currentSprite = 0;
  }
  else {
    Viewport::getInstance().setObjectToTrack(sprites[currentSprite++]);
  }
}

void Engine::play() {
  SDL_Event event;
  const Uint8* keystate;
  bool done = false;
  Uint32 ticks = clock.getElapsedTicks();
  FrameGenerator frameGen;

  while ( !done ) {
    // The next loop polls for events, guarding against key bounce:
    while ( SDL_PollEvent(&event) ) {
      keystate = SDL_GetKeyboardState(NULL);
      if (event.type ==  SDL_QUIT) { done = true; break; }
      if(event.type == SDL_KEYDOWN) {

        if (keystate[SDL_SCANCODE_ESCAPE] || keystate[SDL_SCANCODE_Q]) {
          done = true;
          break;
        }
        if ( keystate[SDL_SCANCODE_P] ) {
          if ( clock.isPaused() ) clock.unpause();
          else clock.pause();
        }
        if ( keystate[SDL_SCANCODE_T] ) {
          switchSprite();
        }
        if ( keystate[SDL_SCANCODE_M] ) {
          currentStrategy = (1 + currentStrategy) % strategies.size();
        }
        // You may press 'F' to track hero directly
        if ( keystate[SDL_SCANCODE_F] ) {
          Viewport::getInstance().setObjectToTrack(player);
        }
        if (keystate[SDL_SCANCODE_F4] && !makeVideo) {
          std::cout << "Initiating frame capture" << std::endl;
          makeVideo = true;
        }
        else if (keystate[SDL_SCANCODE_F4] && makeVideo) {
          std::cout << "Terminating frame capture" << std::endl;
          makeVideo = false;
        }
      }
    }

    // In this section of the event loop we allow key bounce:
    ticks = clock.getElapsedTicks();
    if ( ticks > 0 ) {
      clock.incrFrame();
      // If player is jumping, he can do nothing but turn, move and attack.
      if ( static_cast<Player*>(player)->isJumping () ) {
        if (keystate[SDL_SCANCODE_A]) {
          static_cast<Player*>(player)->turnRight();
          static_cast<Player*>(player)->jump(-200);
        }
        else if (keystate[SDL_SCANCODE_D]) {
          static_cast<Player*>(player)->turnLeft();
          static_cast<Player*>(player)->jump(200);
        }
        else
          static_cast<Player*>(player)->jump(0);
      }
      else if ( static_cast<Player*>(player)->isLanding () ) {
        static_cast<Player*>(player)->land();
      }
      // Only when the player standing on the ground can he perform other mvmts.
      else {
        if (keystate[SDL_SCANCODE_W]) {
          static_cast<Player*>(player)->jumping();
          static_cast<Player*>(player)->jump(0);
        }
        if (keystate[SDL_SCANCODE_A]) {
          static_cast<Player*>(player)->turnRight();
          static_cast<Player*>(player)->walk();
        }
        if (keystate[SDL_SCANCODE_D]) {
          static_cast<Player*>(player)->turnLeft();
          static_cast<Player*>(player)->walk();
        }
        if (keystate[SDL_SCANCODE_S]) {
          static_cast<Player*>(player)->knee();
        }
        if (keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_A]) {
          static_cast<Player*>(player)->turnRight();
          static_cast<Player*>(player)->roll();
        }
        if (keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_D]) {
          static_cast<Player*>(player)->turnLeft();
          static_cast<Player*>(player)->roll();
        }
      }
      draw();
      update(ticks);
      if ( makeVideo ) {
        frameGen.makeFrame();
      }
    }
  }
}
