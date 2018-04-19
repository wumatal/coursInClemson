#include <vector>
#include <SDL.h>
#include "objectPool.h"
#include "gamedata.h"
#include "collisionStrategy.h"

class Rival;

class BladePool : public ObjectPool {
public:
  static BladePool& getInstance();
  ~BladePool() {
    deleteAll();
    delete strategy;
  }

  virtual int getActiveCount()   const { return actives.size(); }
  virtual int getInactiveCount() const { return inPools.size(); }
  virtual int getSize()          const { return numOfObjs;      }

  virtual void deleteAll( );
  virtual void active( );

  virtual void push(Drawable*);
  virtual void draw();
  virtual void update(Uint32);

  virtual void collideWith( Drawable*, HomeSprite* );
private:
  int numOfObjs;
  std::vector<Rival*> actives;
  std::vector<Rival*> inPools;
  CollisionStrategy* strategy;

  BladePool() :
    numOfObjs( Gamedata::getInstance().getXmlInt("Blade/quantity") ),
    actives(),
    inPools(),
    strategy( new RectangularCollisionStrategy )
  {}
  BladePool( const BladePool& );
  BladePool& operator=( const BladePool& );
};
