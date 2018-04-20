#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include "multisprite.h"
#include "gamedata.h"
#include "imageFactory.h"

class Bullet : public MultiSprite {
public:
  explicit Bullet(const string& name) :
    MultiSprite (name),
    distance    (0),
    maxDistance (Gamedata::getInstance().getXmlInt(name+"/distance")),
    tooFar      (false),
    collided    (false),
    collected   (false),
    toLeft      (true ),
    active      (true ),
    velocity    (Gamedata::getInstance().getXmlInt(name+"/speedX")),
    lastFrame   (0),
    bullet      (images),
    bulletRight (ImageFactory::getInstance().getImages(name+"Right")       ),
    collide     (ImageFactory::getInstance().getImages(name+"Collide")     ),
    collideRight(ImageFactory::getInstance().getImages(name+"CollideRight"))
  { }

  virtual void update(Uint32 ticks);
  // bool goneTooFar() const { return tooFar; }
  // void reset() {
  //   tooFar = false;
  //   distance = 0;
  // }
  bool checkCollectStatus() const { return (tooFar || collided || !active); }

  void colliding  () { collided  = true; currentFrame = 0;  }
  void init       ( bool );
  // void fly        ( bool );
  void collideObj ( bool );
  void deactive   () { active = false;        }
  bool isActive   () const { return active; }

private:
  float distance;
  float maxDistance;
  bool tooFar;
  bool collided;
  bool collected;
  bool toLeft;
  bool active;

  int velocity;
  unsigned lastFrame;

  std::vector<Image*> bullet;
  std::vector<Image*> bulletRight;
  std::vector<Image*> collide;
  std::vector<Image*> collideRight;
};
#endif
