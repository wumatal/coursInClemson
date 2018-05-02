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

void SmartSprite::setMode( const std::string& mode ) {
  if( mode == "WALK") currentMode = WALK;
  else if( mode == "ATCK") currentMode = ATCK;
  else if( mode == "FALL") currentMode = FALL;
  else currentMode = DEAD;
}

SmartSprite::SmartSprite(const std::string& name, const Vector2f& pos,
  const Vector2f& bpos, int w, int h, int bw, int bh) :
  MultiSprite(name),
  // lastFrame( 0 ),
  currentMode( WALK ),
  playerPos(pos),
  basePos(bpos),
  playerWidth(w),
  playerHeight(h),
  baseWidth(bw),
  baseHeight(bh),
  playerdead(false),
  safeDistance(Gamedata::getInstance().getXmlFloat(name+"/safeDistance"))
{}


SmartSprite::SmartSprite(const SmartSprite& s) :
  MultiSprite(s),
  // lastFrame( s.lastFrame ),
  currentMode(s.currentMode),
  playerPos(s.playerPos),
  basePos(s.basePos),
  playerWidth(s.playerWidth),
  playerHeight(s.playerHeight),
  baseWidth(s.baseWidth),
  baseHeight(s.baseHeight),
  playerdead(s.playerdead),
  safeDistance(s.safeDistance)
{}

SmartSprite& SmartSprite::operator=( const SmartSprite& s ) {
  MultiSprite::operator=(s);
  // lastFrame    = s.lastFrame;
  playerPos    = s.playerPos;
  basePos      = s.basePos;
  playerWidth  = s.playerWidth;
  playerHeight = s.playerHeight;
  baseWidth    = s.baseWidth;
  baseHeight   = s.baseHeight;
  currentMode  = s.currentMode;
  safeDistance = s.safeDistance;
  playerdead   = s.playerdead;

  return *this;
}

bool SmartSprite::attackable() {
  float x  = getX() + getImage()->getWidth()/2;
  float y  = getY() + getImage()->getHeight()/2;
  float ex = playerPos[0] + playerWidth/2;
  float ey = playerPos[1] + playerHeight/2;
  float bx = basePos[0] + baseWidth * 0.7;
  float by = basePos[1] + baseHeight* 0.7;
  float distanceToEnemy = ::distance( x, y, ex, ey );
  float distanceToBase  = ::distance( x, y, bx, by );

  return (distanceToBase < 1.6 * safeDistance) || ((distanceToEnemy < safeDistance) &&
         (playerPos[0] <= getX()) && (playerPos[1] >= getY()));

}

void SmartSprite::update(Uint32 ticks) {
  MultiSprite::update(ticks);
  // std::cout << getX() << '\n';
  // if ( getX() > 0 && getX() < worldWidth-getScaledWidth() ) {
  if ( currentMode == WALK ) {
    if(attackable() && !playerdead) {
      attacking();
      attack();
    }
    else{
      walk();
    }
  }
  else if ( currentMode == ATCK ) {
    attack();
  }
  else {
    fall();
  }
}
