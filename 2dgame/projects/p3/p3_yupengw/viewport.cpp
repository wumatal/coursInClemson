#include <sstream>
#include "clock.h"
#include "viewport.h"
#include "ioMod.h"

Viewport& Viewport::getInstance() {
  static Viewport viewport;
  return viewport;
}

Viewport::Viewport() :
  gdata(Gamedata::getInstance()),
  position(0, 0),
  worldWidth(gdata.getXmlInt("world/width")),
  worldHeight(gdata.getXmlInt("world/height")),
  viewWidth(gdata.getXmlInt("view/width")),
  viewHeight(gdata.getXmlInt("view/height")),
  objWidth(0), objHeight(0),
  // startclock(SDL_GetTicks()), deltaclock(0), currentFPS(0),
  objectToTrack(NULL)
{}

void Viewport::setObjectToTrack(const Drawable *obj) {
  objectToTrack = obj;
  objWidth = objectToTrack->getScaledWidth();
  objHeight = objectToTrack->getScaledHeight();
}

void Viewport::draw() const {
  IoMod::getInstance().
    writeText("Tracking: " + objectToTrack->getName(), 30, 30);

  std::stringstream currentFPS;
  currentFPS << Clock::getInstance().getFps();
  IoMod::getInstance().
    writeText("fps: " + currentFPS.str(),
    gdata.getXmlInt("fps/positionX"), gdata.getXmlInt("fps/positionY"));
  IoMod::getInstance().
    writeText(gdata.getXmlStr("myName/name"),
    gdata.getXmlInt("myName/positionX"), gdata.getXmlInt("myName/positionY"),
    {(uint8_t)gdata.getXmlInt("myName/red"),
     (uint8_t)gdata.getXmlInt("myName/green"),
     (uint8_t)gdata.getXmlInt("myName/blue"),
     (uint8_t)gdata.getXmlInt("myName/alpha")});
}

void Viewport::update() {
  const float x = objectToTrack->getX();
  const float y = objectToTrack->getY();

  position[0] = (x + objWidth/2) - viewWidth/2;
  position[1] = (y + objHeight/2) - viewHeight/2;
  if (position[0] < 0) position[0] = 0;
  if (position[1] < 0) position[1] = 0;
  if (position[0] > (worldWidth - viewWidth)) {
    position[0] = worldWidth-viewWidth;
  }
  if (position[1] > (worldHeight - viewHeight)) {
    position[1] = worldHeight-viewHeight;
  }

  // fps calculation
  // deltaclock = SDL_GetTicks() - startclock;
  // startclock = SDL_GetTicks();
  // if ( deltaclock != 0 )
  //   currentFPS = 1000 / deltaclock;
}