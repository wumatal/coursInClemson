#ifndef SYMBOLTABLE__H
#define SYMBOLTABLE__H

#include <iostream>
#include <string>
#include <map>
// #include <algorithm>

class Literal;
// class Node;

class SymbolTable {
public:
  // static SymbolTable& getInstance();
  SymbolTable() : symbolTable() {}

  bool found(const std::string& name) const;
  void insert(const std::string& name, const Literal* val);
  const Literal* getValue(const std::string& name) const;
  void display() const;

  // void setValue(const std::string& name, const Literal* val);

private:
  std::map<std::string, const Literal*> symbolTable;
  // SymbolTable(const SymbolTable&);
  // SymbolTable& operator=(const SymbolTable&);
};

#endif
