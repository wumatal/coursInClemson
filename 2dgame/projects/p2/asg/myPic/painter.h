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
   * This function is used to init SDL environment.
   * </description>
   * <param type='SDL_Renderer*'>The renderer to be init.</param>
   * <param type='SDL_Window*'>The window to be init.</param>
   * <param type='std::string*'>The name of the window.</param>
   * <param type='int'>The width of the window.</param>
   * <param type='int'>The height of the window.</param>
   * <return type=bool></return>
   */
  bool initSDL(SDL_Renderer*&, SDL_Window*&, std::string, int, int);

  /**
   * <description>
   * This function is used to destroy SDL environment.
   * </description>
   * <param type='SDL_Renderer*'>The renderer to be destroy.</param>
   * <param type='SDL_Window*'>The window to be destroy.</param>
   * <return type=bool></return>
   */
  void destSDL(SDL_Renderer*&, SDL_Window*&);

  // ~Painter() {
  //   SDL_DestroyRenderer(renderer);
  //   SDL_DestroyWindow(window);
  //   SDL_Quit();
  // }

  /**
   * <description>
   * This function is used to draw basic shapes, like circles, rectangles
   * or lines.
   * </description>
   * <param type='Shape*'>A shape that need to draw</param>
   * <param type='SDL_Renderer*'>The renderer.</param>
   */
  void drawShape(Shape*, SDL_Renderer*);
  // ~Painter() {
  //   SDL_DestroyRenderer(renderer);
  //   SDL_DestroyWindow(window);
  //   SDL_Quit();
  // }
  /**
   * <description>
   * This function is used to draw one star. These stars are comprised of manay
   * concentric circles
   * </description>
   * <param type='int'>The number of loop in this star</param>
   * <param type='SDL_Renderer*'>The position of the star</param>
   * <param type='SDL_Renderer*'>The renderer.</param>
   */
  void drawAStar(int, SDL_Point, SDL_Renderer*);

  /**
   * <description>
   * This function is used to draw stars by calling 'drawAStar' for many times.
   * </description>
   * <param type='SDL_Renderer*'>The renderer.</param>
   */
  void drawStars(SDL_Renderer*);

  /**
   * <description>
   * This function is used to draw the moon comprised of tangential circle
   * </description>
   * <param type='SDL_Renderer*'>The renderer.</param>
   */
  void drawMoon(SDL_Renderer*);

  /**
   * <description>
   * This function is used to draw the sky, which is comprised of curves and
   * circles
   * </description>
   * <param type='SDL_Renderer*'>The renderer.</param>
   */
  void drawSky(SDL_Renderer*);

  /**
   * <description>
   * This function is used to draw the clouds, which is comprised of curves and
   * circles
   * </description>
   * <param type='SDL_Renderer*'>The renderer.</param>
   */
  void drawClouds(SDL_Renderer*);

  /**
   * <description>
   * This function is used to draw the lights over the mountains, which is
   * comprised of curves.
   * </description>
   * <param type='SDL_Renderer*'>The renderer.</param>
   */
  void drawLight(SDL_Renderer*);

  /**
   * <description>
   * A branch is consisted of 2 bezier curves and the area between them.
   * Filling in the area is implemented by scan line algorithm.
   * </description>
   * <param type='SDL_Renderer*'>The renderer.</param>
   * <param type='Curve*'>The left side edge.</param>
   * <param type='Curve*'>The right side edge.</param>
   */
  void drawBranch(SDL_Renderer*, const Curve*, const Curve*);

  /**
   * <description>
   * This function is to draw the main tree in frame. The main tree is represented
   * by a bounch of branches.
   * </description>
   * <param type='SDL_Renderer*'>The renderer.</param>
   */
  void drawTree(SDL_Renderer*);

  /**
   * <description>
   * This function is to draw the houses. A house is represented
   * by a bounch of rectangles and triangles.
   * </description>
   * <param type='SDL_Renderer*'>The renderer.</param>
   */
  void drawHouses(SDL_Renderer*);

  /**
   * <description>
   * This function is used to draw the whole geometric Starry Night.
   * </description>
   * <param type='SDL_Renderer*'>The renderer.</param>
   */
  void drawStarryNight(SDL_Renderer*);
private:
  // SDL_Renderer* renderer;
  // SDL_Window* window;
  Painter() {}
};

#endif
