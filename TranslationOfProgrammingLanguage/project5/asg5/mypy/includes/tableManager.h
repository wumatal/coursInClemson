#ifndef TABLEMANAGER__H
#define TABLEMANAGER__H

#include <iostream>
#include <string>
#include <vector>
#include "symbolTable.h"
#include "functionTable.h"

class Literal;

class TableManager {
public:
  static TableManager& getInstance();
  // ~TableManager();
  const Literal* getSymbol(const std::string&);
  const Node* getSuite(const std::string&);
  void insertSymbol(const std::string&, const Literal*);
  void insertFunction(const std::string&, const Node*);
  bool checkSymbol(const std::string&) const;
  bool checkFuncName(const std::string&) const;
  int getCurrentScope() const { return currentScope; }
  void setCurrentScope(int scope) { currentScope = scope; }
  bool getReturned() const { return returned; }
  void setReturned(bool b) { returned = b; }
  void pushScope();
  void popScope();
  void display() const;
private:
  int currentScope;
  bool returned;
  std::vector<SymbolTable> tables;
  std::vector<FunctionTable> functions;

  TableManager() : currentScope(0), returned(false), tables(), functions() {
    tables.push_back(SymbolTable());
    functions.push_back(FunctionTable());
  }

  TableManager(const TableManager&);
  TableManager& operator=(const TableManager&);
};
#endif
