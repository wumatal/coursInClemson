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

Engine::~Engine() {
  for( Drawable* d : sprites ){
    delete d;
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
  // player(new Player("Player")),
  sprites({new Player("Player")}),
  currentSprite(0),
  makeVideo( false )
{
  sprites.push_back(new EnvrmtSprite("Cloud"));
  sprites.push_back(new EnvrmtSprite("CloudFar"));

  // sprites.push_back(new MultiSprite("Rival"));
  // int msQuantity = Gamedata::getInstance().getXmlInt("Shuriken/quantity");
  // for( int i=0; i < msQuantity; ++i){
    // sprites.push_back(new Sprite("Shuriken"));
  // }
  Viewport::getInstance().setObjectToTrack(sprites[0]);
  std::cout << "Loading complete" << std::endl;
}

void Engine::draw() const {
  sky.draw();
  bamboo4.draw();
  sprites[2]->draw();
  bamboo3.draw();
  bamboo2.draw();

  for( Drawable* d : sprites ){
    // star->draw();
    // spinningStar->draw();
    if( std::strcmp( d->getName().c_str(), "Cloud" ) &&
        std::strcmp( d->getName().c_str(), "CloudFar" ) )
      d->draw();
  }
  grass.draw();
  sprites[1]->draw();

  viewport.draw();
  SDL_RenderPresent(renderer);
}

void Engine::update(Uint32 ticks) {
  sky.update();
  bamboo4.update();
  sprites[2]->update(ticks);
  bamboo3.update();
  bamboo2.update();
  for( Drawable* d : sprites ) {
    // star->update(ticks);
    // spinningStar->update(ticks);
    if( std::strcmp( d->getName().c_str(), "Cloud" ) &&
    std::strcmp( d->getName().c_str(), "CloudFar" ) )
      d->update(ticks);
  }
  grass.update();
  sprites[1]->update(ticks);

  viewport.update(); // always update viewport last
}

void Engine::switchSprite(){
  ++currentSprite;
  currentSprite = currentSprite % sprites.size();
  Viewport::getInstance().setObjectToTrack(sprites[currentSprite]);
  // currentSprite = currentSprite % 2;
  // if ( currentSprite ) {
  //   Viewport::getInstance().setObjectToTrack(sprites[1]);
  // }
  // else {
  //   Viewport::getInstance().setObjectToTrack(sprites[0]);
  // }
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
        // You may press 'F' to track hero directly
        if ( keystate[SDL_SCANCODE_F] ) {
          Viewport::getInstance().setObjectToTrack(sprites[0]);
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
      if (keystate[SDL_SCANCODE_A]) {
        static_cast<Player*>(sprites[0])->turnRight();
        static_cast<Player*>(sprites[0])->walk();
      }
      if (keystate[SDL_SCANCODE_D]) {
        static_cast<Player*>(sprites[0])->turnLeft();
        static_cast<Player*>(sprites[0])->walk();
      }
      if (keystate[SDL_SCANCODE_W]) {
        if ( static_cast<Player*>(sprites[0])->isInAir () ) {

        }
        else {
          static_cast<Player*>(sprites[0])->jump(0);
        }
      }
      if (keystate[SDL_SCANCODE_S]) {
        static_cast<Player*>(sprites[0])->knee();
      }
      if (keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_A]) {
        static_cast<Player*>(sprites[0])->turnRight();
        static_cast<Player*>(sprites[0])->roll();
      }
      if (keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_D]) {
        static_cast<Player*>(sprites[0])->turnLeft();
        static_cast<Player*>(sprites[0])->roll();
      }
      draw();
      update(ticks);
      if ( makeVideo ) {
        frameGen.makeFrame();
      }
    }
  }
}
