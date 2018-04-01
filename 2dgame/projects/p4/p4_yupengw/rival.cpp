#include <cmath>
#include <random>
#include <functional>
#include "rival.h"
#include "gamedata.h"
#include "imageFactory.h"

Rival::Rival ( const std::string& name, const Vector2f& pos, int w, int h ) :
  SmartSprite( name, pos, w, h ),
  walkImgs( images ),
  attackImgs ( ImageFactory::getInstance().getImages(name+"Attack") ),
  fallbwdImgs( ImageFactory::getInstance().getImages(name+"FallBwd")),
  initialVelocity( getVelocity()),
  lastFrame( 0 )
{ }

Rival::Rival ( const Rival& s ) :
  SmartSprite(s),
  walkImgs( s.walkImgs ),
  attackImgs( s.attackImgs ),
  fallbwdImgs( s.fallbwdImgs ),
  initialVelocity( s.getVelocity() ),
  lastFrame( s.lastFrame )
{ }

Rival& Rival::operator=( const Rival& s ) {
  SmartSprite::operator=(s);
  walkImgs  = s.walkImgs;
  attackImgs = s.attackImgs;
  fallbwdImgs  = s.fallbwdImgs;

  initialVelocity = s.initialVelocity;
  lastFrame = s.lastFrame;

  return *this;
}

void Rival::walk()   {
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"/frames");
  images = walkImgs;
  if ( getX() < worldWidth-getScaledWidth())
    setVelocityX(initialVelocity[0]);
}
void Rival::fall()    {
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"FallBwd/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"FallBwd/frames");

  if( currentFrame  >= lastFrame ) {
    lastFrame = currentFrame;
    images = fallbwdImgs;

  }
  else {
    lastFrame = 0;
  }
  setVelocityX(Gamedata::getInstance().getXmlInt(getName()+"FallBwd/speedX"));
  setVelocityY(0);
}
void Rival::attack()   {
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Attack/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Attack/frames");
  if( currentFrame  >= lastFrame ) {
    lastFrame = currentFrame;
    images = attackImgs;

    setVelocityX(0);
    setVelocityY(0);
  }
  else {
    lastFrame = 0;
  }
}

void Rival::update(Uint32 ticks) {
  SmartSprite::update(2 * ticks);
  // walk();
}
