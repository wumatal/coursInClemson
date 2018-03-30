#include "player.h"
#include "gamedata.h"
#include "imageFactory.h"

Player::Player ( const std::string& name ) :
  MultiSprite(name),
  walkImgs( ImageFactory::getInstance().getImages(name+"Walk") ),
  readyImgs( ImageFactory::getInstance().getImages(name)),
  // runImgs( ImageFactory::getInstance().getImages(name+"")),
  jumpImgs( ImageFactory::getInstance().getImages(name+"Jump")),
  rollImgs( ImageFactory::getInstance().getImages(name+"Roll")),
  kneeImgs( ImageFactory::getInstance().getImages(name+"Knee")),
  walkRImgs( ImageFactory::getInstance().getImages(name+"WalkRight")),
  readyRImgs( ImageFactory::getInstance().getImages(name+"Right")),
  // runRImgs( ImageFactory::getInstance().getImages(name+"")),
  jumpRImgs( ImageFactory::getInstance().getImages(name+"JumpRight")),
  rollRImgs( ImageFactory::getInstance().getImages(name+"RollRight")),
  kneeRImgs( ImageFactory::getInstance().getImages(name+"KneeRight")),
  inAir(false),
  toLeft(true),
  collision(false),
  initialVelocity(getVelocity()),
  jumpingVelocity(Vector2f(Gamedata::getInstance().getXmlInt(name+"Jump/speedX"),
                           Gamedata::getInstance().getXmlInt(name+"Jump/speedY")),
  gravity(Gamedata::getInstance().getXmlInt(name+"Jump/grav"))
{ }

Player::Player ( const Player& s ) :
  MultiSprite(s),
  walkImgs( s.walkImgs ),
  readyImgs( s.readyImgs ),
  // runImgs( ImageFactory::getInstance().getImages(name+"")),
  jumpImgs( s.jumpImgs ),
  rollImgs( s.rollImgs ),
  kneeImgs( s.kneeImgs ),
  walkRImgs( s.walkRImgs ),
  readyRImgs( s.readyRImgs ),
  // runRImgs( ImageFactory::getInstance().getImages(name+"")),
  jumpRImgs( s.jumpRImgs ),
  rollRImgs( s.rollRImgs ),
  kneeRImgs( s.kneeRImgs ),
  inAir( s.inAir ),
  toLeft( s.toLeft ),
  collision(s.collision),
  initialVelocity( s.getVelocity()),
  jumpingVelocity( s.jumpingVelocity ),
  gravity( s.gravity )
{ }

Player& Player::operator=( const Player& s ) {
  MultiSprite::operator=(s);
  walkImgs  = s.walkImgs;
  readyImgs = s.readyImgs;
  // runImgs( ImageFactory::getInstance().getImages(name+"")),
  jumpImgs  = s.jumpImgs;
  rollImgs  = s.rollImgs;
  kneeImgs  = s.kneeImgs;
  walkRImgs = s.walkRImgs;
  readyRImgs = s.readyRImgs;
  // runRImgs( ImageFactory::getInstance().getImages(name+"")),
  jumpRImgs = s.jumpRImgs;
  rollRImgs = s.rollRImgs;
  kneeRImgs = s.kneeRImgs;

  inAir = s.inAir;
  toLeft = s.toLeft;
  collision = s.collision;

  initialVelocity = s.initialVelocity;
  jumpingVelocity = s.jumpingVelocity;
  gravity = s.gravity;

  return *this;
}


void Player::ready()  {
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"/frames");
  if( toLeft ) {
    images = readyImgs;
  }
  else {
    images = readyRImgs;
  }
  setVelocityX(0);
  setVelocityY(0);
}

void Player::walk()   {
  int v = Gamedata::getInstance().getXmlInt(getName()+"Walk/speedX");
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Walk/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Walk/frames");
  if ( toLeft ) {
    images = walkImgs;
    setVelocityX(v);
  }
  else {
    images = walkRImgs;
    setVelocityX(-v);
  }
}
// void Player::run()    {
//   if ( getX() > 0) {
//     setVelocityX(-initialVelocity[0]);
//   }
// }
void Player::jump(int v)   {
  if( v[1] != -210 ) {
    inAir = true;
    frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Jump/frameInterval");
    numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Jump/frames");
    if ( toLeft ) {
      images = jumpImgs;
      setVelocityX(v[0]);
      setVelocityY(v[1]);
    }
    else {
      images = jumpRImgs;
      setVelocityX(v[0]);
      setVelocityY(v[1]);
    }
  }
  else
    inAir = false;
}
void Player::roll()   {
  int v = Gamedata::getInstance().getXmlInt(getName()+"Roll/speedX");
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Roll/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Roll/frames");
  if ( toLeft ) {
    images = rollImgs;
    setVelocityX(v);
  }
  else {
    images = rollRImgs;
    setVelocityX(-v);
  }
}
void Player::knee()   {
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Knee/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Knee/frames");
  if ( toLeft ) {
    images = kneeImgs;
    setVelocityX(0);
  }
  else {
    images = kneeRImgs;
    setVelocityX(0);
  }
}

void Player::update(Uint32 ticks) {
  if ( !collision ) MultiSprite::update(ticks);
  ready();
}
