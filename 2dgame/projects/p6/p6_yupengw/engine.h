#include <vector>
#include <SDL.h>
#include "ioMod.h"
#include "renderContext.h"
#include "hud.h"
#include "clock.h"
#include "world.h"
#include "viewport.h"
#include "sound.h"

class CollisionStrategy;
class HomeSprite;
class Player;
class BladePool;

class Engine {
public:
  Engine ();
  ~Engine ();
  bool play();
  void switchSprite();
  Engine(const Engine&) = delete;
  Engine& operator=(const Engine&) = delete;

private:
  const RenderContext* rc;
  const IoMod&         io;
  SDLSound&      sound;
  Hud&  hud;
  Clock& clock;

  SDL_Renderer * const renderer;
  World sky;
  World bamboo4;
  World bamboo3;
  World bamboo2;
  World grass;
  Viewport& viewport;

  HomeSprite* home;
  HomeSprite* gate;
  Player* player;
  unsigned currentSprite;
  BladePool& blades;

  // std::vector<CollisionStrategy*> strategies;
  CollisionStrategy* strategy;
  // int  currentStrategy;
  // bool collision;

  bool makeVideo;
  bool win;
  bool lose;

  void draw() const;
  void update(Uint32);

  void printScales() const;
  void checkForCollisions();
};
