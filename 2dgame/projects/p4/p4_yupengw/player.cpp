#include "player.h"
#include "gamedata.h"
#include "imageFactory.h"

Player::Player ( const std::string& name ) :
  MultiSprite(name),
  observers()
  readyImgs( images ),
  walkImgs( ImageFactory::getInstance().getImages(name+"Walk") ),
  landImgs( ImageFactory::getInstance().getImages(name+"Land")),
  jumpImgs( ImageFactory::getInstance().getImages(name+"Jump")),
  rollImgs( ImageFactory::getInstance().getImages(name+"Roll")),
  kneeImgs( ImageFactory::getInstance().getImages(name+"Knee")),
  readyRImgs( ImageFactory::getInstance().getImages(name+"Right")),
  walkRImgs( ImageFactory::getInstance().getImages(name+"WalkRight")),
  landRImgs( ImageFactory::getInstance().getImages(name+"LandRight")),
  jumpRImgs( ImageFactory::getInstance().getImages(name+"JumpRight")),
  rollRImgs( ImageFactory::getInstance().getImages(name+"RollRight")),
  kneeRImgs( ImageFactory::getInstance().getImages(name+"KneeRight")),
  inAir(false), landed(false), toLeft(true), collision(false),
  initialPosition(getPosition()), initialVelocity(getVelocity()),
  jumpingVelocity(Vector2f(Gamedata::getInstance().getXmlInt(name+"Jump/speedX"),
                           Gamedata::getInstance().getXmlInt(name+"Jump/speedY"))),
  gravity( Gamedata::getInstance().getXmlInt(name+"Jump/grav") ),
  lastFrame( 0 )
{ }

Player::Player ( const Player& s ) :
  MultiSprite(s),
  observers( s.observers )
  readyImgs( s.readyImgs ),
  walkImgs( s.walkImgs ),
  landImgs( s.landImgs ),
  jumpImgs( s.jumpImgs ),
  rollImgs( s.rollImgs ),
  kneeImgs( s.kneeImgs ),
  readyRImgs( s.readyRImgs ),
  walkRImgs( s.walkRImgs ),
  landRImgs( s.landRImgs ),
  jumpRImgs( s.jumpRImgs ),
  rollRImgs( s.rollRImgs ),
  kneeRImgs( s.kneeRImgs ),
  inAir( s.inAir ),
  landed( s.landed ),
  toLeft( s.toLeft ),
  collision(s.collision),
  initialPosition( s.initialPosition ),
  initialVelocity( s.getVelocity() ),
  jumpingVelocity( s.jumpingVelocity ),
  gravity( s.gravity ),
  lastFrame( s.lastFrame )
{ }

Player& Player::operator=( const Player& s ) {
  MultiSprite::operator=(s);
  observers = s.observers;
  walkImgs  = s.walkImgs;
  readyImgs = s.readyImgs;
  landImgs  = s.landImgs;
  jumpImgs  = s.jumpImgs;
  rollImgs  = s.rollImgs;
  kneeImgs  = s.kneeImgs;
  walkRImgs = s.walkRImgs;
  readyRImgs= s.readyRImgs;
  landRImgs = s.landImgs;
  jumpRImgs = s.jumpRImgs;
  rollRImgs = s.rollRImgs;
  kneeRImgs = s.kneeRImgs;

  inAir   = s.inAir;
  landed  = s.landed;
  toLeft  = s.toLeft;
  collision = s.collision;

  initialPosition = s.initialPosition;
  initialVelocity = s.initialVelocity;
  jumpingVelocity = s.jumpingVelocity;
  gravity = s.gravity;
  lastFrame = s.lastFrame;

  return *this;
}


void Player::ready()  {
  if( getY() != initialPosition[1]) {
    setY(initialPosition[1]);
  }
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
    if ( getX() < worldWidth-getScaledWidth())
      setVelocityX(v);
  }
  else {
    images = walkRImgs;
    if ( getX() > 0)
      setVelocityX(-v);
  }
}
void Player::land()    {
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Land/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Land/frames");
  if( getY() != initialPosition[1]) {
    setY(initialPosition[1]);
  }
  if( currentFrame  >= lastFrame ) {
    lastFrame = currentFrame;
    if ( toLeft ) {
      images = landImgs;
    }
    else {
      images = landRImgs;
    }
  }
  else {
    landed = false;
    lastFrame = 0;
  }
  setVelocityX(0);
  setVelocityY(0);
}
void Player::jump(int v)   {
  jumpingVelocity[0] = v;
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Jump/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Jump/frames");
  if( currentFrame  >= lastFrame ) {
    lastFrame = currentFrame;
    if ( toLeft ) {
      images = jumpImgs;
    }
    else {
      images = jumpRImgs;
    }
    jumpingVelocity[1] = (float)(gravity / 6.0) + jumpingVelocity[1];
    setVelocityX(v);
    setVelocityY(jumpingVelocity[1]);
  }
  else {
    // inAir = false;
    lastFrame = 0;
    jumpingVelocity[1] = Gamedata::getInstance().getXmlInt(getName()+"Jump/speedY");
    landing();
  }
}
void Player::roll()   {
  int v = 0;
  if ( getX() < worldWidth-getScaledWidth() && getX() > 0)
    v = Gamedata::getInstance().getXmlInt(getName()+"Roll/speedX");
  frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Roll/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Roll/frames");
  if ( toLeft ) {
    images = rollImgs;
    if ( getX() < worldWidth-getScaledWidth())
      setVelocityX(v);
  }
  else {
    images = rollRImgs;
    if ( getX() > 0)
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
  if ( !isJumping() )  ready();
}
