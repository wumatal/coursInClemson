#include "tableManager.h"

// Gof
TableManager& TableManager::getInstance(){
  static TableManager instance;
  return instance;
}

// Get the Symbol Entry
const Literal* TableManager::getSymbol( const std::string& name ) {
  // const Literal* symbol;
  // for ( SymbolTable s : tables ) {
  //   symbol = s.getSymbol(name);
  //   if ( symbol != nullptr )
  //     return symbol;
  // }
  // std::cout << "tableManager: symbol" << name << "NOT FOUND!" << std::endl;
  // std::exception up = std::exception();
  // throw up;
  SymbolTable& symbolTable = tables[currentScope];
  return symbolTable.getValue(name);
}

// Get the Function Entry
const Node* TableManager::getSuite(const std::string& name) {
  // const Node* func;
  // for ( FunctionTable f : functions ) {
  //   func = f.getSymbol(name);
  //   if ( func != nullptr )
  //     return func;
  // }
  // std::cout << "tableManager: func" << name << "NOT FOUND!" << std::endl;
  // std::exception up = std::exception();
  // throw up;
  const Node* func;
  for( int i=currentScope-1; i >= 0; i--) {
    func = functions[i].getValue(name);
    if ( func != NULL )
      return func;
  }
  std::cout << "tableManager: func" << name << "NOT FOUND!" << std::endl;
  std::exception up = std::exception();
  throw up;
  // FunctionTable& funcTable = functions[currentScope-1];
  // return funcTable.getValue(name);
}

// Record newly scaned symbol
// Scope ++?
void TableManager::insertSymbol(const std::string& name, const Literal* node) {
  SymbolTable& table = tables[currentScope];
  table.insert(name, node);
}

// Record newLy scaned function
// Scope ++?
void TableManager::insertFunction(const std::string& name, const Node* node) {
  FunctionTable& table = functions[currentScope];
  SymbolTable symbTemp;
  FunctionTable funcTemp;

  table.insert(name, node);
  tables.push_back(symbTemp);
  functions.push_back(funcTemp);
}

// search this scope and above to trace a symbol
bool TableManager::checkSymbol(const std::string& name) const {
  return tables[currentScope].found(name);
}

// search this scope and above to trace a func
bool TableManager::checkFuncName(const std::string& name) const {
  // std::cout << currentScope << std::endl;
  bool found = false;
  for( int i=currentScope; i >= 0; i--) {
    found += functions[i].found(name);
  }
  return found;
  // return functions[currentScope].found(name);
}

void TableManager::pushScope() {
  currentScope++;
}

void TableManager::popScope() {
  if (currentScope > 0) {
    currentScope--;
  }
}

void TableManager::display() const {
  for ( SymbolTable s : tables ) {
    s.display();
  }
  for ( FunctionTable f : functions ) {
    f.display();
  }
}
