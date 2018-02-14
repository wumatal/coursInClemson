#ifndef PAINTER_H
#define PAINTER_H

#include "shape.h"
/**
 * This class is used to act as a painter who can draw patterns by given a
 * specific location and a shape to draw. Therefore, I'd like to implement
 * this class in singleton way.
 */
class Painter {
public:
  static Painter& getInstance();
  /**
   * <description>
   * This destructor is used to destroy SDL environment and all pointers.
   * </description>
   */
  ~Painter();

  /**
   * <description>
   * This function is used to init SDL environment.
   * </description>
   * <param type='std::string*'>The name of the window.</param>
   * <param type='int'>The width of the window.</param>
   * <param type='int'>The height of the window.</param>
   * <return type=bool></return>
   */
  bool initSDL(std::string, int, int);

  /**
   * <description>
   * This function is used to draw one star. These stars are comprised of manay
   * concentric circles
   * </description>
   * <param type='int'>The number of loop in this star</param>
   * <param type='SDL_Point'>The position of the star</param>
   */
  void drawAStar(int, SDL_Point);

  /**
   * <description>
   * This function is used to draw stars by calling 'drawAStar' for many times.
   * </description>
   */
  void drawStars();

  /**
   * <description>
   * This function is used to draw the moon comprised of tangential circle
   * </description>
   */
  void drawMoon();

  /**
   * <description>
   * This function is used to draw the sky, which is comprised of curves and
   * circles
   * </description>
   */
  void drawSky();

  /**
   * <description>
   * This function is used to draw the clouds, which is comprised of curves and
   * circles
   * </description>
   */
  void drawClouds();

  /**
   * <description>
   * This function is used to draw the lights over the mountains, which is
   * comprised of curves.
   * </description>
   */
  void drawLight();

  /**
   * <description>
   * A branch is consisted of 2 bezier curves and the area between them.
   * Filling in the area is implemented by scan line algorithm.
   * </description>
   * <param type='Curve*'>The left side edge.</param>
   * <param type='Curve*'>The right side edge.</param>
   */
  void drawBranch(const Curve*, const Curve*);

  /**
   * <description>
   * This function is to draw the main tree in frame. The main tree is represented
   * by a bounch of branches.
   * </description>
   */
  void drawTree();

  /**
   * <description>
   * This function is to draw the houses. A house is represented
   * by a bounch of rectangles and triangles.
   * </description>
   */
  void drawHouses();

  /**
   * <description>
   * This function is used to draw the whole geometric Starry Night.
   * </description>
   */
  void drawStarryNight();

  SDL_Renderer* getRenderer() { return renderer; }
  SDL_Window*   getWindow()   { return window;   }

  // To meet rule of three.
  Painter& operator=(const Painter&) = delete;
  Painter(SDL_Renderer*, SDL_Window*) = delete;
private:
  SDL_Renderer* renderer;
  SDL_Window* window;
  std::vector<Shape*> shapes;
  Painter() {};
};

#endif
