#include "hud.h"
#include "ioMod.h"

Hud& Hud::getInstance() {
  static Hud instance;
  return instance;
}

Hud::Hud() :
  rect    ({Gamedata::getInstance().getXmlInt("hud/positionX" ),
            Gamedata::getInstance().getXmlInt("hud/positionY" ),
          854-2*Gamedata::getInstance().getXmlInt("hud/positionX"  ),
          600-2*Gamedata::getInstance().getXmlInt("hud/positionY")}),
  red     ( Gamedata::getInstance().getXmlInt("hud/red"       ) ),
  green   ( Gamedata::getInstance().getXmlInt("hud/green"     ) ),
  blue    ( Gamedata::getInstance().getXmlInt("hud/blue"      ) ),
  alpha   ( Gamedata::getInstance().getXmlInt("hud/alpha"     ) ),
  fontSize( Gamedata::getInstance().getXmlInt("font/size"     ) ),
  offset  ( Gamedata::getInstance().getXmlInt("hud/offset"    ) )
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
 
  IoMod::getInstance().writeText(
    "A / D" 
    + Gamedata::getInstance().getXmlStr("hud/keyAD"), 
    rect.x+7*offset, rect.y+offset,
    {red, green, blue, alpha});  
  IoMod::getInstance().writeText(
    "J" 
    + Gamedata::getInstance().getXmlStr("hud/keyJ"), 
    rect.x+7*offset, rect.y+2*offset+fontSize,
    {red, green, blue, alpha});  
  IoMod::getInstance().writeText(
    "W" 
    + Gamedata::getInstance().getXmlStr("hud/keyW"), 
    rect.x+7*offset, rect.y+3*offset+2*fontSize,
    {red, green, blue, alpha});  
  IoMod::getInstance().writeText(
    "S" 
    + Gamedata::getInstance().getXmlStr("hud/keyS"), 
    rect.x+7*offset, rect.y+4*offset+3*fontSize,
    {red, green, blue, alpha});  
  IoMod::getInstance().writeText(
    "S + A / D" 
    + Gamedata::getInstance().getXmlStr("hud/keySAD"), 
    rect.x+7*offset, rect.y+5*offset+4*fontSize,
    {red, green, blue, alpha});
  IoMod::getInstance().writeText(
    "Left shift" 
    + Gamedata::getInstance().getXmlStr("hud/keySHIFT"), 
    rect.x+7*offset, rect.y+6*offset+5*fontSize,
    {red, green, blue, alpha});
  IoMod::getInstance().writeText(
    "F1" 
    + Gamedata::getInstance().getXmlStr("hud/keyF1"), 
    rect.x+7*offset, rect.y+7*offset+6*fontSize,
    {red, green, blue, alpha}); 
  IoMod::getInstance().writeText(
    Gamedata::getInstance().getXmlStr("hud/resume"), 
    rect.x+7*offset, rect.y+rect.h-offset-fontSize,
    {red, green, blue, alpha});

  // Render the rect to the screen
  SDL_RenderPresent(renderer);
}
