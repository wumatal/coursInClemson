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
  for( Drawable* d : spritesFreelist ){
    delete d;
  }
  // for ( CollisionStrategy* strategy : strategies ) {
  //   delete strategy;
  // }
  delete strategy;
  std::cout << "Terminating program" << std::endl;
}

Engine::Engine() :
  rc   ( RenderContext::getInstance() ),
  io   ( IoMod::getInstance() ),
  hud  ( Hud::getInstance() ),
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
  sprites(),
  spritesFreelist(),
  currentSprite(0),
  // strategies(), //currentStrategy(0),
  strategy( new RectangularCollisionStrategy ),
  // collision( false ),
  makeVideo( false )
{
  Vector2f pos = player->getPosition();
  int w = player->getScaledWidth();
  int h = player->getScaledHeight();

  Vector2f bpos = home->getPosition();
  int bw = home->getScaledWidth();
  int bh = home->getScaledHeight();

  int n = Gamedata::getInstance().getXmlInt("Blade/quantity");
  sprites.reserve(n);
  spritesFreelist.reserve(n);

  for (int i = 0; i < n; ++i) {
    // spritesFreelist.push_back( new Rival("Blade", pos, bpos, w, h, bw, bh) );
    sprites.push_back( new Rival("Blade", pos, bpos, w, h, bw, bh) );
    player->attach( static_cast<Rival*>(sprites[i]) );
  }

  // strategies.push_back( new RectangularCollisionStrategy );
  // strategies.push_back( new MidPointCollisionStrategy );

  Viewport::getInstance().setObjectToTrack(player);
  std::cout << "Loading complete" << std::endl;
}

void Engine::draw() const {
  sky.draw();
  bamboo4.draw();
  bamboo3.draw();
  bamboo2.draw();
  home->draw();
  gate->draw();

  io.writeText("Press F 1 to More infos", 500, 60);
  for( Drawable* d : sprites ){
      d->draw();
  }

  // strategies[currentStrategy]->draw();
  // strategy->draw();

  player->draw();
  grass.draw();
  viewport.draw();
  SDL_RenderPresent(renderer);
}

void Engine::checkForCollisions() {
  auto it = sprites.begin();
  bool deleted = false;
  while ( it != sprites.end() ) {
    deleted = false;
    Rival* doa = static_cast<Rival*>(*it);
    // Check if player is collided with rival.
    // if ( strategies[0]->execute(*player, **it) ) {
    if ( strategy->execute(*player, **it) ) {
      // If the rival is attacking, check if the player defends or not.
      if( doa->isHit()) {
        if( player->getMode() == 4 )
          player->setVelocityX(-200);
        // else
        //   player->jumping();
      }
      // If the player is attacking, set the rival to fall.
      if( player->isHit() && doa->getMode() < 2 ) {
        doa->falling();
      }
    }

    // else if ( strategies[1]->execute(*home, **it) ) {
    else if ( strategy->execute(*home, **it) ) {
      if( doa->isHit() ) {
        home->shake();
      }
    }
    // Check the deads
    if( doa->getMode() == 3 ) {
      player->detach(doa);
      delete doa;
      // spritesFreelist.push_back(*it);
      it = sprites.erase(it);
      deleted = true;
    }
    if( !deleted ) ++it;
  }

  // if ( strategies[0]->execute(*player, *gate) ) {
  if ( strategy->execute(*player, *gate) ) {
    if( player->isHit() ) {
      gate->shake();
    }
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

  sky.update();
  bamboo4.update();
  bamboo3.update();
  bamboo2.update();
  home->update(ticks);
  gate->update(ticks);

  for( Drawable* d : sprites ) {
      d->update(ticks);
  }
  checkForCollisions();

  while ( sprites.size() < n ) {
    Drawable* d = new Rival("Blade", pos, bpos, w, h, bw, bh);
    sprites.push_back( d );
    player->attach( static_cast<Rival*>(d) );
  }
  player->update(ticks);
  grass.update();

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
        // Press F1 to bring the game pause and show the instructions
        if ( keystate[SDL_SCANCODE_F1] ) {
          if ( clock.isPaused() ) {
            clock.unpause();
          }
          else {
            hud.showInstructions(renderer);
            clock.pause();
          }
        }
        if (keystate[SDL_SCANCODE_F4] && !makeVideo) {
          std::cout << "Initiating frame capturshowHintse" << std::endl;
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
      // switch player's mode to do correspoding actions.
      switch ( player->getMode() ) {
        // If player is jumping, he can do nothing but turn, move and attack.
        case 0:
          if (keystate[SDL_SCANCODE_A]) {
            player->turnRight();
            player->jump(-300);
          }
          else if (keystate[SDL_SCANCODE_D]) {
            player->turnLeft();
            player->jump(300);
          }
          else
            player->jump(0);
          break;
        // If landing, player can not be interrupted
        case 1:
          player->land();
          break;
        // If attacking, player can not be interrupted
        case 2:
        case 6:
          player->lattack();
          break;
        // If blocking held, player will stay the final frame.
        case 3:
        case 4:
          if (keystate[SDL_SCANCODE_LSHIFT]) {
            player->block();
          }
          else{
            player->blockDone();
          }
          if (keystate[SDL_SCANCODE_J]) {
            player->lattacking();
            player->lattack();
          }
          break;
        default:

          if (keystate[SDL_SCANCODE_W]) {
            player->jumping();
            player->jump(0);
          }
          if (keystate[SDL_SCANCODE_A]) {
            player->turnRight();
            player->walk();
          }
          if (keystate[SDL_SCANCODE_D]) {
            player->turnLeft();
            player->walk();
          }
          if (keystate[SDL_SCANCODE_S]) {
            player->knee();
          }
          if (keystate[SDL_SCANCODE_J]) {
            player->lattacking();
            player->lattack();
          }
          if (keystate[SDL_SCANCODE_LSHIFT]) {
            player->blocking();
            player->block();
          }
          if (keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_A]) {
            player->turnRight();
            player->roll();
          }
          if (keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_D]) {
            player->turnLeft();
            player->roll();
          }
      }

      // if( !spritesFreelist.empty() && std::rand()%4 == 0 ) {
      //   sprites.push_back(spritesFreelist.back());
      //   spritesFreelist.pop_back();
      // }

      draw();
      update(ticks);
      if ( makeVideo ) {
        frameGen.makeFrame();
      }
    }
  }
}
