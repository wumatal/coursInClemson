#ifndef SHAPE_H
#define SHAPE_H

#include <SDL2/SDL.h>
#include "starrynight.h"
/**
 * This class is the base class of all kinds of shapes.
 */
class Shape {
public:
  Shape() {}
  virtual ~Shape() {}
  virtual void draw(SDL_Renderer* renderer) = 0;
};

/**
 * Class Circle takes charge of painting a circle on screen.
 */
class Circle : public Shape {
public:
  Circle(const SDL_Point p, const SDL_Color c, const int r) :
    pos(p), color(c), radius(r) {}
  virtual void draw(SDL_Renderer* renderer);
private:
  SDL_Point pos;
  SDL_Color color;
  int radius;
};

/**
 * Class Quadrangle takes charge of painting a Quadrangle with a sharp angle a.
 */
class Quadrangle : public Shape {
public:
  Quadrangle(SDL_Point p, SDL_Color c, int h, int w) : //, float a) :
    pos(p), color(c), height(h), width(w){}//, angle(a) {}
  virtual void draw(SDL_Renderer* renderer);
private:
  SDL_Point pos;
  SDL_Color color;
  int height;
  int width;
  // float angle;
};

/**
 * Class Triange takes charge of painting a triangle.
 */
class Triange : public Shape {
public:
  Triange(SDL_Point a, SDL_Point b, SDL_Point c, SDL_Color cl) :
    pos_a(a), pos_b(b), pos_c(c), color(cl) {}
  virtual void draw(SDL_Renderer* renderer);
private:
  SDL_Point pos_a;
  SDL_Point pos_b;
  SDL_Point pos_c;
  SDL_Color color;
};

/**
 * Class Curve takes charge of painting a circle on screen.
 */
class Curve : public Shape {
public:
  Curve(const SDL_Point p0, const SDL_Point p3,
    SDL_Point p1, SDL_Point p2, SDL_Color c) :
    startPos(p0), endPos(p3), fstPos(p1), sndPos(p2), color(c){}
  Curve(const Curve& cv) : startPos(cv.startPos), endPos(cv.endPos),
    fstPos(cv.fstPos), sndPos(cv.sndPos), color(cv.color){}
  void setColor(const SDL_Color c) { color = c;  }
  SDL_Point getStartPos() const { return startPos; }
  SDL_Point getEndPos() const { return endPos; }
  SDL_Point getFstPos() const { return fstPos; }
  SDL_Point getSndPos() const { return sndPos; }
  virtual void draw(SDL_Renderer* renderer);
private:
  SDL_Point startPos;
  SDL_Point endPos;
  SDL_Point fstPos;
  SDL_Point sndPos;
  SDL_Color color;
};

/**
 * This class is used to draw the branches of the main tree
 */
class Branch : public Shape {
public:
  Branch(const Curve* l, const Curve* r) :
    left(new Curve(*l)), right(new Curve(*r)) {}
  virtual void draw(SDL_Renderer* renderer);
  ~Branch() { delete left; delete right; }
private:
  Curve* left;
  Curve* right;
};
#endif
