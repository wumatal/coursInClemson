#ifndef RIVAL_H
#define RIVAL_H

#include "multisprite.h"

class Rival : public MultiSprite {
public:
  Rival( const std::string& );
  Rival( const Rival& );
  virtual void update( Uint32 ticks );

  void collided() { collision = true;   }
  void missed()   { collision = false;  }
  Rival& operator=( const Rival& );

  void walk();
  void attack();
  void fallbwd();

private:
  enum MODE { ADVANCE, ATTACK, DIE };
  // The frames of all motions of the Rival
  std::vector<Image *> walkImgs;
  std::vector<Image *> attackImgs;
  std::vector<Image *> fallbwdImgs;
  // Indicate the orientation of the Rival
  bool collision;
  Vector2f initialPosition;
  Vector2f initialVelocity;
  unsigned lastFrame;
};
#endif
