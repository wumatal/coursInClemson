#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>
#include <vector>
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


class IfNode : public Node {
public:
  IfNode ( Node* n, Node* ts, Node* es )
    : Node(), test(n), suite(ts), elseSuite(es) {}
  virtual const Literal* eval() const;
private:
  Node* test;
  Node* suite;
  Node* elseSuite;
  IfNode(const IfNode&);
  IfNode& operator=(const IfNode&);
};

class ReturnNode : public Node {
public:
  ReturnNode( Node* n) : Node(), node(n) {}
  virtual const Literal* eval() const;
private:
  Node* node;

  ReturnNode(const ReturnNode&);
  ReturnNode& operator=(const ReturnNode&);
};

class CallNode : public Node {
public:
  CallNode(const std::string& id) : Node(), ident(id) {}
  // virtual ~CallNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
};

class FuncNode : public Node {
public:
  FuncNode(const std::string& id, Node* s, Node* arg)
    : Node(), ident(id), suite(s), para(arg) {}
  // virtual ~FuncNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
  Node* suite;
  Node* para;

  FuncNode(const FuncNode&);
  FuncNode& operator=(const FuncNode&);
};

class ParaNode : public Node {
public:
  virtual ~ParaNode() {}
  virtual const Literal* eval() const = 0;
};

class ActParaNode : public ParaNode {
public:
  virtual const Literal* eval() const;
private:
  Node* para;
};

class FmlParaNode : public ParaNode {
public:
  virtual const Literal* eval() const;
private:
  Node* para;
};

class SuiteNode : public Node {
public:
  SuiteNode(const std::vector<Node*>& vec) : Node(), stmts(vec) {}
  // virtual ~SuiteNode() {}
  virtual const Literal* eval() const;
private:
  std::vector<Node*> stmts;
};

class PrintNode : public Node {
public:
  PrintNode(Node* n) : Node(), node(n) {}
  virtual const Literal* eval() const;
private:
  Node* node;

  PrintNode(const PrintNode&);
  PrintNode& operator=(const PrintNode&);
};

class ArgNode : public Node {
public:
  ArgNode(Node* n): Node(), arglist(n) {}
  virtual const Literal* eval() const { return NULL; }
private:
  Node* arglist;

  ArgNode& operator=(const ArgNode&);
  ArgNode(const ArgNode&);
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

// Add logic node
class LessThanBianryNode : public BinaryNode {
public:
  LessThanBianryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class LessEqualBianryNode : public BinaryNode {
public:
  LessEqualBianryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class NotEqualBianryNode : public BinaryNode {
public:
  NotEqualBianryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class EqualBianryNode : public BinaryNode {
public:
  EqualBianryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class GreatEqualBianryNode : public BinaryNode {
public:
  GreatEqualBianryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class GreatThanBianryNode : public BinaryNode {
public:
  GreatThanBianryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
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

// class LShiftBinaryNode : public BinaryNode {
// public:
//   LShiftBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
//   virtual const Literal* eval() const;
// };
//
// class RShiftBinaryNode : public BinaryNode {
// public:
//   RShiftBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
//   virtual const Literal* eval() const;
// };
