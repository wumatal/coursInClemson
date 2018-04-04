#include <SDL.h>
#include "gamedata.h"


class Hud {
public:
  static Hud& getInstance();
  void closeInstructions() ;
  void showInstructions (SDL_Renderer*) ;
  void draw() const;
private:

  SDL_Rect rect;
  Uint8 red;
  Uint8 green;
  Uint8 blue;
  Uint8 alpha;
  bool show;

  Hud();
  Hud(const Hud&);
  Hud& operator=(const Hud&);
};
