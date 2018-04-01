#include "rival.h"
#include "gamedata.h"
#include "imageFactory.h"

Rival::Rival ( const std::string& name ) :
  MultiSprite( name ),
  walkImgs( images ),
  attackImgs ( ImageFactory::getInstance().getImages(name+"Attack") ),
  fallbwdImgs( ImageFactory::getInstance().getImages(name+"FallBwd")),
  collision(false),
  initialPosition( getPosition()),
  initialVelocity( getVelocity()),
  lastFrame( 0 )
{ }

Rival::Rival ( const Rival& s ) :
  MultiSprite(s),
  walkImgs( s.walkImgs ),
  attackImgs( s.attackImgs ),
  fallbwdImgs( s.fallbwdImgs ),
  collision(s.collision),
  initialPosition( s.initialPosition ),
  initialVelocity( s.getVelocity() ),
  lastFrame( s.lastFrame )
{ }

Rival& Rival::operator=( const Rival& s ) {
  MultiSprite::operator=(s);
  walkImgs  = s.walkImgs;
  attackImgs = s.attackImgs;
  fallbwdImgs  = s.fallbwdImgs;

  collision = s.collision;
  initialPosition = s.initialPosition;
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
void Rival::fallbwd()    {
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"FallBwd/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"FallBwd/frames");
  if( getY() != initialPosition[1]) {
    setY(initialPosition[1]);
  }
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
  if ( !collision ) MultiSprite::update(ticks);
  walk();
}
