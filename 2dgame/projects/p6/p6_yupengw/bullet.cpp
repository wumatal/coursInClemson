#include <iostream>
#include <cmath>
#include "bullet.h"

void Bullet::init( bool l ) {
  toLeft    = l;
  tooFar    = false;
  distance  = 0;
  collided  = false;
  collected = false;
  active    = true;

  if( toLeft ) {
    images = bullet;
    setVelocityX( velocity );
  }
  else {
    images = bulletRight;
    setVelocityX( - velocity );
  }
}

void Bullet::collideObj( bool toLeft ) {
  if( currentFrame  >= lastFrame ) {
    lastFrame = currentFrame;
    if( toLeft )
      images = bullet;
    else
      images = bulletRight;
  }
  else {
    lastFrame = 0;
    collected = true;
  }

  setVelocityX( 0 );
  setVelocityY( 0 );
}

void Bullet::update(Uint32 ticks) {
  Vector2f pos = getPosition();
  MultiSprite::update(ticks);
  distance += ( hypot(getX()-pos[0], getY()-pos[1]) );
  if ( distance > maxDistance ) tooFar = true;
  if ( collided ) collideObj( toLeft );
}
