#ifndef SYMBOLTABLE__H
#define SYMBOLTABLE__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

class Literal;

class SymbolTable {
public:
  SymbolTable() : symbolTable() {}
  bool found(const std::string& name) const;
  void insert(const std::string& name, const Literal* val);
  void insert(const std::string& name, const Literal* val, const int type);
  const Literal* getValue(const std::string& name) const;
  std::map<std::string, const Literal*> getSymbolTable() { return symbolTable;}
  void moveTo(std::map<std::string, const Literal*>);
  void recoverFrom(std::map<std::string, const Literal*>);
  void clearTable();
  void display() const;
  // static   SymbolTable& getInstance();
  // void     setValue(const std::string& name, const Literal* val);
  // void     setValue(const std::string& name, const Literal* val, const int type);
  // const Literal* getValue(const std::string& name) const;
private:
  std::map<std::string, const Literal*> symbolTable;
  // SymbolTable() : table() {}
};

#endif
