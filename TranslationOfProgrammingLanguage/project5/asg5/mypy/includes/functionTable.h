#ifndef FUNCTIONTABLE__H
#define FUNCTIONTABLE__H

#include <iostream>
#include <string>
#include <map>

class Node;

class FunctionTable {
public:
  FunctionTable() : funcTable() {}
  bool found(const std::string& name) const;
  void insert(const std::string& name, const Node* suite);
  const Node* getValue(const std::string& name) const;
  void display() const;
private:
  std::map<std::string, const Node*> funcTable;
};

#endif
