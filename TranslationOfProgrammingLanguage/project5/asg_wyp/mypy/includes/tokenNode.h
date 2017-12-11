#pragma once

#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "tableManager.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char*);

class IfNode : public Node {
public:
  IfNode ( const Node* n, const Node* ts, const Node* es )
    : test(n), thenSuite(ts), elseSuite(es) {}
  virtual const Literal* eval() const;
protected:
  const Node* test;
  const Node* thenSuite;
  const Node* elseSuite;
};

class RetrunNode : public Node {
public:
  ReturnNode(const Node* n) : node(n) {}
private:
  const Node* node;
};

class CallNode : public Node {
public:
  // virtual ~CallNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
};

class FuncNode : public Node {
public:
  FuncNode ( const std::string id, Node* stmts );
  // virtual ~FuncNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
  Node* suite;
};

class SuiteNode : public Node {
public:
  SuiteNode ( const std::vector<Node*> s ) : Node(), stmts(s) {}
  // virtual ~SuiteNode() {}
  virtual const Literal* eval() const;
private:
  std::vector<Node*> stmts;
};
