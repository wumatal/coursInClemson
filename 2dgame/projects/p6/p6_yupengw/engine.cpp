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
// #include "bladePool.h"

Engine::~Engine() {

  delete player;
  delete home;
  delete gate;

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
  currentSprite(0),
  blades( BladePool::getInstance() ),
  // strategies(), //currentStrategy(0),
  strategy( new PerPixelCollisionStrategy ),
  // collision( false ),
  makeVideo( false )
{
  Viewport::getInstance().setObjectToTrack(player->getPlayer());
  std::cout << "Loading complete" << std::endl;
}

void Engine::draw() const {
  sky.draw();
  bamboo4.draw();
  bamboo3.draw();
  bamboo2.draw();
  home->draw();
  gate->draw();

  blades.draw();

  player->draw();
  grass.draw();

  std::stringstream pHl;
  std::stringstream gtHl;
  std::stringstream hHl;
  pHl << player->getPlayer()->getHealth();
  hHl << home->getHealth();
  gtHl << gate->getHealth();

  IoMod::getInstance().
    writeText("player: " + pHl.str(),
    Gamedata::getInstance().getXmlInt("Player/healthBarX"),
    Gamedata::getInstance().getXmlInt("Player/healthBarY"));
  IoMod::getInstance().
    writeText("home: " + hHl.str(),
    Gamedata::getInstance().getXmlInt("home/healthBarX"),
    Gamedata::getInstance().getXmlInt("home/healthBarY"));
  IoMod::getInstance().
    writeText("gate: " + gtHl.str(),
    Gamedata::getInstance().getXmlInt("gate/healthBarX"),
    Gamedata::getInstance().getXmlInt("gate/healthBarY"));


  viewport.draw();
  SDL_RenderPresent(renderer);
}

void Engine::checkForCollisions() {

  blades.collideWith( player, home );

  if ( strategy->execute(*(player->getPlayer()), *gate) ) {
    if( player->isHit() ) {
      if( gate->subtractHealth(player->getPlayer()->getAttack()) ) {
        gate->explode();
        // win!
      }
      else {
        gate->shake();
      }
    }
  }
}

void Engine::update(Uint32 ticks) {
  sky.update();
  bamboo4.update();
  bamboo3.update();
  bamboo2.update();
  home->update(ticks);
  gate->update(ticks);

  blades.active(player, home);
  blades.update(ticks);
  checkForCollisions();

  player->update(ticks);

  grass.update();

  viewport.update(); // always update viewport last
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
        // You may press 'F' to track hero directly
        if ( keystate[SDL_SCANCODE_F] ) {
          Viewport::getInstance().setObjectToTrack(player->getPlayer());
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

      player->respondTo(keystate);

      draw();
      update(ticks);
      if ( makeVideo ) {
        frameGen.makeFrame();
      }
    }
  }
}
