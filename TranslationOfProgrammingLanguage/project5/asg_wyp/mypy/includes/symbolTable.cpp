#include <map>
#include <algorithm>
#include "symbolTable.h"
#include "literal.h"

bool SymbolTable::found(const std::string& name) const {
  std::map<std::string, const Literal*>::const_iterator it = table.find(name);
  if ( it == table.end() )
    return false;
  else
    return true;
}

void SymbolTable::insert(const std::string& name, const Literal* val) {
  table[name] = val;
}

const Literal* SymbolTable::getEntry(const std::string& name) const {
  std::map<std::string, const Literal*>::const_iterator it = table.find(name);
  if ( it == table.end() )
    return nullptr;
  else
    return it->second;
}
void SymbolTable::display() const {
  std::map<std::string, const Literal*>::const_iterator it = table.begin();
  while (it != table.end()) {
    std::cout << "symbolTable: " << it->first << std::endl;
    it++;
  }
}

void SymbolTable::insert(const std::string& name, const Literal* val, const int type) {
  switch(type) {
    case _ADD   : table[name] = (*table[name] + *val);
                  break;
    case _MINUS : table[name] = (*table[name] - *val);
                  break;
    case _MULT  : table[name] = (*table[name] * (*val));
                  break;
    case _DIV   : table[name] = (*table[name] / *val);
                  break;
    case _MOD   : table[name] = (*table[name] % *val);
                  break;
    case _IDIV  : table[name] = (*table[name]).operatorIdiv(*val);
                  break;
    case _POW   : table[name] = (*table[name]).operatorPow(*val);
                  break;
  }
}
