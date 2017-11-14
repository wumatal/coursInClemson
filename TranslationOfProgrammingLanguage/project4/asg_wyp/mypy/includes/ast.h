#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>
#include "literal.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

class IdentNode : public Node {
public:
  IdentNode(const std::string id) : Node(), ident(id) { }
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
};

class UnaryNode : public Node {
public:
  UnaryNode(const int sng, Node* n) : Node(), num(n), sngs(sng) { }
  virtual const Literal* eval() const;
  Node* getNum() const { return num;  }
  UnaryNode(const UnaryNode&) = delete;
  UnaryNode& operator=(const UnaryNode&) = delete;
  virtual ~UnaryNode() {}
protected:
  Node *num;
private:
  int sngs;
};

class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual const Literal* eval() const = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
protected:
  Node *left;
  Node *right;
};

class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class PlusAsgBinaryNode : public BinaryNode {
public:
  PlusAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class MinusAsgBinaryNode : public BinaryNode {
public:
  MinusAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class MultAsgBinaryNode : public BinaryNode {
public:
  MultAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class DivAsgBinaryNode : public BinaryNode {
public:
  DivAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class ModAsgBinaryNode : public BinaryNode {
public:
  ModAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class IdivAsgBinaryNode : public BinaryNode {
public:
  IdivAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class PowAsgBinaryNode : public BinaryNode {
public:
  PowAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class ModBinaryNode : public BinaryNode {
public:
  ModBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class IdivBinaryNode : public BinaryNode {
public:
  IdivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class PowBinaryNode : public BinaryNode {
public:
  PowBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};
