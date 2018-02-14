#include <SDL2/SDL.h>
#include <map>
#include <vector>
#include "shape.h"

// In order to make it possible that SDL_point as key of a map, operator < 
// and == are both needed. Or the compiler will have no idea how to compare
// these keys.
inline bool operator==(const SDL_Point &a, const SDL_Point &b){
  return a.x == b.x && a.y == b.y;
}
inline bool operator<(const SDL_Point &a, const SDL_Point &b){
  return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}


// bool SDL_point::operator==(const SDL_Point &b){
//   return x == b.x && y == b.y;
// }
// bool SDL_point::operator<(const SDL_Point &b){
//   return (x < b.x) || (x == b.x && y < b.y);
// }

const SDL_Point pDefault = {0, 0};
const int SEGMENT_COUNT = 16;
// The properties of all stars
const std::map<const SDL_Point, const int> stars {
  {{ 59,  16}, 4}, {{150,  11}, 2}, {{215,  18}, 3},
  {{270,  34}, 2}, {{376,  47}, 3}, {{165,  84}, 3},
  {{446, 106}, 3}, {{223, 180}, 2}, {{ 21, 238}, 2},
  {{ 74, 251}, 3}, {{241, 266}, 4}
};
const SDL_Color starLoop = {246, 233,  67, 255};
const SDL_Color starMid  = {211, 183,  10, 255};
const SDL_Color starEdge = {  0,   5, 106, 255};
const int loopWid = 10;
const int edgeWid = 3;
const int loopOffset = 3;

// The properties of the moon
const SDL_Point moonOutPos = {549, 69};
const SDL_Point moonInPos  = {563, 61};
const int moonOutRadius    = 39;
const int moonInRadius     = 25;
const SDL_Color moonColor  = {252, 141,  25, 255};

// The properties of the sky

const SDL_Color skyOut  = {37, 85, 187, 255};
const SDL_Color skyMain = {12,  7,  99, 255};
const SDL_Color skyIn   = { 0,  5,  21, 255};
const int midWid = 13;

// The properties of the tree
const SDL_Color branchArea = {  0,   0,   0, 255};
const SDL_Color branchEdge = {155, 165, 140, 255};
const std::vector<std::vector<SDL_Point>> branches = {
  {{130,  53}, {108,  76}, {143, 185}, {120, 182},
   {130,  53}, {122,  76}, {158, 129}, {157, 186}},

  {{120, 182}, { 97, 227}, {128, 258}, {104, 304},
   {157, 186}, {142, 242}, {167, 280}, {152, 352}},  

  {{170, 184}, {171, 193}, {117, 233}, {100, 256},
   {170, 184}, {171, 242}, {138, 287}, {132, 376}},

  {{ 92, 185}, {128, 216}, { 65, 313}, {100, 345},
   { 92, 185}, {137, 198}, {104, 326}, {160, 362}},

  {{100, 258}, { 57, 285}, {142, 408}, {100, 427},
   {100, 258}, { 85, 295}, {194, 364}, {164, 373}},
  
  {{ 92, 325}, {122, 383}, { 58, 440}, { 89, 479},
   { 92, 325}, {150, 330}, { 88, 466}, {151, 479}},

  {{161, 348}, {187, 413}, {124, 462}, {153, 479},
   {161, 348}, {231, 348}, {164, 471}, {239, 479}},

  {{183, 253}, { 91, 266}, {210, 440}, {110, 479},
   {183, 253}, {153, 281}, {214, 385}, {184, 431}},

  {{140, 335}, {150, 330}, { 88, 466}, {151, 479},
   {140, 335}, {190, 394}, {139, 456}, {180, 479}},

  {{212, 282}, {163, 300}, {222, 389}, {146, 479},
   {212, 282}, {174, 307}, {265, 366}, {229, 422}},

  {{246, 408}, {225, 406}, {191, 476}, {238, 479},
   {246, 408}, {236, 432}, {299, 462}, {286, 479}},

  {{271, 394}, {237, 412}, {277, 471}, {238, 479},
   {271, 394}, {246, 408}, {308, 452}, {286, 479}}

};

// The properties of lights
const int lightEdgeWid = 3;
const int lightAreaWid = 7;
const std::vector<std::vector<SDL_Point>> lights{
  {{  0, 300}, { 16, 287}, {100, 342}, {116, 329}},

  {{196, 323}, {248, 328}, {304, 291}, {364, 296}},

  {{364, 296}, {405, 274}, {457, 281}, {484, 264}},

  {{484, 264}, {484, 264}, {496, 258}, {499, 254}},

  {{499, 254}, {524, 228}, {565, 195}, {599, 196}},

  {{116, 329}, {116, 329}, {196, 323}, {196, 323}}

};

// The properties of clouds
const SDL_Color cloudMain = {184, 200, 226, 255};
const SDL_Color cloudEdge = { 28,  57, 125, 255};
const int cloudMainWid = 7;
const int cloudEdgeWid = 4;

const std::map<const SDL_Point, const int> clouds {
  {{423, 413}, 103}, {{587, 280}, 51}, {{ 11, 383}, 42},
  {{ 69, 443},  76}, {{321, 382}, 65}, {{531, 357}, 80},
  {{258, 426},  87}
};

// houses
const SDL_Color writeWall = {68, 105, 158, 255};
const SDL_Color lightwall = { 3,  40, 121, 255};
const SDL_Color darkWall  = { 5,   5,  15, 255};
const SDL_Color blackWall = { 1,   3,   0, 255};
const SDL_Point roofA = {336, 391};
const SDL_Point roofB = {323, 416};
const SDL_Point roofC = {353, 416};
