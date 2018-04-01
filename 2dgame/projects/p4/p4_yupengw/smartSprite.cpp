#include <cmath>
#include <random>
#include <functional>
#include "smartSprite.h"
#include "gamedata.h"
#include "renderContext.h"

float distance(float x1, float y1, float x2, float y2) {
  float x = x1-x2;
  float y = y1-y2;
  return hypot(x, y);
}

// void SmartSprite::walk()   { setVelocityX( -abs(getVelocityX()) );  }
// void SmartSprite::attack() { setVelocityX( fabs(getVelocityX()) );  }
// void SmartSprite::fall()   { setVelocityY( -fabs(getVelocityY()) ); }


SmartSprite::SmartSprite(const std::string& name, const Vector2f& pos,
  int w, int h) :
  MultiSprite(name),
  playerPos(pos),
  playerWidth(w),
  playerHeight(h),
  currentMode( WALK ),
  safeDistance(Gamedata::getInstance().getXmlFloat(name+"/safeDistance"))
{}


SmartSprite::SmartSprite(const SmartSprite& s) :
  MultiSprite(s),
  playerPos(s.playerPos),
  playerWidth(s.playerWidth),
  playerHeight(s.playerHeight),
  currentMode(s.currentMode),
  safeDistance(s.safeDistance)
{}

SmartSprite& SmartSprite::operator=( const SmartSprite& s ) {
  MultiSprite::operator=(s);
  playerPos = s.playerPos;
  playerWidth = s.playerWidth;
  playerHeight = s.playerHeight;
  currentMode = s.currentMode;
  safeDistance = s.safeDistance;

  return *this;
}

bool SmartSprite::attackable() {
  float x  = getX() + getImage()->getWidth()/2;
  float y  = getY() + getImage()->getHeight()/2;
  float ex = playerPos[0] + playerWidth/2;
  float ey = playerPos[1] + playerHeight/2;
  float distanceToEnemy = ::distance( x, y, ex, ey );

  return (distanceToEnemy < safeDistance) &&
         (playerPos[0] <= getX()) && (playerPos[1] <= getY());

}
void SmartSprite::update(Uint32 ticks) {
  MultiSprite::update(ticks);
  // std::cout << getX() << '\n';
  if ( getX() > 0 && getX() < worldWidth-getScaledWidth() ) {
    if ( currentMode == WALK ) {
      walk();
    }
    else if ( currentMode == ATCK ) {
      attack();
    }
    else {
      falling();
      fall();
    }
  }
  else {
    if( currentMode != ATCK ) attacking();
    attack();
  }
}
