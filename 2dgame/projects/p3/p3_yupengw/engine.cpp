#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <iomanip>
#include "sprite.h"
#include "multisprite.h"
#include "twowaysprite.h"
#include "gamedata.h"
#include "engine.h"
#include "frameGenerator.h"

Engine::~Engine() {
  for( Drawable* d : sprites ){
    // delete star;
    // delete spinningStar;
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
  // star(new Sprite("YellowStar")),
  // spinningStar(new MultiSprite("SpinningStar")),
  sprites({new TwowaySprite("Warrior")}),
  currentSprite(0),
  makeVideo( false )
{
  int msQuantity = Gamedata::getInstance().getXmlInt("YellowStar/quantity");
  for( int i=0; i < msQuantity; ++i){
    sprites.push_back(new Sprite("YellowStar"));
  }
  sprites.push_back(new MultiSprite("SpinningStar"));
  Viewport::getInstance().setObjectToTrack(sprites[0]);
  std::cout << "Loading complete" << std::endl;
}

void Engine::draw() const {
  sky.draw();
  bamboo4.draw();
  bamboo3.draw();
  bamboo2.draw();

  for( Drawable* d : sprites ){
    // star->draw();
    // spinningStar->draw();
    d->draw();
  }
  grass.draw();

  viewport.draw();
  SDL_RenderPresent(renderer);
}

void Engine::update(Uint32 ticks) {
  for( Drawable* d : sprites ) {
    // star->update(ticks);
    // spinningStar->update(ticks);
    d->update(ticks);
  }
  sky.update();
  bamboo4.update();
  bamboo3.update();
  bamboo2.update();
  grass.update();
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
      draw();
      update(ticks);
      if ( makeVideo ) {
        frameGen.makeFrame();
      }
    }
  }
}
