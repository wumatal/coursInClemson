#include "shape.h"


void Circle::draw(SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  for (int w = 0; w < radius * 2; w++) {
    for (int h = 0; h < radius * 2; h++) {
      int dx = radius - w; // horizontal offset
      int dy = radius - h; // vertical offset
      if ((dx*dx + dy*dy) <= (radius * radius)) {
        SDL_RenderDrawPoint(renderer, pos.x + dx, pos.y + dy);
      }
    }
  }
}

void Quadrangle::draw(SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  for (int w = 0; w < width; w++) {
    for (int h = 0; h < height; h++) {
      int dx = width - w; // horizontal offset
      int dy = height - h; // vertical offset
      if ((dx*dx + dy*dy) <= (height * width)) {
        SDL_RenderDrawPoint(renderer, pos.x + dx, pos.y + dy);
      }
    }
  }
}

void Triange::draw(SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawLine(renderer, pos_a.x, pos_a.y, pos_b.x, pos_b.y);
  SDL_RenderDrawLine(renderer, pos_b.x, pos_b.y, pos_c.x, pos_c.y);
  SDL_RenderDrawLine(renderer, pos_c.x, pos_c.y, pos_a.x, pos_a.y);

}


int CalculateBezierPoint(float t,
  const int p0, const int p1, const int p2, const int p3)
{
  float u = 1 - t;
  float tt = t * t;
  float uu = u * u;
  float uuu = uu * u;
  float ttt = tt * t;
 
  float p = uuu * p0; //first term
  p += 3 * uu * t * p1; //second term
  p += 3 * u * tt * p2; //third term
  p += ttt * p3; //fourth term
 
  return static_cast<int>(p);
}


void Curve::draw(SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

  int q0 = CalculateBezierPoint(0, startPos.y, fstPos.y, sndPos.y, endPos.y);
  int q1;
  float t;
  int distance = endPos.x - startPos.x;
   
  for(int i = 1; i <= distance; i++)
  {
    t = i / (float) distance;
    q1 = CalculateBezierPoint(t, startPos.y, fstPos.y, sndPos.y, endPos.y);
    SDL_RenderDrawLine(renderer, startPos.x+i, q0, startPos.x+i+1, q1);
    q0 = q1;
  }
}

void Branch::draw(SDL_Renderer* renderer) {
  int y = left->getStartPos().y;

  int lp0 = left->getStartPos().x;
  int lp1 = left->getFstPos().x;
  int lp2 = left->getSndPos().x;
  int lp3 = left->getEndPos().x;

  int rp0 = right->getStartPos().x;
  int rp1 = right->getFstPos().x;
  int rp2 = right->getSndPos().x;
  int rp3 = right->getEndPos().x;

  float t;

  int distance = left->getEndPos().y > right->getEndPos().y ? 
                 left->getEndPos().y : right->getEndPos().y;
  distance -= y;

  int lx = lp0;
  int rx = rp0;

  for(int i = 0; i < distance; i++){
    t = i / (float) distance;
    lx = CalculateBezierPoint(t, lp0, lp1, lp2, lp3);
    rx = CalculateBezierPoint(t, rp0, rp1, rp2, rp3);
    if( rx - lx < 4 ){
      // Draw edges
      SDL_SetRenderDrawColor(renderer, branchEdge.r, branchEdge.g, branchEdge.b, branchEdge.a);
      SDL_RenderDrawLine(renderer, lx, i+y, rx, i+y);
    }
    else {
      // Draw edges
      SDL_SetRenderDrawColor(renderer, branchEdge.r, branchEdge.g, branchEdge.b, branchEdge.a);
      SDL_RenderDrawLine(renderer, lx, i+y, rx, i+y);
      // Fill area
      SDL_SetRenderDrawColor(renderer, branchArea.r, branchArea.g, branchArea.b, branchArea.a);
      SDL_RenderDrawLine(renderer, lx+2, i+y, rx-2, i+y);
    }

  }

}
