#include "homeSprite.h"
#include "gamedata.h"
#include "imageFactory.h"
#include "explodingSprite.h"

HomeSprite::HomeSprite ( const std::string& name ) :
  MultiSprite(name),
  stopImgs( images ),
  shakeImgs( ImageFactory::getInstance().getImages(name+"Shake") ),
  lastFrame(0),
  explosion(nullptr)
{
  setAttack(Gamedata::getInstance().getXmlInt(name+"/power") );
  setHealth(Gamedata::getInstance().getXmlInt(name+"/health"));
}

HomeSprite::HomeSprite ( const HomeSprite& s ) :
  MultiSprite( s ),
  stopImgs( s.stopImgs ),
  shakeImgs( s.shakeImgs ),
  lastFrame( s.lastFrame ),
  explosion( s.explosion )
{ }

HomeSprite::~HomeSprite( ) { if (explosion) delete explosion; }

HomeSprite& HomeSprite::operator=( const HomeSprite& s ) {
  MultiSprite::operator=( s ),
  stopImgs  = s.stopImgs;
  shakeImgs = s.shakeImgs;
  lastFrame = s.lastFrame;
  explosion = s.explosion;

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
    lastFrame = 0;
  }
}

void HomeSprite::explode() {
  if ( !explosion ){
    Sprite
    sprite(getName(), getPosition(), getVelocity(), images[currentFrame]);
    explosion = new ExplodingSprite(sprite);
  }
}

void HomeSprite::draw() const {
  if ( explosion ) explosion->draw();
  else MultiSprite::draw();
}

void HomeSprite::update(Uint32 ticks) {
  if ( explosion ) {
    explosion->update(ticks);
    if ( explosion->chunkCount() == 0 ) {
      delete explosion;
      explosion = NULL;
    }
    return;
  }

  MultiSprite::update(6*ticks);
  stop();
}
