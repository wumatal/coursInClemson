#ifndef RIVAL_H
#define RIVAL_H

#include "smartSprite.h"

class Rival : public SmartSprite {
public:
  Rival( const std::string&, const Vector2f& pos, int w, int h );
  Rival( const Rival& );
  Rival& operator=( const Rival& );

  virtual void update(Uint32 ticks);
private:
  // The frames of all motions of the Rival
  std::vector<Image *> walkImgs;
  std::vector<Image *> attackImgs;
  std::vector<Image *> fallbwdImgs;

  Vector2f initialVelocity;
  unsigned lastFrame;

  virtual void walk();
  virtual void attack();
  virtual void fall();
};
#endif
