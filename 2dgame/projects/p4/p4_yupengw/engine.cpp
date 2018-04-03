#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <iomanip>
#include "sprite.h"
#include "multisprite.h"
#include "homeSprite.h"
#include "player.h"
#include "gamedata.h"
#include "engine.h"
#include "frameGenerator.h"
#include "collisionStrategy.h"

Engine::~Engine() {
  delete player;
  delete home;
  delete gate;
  for( Drawable* d : sprites ){
    delete d;
  }
  // for ( CollisionStrategy* strategy : strategies ) {
    // delete strategy;
  // }
  delete strategy;
  std::cout << "Terminating program" << std::endl;
}

Engine::Engine() :
  rc( RenderContext::getInstance() ),
  io( IoMod::getInstance() ),
  clock( Clock::getInstance() ),
  renderer( rc->getRenderer() ),
  sky    ("sky",     Gamedata::getInstance().getXmlInt("sky/factor")     ),
  bamboo4("bamboo4", Gamedata::getInstance().getXmlInt("bamboo4/factor") ),
  bamboo3("bamboo3", Gamedata::getInstance().getXmlInt("bamboo3/factor") ),
  bamboo2("bamboo2", Gamedata::getInstance().getXmlInt("bamboo2/factor") ),
  grass  ("grass",   Gamedata::getInstance().getXmlInt("grass/factor")   ),
  viewport( Viewport::getInstance() ),
  home  ( new HomeSprite("home") ),
  gate  ( new HomeSprite("gate") ),
  player( new Player("Player") ),
  sprites(), currentSprite(0),
  // strategies(), currentStrategy(0),
  strategy( new PerPixelCollisionStrategy ),
  collision( false ),
  // pause    ( false ),
  makeVideo( false )
{
  Vector2f pos = player->getPosition();
  int w = player->getScaledWidth();
  int h = player->getScaledHeight();
  Vector2f bpos = home->getPosition();
  int bw = home->getScaledWidth();
  int bh = home->getScaledHeight();
  Player* p = static_cast<Player*>(player);

  int n = Gamedata::getInstance().getXmlInt("Blade/quantity");
  sprites.reserve(n);

  for (int i = 0; i < n; ++i) {
    sprites.push_back( new Rival("Blade", pos, bpos, w, h, bw, bh) );
    p->attach( static_cast<Rival*>(sprites[i]) );
  }

  // strategies.push_back( new PerPixelCollisionStrategy );
  // strategies.push_back( new RectangularCollisionStrategy );
  // strategies.push_back( new MidPointCollisionStrategy );

  Viewport::getInstance().setObjectToTrack(player);
  std::cout << "Loading complete" << std::endl;
}

void Engine::draw() const {
  sky.draw();
  bamboo4.draw();
  // cloudFar->draw();
  bamboo3.draw();
  bamboo2.draw();
  home->draw();
  gate->draw();

  // io.writeText("Press m to change strategy", 500, 60);
  for( Drawable* d : sprites ){
      d->draw();
  }

  // strategies[currentStrategy]->draw();
  strategy->draw();

  player->draw();
  grass.draw();
  // cloud->draw();

  viewport.draw();
  SDL_RenderPresent(renderer);
}

void Engine::checkForCollisions() {
  auto it = sprites.begin();
  bool deleted = false;
  while ( it != sprites.end() ) {
    deleted = false;
    Rival* doa = static_cast<Rival*>(*it);
    Player* p  = static_cast<Player*>(player);
    // Check if player is collided with rival.
    // if ( strategies[currentStrategy]->execute(*p, **it) ) {
    if ( strategy->execute(*p, **it) ) {
      // If the rival is attacking, check if the player defends or not.
      if( doa->getMode() == 1) {
      }
      // If the player is attacking, set the rival to fall.
      if( p->getMode() == 6 && doa->getMode() < 2 ) {
        doa->falling();
      }
    }
    // Check the deads
    if( doa->getMode() == 3 ) {
      p->detach(doa);
      delete doa;
      it = sprites.erase(it);
      deleted = true;
    }
    if( !deleted ) ++it;
  }
}

void Engine::update(Uint32 ticks) {
  unsigned n = Gamedata::getInstance().getXmlInt("Blade/quantity");
  Vector2f pos = player->getPosition();
  int w = player->getScaledWidth();
  int h = player->getScaledHeight();
  Vector2f bpos = home->getPosition();
  int bw = home->getScaledWidth();
  int bh = home->getScaledHeight();
  Player* p = static_cast<Player*>(player);

  sky.update();
  bamboo4.update();
  // cloudFar->update(ticks);
  bamboo3.update();
  bamboo2.update();
  home->update(ticks);
  gate->update(ticks);

  checkForCollisions();
  for( Drawable* d : sprites ) {
      d->update(ticks);
  }

  while ( sprites.size() < n ) {
    Drawable* d = new Rival("Blade", pos, bpos, w, h, bw, bh);
    sprites.push_back( d );
    p->attach( static_cast<Rival*>(d) );
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
        // if ( keystate[SDL_SCANCODE_M] ) {
        //   currentStrategy = (1 + currentStrategy) % strategies.size();
        // }
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
      Player* p = static_cast<Player*>(player);
      // switch player's mode to do correspoding actions.
      switch ( p->getMode() ) {
        // If player is jumping, he can do nothing but turn, move and attack.
        case 0:
          if (keystate[SDL_SCANCODE_A]) {
            p->turnRight();
            p->jump(-200);
          }
          else if (keystate[SDL_SCANCODE_D]) {
            p->turnLeft();
            p->jump(200);
          }
          else
            p->jump(0);
          break;
        // If landing, player can not be interrupted
        case 1:
          p->land();
          break;
        // If attacking, player can not be interrupted
        case 2:
        case 6:
          p->lattack();
          break;
        // If blocking held, player will stay the final frame.
        case 3:
        case 4:
          if (keystate[SDL_SCANCODE_LSHIFT]) {
            p->block();
          }
          else{
            p->blockDone();
          }
          break;
        default:

          if (keystate[SDL_SCANCODE_W]) {
            p->jumping();
            p->jump(0);
          }
          if (keystate[SDL_SCANCODE_A]) {
            p->turnRight();
            p->walk();
          }
          if (keystate[SDL_SCANCODE_D]) {
            p->turnLeft();
            p->walk();
          }
          if (keystate[SDL_SCANCODE_S]) {
            p->knee();
          }
          if (keystate[SDL_SCANCODE_J]) {
            p->lattacking();
            p->lattack();
          }
          if (keystate[SDL_SCANCODE_LSHIFT]) {
            p->blocking();
            p->block();
          }
          if (keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_A]) {
            p->turnRight();
            p->roll();
          }
          if (keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_D]) {
            p->turnLeft();
            p->roll();
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
