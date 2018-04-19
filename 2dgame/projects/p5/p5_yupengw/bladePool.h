#include <vector>
#include "objectPool.h"
#include "gamedata.h"

class CollisionStrategy;
class HomeSprite;

class BladePool : public ObjectPool {
public:
  static BladePool& getInstance();

  virtual int getActiveCount()   const { return actives.size(); }
  virtual int getInactiveCount() const { return inPools.size(); }
  virtual int getSize()          const { return numOfObjs;      }

  virtual void deleteAll( );
  virtual void active( );

  virtual void push(Drawable*);
  virtual void draw();
  virtual void update(Uint32);

  virtual void collideWith( const Drawable*, const HomeSprite* );
private:
  int numOfObjs;
  std::vector<Rival*> actives;
  std::vector<Rival*> inPools;
  CollisionStrategy* strategy;

  Blade() :
    numOfObjs( Gamedata::getInstance.getXmlInt("Blade/quantity") ),
    actions(),
    inPools(),
    strategy( new RectangularCollisionStrategy )
  {}
  Blade( const Blade& );
  Blade& operator=( const Blade& );
};
