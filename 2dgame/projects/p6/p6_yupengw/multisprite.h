#ifndef MULTISPRITE__H
#define MULTISPRITE__H
#include <string>
#include <vector>
#include <cmath>
#include "drawable.h"

// class ExplodingSprite;

class MultiSprite : public Drawable {
public:
  MultiSprite(const std::string&);
  MultiSprite(const MultiSprite&);
  // ~MultiSprite();
  ~MultiSprite(){}

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

  void resetCurrentFrame()    { currentFrame = 0;     }
  void decreaseCurrentFrame() { --currentFrame;       }
  unsigned getCurrentFrame()  { return currentFrame;  }
  unsigned getNumberOfFrames(){ return numberOfFrames;}
  void setNumberOfFrames( unsigned nof ) { numberOfFrames = nof; }

  int getWorldWidth () { return worldWidth; }
  int getWorldHeight() { return worldHeight;}

  void setImages(const std::vector<Image *>& _images) {
    images = _images;
  }

  std::vector<Image*> getImages() const { return images; }

  int getHealth() const { return health; }
  int getAttack() const { return attack; }

  void setHealth(const int h ) { health = h; }
  void setAttack(const int a ) { attack = a; }

  bool subtractHealth( const int );

  MultiSprite& operator=(const MultiSprite&);

  // virtual void explode();

protected:
  std::vector<Image *> images;
  // ExplodingSprite* explosion;

  unsigned currentFrame;
  unsigned numberOfFrames;
  unsigned frameInterval;
  float timeSinceLastFrame;
  int worldWidth;
  int worldHeight;

  void advanceFrame(Uint32 ticks);

private:
  int attack;
  int health;
};
#endif
