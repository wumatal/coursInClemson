#pragma once
#include <iostream>

class Literal;

class Node {
public:
  Node() {}
  virtual ~Node() {}
  virtual const Literal* eval(std::string caller) const = 0;
  virtual void print() const {
    std::cout << "NODE" << std::endl;
  }
};
