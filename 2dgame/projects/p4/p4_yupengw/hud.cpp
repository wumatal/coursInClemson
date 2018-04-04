#include "hud.h"
#include "ioMod.h"

Hud& Hud::getInstance() {
  static Hud instance;
  return instance;
}

Hud::Hud() :
  rect  ({Gamedata::getInstance().getXmlInt("hud/positionX"),
          Gamedata::getInstance().getXmlInt("hud/positionY"),
          Gamedata::getInstance().getXmlInt("hud/width"     ),
          Gamedata::getInstance().getXmlInt("hud/height"    )}),
  red   ( Gamedata::getInstance().getXmlInt("hud/red"       )),
  green ( Gamedata::getInstance().getXmlInt("hud/green"     )),
  blue  ( Gamedata::getInstance().getXmlInt("hud/blue"      )),
  alpha ( Gamedata::getInstance().getXmlInt("hud/alpha"     )),
  show  ( false )
{ }

void Hud::showInstructions(SDL_Renderer* renderer)  {
  // First set the blend mode so that alpha blending will work;
  // the default blend mode is SDL_BLENDMODE_NONE!
  SDL_SetRenderDrawBlendMode( renderer, SDL_BLENDMODE_BLEND );
  // Now set the color for the hud:
  SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255/2 );

  // Render rect
  SDL_RenderFillRect( renderer, &rect );

  // Now set the color for the outline of the hud:
  SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255/2 );
  SDL_RenderDrawRect( renderer, &rect );

  // Render the rect to the screen
  SDL_RenderPresent(renderer);

  IoMod::getInstance().writeText("WU", rect.x+10, rect.y+60,
  {(uint8_t)Gamedata::getInstance().getXmlInt("hud/red"),
   (uint8_t)Gamedata::getInstance().getXmlInt("hud/green"),
   (uint8_t)Gamedata::getInstance().getXmlInt("hud/blue"),
   (uint8_t)Gamedata::getInstance().getXmlInt("hud/alpha")});

}


void Hud::draw() const {

  // IoMod::getInstance().writeText("WU", rect.x+10, rect.y+60,
  // {(uint8_t)Gamedata::getInstance().getXmlInt("hud/red"),
  //  (uint8_t)Gamedata::getInstance().getXmlInt("hud/green"),
  //  (uint8_t)Gamedata::getInstance().getXmlInt("hud/blue"),
  //  (uint8_t)Gamedata::getInstance().getXmlInt("hud/alpha")});
}
