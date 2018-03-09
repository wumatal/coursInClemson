#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "gamedata.h"

class IoMod {
public:
  static IoMod& getInstance();
  ~IoMod();
  SDL_Texture* readTexture(const std::string& filename);
  SDL_Surface* readSurface(const std::string& filename);
  void writeText(const std::string&, int, int, 
    SDL_Color = {(uint8_t)Gamedata::getInstance().getXmlInt("font/red"), 
                 (uint8_t)Gamedata::getInstance().getXmlInt("font/green"), 
                 (uint8_t)Gamedata::getInstance().getXmlInt("font/blue"), 
                 (uint8_t)Gamedata::getInstance().getXmlInt("font/alpha")}) const;
  // void writeText(const std::string&, int, int) const;
  SDL_Renderer* getRenderer() const { return renderer; }
private:
  int init;
  SDL_Renderer* renderer;
  TTF_Font* font;
  SDL_Color textColor;
  IoMod();
  IoMod(const IoMod&);
  IoMod& operator=(const IoMod&);
};
