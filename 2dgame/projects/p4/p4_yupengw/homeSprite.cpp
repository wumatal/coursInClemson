#include "homeSprite.h"
#include "gamedata.h"
#include "imageFactory.h"

HomeSprite::HomeSprite ( const std::string& name ) :
  MultiSprite(name),
  stopImgs( images ),
  shakeImgs( ImageFactory::getInstance().getImages(name+"Shake") ),
  attacked( false ),
  collision( false ),
  lastFrame(0)
{ }

HomeSprite::HomeSprite ( const HomeSprite& s ) :
  MultiSprite( s ),
  stopImgs( s.stopImgs ),
  shakeImgs( s.shakeImgs ),
  attacked( s.attacked ),
  collision( s.collision ),
  lastFrame( s.lastFrame )
{ }

HomeSprite& HomeSprite::operator=( const HomeSprite& s ) {
  MultiSprite::operator=( s ),
  stopImgs  = s.stopImgs;
  shakeImgs = s.shakeImgs;
  attacked  = s.attacked;
  collision = s.collision;
  lastFrame = s.lastFrame;

  return *this;
}

void HomeSprite::stop() {
  images = stopImgs;
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"/frames");
}

void HomeSprite::shake(){
  images = shakeImgs;
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Shake/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Shake/frames");
  if( currentFrame  >= lastFrame ) {
    lastFrame = currentFrame;
  }
  else {
    // landed = false;
    lastFrame = 0;
  }
}

void HomeSprite::update(Uint32 ticks) {
  if ( !collision ) MultiSprite::update(6*ticks);
  if ( !attacked )  stop();
}
