#ifndef OBJPOOL_H
#define OBJPOOL_H

#include <vector>
#include <string>

class ObjectPool {
public:
  ObjectPool(const std::string& );

  virtual int getActiveCount()   const = 0;
  virtual int getInactiveCount() const = 0;
  virtual int getSize()          const = 0;

  virtual void deleteAll( ) = 0;
  virtual void active( )    = 0;

  virtual void push(Drawable*) = 0;
  virtual void draw()          = 0;
  virtual void update(Uint32)  = 0;

  virtual void collideWith( const Drawable*, const HomeSprite* ) = 0;

};
#endif
