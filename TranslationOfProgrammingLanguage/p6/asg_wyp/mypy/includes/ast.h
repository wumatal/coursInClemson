#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "literal.h"
#include "tableManager.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

class IdentNode : public Node {
public:
  IdentNode(const std::string id) : Node(), ident(id) { }
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval(std::string) const;
private:
  std::string ident;
};

class SuiteNode : public Node {
public:
  SuiteNode(const std::vector<Node*>& vec) : Node(), stmts(vec) {}
  // virtual ~SuiteNode() {}
  virtual const Literal* eval(std::string) const;
private:
  std::vector<Node*> stmts;
};

class IfNode : public Node {
public:
  IfNode ( Node* n, Node* ts, Node* es )
    : Node(), test(n), suite(static_cast<SuiteNode*> (ts)), elseSuite(static_cast<SuiteNode*> (es)) {}
  virtual const Literal* eval(std::string) const;
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
  virtual const Literal* eval(std::string) const;
private:
  Node* node;

  ReturnNode(const ReturnNode&);
  ReturnNode& operator=(const ReturnNode&);
};

class CallNode : public Node {
public:
  CallNode(const std::string& id, Node* args)
  : Node(), ident(id), acts(args), caller() {}
  // virtual ~CallNode() {}
  void  setCaller(std::string func)  { caller = func; }
  std::string getCaller() const { return caller;      }
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval(std::string) const;
private:
  std::string ident;
  Node* acts;
  std::string caller;

  CallNode(const CallNode&);
  CallNode& operator=(const CallNode&);
};

class FuncNode : public Node {
public:
  FuncNode(const std::string& id, Node* s, Node* arg)
    : Node(), ident(id), para(arg), suite(s), creater(),
      createScope(TableManager::getInstance().getCurrentScope()){}
  // virtual ~FuncNode() {}
  void  setCreater(std::string func)  { creater = func; }
  std::string getCreater() const { return creater;      }
  const std::string getIdent() const { return ident;  }
  void  setCreateScope( int s ) { createScope = s;    }
  int   getCreateScope() const  { return createScope; }
  virtual const Literal* eval(std::string) const;
private:
  std::string ident;
  Node* para;
  Node* suite;
  std::string creater;
  int   createScope;

  FuncNode(const FuncNode&);
  FuncNode& operator=(const FuncNode&);
};


class ActParaNode : public Node {
public:
  ActParaNode(const std::vector<Node*>& vec) : Node(), acts(vec) {}
  virtual const Literal* eval(std::string) const;
  std::vector<Node*> getValue() const { return acts; }
private:
  std::vector<Node*> acts;
};

class FmlParaNode : public Node {
public:
  FmlParaNode(const std::vector<Node*>* vec) : Node(), fmls(*vec) {}
  virtual const Literal* eval(std::string) const;
  std::vector<Node*> getValue() const { return fmls; }
private:
  std::vector<Node*> fmls;
};


class PrintNode : public Node {
public:
  PrintNode(Node* n) : Node(), node(n) {}
  virtual const Literal* eval(std::string) const;
private:
  Node* node;

  PrintNode(const PrintNode&);
  PrintNode& operator=(const PrintNode&);
};
//
// class ArgNode : public Node {
// public:
//   ArgNode(Node* n): Node(), arglist(n) {}
//   virtual const Literal* eval(std::string) const { return NULL; }
// private:
//   Node* arglist;
//
//   ArgNode& operator=(const ArgNode&);
//   ArgNode(const ArgNode&);
// };

class UnaryNode : public Node {
public:
  UnaryNode(const int sng, Node* n) : Node(), num(n), sngs(sng) { }
  virtual const Literal* eval(std::string) const;
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
  virtual const Literal* eval(std::string) const = 0;
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
  virtual const Literal* eval(std::string) const;
};

class LessEqualBianryNode : public BinaryNode {
public:
  LessEqualBianryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(std::string) const;
};

class NotEqualBianryNode : public BinaryNode {
public:
  NotEqualBianryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(std::string) const;
};

class EqualBianryNode : public BinaryNode {
public:
  EqualBianryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(std::string) const;
};

class GreatEqualBianryNode : public BinaryNode {
public:
  GreatEqualBianryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(std::string) const;
};

class GreatThanBianryNode : public BinaryNode {
public:
  GreatThanBianryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(std::string) const;
};

class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(std::string) const;
};

class PlusAsgBinaryNode : public BinaryNode {
public:
  PlusAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval(std::string) const;
};

class MinusAsgBinaryNode : public BinaryNode {
public:
  MinusAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval(std::string) const;
};

class MultAsgBinaryNode : public BinaryNode {
public:
  MultAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval(std::string) const;
};

class DivAsgBinaryNode : public BinaryNode {
public:
  DivAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval(std::string) const;
};

class ModAsgBinaryNode : public BinaryNode {
public:
  ModAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval(std::string) const;
};

class IdivAsgBinaryNode : public BinaryNode {
public:
  IdivAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval(std::string) const;
};

class PowAsgBinaryNode : public BinaryNode {
public:
  PowAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval(std::string) const;
};

class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(std::string) const;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(std::string) const;
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval(std::string) const;
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(std::string) const;
};

class ModBinaryNode : public BinaryNode {
public:
  ModBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(std::string) const;
};

class IdivBinaryNode : public BinaryNode {
public:
  IdivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(std::string) const;
};

class PowBinaryNode : public BinaryNode {
public:
  PowBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(std::string) const;
};

// class LShiftBinaryNode : public BinaryNode {
// public:
//   LShiftBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
//   virtual const Literal* eval(std::string) const;
// };
//
// class RShiftBinaryNode : public BinaryNode {
// public:
//   RShiftBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
//   virtual const Literal* eval(std::string) const;
// };
