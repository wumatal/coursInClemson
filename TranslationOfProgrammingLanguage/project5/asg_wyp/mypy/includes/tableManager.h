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
  const  Literal*      getEntry( const std::string& name );
  const  Node*         getSuite( const std::string& name );
  void   insert( const std::string& name, const Literal* node);
  void   insert( const std::string& name, const Node* node );
  bool   checkName( const std::string& name ) const;
  bool   checkFunc( const std::string& name ) const;
  // accessors added
  int    getCurrentScope() const { return currentScope;       }
  void   setCurrentScope( int scope ) { currentScope = scope; }
  bool   isReturned() const { return returned;                }
  void   setReturned( bool re ) { returned = re;              }
  void   pushScope();
  void   popScope();
  void   display() const;

private:
  int  currentScope;
  bool returned;

  std::vector<SymbolTable>   tables;
  std::vector<FunctionTable> functions;

  TableManager() : currentScope(0), returned(false), tables(), functions() {
    tables.push_back( SymbolTable() );
    functions.push_back( FunctionTable() );
  }

  TableManager(const TableManager&);
  TableManager& operator=(const TableManager&);
};

#endif
