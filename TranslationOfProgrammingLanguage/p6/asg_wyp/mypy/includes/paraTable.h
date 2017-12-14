#ifndef PARATABLE_H
#define PARATABLE_H

#include <iostream>
#include <string>
#include <map>

class Node;

class ParaTable {
public:
  ParaTable () : parameters() {}
  // int found(const std::string& name) const;
  bool found(const std::string& name) const;
  void insert(const std::string& name, const Node* fmls);
  const Node* getValue(const std::string& name) const;
  void display() const;
  // virtual ~FunctionTable ();
private:
  std::map<std::string, const Node*> parameters;
};

#endif
