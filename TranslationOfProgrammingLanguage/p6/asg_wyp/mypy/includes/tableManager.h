#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "symbolTable.h"
#include "functionTable.h"

class Literal;

class TableManager {
public:
  static TableManager& getInstance();
  const Literal* getSymbol(const std::string&);
  const Node* getSuite(const std::string&, int);
  const Node* getPara(const std::string&, int);
  void  insertSymbol(const std::string&, const Literal*);
  void  insertFunction(const std::string&, const Node*, const Node*);
  bool  checkSymbol(const std::string&) const;
  int   checkFuncName(const std::string&) const;
  // bool  checkFuncName(const std::string&) const;
  // Protect suite
  // std::vector<std::map<std::string, const Literal*>>  protectStack(int);
  // void  restoreStack(int, std::vector<std::map<std::string, const Literal*>>);
  void  protectStack(int);
  void  restoreStack(int);
  // accessors added
  int   getCurrentScope() const { return currentScope; }
  void  setCurrentScope(int scope) { currentScope = scope; }
  bool  getReturned() const { return returned; }
  void  setReturned(bool b) { returned = b; }
  void  pushScope();
  // void  pushScope(const std::string&);
  void  popScope();
  void  display() const;

private:
  int  currentScope;
  bool returned;

  std::vector<SymbolTable>   tables;
  std::vector<FunctionTable> functions;
  // std::vector<SymbolTable>   recvTables;
  std::vector<std::map<std::string, const Literal*>> recvTables;

  TableManager()
  : currentScope(0), returned(false), tables(), functions(), recvTables() {
    tables.push_back( SymbolTable() );
    functions.push_back( FunctionTable() );
    recvTables.push_back(std::map<std::string, const Literal*>());
    // recvTables.push_back( SymbolTable() );
  }

  TableManager(const TableManager&);
  TableManager& operator=(const TableManager&);
};

#endif
