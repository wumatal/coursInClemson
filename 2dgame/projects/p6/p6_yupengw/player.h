#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>
#include <cmath>
#include "multisprite.h"
#include "rival.h"
#include "bullet.h"

class ExplodingSprite;
class SDLSound;

class Player {
public:
  Player( const std::string& );
  Player( const Player& );
  Player& operator=( const Player& );

  void update( Uint32 ticks );
  void draw() const;
  // Add collision
  void attach( Rival* o ) { observers.push_back(o); }
  void detach( Rival* o );

  const std::string& getName() const { return player.getName(); }
  int getX() const { return player.getX(); }
  int getY() const { return player.getY(); }
  void setX( float x) { player.setX(x); }
  void setY( float y) { player.setY(y); }
  void setVelocityX( float vx ) { player.setVelocityX(vx);  }
  void setVelocityY( float vy ) { player.setVelocityY(vy);  }
  const Image* getImage() const {
    return player.getImage();
  }
  int getScaledWidth()  const {
    return player.getScaledWidth();
  }
  int getScaledHeight()  const {
    return player.getScaledHeight();
  }
  const SDL_Surface* getSurface() const {
    return player.getSurface();
  }
  const Vector2f& getPosition() const    { return player.getPosition(); }

  MultiSprite* getPlayer() { return &player; }

  void respondTo( const Uint8 *, SDLSound& );
  bool lostLife();

  void turnLeft()   { toLeft    = true;   }
  void turnRight()  { toLeft    = false;  }
  void jumping()    { currentMode = JUMP;  player.resetCurrentFrame(); }
  void landing()    { currentMode = LAND;  player.resetCurrentFrame(); }
  void lattacking() { currentMode = ATCK;  player.resetCurrentFrame(); }
  void blocking()   { currentMode = BLCK;  player.resetCurrentFrame(); }
  void hurting()    {
    if( currentMode == IDLE || currentMode == LAND ) {
      currentMode = HURT;
      player.resetCurrentFrame();
    }
  }
  void shooting()   { currentMode = SHOT;  player.resetCurrentFrame(); }
  void blockDone()  { currentMode = IDLE; }
  bool isHit() const{ return hit;         }
  bool hurtable() const {
    if( !dead && (currentMode == LAND || currentMode == IDLE || currentMode == HURT ))
      return true;
    else return false;
  }

  int  getMode () const { return currentMode;   }
  int  getLives() const { return lives;         }

  void ready();
  void walk();
  void land();
  void jump(int);
  void roll();
  void knee();
  void lattack();
  void block();
  void hurt( );
  void shoot(SDLSound&);
  void explode();
  void activeBullet ( );

  void revive();
  // void deleteBullets( );

private:
  MultiSprite player;

  enum MODE {JUMP, LAND, ATCK, BLCK, DFND, IDLE, SHOT, HURT};
  std::list<Rival*> observers;
  // The frames of all motions of the player
  std::vector<Image *> readyImgs;
  std::vector<Image *> walkImgs;
  std::vector<Image *> landImgs;
  std::vector<Image *> jumpImgs;
  std::vector<Image *> rollImgs;
  std::vector<Image *> kneeImgs;
  std::vector<Image *> blockImgs;
  std::vector<Image *> lattackImgs;
  std::vector<Image *> hurtImgs;
  std::vector<Image *> shootImgs;

  std::vector<Image *> readyRImgs;
  std::vector<Image *> walkRImgs;
  std::vector<Image *> landRImgs;
  std::vector<Image *> jumpRImgs;
  std::vector<Image *> rollRImgs;
  std::vector<Image *> kneeRImgs;
  std::vector<Image *> blockRImgs;
  std::vector<Image *> lattackRImgs;
  std::vector<Image *> hurtRImgs;
  std::vector<Image *> shootRImgs;

  std::list<Bullet> bullets;
  // std::list<Bullet> bulletsFreeList;
  // Indicate the orientation of the player
  bool toLeft;
  // bool collision;
  bool hit;
  bool dead;

  int lives;

  Vector2f initialPosition;
  Vector2f initialVelocity;
  Vector2f jumpingVelocity;

  MODE currentMode;

  int  gravity;
  unsigned lastFrame;
  unsigned hitFrame;
  ExplodingSprite* explosion;
};
#endif
