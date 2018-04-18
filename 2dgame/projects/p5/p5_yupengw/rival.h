#ifndef RIVAL_H
#define RIVAL_H

#include "smartSprite.h"

class Rival : public SmartSprite {
public:
  Rival(const std::string&, const Vector2f& pos,  const Vector2f& bpos,
    int w, int h, int bw, int bh );
  Rival( const Rival& );
  Rival& operator=( const Rival& );

  bool isHit() const { return hit; }

  virtual void falling()   { SmartSprite::falling(); lastFrame = 0;}
  virtual void update(Uint32 ticks);
private:
  // The frames of all motions of the Rival
  std::vector<Image *> walkImgs;
  std::vector<Image *> attackImgs;
  std::vector<Image *> fallbwdImgs;

  Vector2f initialVelocity;
  unsigned lastFrame;
  bool     hit;
  unsigned hitFrame;

  virtual void walk();
  virtual void attack();
  virtual void fall();
  Vector2f makeVelocity(int) const;
};
#endif
