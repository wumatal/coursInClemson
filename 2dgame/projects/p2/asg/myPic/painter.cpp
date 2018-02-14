#include <iostream>
#include "painter.h"

Painter& Painter::getInstance() {
  static Painter instance;
  return instance;
}

bool Painter::initSDL(SDL_Renderer* renderer, SDL_Window* window, std::string n, int w, int h) {
  if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
    return false;
  }
  window = SDL_CreateWindow(
      n.c_str(), SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      w, h, SDL_WINDOW_SHOWN
  );
  renderer = SDL_CreateRenderer(
    window, -1, SDL_RENDERER_ACCELERATED
  );

  SDL_SetRenderDrawColor( renderer, skyMain.r, skyMain.g, skyMain.b, 255 );
  SDL_RenderClear(renderer);

  return true;
}

void Painter::destSDL(SDL_Renderer* renderer, SDL_Window* window) {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Painter::drawShape(Shape* shape, SDL_Renderer* renderer) {
  shape->draw(renderer);
}

void Painter::drawAStar(int loop,
  SDL_Point     pos,
  SDL_Renderer* renderer)
{
  Circle center(pos, starLoop, 2);
  for( int i=loop; i>0; i-- ) {
    Circle loop( pos, starLoop,     i*loopWid + loopOffset );
    Circle mid ( pos, starMid,  (i-1)*loopWid + loopOffset + edgeWid*2 );
    Circle edge( pos, starEdge, (i-1)*loopWid + loopOffset + edgeWid);

    drawShape(&loop, renderer);
    drawShape(&mid,  renderer);
    drawShape(&edge, renderer);
  }
  drawShape(&center, renderer);
}

void Painter::drawStars(SDL_Renderer* renderer) {
  for(auto star : stars)
    drawAStar(star.second, star.first, renderer);
}

void Painter::drawMoon(SDL_Renderer* renderer) {
  Circle moonOut(moonOutPos, moonColor, moonOutRadius);
  Circle moonIn (moonInPos,  starLoop,  moonInRadius );
  // Shape* moonIn = new Circle(moonInPos,  starLoop,  moonInRadius );

  // Draw halo
  drawAStar( 7, moonOutPos, renderer);
  // Draw outer moon
  drawShape(&moonOut, renderer);
  // Draw inner moon
  drawShape(&moonIn, renderer);
  // moonIn->draw(renderer);
  // delete moonIn
}

// void Painter::drawSky(SDL_Renderer* renderer) {

// }

void Painter::drawClouds(SDL_Renderer* renderer) {
  int radius;
  for(auto cloud : clouds) {
    radius = cloud.second;

    for( int i=0; i<3; i++) {
      Circle edge(cloud.first, cloudEdge, radius);
      radius -= cloudEdgeWid;
      Circle main(cloud.first, cloudMain, radius);
      radius -= cloudMainWid;

      drawShape(&edge, renderer);
      drawShape(&main, renderer);

    }
  }
}

void Painter::drawLight(SDL_Renderer* renderer) {
  SDL_Point p0, p1, p2, p3;
  int j;
  for(unsigned long int i = 0; i<lights.size(); i++) {
    p0 = lights[i][0];
    p1 = lights[i][1];
    p2 = lights[i][2];
    p3 = lights[i][3];

    for( int k=0; k<5; k++) {
      for(j = 0; j < lightEdgeWid; j++ ) {
        Curve c ( p0, p3, p1, p2, starLoop);
        c.draw(renderer);
        p0.y++; p1.y++; p2.y++; p3.y++;
      }
      for(j = 0; j < lightAreaWid; j++ ) {
        Curve c ( p0, p3, p1, p2, starMid);
        c.draw(renderer);
        p0.y++; p1.y++; p2.y++; p3.y++;
      }
      for(j = 0; j < lightEdgeWid; j++ ) {
        Curve c ( p0, p3, p1, p2, starEdge);
        c.draw(renderer);
        p0.y++; p1.y++; p2.y++; p3.y++;
      }
    }
  }
}

void Painter::drawBranch(SDL_Renderer* renderer, const Curve* left, const Curve* right){
  Branch b(left, right);
  drawShape(&b, renderer);
}

void Painter::drawTree(SDL_Renderer* renderer){
  for(unsigned long int i = 0; i<branches.size(); i++) {
    Curve left (branches[i][0], branches[i][3],
      branches[i][1], branches[i][2], branchArea);
    Curve right(branches[i][4], branches[i][7],
      branches[i][5], branches[i][6], branchArea);
    drawBranch (renderer, &left, &right);
  }
}

void Painter::drawHouses(SDL_Renderer* renderer){

  for(int i=0; i<3; i++){
    Triange roof(roofA, roofB, roofC, lightwall);
    drawShape(&roof, renderer);

  }
}

void Painter::drawStarryNight(SDL_Renderer* renderer) {

  drawStars (renderer);
  drawMoon  (renderer);
  drawLight (renderer);
  drawClouds(renderer);
  drawHouses(renderer);
  drawTree  (renderer);

}
