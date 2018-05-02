#include "player.h"
#include "gamedata.h"
#include "explodingSprite.h"
#include "sound.h"

Player::Player ( const std::string& name ) :
  player(name),
  observers(),
  readyImgs   ( player.getImages() ),
  walkImgs    ( ImageFactory::getInstance().getImages(name+"Walk")      ),
  landImgs    ( ImageFactory::getInstance().getImages(name+"Land")      ),
  jumpImgs    ( ImageFactory::getInstance().getImages(name+"Jump")      ),
  rollImgs    ( ImageFactory::getInstance().getImages(name+"Roll")      ),
  kneeImgs    ( ImageFactory::getInstance().getImages(name+"Knee")      ),
  blockImgs   ( ImageFactory::getInstance().getImages(name+"Block")     ),
  lattackImgs ( ImageFactory::getInstance().getImages(name+"LAttack")   ),
  hurtImgs    ( ImageFactory::getInstance().getImages(name+"Hurt")      ),
  shootImgs   ( ImageFactory::getInstance().getImages(name+"Shoot")     ),
  readyRImgs  ( ImageFactory::getInstance().getImages(name+"Right")     ),
  walkRImgs   ( ImageFactory::getInstance().getImages(name+"WalkRight") ),
  landRImgs   ( ImageFactory::getInstance().getImages(name+"LandRight") ),
  jumpRImgs   ( ImageFactory::getInstance().getImages(name+"JumpRight") ),
  rollRImgs   ( ImageFactory::getInstance().getImages(name+"RollRight") ),
  kneeRImgs   ( ImageFactory::getInstance().getImages(name+"KneeRight") ),
  blockRImgs  ( ImageFactory::getInstance().getImages(name+"BlockRight")),
  lattackRImgs( ImageFactory::getInstance().getImages(name+"LAttackRight")),
  hurtRImgs   ( ImageFactory::getInstance().getImages(name+"HurtRight")   ),
  shootRImgs  ( ImageFactory::getInstance().getImages(name+"ShootRight")),
  bullets(), // bulletsFreeList(),
  // inAir(false), landed(false),
  toLeft ( true  ), //collision(false),
  hit    ( false ),
  dead   ( false ),
  lives  ( Gamedata::getInstance().getXmlInt(name+"/life")),
  initialPosition(player.getPosition()),
  initialVelocity(player.getVelocity()),
  jumpingVelocity(Vector2f(Gamedata::getInstance().getXmlInt(name+"Jump/speedX"),
                           Gamedata::getInstance().getXmlInt(name+"Jump/speedY"))),
  currentMode ( IDLE ),
  gravity     ( Gamedata::getInstance().getXmlInt(name+"Jump/grav") ),
  lastFrame   ( 0 ),
  hitFrame( Gamedata::getInstance().getXmlInt(getName()+"LAttack/hitFrame")-1 ),
  explosion(nullptr)
{
  player.setAttack( Gamedata::getInstance().getXmlInt(name+"/power")  );
  player.setHealth( Gamedata::getInstance().getXmlInt(name+"/health") );
}

Player::Player ( const Player& s ) :
  player     ( s.player   ),
  observers  ( s.observers ),
  readyImgs  ( s.readyImgs ),
  walkImgs   ( s.walkImgs ),
  landImgs   ( s.landImgs ),
  jumpImgs   ( s.jumpImgs ),
  rollImgs   ( s.rollImgs ),
  kneeImgs   ( s.kneeImgs ),
  blockImgs  ( s.blockImgs),
  lattackImgs( s.lattackImgs),
  hurtImgs   ( s.hurtImgs ),
  shootImgs  ( s.shootImgs),
  readyRImgs ( s.readyRImgs ),
  walkRImgs  ( s.walkRImgs ),
  landRImgs  ( s.landRImgs ),
  jumpRImgs  ( s.jumpRImgs ),
  rollRImgs  ( s.rollRImgs ),
  kneeRImgs  ( s.kneeRImgs ),
  blockRImgs  ( s.blockRImgs),
  lattackRImgs( s.lattackImgs),
  hurtRImgs   ( s.hurtRImgs),
  shootRImgs  ( s.shootRImgs),
  bullets  ( s.bullets),
  // bulletsFreeList(s.bulletsFreeList),
  toLeft   ( s.toLeft ),
  // collision( s.collision ),
  hit      ( s.hit  ),
  dead     ( s.dead ),
  lives    ( s.lives ),
  initialPosition( s.initialPosition ),
  initialVelocity( s.player.getVelocity() ),
  jumpingVelocity( s.jumpingVelocity ),
  currentMode( s.currentMode ),
  gravity( s.gravity ),
  lastFrame( s.lastFrame ),
  hitFrame( s.hitFrame ),
  explosion( s.explosion )
{}

Player& Player::operator=( const Player& s ) {
  // MultiSprite::operator=(s.player);
  player     = s.player;
  observers  = s.observers;
  walkImgs   = s.walkImgs;
  readyImgs  = s.readyImgs;
  landImgs   = s.landImgs;
  jumpImgs   = s.jumpImgs;
  rollImgs   = s.rollImgs;
  kneeImgs   = s.kneeImgs;
  blockImgs  = s.blockImgs;
  lattackImgs= s.lattackImgs;
  hurtImgs   = s.hurtImgs;
  shootImgs  = s.shootImgs;
  walkRImgs  = s.walkRImgs;
  readyRImgs = s.readyRImgs;
  landRImgs  = s.landImgs;
  jumpRImgs  = s.jumpRImgs;
  rollRImgs  = s.rollRImgs;
  kneeRImgs  = s.kneeRImgs;
  blockRImgs   = s.blockRImgs;
  lattackRImgs = s.lattackRImgs;
  hurtRImgs    = s.hurtRImgs;
  shootRImgs   = s.shootRImgs;

  bullets   = s.bullets;
  // bulletsFreeList = s.bulletsFreeList;
  toLeft    = s.toLeft;
  hit       = s.hit;
  dead      = s.dead;
  lives     = s.lives;

  initialPosition = s.initialPosition;
  initialVelocity = s.initialVelocity;
  jumpingVelocity = s.jumpingVelocity;
  currentMode = s.currentMode;
  gravity     = s.gravity;
  lastFrame   = s.lastFrame;
  hitFrame    = s.hitFrame;

  explosion = s.explosion;

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
  player.setNumberOfFrames(Gamedata::getInstance().getXmlInt(getName()+"/frames"));

  if( toLeft ) {
    player.setImages(readyImgs);
  }
  else {
    player.setImages(readyRImgs);
  }
  player.setVelocityX(0);
  player.setVelocityY(0);
}

void Player::walk()   {
  int v = Gamedata::getInstance().getXmlInt(getName()+"Walk/speedX");
  // frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Walk/frameInterval");
  player.setNumberOfFrames(Gamedata::getInstance().getXmlInt(getName()+"Walk/frames"));

  if ( toLeft ) {
    player.setImages(walkImgs);
    if ( getX() < player.getWorldWidth()-getScaledWidth())
      player.setVelocityX(v);
  }
  else {
    player.setImages(walkRImgs);
    if ( getX() > 0)
      player.setVelocityX(-v);
  }
}
void Player::land()    {
  // frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Land/frameInterval");
  player.setNumberOfFrames(Gamedata::getInstance().getXmlInt(getName()+"Land/frames"));

  if( getY() != initialPosition[1]) {
    setY(initialPosition[1]);
  }
  if( player.getCurrentFrame()  >= lastFrame ) {
    lastFrame = player.getCurrentFrame();
    if ( toLeft ) {
      player.setImages(landImgs);
    }
    else {
      player.setImages(landRImgs);
    }
  }
  else {
    // landed = false;
    currentMode = IDLE;
    lastFrame = 0;
  }
  player.setVelocityX(0);
  player.setVelocityY(0);
}
void Player::jump(int v)   {
  jumpingVelocity[0] = 0;
  // frameInterval = Gamedata::getInstance().getXmlInt(getName()+"Jump/frameInterval");
  player.setNumberOfFrames(Gamedata::getInstance().getXmlInt(getName()+"Jump/frames"));
  if( player.getCurrentFrame()  >= lastFrame ) {
    lastFrame = player.getCurrentFrame();
    if ( toLeft ) {
      player.setImages(jumpImgs);
      if ( getX() < player.getWorldWidth()-getScaledWidth())
        jumpingVelocity[0] = v;
    }
    else {
      player.setImages(jumpRImgs);
      if ( getX() > 0)
        jumpingVelocity[0] = v;
    }
    // std::cout << player.getCurrentFrame() <<": " << jumpingVelocity[1] << std::endl;
    jumpingVelocity[1] = (float)(gravity / 6.0) + jumpingVelocity[1];
    player.setVelocity(jumpingVelocity);
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
  player.setNumberOfFrames(Gamedata::getInstance().getXmlInt(getName()+"Roll/frames"));

  if ( toLeft ) {
    player.setImages(rollImgs);
    if ( getX() < player.getWorldWidth()-getScaledWidth())
      player.setVelocityX(v);
  }
  else {
    player.setImages(rollRImgs);
    if ( getX() > 0)
      player.setVelocityX(-v);
  }
}
void Player::knee()   {
  player.setNumberOfFrames(Gamedata::getInstance().getXmlInt(getName()+"Knee/frames"));

  if ( toLeft ) {
    player.setImages(kneeImgs);
    player.setVelocityX(0);
  }
  else {
    player.setImages(kneeRImgs);
    player.setVelocityX(0);
  }
}
void Player::lattack() {
  player.setNumberOfFrames(Gamedata::getInstance().getXmlInt(getName()+"LAttack/frames"));

  if( player.getCurrentFrame()  >= lastFrame ) {

    if( player.getCurrentFrame() == hitFrame && lastFrame != hitFrame)
      hit = true;
    else
      hit = false;

    lastFrame = player.getCurrentFrame();
    if ( toLeft ) {
      player.setImages(lattackImgs);
    }
    else {
      player.setImages(lattackRImgs);
    }
  }
  else {
    currentMode = IDLE;
    lastFrame = 0;
  }
  player.setVelocityX(0);
  player.setVelocityY(0);
}
void Player::block() {
  // frameInterval  = Gamedata::getInstance().getXmlInt(getName()+"Block/frameInterval");
  unsigned numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Block/frames");
  player.setNumberOfFrames(numberOfFrames);

  if( player.getCurrentFrame()  != (numberOfFrames-1) ) {
    if ( toLeft ) {
      player.setImages(blockImgs);
    }
    else {
      player.setImages(blockRImgs);
    }
  }
  else {
    currentMode = DFND;
    player.decreaseCurrentFrame();
  }
  player.setVelocityX(0);
  player.setVelocityY(0);
}

void Player::shoot(SDLSound& sound) {
  player.setNumberOfFrames(Gamedata::getInstance().getXmlInt(getName()+"Shoot/frames"));

  if( !hit ) {
    hit = true;
  }

  if( player.getCurrentFrame()  >= lastFrame ) {
    if( player.getCurrentFrame() > lastFrame && lastFrame == 2*hitFrame ){
      activeBullet();
      sound[5];
    }

    lastFrame = player.getCurrentFrame();
    if ( toLeft ) {
      player.setImages(shootImgs);
    }
    else {
      player.setImages(shootRImgs);
    }
  }
  else {
    currentMode = IDLE;
    lastFrame = 0;
    hit = false;
  }
  player.setVelocityX(0);
  player.setVelocityY(0);
}
void Player::hurt() {
  // frameInterval  = Gamedata::getInstance().getXmlInt(getName()+"Block/frameInterval");
  unsigned numberOfFrames = Gamedata::getInstance().getXmlInt(getName()+"Hurt/frames");
  player.setNumberOfFrames(numberOfFrames);

  if( player.getCurrentFrame()  != (numberOfFrames-1) ) {
    if ( toLeft ) {
      player.setImages(hurtImgs);
    }
    else {
      player.setImages(hurtRImgs);
    }
  }
  else {
    currentMode = IDLE;
    lastFrame = 0;
  }
  player.setVelocityX(0);
  player.setVelocityY(0);
}

void Player::respondTo( const Uint8 * keystate, SDLSound& sound) {
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
    case LAND:  land();    break;
    // If attacking, player can not be interrupted
    case ATCK:  lattack(); break;
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
      if (keystate[SDL_SCANCODE_SPACE]) {
        shooting();
        shoot( sound );
      }
      break;
    case SHOT: shoot(sound); break;
    case HURT:
      hurt();
      if (keystate[SDL_SCANCODE_SPACE]) {
        shooting();
        shoot(sound);
      }
      if (keystate[SDL_SCANCODE_LSHIFT]) {
        blocking();
        block();
      }
      break;
    default:

      if (keystate[SDL_SCANCODE_W]) {
        sound[1];
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
        sound[4];
        lattacking();
        lattack();
      }
      if (keystate[SDL_SCANCODE_LSHIFT]) {
        blocking();
        block();
      }
      if (keystate[SDL_SCANCODE_SPACE]) {
        sound[3];
        shooting();
        shoot(sound);
      }
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

void Player::revive() {
  player.setPosition(initialPosition);
  player.setHealth(
    Gamedata::getInstance().getXmlInt(player.getName()+"/health") );
  turnLeft();
  lastFrame = 0;
  dead = false;
  ready();
}

void Player::draw() const {
  if ( explosion ) explosion->draw();
  else {
    player.draw();
    for ( const Bullet& bullet : bullets ) {
      if( !bullet.checkCollectStatus() )
      bullet.draw();
    }

  }
}

void Player::update(Uint32 ticks) {
  if ( explosion ) {
    if( !dead ) dead = true;
    explosion->update(ticks);
    if ( explosion->chunkCount() == 0 ) {
      delete explosion;
      explosion = NULL;
    }
    return;
  }

  if( dead ) {
    dead = false;
    revive();
  }


  if ( currentMode == SHOT ) ticks *= 1.5;
  player.update( 3 * ticks);
  if ( currentMode == IDLE )  ready();
  std::list<Rival*>::iterator ptr = observers.begin();
  while ( ptr != observers.end() ) {
    (*ptr)->setPlayerPos( player.getPosition() );
    (*ptr)->setPlayerDead( dead );
    ++ptr;
  }
  for ( Bullet& bullet : bullets ) {
    if( !bullet.checkCollectStatus() ) {
      bullet.update( ticks );
    }
    else
      bullet.deactive( );
  }
}

bool Player::lostLife() {
  return --lives > 0;
}

void Player::explode() {
  if ( !explosion ){
    Sprite
    sprite(player.getName(), player.getPosition(), player.getVelocity(), player.getImage());
    explosion = new ExplodingSprite(sprite);
  }
}

void Player::activeBullet() {

  float deltaX = getScaledWidth()/2;
  float deltaY = getScaledHeight()/3;
  if( bullets.empty() ) {
    Bullet bullet("bullet");
    bullet.setPosition( player.getPosition() + Vector2f(deltaX, deltaY) );
    bullets.push_back( bullet );
    return;
  }

  for ( Bullet& bullet : bullets ) {
    if( !bullet.isActive() ) {
      bullet.init( toLeft );
      bullet.setPosition( player.getPosition() + Vector2f(deltaX, deltaY) );
      return;
    }
  }

  Bullet bullet("bullet");
  bullet.setPosition( player.getPosition() + Vector2f(deltaX, deltaY) );
  bullets.push_back( bullet );
}
