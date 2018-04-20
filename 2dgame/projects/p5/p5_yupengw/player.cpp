#include "player.h"
#include "gamedata.h"
#include "imageFactory.h"

Player::Player ( const std::string& name ) :
  MultiSprite(name),
  observers(),
  readyImgs( images ),
  walkImgs    ( ImageFactory::getInstance().getImages(name+"Walk")      ),
  landImgs    ( ImageFactory::getInstance().getImages(name+"Land")      ),
  jumpImgs    ( ImageFactory::getInstance().getImages(name+"Jump")      ),
  rollImgs    ( ImageFactory::getInstance().getImages(name+"Roll")      ),
  kneeImgs    ( ImageFactory::getInstance().getImages(name+"Knee")      ),
  blockImgs   ( ImageFactory::getInstance().getImages(name+"Block")     ),
  lattackImgs ( ImageFactory::getInstance().getImages(name+"LAttack")   ),
  // hurtImgs    ( ImageFactory::getInstance().getImages(name+"Hurt")      ),
  // shootImgs   ( ImageFactory::getInstance().getImages(name+"Shoot")     ),
  readyRImgs  ( ImageFactory::getInstance().getImages(name+"Right")     ),
  walkRImgs   ( ImageFactory::getInstance().getImages(name+"WalkRight") ),
  landRImgs   ( ImageFactory::getInstance().getImages(name+"LandRight") ),
  jumpRImgs   ( ImageFactory::getInstance().getImages(name+"JumpRight") ),
  rollRImgs   ( ImageFactory::getInstance().getImages(name+"RollRight") ),
  kneeRImgs   ( ImageFactory::getInstance().getImages(name+"KneeRight") ),
  blockRImgs  ( ImageFactory::getInstance().getImages(name+"BlockRight")),
  lattackRImgs( ImageFactory::getInstance().getImages(name+"LAttackRight")),
  // hurtRImgs   ( ImageFactory::getInstance().getImages(name+"HurtRight")   ),
  // shootRImgs  ( ImageFactory::getInstance().getImages(name+"ShootRight")),
  // inAir(false), landed(false),
  toLeft(true), collision(false), hit( false ),
  initialPosition(getPosition()), initialVelocity(getVelocity()),
  jumpingVelocity(Vector2f(Gamedata::getInstance().getXmlInt(name+"Jump/speedX"),
                           Gamedata::getInstance().getXmlInt(name+"Jump/speedY"))),
  currentMode ( IDLE ),
  gravity     ( Gamedata::getInstance().getXmlInt(name+"Jump/grav") ),
  lastFrame   ( 0 ),
  hitFrame( Gamedata::getInstance().getXmlInt(getName()+"LAttack/hitFrame")-1 )
{ }

Player::Player ( const Player& s ) :
  MultiSprite(s),
  observers  ( s.observers ),
  readyImgs  ( s.readyImgs ),
  walkImgs   ( s.walkImgs ),
  landImgs   ( s.landImgs ),
  jumpImgs   ( s.jumpImgs ),
  rollImgs   ( s.rollImgs ),
  kneeImgs   ( s.kneeImgs ),
  blockImgs  ( s.blockImgs),
  lattackImgs( s.lattackImgs),
  // hurtImgs   ( s.hurtImgs),
  // shootImgs  ( s.shootImgs),
  readyRImgs ( s.readyRImgs ),
  walkRImgs  ( s.walkRImgs ),
  landRImgs  ( s.landRImgs ),
  jumpRImgs  ( s.jumpRImgs ),
  rollRImgs  ( s.rollRImgs ),
  kneeRImgs  ( s.kneeRImgs ),
  blockRImgs  ( s.blockImgs),
  lattackRImgs( s.lattackImgs),
  // hurtRImgs   ( s.hurtRImgs),
  // shootRImgs  ( s.shootRImgs),
  toLeft   ( s.toLeft ),
  collision( s.collision ),
  hit      ( s.hit ),
  initialPosition( s.initialPosition ),
  initialVelocity( s.getVelocity() ),
  jumpingVelocity( s.jumpingVelocity ),
  currentMode( s.currentMode ),
  gravity( s.gravity ),
  lastFrame( s.lastFrame ),
  hitFrame( s.hitFrame )
{ }

Player& Player::operator=( const Player& s ) {
  MultiSprite::operator=(s);
  observers  = s.observers;
  walkImgs   = s.walkImgs;
  readyImgs  = s.readyImgs;
  landImgs   = s.landImgs;
  jumpImgs   = s.jumpImgs;
  rollImgs   = s.rollImgs;
  kneeImgs   = s.kneeImgs;
  blockImgs  = s.blockImgs;
  lattackImgs= s.lattackImgs;
  // hurtImgs   = s.hurtImgs;
  // shootImgs  = s.shootImgs;
  walkRImgs  = s.walkRImgs;
  readyRImgs = s.readyRImgs;
  landRImgs  = s.landImgs;
  jumpRImgs  = s.jumpRImgs;
  rollRImgs  = s.rollRImgs;
  kneeRImgs  = s.kneeRImgs;
  blockRImgs   = s.blockRImgs;
  lattackRImgs = s.lattackRImgs;
  // hurtRImgs    = s.hurtRImgs;
  // shootRImgs   = s.shootRImgs;

  toLeft    = s.toLeft;
  collision = s.collision;
  hit       = s.hit;

  initialPosition = s.initialPosition;
  initialVelocity = s.initialVelocity;
  jumpingVelocity = s.jumpingVelocity;
  currentMode = s.currentMode;
  gravity = s.gravity;
  lastFrame = s.lastFrame;
  hitFrame  = s.hitFrame;

  return *this;
}

void Player::detach( Rival* o ) {
  std::list<Rival*>::iterator ptr = observers.begin();
  while ( ptr != observers.end() ) {
    if ( *ptr == o ) {
      ptr = observers.erase(ptr);
      return;
    }
    ++ptr;
  }
}

void Player::ready()  {
  if( getY() != initialPosition[1]) {
    setY(initialPosition[1]);
  }
  // frameInterval = Gamedata::getInstance().getXmlInt(getName()+"/frameInterval");
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
  // frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Walk/frameInterval");
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
  // frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Land/frameInterval");
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
    // landed = false;
    currentMode = IDLE;
    lastFrame = 0;
  }
  setVelocityX(0);
  setVelocityY(0);
}
void Player::jump(int v)   {
  jumpingVelocity[0] = 0;
  // frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Jump/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Jump/frames");
  if( currentFrame  >= lastFrame ) {
    lastFrame = currentFrame;
    if ( toLeft ) {
      images = jumpImgs;
      if ( getX() < worldWidth-getScaledWidth())
        jumpingVelocity[0] = v;
    }
    else {
      images = jumpRImgs;
      if ( getX() > 0)
        jumpingVelocity[0] = v;
    }
    // std::cout << currentFrame <<": " << jumpingVelocity[1] << std::endl;
    jumpingVelocity[1] = (float)(gravity / 6.0) + jumpingVelocity[1];
    setVelocity(jumpingVelocity);
  }
  else {
    // inAir = false;
    lastFrame = 0;
    jumpingVelocity[1] = Gamedata::getInstance().getXmlInt(getName()+"Jump/speedY");
    landing();
  }
}
void Player::roll()   {
  int v = Gamedata::getInstance().getXmlInt(getName()+"Roll/speedX");
  // frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Roll/frameInterval");
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
  // frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Knee/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Knee/frames");
  if ( toLeft ) {
    images = kneeImgs;
    setVelocityX(0);
  }
  else {
    images = kneeRImgs;
  std::vector<Image *> lattackImgs;
    setVelocityX(0);
  }
}
void Player::lattack() {
  // frameInterval  = Gamedata::getInstance().getXmlInt(getName()+"LAttack/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"LAttack/frames");

  if( currentFrame  >= lastFrame ) {
    if( hit )
      hit = false;
    
    if( currentFrame == hitFrame )
      hit = true;

    lastFrame = currentFrame;
    if ( toLeft ) {
      images = lattackImgs;
    }
    else {
      images = lattackRImgs;
    }
  }
  else {
    // inAir = false;
    currentMode = IDLE;
    lastFrame = 0;
  }
  setVelocityX(0);
  setVelocityY(0);
}
void Player::block() {
  // frameInterval  = Gamedata::getInstance().getXmlInt(getName()+"Block/frameInterval");
  numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Block/frames");
  if( currentFrame  != (numberOfFrames-1) ) {
    if ( toLeft ) {
      images = blockImgs;
    }
    else {
      images = blockRImgs;
    }
  }
  else {
    currentMode = DFND;
    --currentFrame;
  }
  setVelocityX(0);
  setVelocityY(0);
}
// void Player::shoot() {
//   numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Shoot/frames");

//   if( currentFrame  >= lastFrame ) {

//     lastFrame = currentFrame;
//     if ( toLeft ) {
//       images = shootImgs;
//     }
//     else {
//       images = shootRImgs;
//     }
//   }
//   else {
//     currentMode = IDLE;
//     lastFrame = 0;
//   }
//   setVelocityX(0);
//   setVelocityY(0);
// }
// void Player::hurt() {
//   // frameInterval  = Gamedata::getInstance().getXmlInt(getName()+"Block/frameInterval");
//   numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Hurt/frames");
//   if( currentFrame  != (numberOfFrames-1) ) {
//     if ( toLeft ) {
//       images = hurtImgs;
//     }
//     else {
//       images = hurtRImgs;
//     }
//   }
//   else {
//     currentMode = IDLE;
//     lastFrame = 0;
//   }
//   setVelocityX(0);
//   setVelocityY(0);
// }

void Player::respondTo( const Uint8 * keystate) {
  switch ( getMode() ) {
    // If player is jumping, he can do nothing but turn, move and attack.
    case JUMP:
      if (keystate[SDL_SCANCODE_A]) {
        turnRight();
        jump(-100);
      }
      else if (keystate[SDL_SCANCODE_D]) {
        turnLeft();
        jump(100);
      }
      else
        jump(0);
      break;
    // If landing, player can not be interrupted
    case LAND: 
      land();
      break;
    // If attacking, player can not be interrupted
    case ATCK:
      lattack();
      break;
    // If blocking held, player will stay the final frame.
    case BLCK:
    case DFND:
      if (keystate[SDL_SCANCODE_LSHIFT]) {
        block();
      }
      else{
        blockDone();
      }
      if (keystate[SDL_SCANCODE_J]) {
        lattacking();
        lattack();
      }
      break;
    // case SHOT:
    //   shoot();
    //   break;
    default:

      if (keystate[SDL_SCANCODE_W]) {
        jumping();
        jump(0);
      }
      if (keystate[SDL_SCANCODE_A]) {
        turnRight();
        walk();
      }
      if (keystate[SDL_SCANCODE_D]) {
        turnLeft();
        walk();
      }
      if (keystate[SDL_SCANCODE_S]) {
        knee();
      }
      if (keystate[SDL_SCANCODE_J]) {
        lattacking();
        lattack();
      }
      if (keystate[SDL_SCANCODE_LSHIFT]) {
        blocking();
        block();
      }
      // if (keystate[SDL_SCANCODE_SPACE]) {
      //   shooting();
      //   shoot();
      // }
      if (keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_A]) {
        turnRight();
        roll();
      }
      if (keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_D]) {
        turnLeft();
        roll();
      }
  }
}

void Player::update(Uint32 ticks) {
  // if ( currentMode == ATCK ) ticks *= 2;
  if ( !collision ) MultiSprite::update( 3 * ticks);
  if ( currentMode == IDLE )  ready();
  std::list<Rival*>::iterator ptr = observers.begin();
  while ( ptr != observers.end() ) {
    (*ptr)->setPlayerPos( getPosition() );
    ++ptr;
  }
}
