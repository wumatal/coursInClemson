#ifndef FUNCTIONTABLE_H
#define FUNCTIONTABLE_H

#include <iostream>
#include <string>
#include <map>

class Node;

class FunctionTable {
public:
  FunctionTable () : functions() {}
  // int found(const std::string& name) const;
  bool found(const std::string& name) const;
  void insert(const std::string& name, const Node* suite);
  const Node* getValue(const std::string& name) const;
  void display() const;
  // virtual ~FunctionTable ();
private:
  std::map<std::string, const Node*> functions;
};

#endif
