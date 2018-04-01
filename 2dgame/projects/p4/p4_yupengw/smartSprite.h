#ifndef SMARTSPRITE__H
#define SMARTSPRITE__H
#include <string>
#include "multisprite.h"

class SmartSprite : public MultiSprite {
public:
  SmartSprite(const std::string&, const Vector2f& pos, int w, int h);
  SmartSprite(const SmartSprite&);
  SmartSprite& operator=( const SmartSprite& );
  virtual ~SmartSprite() { }

  void attacking() { currentMode = ATCK; currentFrame = 0; }
  void falling()   { currentMode = FALL; currentFrame = 0; }
  void walking()   { currentMode = WALK;  }
  int getMode()   { return currentMode;  }
  virtual void update(Uint32 ticks);

  void setPlayerPos(const Vector2f& p) { playerPos = p; }
  bool attackable();

  virtual void walk()   = 0;
  virtual void attack() = 0;
  virtual void fall()   = 0;

private:
  enum MODE {WALK, ATCK, FALL};
  Vector2f playerPos;
  int playerWidth;
  int playerHeight;
  MODE currentMode;
  float safeDistance;

};
#endif
