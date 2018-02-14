#include <iostream>
#include "painter.h"

Painter& Painter::getInstance() {
  static Painter instance;
  return instance;
}

Painter::~Painter() {
  std::cout << "size of shapes: " <<  shapes.size() << std::endl;
  for( Shape* s : shapes ) {
    delete s;
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool Painter::initSDL(std::string n, int w, int h) {
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

  shapes.reserve(575);
  return true;
}

void Painter::drawAStar(int loop, SDL_Point pos) {
  Shape* center = new Circle(pos, starLoop, 2);
  for( int i=loop; i>0; i-- ) {
    Shape* loop = new Circle( pos, starLoop,     i*loopWid + loopOffset );
    Shape* mid  = new Circle( pos, starMid,  (i-1)*loopWid + loopOffset + edgeWid*2 );
    Shape* edge = new Circle( pos, starEdge, (i-1)*loopWid + loopOffset + edgeWid);

    loop->draw(renderer);
    mid->draw(renderer);
    edge->draw(renderer);

    shapes.push_back(loop);
    shapes.push_back(mid );
    shapes.push_back(edge);
  }
  center->draw(renderer);
  shapes.push_back(center);
}

void Painter::drawStars() {
  for(auto star : stars)
    drawAStar(star.second, star.first);
}

void Painter::drawMoon() {
  Shape* moonOut = new Circle(moonOutPos, moonColor, moonOutRadius);
  Shape* moonIn  = new Circle(moonInPos,  starLoop,  moonInRadius );

  // Draw halo
  drawAStar( 7, moonOutPos);
  // Draw outer moon
  moonOut->draw(renderer);
  // Draw inner moon
  moonIn->draw(renderer);

  shapes.push_back(moonOut);
  shapes.push_back(moonIn);
}

// void Painter::drawSky(SDL_Renderer* renderer) {

// }

void Painter::drawClouds() {
  int radius;
  for(auto cloud : clouds) {
    radius = cloud.second;

    for( int i=0; i<3; i++) {
      Shape* edge = new Circle(cloud.first, cloudEdge, radius);
      radius -= cloudEdgeWid;
      Shape* main = new Circle(cloud.first, cloudMain, radius);
      radius -= cloudMainWid;

      edge->draw(renderer);
      main->draw(renderer);

      shapes.push_back(edge);
      shapes.push_back(main);
    }
  }
}

void Painter::drawLight() {
  SDL_Point p0, p1, p2, p3;
  int j;
  for(unsigned long int i = 0; i<lights.size(); i++) {
    p0 = lights[i][0];
    p1 = lights[i][1];
    p2 = lights[i][2];
    p3 = lights[i][3];

    for( int k=0; k<5; k++) {
      for(j = 0; j < lightEdgeWid; j++ ) {
        Shape* c = new Curve( p0, p3, p1, p2, starLoop);
        c->draw(renderer);
        shapes.push_back(c);
        p0.y++; p1.y++; p2.y++; p3.y++;
      }
      for(j = 0; j < lightAreaWid; j++ ) {
        Shape* c = new Curve( p0, p3, p1, p2, starMid);
        c->draw(renderer);
        shapes.push_back(c);
        p0.y++; p1.y++; p2.y++; p3.y++;
      }
      for(j = 0; j < lightEdgeWid; j++ ) {
        Shape* c = new Curve( p0, p3, p1, p2, starEdge);
        c->draw(renderer);
        shapes.push_back(c);
        p0.y++; p1.y++; p2.y++; p3.y++;
      }
    }
  }
}

void Painter::drawBranch(const Curve* left, const Curve* right) {
  Shape* b = new Branch(left, right);
  b->draw(renderer);
  shapes.push_back(b);
}

void Painter::drawTree() {
  for(unsigned long int i = 0; i<branches.size(); i++) {
    Curve left (branches[i][0], branches[i][3],
      branches[i][1], branches[i][2], branchArea);
    Curve right(branches[i][4], branches[i][7],
      branches[i][5], branches[i][6], branchArea);
    drawBranch (&left, &right);
  }
}

void Painter::drawHouses() {
  for(int i=0; i<3; i++){
    Shape* roof = new Triange(roofA, roofB, roofC, lightwall);
    roof->draw(renderer);
    shapes.push_back(roof);
  }
}

void Painter::drawStarryNight() {
  drawStars ();
  drawMoon  ();
  drawLight ();
  drawClouds();
  drawHouses();
  drawTree  ();

  SDL_RenderPresent(renderer);
}
