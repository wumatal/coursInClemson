#include <sstream>
#include <iostream>
#include <limits>
#include <cmath>
#include "gamedata.h"

Gamedata& Gamedata::getInstance() {
  static Gamedata gamedata;
  return gamedata;
}

Gamedata::~Gamedata( ) { }

Gamedata::Gamedata(const string& fn ) :
  parser(fn),
  gameData(parser.getXmlData())
{ }

float Gamedata::getRandInRange(int min, int max) const {
  return min + (rand()/(std::numeric_limits<int>::max()+1.0f))*(max-min);
}

float Gamedata::getRandFloat(float min, float max) const {
  return min + (rand() / (RAND_MAX + 1.0f)) * (max - min);
}

bool  Gamedata::checkTag(const std::string& tag)const{
  return gameData.count(tag)!=0;
}

bool Gamedata::getXmlBool(const string& tag) const {
  std::map<string, string>::const_iterator ptr = gameData.find(tag);
  if ( ptr == gameData.end() )
    throw string("Game: Didn't find boolean tag ")+tag+string(" in xml");
  else {
    if ( ptr->second == "true" ) return true;
    else return false;
  }
}

int Gamedata::getXmlInt(const string& tag) const {
  std::map<string, string>::const_iterator ptr = gameData.find(tag);
  if ( ptr == gameData.end() )
    throw string("Game: Didn't find integer tag ")+tag+string(" in xml");
  else {
    std::stringstream strm;
    strm << ptr->second;
    int data;
    strm >> data;
    return data;
  }
}

float Gamedata::getXmlFloat(const string& tag) const {
  std::map<string, string>::const_iterator ptr = gameData.find(tag);
  if ( ptr == gameData.end() )
    throw string("Game: Didn't find float tag ")+tag+string(" in xml");
  else {
    std::stringstream strm;
    strm << ptr->second;
    float data;
    strm >> data;
    return data;
  }
}

const string& Gamedata::getXmlStr(const string& tag) const {
  std::map<string, string>::const_iterator ptr = gameData.find(tag);
  if ( ptr == gameData.end() )
    throw string("Game: Didn't find string tag ")+tag+string(" in xml");
  else return ptr->second;
}

// const SDL_Color Gamedata::getXmlColor(const string& tag) const {
//   std::map<string, string>::const_iterator ptr = gameData.find(tag);
//   if( ptr == gameData.end() )
//     throw string("Game: Didn't find color tag ")+tag+string(" in xml");
//   else
//     return stringToSDLColor(ptr->second);
// }

void Gamedata::displayData() const {
  for(std::map<std::string, std::string>::const_iterator ptr = gameData.begin();
      ptr != gameData.end(); ++ptr) {
  // map<std::string, std::string>::const_iterator ptr =
  //   gameData.begin();
  // while ( ptr != gameData.end() ) {
    std::cout << ptr->first << ", " << ptr->second << std::endl;
    ++ptr;
  }
}

// const SDL_Color stringToSDLColor(const std::string colorString) {
//   std::regex pattern("([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})");
//   std::smatch match;
//
//   SDL_Color color = {0xff, 0, 0, 0};
//
//   if (std::regex_match(colorString, match, pattern)) {
//     int r = std::stoi(match[1].str(), nullptr, 16);
//     int g = std::stoi(match[2].str(), nullptr, 16);
//     int b = std::stoi(match[3].str(), nullptr, 16);
//     int a = std::stoi(match[4].str(), nullptr, 16);
//     color = {r, g, b, a};
//   }
//   else {
//     std::cout << colorString << " is an invalid rgb color\n";
//   }
//   return color;
// }
