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
  objectToTrack(NULL),
  blades( BladePool::getInstance() )
{}

void Viewport::setObjectToTrack(const Drawable *obj) {
  objectToTrack = obj;
  objWidth = objectToTrack->getScaledWidth();
  objHeight = objectToTrack->getScaledHeight();
}

void Viewport::draw() const {


  std::stringstream currentFPS;
  std::stringstream currentBladeActive;
  std::stringstream currentBladeInPool;
  currentFPS << Clock::getInstance().getFps();
  currentBladeActive << blades.getActiveCount();
  currentBladeInPool << blades.getInactiveCount();

  IoMod::getInstance().
    writeText("fps: " + currentFPS.str(),
    gdata.getXmlInt("fps/positionX"), gdata.getXmlInt("fps/positionY"));
  IoMod::getInstance().
    writeText("Active: " + currentBladeActive.str(),
    gdata.getXmlInt("bladeActive/positionX"), gdata.getXmlInt("bladeActive/positionY"));
  IoMod::getInstance().
    writeText("In Pool: " + currentBladeInPool.str(),
    gdata.getXmlInt("bladeInPool/positionX"), gdata.getXmlInt("bladeInPool/positionY"));
  IoMod::getInstance().
    writeText(gdata.getXmlStr("myName/name"),
    gdata.getXmlInt("myName/positionX"), gdata.getXmlInt("myName/positionY"),
    {(uint8_t)gdata.getXmlInt("myName/red"),
     (uint8_t)gdata.getXmlInt("myName/green"),
     (uint8_t)gdata.getXmlInt("myName/blue"),
     (uint8_t)gdata.getXmlInt("myName/alpha")});

  IoMod::getInstance().
    writeText("Press F 1 to More infos",
    gdata.getXmlInt("hudInfo/positionX"), gdata.getXmlInt("hudInfo/positionY"));
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
}
