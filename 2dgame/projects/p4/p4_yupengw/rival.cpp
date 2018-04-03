#include <cmath>
#include <random>
#include <functional>
#include <string>
#include "rival.h"
#include "gamedata.h"
#include "imageFactory.h"

Vector2f Rival::makeVelocity(int vx) const {
  int offset = Gamedata::getInstance().getXmlInt(getName()+"/velOffset");
  float newvx = Gamedata::getInstance().getRandFloat(vx-offset,vx+offset);
  // newvx *= [](){ if(rand()%2) return -1; else return 1; }();

  return Vector2f(newvx, 0);
}

Rival::Rival ( const std::string& name, const Vector2f& pos,
  const Vector2f& bpos, int w, int h, int bw, int bh ) :
  SmartSprite( name, pos, bpos, w, h, bw, bh ),
  walkImgs( images ),
  attackImgs ( ImageFactory::getInstance().getImages(name+"Attack") ),
  fallbwdImgs( ImageFactory::getInstance().getImages(name+"FallBwd")),
  initialVelocity( makeVelocity(getVelocityX())),
  lastFrame( 0 ),
  hitFrame( Gamedata::getInstance().getXmlInt(getName()+"Attack/hitFrame") )
{ }

Rival::Rival ( const Rival& s ) :
  SmartSprite(s),
  walkImgs( s.walkImgs ),
  attackImgs( s.attackImgs ),
  fallbwdImgs( s.fallbwdImgs ),
  initialVelocity( s.getVelocity() ),
  lastFrame( s.lastFrame ),
  hitFrame( s.hitFrame )
{ }

Rival& Rival::operator=( const Rival& s ) {
  SmartSprite::operator=(s);
  walkImgs  = s.walkImgs;
  attackImgs = s.attackImgs;
  fallbwdImgs  = s.fallbwdImgs;

  initialVelocity = s.initialVelocity;
  lastFrame    = s.lastFrame;
  hitFrame = s.hitFrame;

  return *this;
}

void Rival::walk()   {
  frameInterval  = Gamedata::getInstance().getXmlInt(getName()+"/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"/frames");
  images = walkImgs;
  // if ( getX() < worldWidth-getScaledWidth())
  setVelocityX(initialVelocity[0]);
}
void Rival::fall()    {
  frameInterval  = Gamedata::getInstance().getXmlInt(getName()+"FallBwd/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"FallBwd/frames");

  if( currentFrame  >= lastFrame ) {
    lastFrame = currentFrame;
    images = fallbwdImgs;
  }
  else {
    lastFrame = 0;
    // const string s("DEAD");
    // currentMode = DEAD ;
    setMode("DEAD");
  }
  setVelocityX(Gamedata::getInstance().getXmlInt(getName()+"FallBwd/speedX"));
  setVelocityY(0);
}
void Rival::attack()   {
  frameInterval  = Gamedata::getInstance().getXmlInt(getName()+"Attack/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Attack/frames");
  if( currentFrame  >= lastFrame ) {
    lastFrame = currentFrame;
    images = attackImgs;

    setVelocityX(0);
    setVelocityY(0);
  }
  else {
    walking();
    lastFrame = 0;
  }
}

void Rival::update(Uint32 ticks) {
  if( getMode() == 1) ticks *= 2;
  SmartSprite::update(2 * ticks);
  // walk();
}
