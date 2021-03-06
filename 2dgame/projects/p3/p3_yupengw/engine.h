#include <vector>
#include <SDL.h>
#include "ioMod.h"
#include "renderContext.h"
#include "clock.h"
#include "world.h"
#include "viewport.h"
#include "envrmtsprite.h"

class Engine {
public:
  Engine ();
  ~Engine ();
  void play();
  void switchSprite();
  Engine(const Engine&) = delete;
  Engine& operator=(const Engine&) = delete;

private:
  const RenderContext* rc;
  const IoMod& io;
  Clock& clock;

  SDL_Renderer * const renderer;
  World sky;
  World bamboo4;
  World bamboo3;
  World bamboo2;
  World grass;
  // EnvrmtSprite cloud;
  // EnvrmtSprite cloudFar;
  Viewport& viewport;

  std::vector<Drawable*> sprites;
  // Drawable* star;
  // Drawable* spinningStar;
  int currentSprite;

  bool makeVideo;

  void draw() const;
  void update(Uint32);

  void printScales() const;
  void checkForCollisions();
};
