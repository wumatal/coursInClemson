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
  void inAir()    { inAir     = true;   }
  void land()     { inAir     = false;  }
  Player& operator=( const Player& );

  void ready();
  void walk();
  // void run();
  void jump(Vector2f);
  void roll();
  void knee();

private:
    // The frames of all motions of the player
  std::vector<Image *> walkImgs;
  std::vector<Image *> readyImgs;
  // std::vector<Image *> runImgs;
  std::vector<Image *> jumpImgs;
  std::vector<Image *> rollImgs;
  std::vector<Image *> kneeImgs;
  std::vector<Image *> walkRImgs;
  std::vector<Image *> readyRImgs;
  // std::vector<Image *> runRImgs;
  std::vector<Image *> jumpRImgs;
  std::vector<Image *> rollRImgs;
  std::vector<Image *> kneeRImgs;
  // Indicate the orientation of the player
  bool inAir;
  bool toLeft;
  bool collision;
  Vector2f initialVelocity;
};
#endif
