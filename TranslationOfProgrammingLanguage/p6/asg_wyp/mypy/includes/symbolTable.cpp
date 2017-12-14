#include <map>
#include <algorithm>
#include "symbolTable.h"
#include "literal.h"

bool SymbolTable::found(const std::string& name) const {
  std::map<std::string, const Literal*>::const_iterator it = symbolTable.find(name);
  if ( it == symbolTable.end() )
    return false;
  else
    return true;
}

void SymbolTable::insert(const std::string& name, const Literal* val) {
  symbolTable[name] = val;
  // display();
}

const Literal* SymbolTable::getValue(const std::string& name) const {
  std::map<std::string, const Literal*>::const_iterator it = symbolTable.find(name);
  if ( it == symbolTable.end() )
    throw name+std::string(" not found");
  return it->second;
}
void SymbolTable::display() const {
  std::map<std::string, const Literal*>::const_iterator it = symbolTable.begin();
  while (it != symbolTable.end()) {
    std::cout << "symbolTable: " << it->first << std::endl;
    it++;
  }
}

void SymbolTable::insert(const std::string& name, const Literal* val, const int type) {
  switch(type) {
    case _ADD   : symbolTable[name] = (*symbolTable[name] + *val);
                  break;
    case _MINUS : symbolTable[name] = (*symbolTable[name] - *val);
                  break;
    case _MULT  : symbolTable[name] = (*symbolTable[name] * (*val));
                  break;
    case _DIV   : symbolTable[name] = (*symbolTable[name] / *val);
                  break;
    case _MOD   : symbolTable[name] = (*symbolTable[name] % *val);
                  break;
    case _IDIV  : symbolTable[name] = (*symbolTable[name]).operatorIdiv(*val);
                  break;
    case _POW   : symbolTable[name] = (*symbolTable[name]).operatorPow(*val);
                  break;
  }
}
