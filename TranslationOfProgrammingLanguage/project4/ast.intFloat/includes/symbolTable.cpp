#include <map>
#include <algorithm>
#include "symbolTable.h"
#include "literal.h"

SymbolTable& SymbolTable::getInstance() {
  static SymbolTable instance;
  return instance;
}

const Literal* SymbolTable::getValue(const std::string& name) const {
  std::map<std::string, const Literal*>::const_iterator it = 
    table.find(name);
  if ( it == table.end() ) throw name+std::string(" not found");
  return it->second;
}

void SymbolTable::setValue(const std::string& name, const Literal* val) { 
  table[name] = val;
}

void SymbolTable::setValue(const std::string& name, const Literal* val, const int type) { 
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
    case _POW : table[name] = (*table[name]).operatorPow(*val);  
                  break;
  }
}

