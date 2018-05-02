#include <cmath>
#include <random>
#include <functional>
#include "sprite.h"
#include "gamedata.h"
#include "imageFactory.h"
// #include "explodingSprite.h"

Vector2f Sprite::makeVelocity(int vx, int vy) const {
  int offset = Gamedata::getInstance().getXmlInt("Shuriken/velOffset");
  float newvx = Gamedata::getInstance().getRandFloat(vx-offset,vx+offset);;
  float newvy = Gamedata::getInstance().getRandFloat(vy-offset,vy+offset);;
  newvx *= [](){ if(rand()%2) return -1; else return 1; }();
  newvy *= [](){ if(rand()%2) return -1; else return 1; }();

  return Vector2f(newvx, newvy);
}

Sprite::Sprite(const string& n, const Vector2f& pos, const Vector2f& vel,
               const Image* img):
  Drawable(n, pos, vel),
  image( img ),
  // explosion(nullptr),
  worldWidth(Gamedata::getInstance().getXmlInt("world/width")),
  worldHeight(Gamedata::getInstance().getXmlInt("world/height"))
{ }

Sprite::Sprite(const std::string& name) :
  Drawable(name,
           Vector2f(Gamedata::getInstance().getXmlInt(name+"/startLoc/x"),
                    Gamedata::getInstance().getXmlInt(name+"/startLoc/y")),
           makeVelocity(
                    Gamedata::getInstance().getXmlInt(name+"/speedX"),
                    Gamedata::getInstance().getXmlInt(name+"/speedY"))
           ),
  image( ImageFactory::getInstance().getImage(name) ),
  // explosion(nullptr),
  worldWidth(Gamedata::getInstance().getXmlInt("world/width")),
  worldHeight(Gamedata::getInstance().getXmlInt("world/height"))
{ }

Sprite::Sprite(const Sprite& s) :
  Drawable(s),
  image(s.image),
  // explosion(s.explosion),
  worldWidth(Gamedata::getInstance().getXmlInt("world/width")),
  worldHeight(Gamedata::getInstance().getXmlInt("world/height"))
{ }

// Sprite::~Sprite() { if ( explosion ) delete explosion; }

Sprite& Sprite::operator=(const Sprite& rhs) {
  Drawable::operator=( rhs );
  image = rhs.image;
  worldWidth = rhs.worldWidth;
  worldHeight = rhs.worldHeight;
  // explosion = rhs.explosion;
  return *this;
}

inline namespace{
  constexpr float SCALE_EPSILON = 2e-7;
}

void Sprite::draw() const {
  if(getScale() < SCALE_EPSILON) return;
  image->draw(getX(), getY(), getScale());
}

void Sprite::update(Uint32 ticks) {
  Vector2f incr = getVelocity() * static_cast<float>(ticks) * 0.001;
  setPosition(getPosition() + incr);

  if ( getY() < 0) {
    setVelocityY( std::abs( getVelocityY() ) );
  }
  if ( getY() > worldHeight-getScaledHeight()) {
    setVelocityY( -std::abs( getVelocityY() ) );
  }

  if ( getX() < 0) {
    setVelocityX( std::abs( getVelocityX() ) );
  }
  if ( getX() > worldWidth-getScaledWidth()) {
    setVelocityX( -std::abs( getVelocityX() ) );
  }
}

// void Sprite::explode() {
//   if ( !explosion ) explosion = new ExplodingSprite(*this);
// }