#ifndef SMARTSPRITE__H
#define SMARTSPRITE__H
#include <string>
#include "multisprite.h"

class SmartSprite : public MultiSprite {
public:
  SmartSprite(const std::string&, const Vector2f& pos,  const Vector2f& bpos,
    int w, int h, int bw, int bh );
  SmartSprite(const SmartSprite&);
  SmartSprite& operator=( const SmartSprite& );
  virtual ~SmartSprite() { }

  void attacking() { currentMode = ATCK; currentFrame = 0; }
  void walking()   { currentMode = WALK;  }
  int  getMode() const { return currentMode;  }
  void setMode( const std::string&  );
  void update(Uint32 ticks);

  void setPlayerPos(const Vector2f& p) { playerPos = p; }
  bool attackable();

  virtual void falling()   { currentMode = FALL; currentFrame = 0; }
  virtual void walk()   = 0;
  virtual void attack() = 0;
  virtual void fall()   = 0;


private:
  enum MODE {WALK, ATCK, FALL, DEAD};
  MODE currentMode;

  Vector2f playerPos;
  Vector2f basePos;
  int playerWidth;
  int playerHeight;
  int baseWidth;
  int baseHeight;
  float safeDistance;

};
#endif
