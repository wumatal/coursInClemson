#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "literal.h"
// #include "intliteral.h"

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

class SuiteNode : public Node {
public:
  SuiteNode(const std::vector<Node*>& vec) : Node(), stmts(vec) {}
  // virtual ~SuiteNode() {}
  virtual const Literal* eval() const;
private:
  std::vector<Node*> stmts;
};

class FuncNode : public Node {
public:
  FuncNode(const std::string& id, Node* n) : Node(), ident(id), suite(n) {}
  // virtual ~FuncNode() {}
  FuncNode(const FuncNode&) = delete;
  FuncNode& operator=(const FuncNode&) = delete;
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
  Node* suite;
};

class CallNode : public Node {
public:
  CallNode(const std::string& id) : Node(), ident(id) {}
  // virtual ~CallNode() {}
  virtual const Literal* eval() const;
private:
  std::string ident;
  // Node* node;
};

class PrintNode : public Node {
public:
  PrintNode(Node* n) : Node(), node(n) {}
  virtual const Literal* eval() const;
  PrintNode(const PrintNode&) = delete;
  PrintNode& operator=(const PrintNode&) = delete;
private:
  Node* node;
};

class ArgNode : public Node {
public:
  ArgNode(Node* n): Node(), arglist(n) {}
  virtual const Literal* eval() const { return NULL; }
  ArgNode(const ArgNode&) = delete;
  ArgNode& operator=(const ArgNode&) = delete;
private:
  Node* arglist;
};

class IfNode : public Node {
public:
  IfNode(Node* t, Node* s, Node* es) : Node(), test(t), suite(s), elseSuite(es) {}
  virtual const Literal* eval() const;
  IfNode(const IfNode&) = delete;
  IfNode& operator=(const IfNode&) = delete;
private:
  Node* test;
  Node* suite;
  Node* elseSuite;
};

class ReturnNode : public Node {
public:
  ReturnNode(Node* n) : Node(), result(n) {}
  virtual const Literal* eval() const;
  ReturnNode(const ReturnNode&) = delete;
  ReturnNode& operator=(const ReturnNode&) = delete;
private:
  Node* result;
};

class UnaryNode : public Node {
public:
  UnaryNode(Node* r) : Node(), right(r) {}
  virtual const Literal* eval() const = 0;
  Node* getRight() const { return right; }
  UnaryNode(const UnaryNode&) = delete;
  UnaryNode& operator=(const UnaryNode&) = delete;
protected:
  Node* right;
};

class MinusUnaryNode : public UnaryNode {
public:
  MinusUnaryNode(Node* right) : UnaryNode(right) {}
  virtual const Literal* eval() const;
};

class TildeUnaryNode : public UnaryNode {
public:
  TildeUnaryNode(Node* right) : UnaryNode(right) {}
  virtual const Literal* eval() const;
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
  ModBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class FlrDivBinaryNode : public BinaryNode {
public:
  FlrDivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class PowBinaryNode : public BinaryNode {
public:
  PowBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class LShiftBinaryNode : public BinaryNode {
public:
  LShiftBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class RShiftBinaryNode : public BinaryNode {
public:
  RShiftBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class EqEqualBinaryNode : public BinaryNode {
public:
  EqEqualBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class LessBinaryNode : public BinaryNode {
public:
  LessBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class GreaterBinaryNode : public BinaryNode {
public:
  GreaterBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class LessEqualBinaryNode : public BinaryNode {
public:
  LessEqualBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class GreaterEqualBinaryNode : public BinaryNode {
public:
  GreaterEqualBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class NotEqualBinaryNode : public BinaryNode {
public:
  NotEqualBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};
