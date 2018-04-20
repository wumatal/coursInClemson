#ifndef MULTISPRITE__H
#define MULTISPRITE__H
#include <string>
#include <vector>
#include <cmath>
#include "drawable.h"

class MultiSprite : public Drawable {
public:
  MultiSprite(const std::string&);
  MultiSprite(const MultiSprite&);

  virtual void draw() const;
  virtual void update(Uint32 ticks);

  virtual const Image* getImage() const {
    return images[currentFrame];
  }
  int getScaledWidth()  const {
    return getScale()*images[currentFrame]->getWidth();
  }
  int getScaledHeight()  const {
    return getScale()*images[currentFrame]->getHeight();
  }
  virtual const SDL_Surface* getSurface() const {
    return images[currentFrame]->getSurface();
  }

  int getPower()  const { return power;  }
  int getHealth() const { return health; }
  int getAttack() const { return attack; }
  int getDefend() const { return defend; }

  void setPower (const int p ) { power  = p; }
  void setHealth(const int h ) { health = h; }
  void setAttack(const int a ) { attack = a; }
  void setDefend(const int d ) { defend = d; }

  void subtractHealth( const int harm ) {
    if( harm > defend )
      health -= (harm - defend);
  }

protected:
  std::vector<Image *> images;

  unsigned currentFrame;
  unsigned numberOfFrames;
  unsigned frameInterval;
  float timeSinceLastFrame;
  int worldWidth;
  int worldHeight;

  void advanceFrame(Uint32 ticks);
  MultiSprite& operator=(const MultiSprite&);
private:
  int attack;
  int defend;
  int health;
  int power;
};
#endif
