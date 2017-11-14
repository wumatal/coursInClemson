#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "symbolTable.h"

const Literal* IdentNode::eval() const {
  const Literal* val = SymbolTable::getInstance().getValue(ident);
  return val;
}

const Literal* UnaryNode::eval() const {
  if (!num) {
    throw "error";
  }
  const Literal* x = num->eval();
  if( sngs == '-' ){
    return -(*x);
  }
  else
    return +(*x);
}

AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
}

PlusAsgBinaryNode::PlusAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res, _ADD);
}

MinusAsgBinaryNode::MinusAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res, _MINUS);
}

MultAsgBinaryNode::MultAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res, _MULT);
}

DivAsgBinaryNode::DivAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res, _DIV);
}

ModAsgBinaryNode::ModAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res, _MOD);
}

IdivAsgBinaryNode::IdivAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res, _IDIV);
}

PowAsgBinaryNode::PowAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res, _POW);
}


const Literal* AsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* res = right->eval();

  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

const Literal* PlusAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }

  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}

const Literal* MinusAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}

const Literal* MultAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}

const Literal* DivAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}

const Literal* ModAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}

const Literal* IdivAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}

const Literal* PowAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = SymbolTable::getInstance().getValue(n);
  return res;
}

const Literal* AddBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  //return (*x+*y);
  return (*x).operator+(*y);
}

const Literal* SubBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)/(*y));
}

const Literal* ModBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)%(*y));
}

const Literal* IdivBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).operatorIdiv(*y));
}

const Literal* PowBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).operatorPow(*y));
}
