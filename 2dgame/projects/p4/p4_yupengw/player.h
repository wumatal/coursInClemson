#ifndef PLAYER_H
#define PLAYER_H

#include "multisprite.h"

class Player : public MultiSprite {
public:
  Player( const std::string& );
  Player( const Player& );
  virtual void update( Uint32 ticks );

  void collided() { collision = true;   }
  void missed()   { collision = false;  }
  void turnLeft() { toLeft    = true;   }
  void turnRight(){ toLeft    = false;  }
  void jumping()  { inAir = true;  currentFrame = 0; }
  void landing()  { inAir = false; landed = true;    }
  bool isJumping() const { return inAir;  }
  bool isLanding() const { return landed; }
  Player& operator=( const Player& );

  void ready();
  void walk();
  void land();
  void jump(int);
  void roll();
  void knee();

private:
  // The frames of all motions of the player
  std::vector<Image *> walkImgs;
  std::vector<Image *> readyImgs;
  std::vector<Image *> landImgs;
  std::vector<Image *> jumpImgs;
  std::vector<Image *> rollImgs;
  std::vector<Image *> kneeImgs;
  std::vector<Image *> walkRImgs;
  std::vector<Image *> readyRImgs;
  std::vector<Image *> landRImgs;
  std::vector<Image *> jumpRImgs;
  std::vector<Image *> rollRImgs;
  std::vector<Image *> kneeRImgs;
  // Indicate the orientation of the player
  bool inAir;
  bool landed;
  bool toLeft;
  bool collision;
  Vector2f initialPosition;
  Vector2f initialVelocity;
  Vector2f jumpingVelocity;
  int gravity;
  unsigned jLastFrame;
};
#endif
