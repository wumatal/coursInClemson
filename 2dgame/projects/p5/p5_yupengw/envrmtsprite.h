#ifndef EVMSPRITE__H
#define EVMSPRITE__H
#include <string>
#include "drawable.h"

class EnvrmtSprite : public Drawable {
public:
  EnvrmtSprite(const std::string&);
  EnvrmtSprite(const std::string&, const Vector2f& pos, const Vector2f& vel,
         const Image*);
  EnvrmtSprite(const EnvrmtSprite&);
  virtual ~EnvrmtSprite() { }
  EnvrmtSprite& operator=(const EnvrmtSprite&);

  virtual void draw() const;
  virtual void update(Uint32 ticks);

  virtual const Image* getImage() const { return image; }
  virtual const SDL_Surface* getSurface() const {
    return image->getSurface();
  }
  int getScaledWidth()  const { return getScale()*image->getWidth();  }
  int getScaledHeight() const { return getScale()*image->getHeight(); }

private:
  const Image * image;

protected:
  int worldWidth;
  int worldHeight;

  int getDistance(const EnvrmtSprite*) const;
};
#endif
