#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>
#include <cmath>
#include "multisprite.h"
#include "rival.h"

class Player : public MultiSprite {
public:
  Player( const std::string& );
  Player( const Player& );
  Player& operator=( const Player& );

  virtual void update( Uint32 ticks );
  // Add collision
  void attach( Rival* o ) { observers.push_back(o); }
  void detach( Rival* o );

  void collided()   { collision = true;   }
  void missed()     { collision = false;  }
  void turnLeft()   { toLeft    = true;   }
  void turnRight()  { toLeft    = false;  }
  void jumping()    { currentMode = JUMP;  currentFrame = 0; }
  void landing()    { currentMode = LAND;  currentFrame = 0; }
  void lattacking() { currentMode = ATCK;  currentFrame = 0; }
  void blocking()   { currentMode = BLCK;  currentFrame = 0; }
  void blockDone()  { currentMode = IDLE; }
  bool isHit() const{ return hit;         }

  int  getMode() const { return currentMode;   }

  void ready();
  void walk();
  void land();
  void jump(int);
  void roll();
  void knee();
  void lattack();
  void block();

private:
  enum MODE {JUMP, LAND, ATCK, BLCK, DFND, IDLE};
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
  std::vector<Image *> readyRImgs;
  std::vector<Image *> walkRImgs;
  std::vector<Image *> landRImgs;
  std::vector<Image *> jumpRImgs;
  std::vector<Image *> rollRImgs;
  std::vector<Image *> kneeRImgs;
  std::vector<Image *> blockRImgs;
  std::vector<Image *> lattackRImgs;
  // Indicate the orientation of the player
  bool toLeft;
  bool collision;
  bool hit;

  Vector2f initialPosition;
  Vector2f initialVelocity;
  Vector2f jumpingVelocity;

  MODE currentMode;

  int  gravity;
  unsigned lastFrame;
  unsigned hitFrame;
};
#endif
