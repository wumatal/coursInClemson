#ifndef GAMEDATA__H
#define GAMEDATA__H
#include <string>
#include <map>
#include <regex>
#include <SDL.h>
#include "vector2f.h"
#include "parseXML.h"

class Gamedata {
public:
  static Gamedata& getInstance();
  ~Gamedata();
  void displayData() const;

  bool getXmlBool(const std::string&) const;
  const std::string& getXmlStr(const std::string&) const;
  // const SDL_Color getXmlColor(const string&) const;
  float getXmlFloat(const std::string&) const;
  int getXmlInt(const std::string&) const;
  float getRandInRange(int min, int max) const;
  float getRandFloat(float min, float max) const;
  bool  checkTag(const std::string&)const;
  // SDL_Color stringToSDLColor(std::string);
private:
  ParseXML parser;
  const map<std::string, std::string> gameData;

  Gamedata(const std::string& fn = "xmlSpec/game.xml");
  Gamedata(const Gamedata&);
  Gamedata& operator=(const Gamedata&);
};
#endif
