#include <list>
#include <SDL.h>
#include "objectPool.h"
#include "gamedata.h"
#include "collisionStrategy.h"

class Rival;
class Player;

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
  void active( Player*, HomeSprite* );

  virtual void push(Drawable*);
  virtual void draw();
  virtual void update(Uint32);

  virtual void collideWith( Drawable*, HomeSprite* ) {}
  virtual void collideWith( Player*,   HomeSprite* );
private:
  int numOfObjs;
  std::list<Rival*> actives;
  std::list<Rival*> inPools;
  CollisionStrategy* strategy;

  BladePool() :
    numOfObjs( Gamedata::getInstance().getXmlInt("Blade/quantity") ),
    actives(),
    inPools(),
    strategy( new PerPixelCollisionStrategy )
  {}
  BladePool( const BladePool& );
  BladePool& operator=( const BladePool& );
};
