#include "tableManager.h"

// Gof
TableManager& TableManager::getInstance(){
  static TableManager instance;
  return instance;
}

// Get the Symbol Entry
const Literal* TableManager::getSymbol( const std::string& name ) {
  
  SymbolTable& symbolTable = tables[currentScope];

  return symbolTable.getValue(name);
}

// Get the Function Entry
const Node* TableManager::getSuite(const std::string& name, int startScope) {
  const Node* func;
  for( int i=startScope; i >= 0; i--) {
    func = functions[i].getValue(name);
    if ( func != NULL ){
      // std::cout << "scope: " << i << std::endl;
      return func;
    }
  }
  std::cout << "tableManager: func" << name << "NOT FOUND!" << std::endl;
  std::exception up = std::exception();
  throw up;
  // FunctionTable& funcTable = functions[currentScope-1];
  // return funcTable.getValue(name);
}

const Node* TableManager::getPara(const std::string& name, int scope) {
  //scope = currentScope;
  FunctionTable& funcTable = functions[scope];
  // FunctionTable& funcTable = functions[currentScope];
  // std::cout << "found? " << funcTable.found(name) << std::endl;
  return funcTable.getPara(name);
}

// Record newly scaned symbol
// Scope ++?
void TableManager::insertSymbol(const std::string& name, const Literal* node) {
  unsigned int test = (unsigned int)currentScope;
  if(test >= tables.size()){
    for(int i=tables.size(); i<=currentScope+1; i++)
      tables.push_back(SymbolTable());
  }
  SymbolTable& table = tables[currentScope];

  table.insert(name, node);
}

// Record newLy scaned function
// Scope ++?
void TableManager::insertFunction(const std::string& name, const Node* node, const Node* para) {
  unsigned int test = (unsigned int)currentScope;
  if(test >= tables.size()){
    for(int i=tables.size(); i<=currentScope+1; i++)
      tables.push_back(SymbolTable());
  }
  if(test >= functions.size()){
    for(int i=functions.size(); i<=currentScope+1; i++)
      functions.push_back(FunctionTable());
  }
  FunctionTable& table = functions[currentScope];
  table.insert(name, node);
  if (para) {
    table.insertPara(name, para);
  }
}

// search this scope and above to trace a symbol
bool TableManager::checkSymbol(const std::string& name) const {
  return tables[currentScope].found(name);
}

// search this scope and above to trace a func
// bool TableManager::checkFuncName(const std::string& name) const {
int TableManager::checkFuncName(const std::string& name) const {

  int i;
  for( i=currentScope; i >= 0; i--) {
    if( functions[i].found(name) )
      return i;
  }
  return -1;
  // return functions[currentScope].found(name);
}

// When a function defined in higher scope is called,
// the symbol in lower scopes need to be remove and stored in recvTables
void TableManager::protectStack(int scope) {
  recvTables.reserve(currentScope + 1);
  for( int i = currentScope; i <= scope; i++ ){
    std::map<std::string, const Literal*> recvTable;
    tables[i].moveTo(recvTable);
    recvTables[i] = recvTable;
  }
}

// After a higher scope function call, the symbol protected in recvTables
// need to store back in current stack.
void TableManager::restoreStack(int scope) {
  for( int i = currentScope; i <= scope; i++ ){
    tables[i].recoverFrom(recvTables[i]);
  }
}


// void TableManager::pushScope(const std::string& name) {
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
