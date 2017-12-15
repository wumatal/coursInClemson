#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"



const Literal* IfNode::eval() const {
  int testFlag;
  const IntLiteral* testptr = dynamic_cast<const IntLiteral*>(test->eval());
  if (testptr) {
    // std::cout << "Int Bool: " << ptr->getSymbol() << std::endl;
    testFlag = testptr->getValue();
  }
  else {
    // std::cout << "Float Bool: " << static_cast<const FloatLiteral*>(test->eval())->getSymbol() << std::endl;
    const FloatLiteral* ftestptr = static_cast<const FloatLiteral*>(test->eval());
    testFlag = static_cast<int>(ftestptr->getValue());
  }
  const Literal* res = NULL;


  if (testFlag) {
    const SuiteNode* stmts = static_cast<const SuiteNode*> (suite);
    res = stmts->eval();
  }
  else if( elseSuite ){
    const SuiteNode* stmts = static_cast<const SuiteNode*> (elseSuite);
    res = stmts->eval();
  }

  return res;
}

const Literal* FuncNode::eval() const {
  TableManager::getInstance().insertFunction(ident, para, suite);
  return NULL;
}

const Literal* ActParaNode::eval() const {
  // TableManager::getInstance().insertSymbol(ident, suite);
  const Literal* result = NULL;
  return result;
}

const Literal* FmlParaNode::eval() const {
  // std::cout << "suite" << std::endl;
  const Literal* result = NULL;

  return result;
}

const Literal* SuiteNode::eval() const {
  // std::cout << "suite" << std::endl;
  const Literal* result = NULL;
  for (const Node* node : stmts) {
    // if(!n)
    // throw std::string("SuiteNode is nullptr");
    if ( node ) {
      if (TableManager::getInstance().getReturned()) {
        break;
      }
      result = node->eval();
      const ReturnNode* ptr = dynamic_cast<const ReturnNode*>(node);
      if (ptr) {
        TableManager::getInstance().setReturned(true);
        break;
      }
    }
  }
  return result;
}

const Literal* CallNode::eval() const {
  TableManager& tm = TableManager::getInstance();
  // tm.display();
  const Literal* result = NULL;
  int startScope = tm.checkFuncName(ident);
  int currentScope = tm.getCurrentScope();
  // protect site
  if (startScope != -1) {
    std::vector<Node*> parameters;
    // tm.display();
    tm.setCurrentScope(startScope);
    tm.pushScope();
    const SuiteNode* stmts = static_cast<const SuiteNode*> (tm.getSuite(ident, startScope));
    tm.protectStack(currentScope);
    // std::vector<std::map<std::string, const Literal*>> recvTables = tm.protectStack(currentScope);
    // tm.pushScope(ident);
    if( tm.getPara( ident, startScope ) ) {

      parameters = static_cast<const FmlParaNode*>(tm.getPara(ident, startScope))->getValue();
      std::vector<Node*> argVec;
      if (acts ) {
        argVec = static_cast<const ActParaNode*>(acts)->getValue();
      }
      std::vector<const Literal*> augVal;
      if ( argVec.size() != parameters.size() ) throw std::string("Parameter Match Failed!");
      for (unsigned int i = 0; i < parameters.size(); i++) {
        augVal.push_back(argVec[i]->eval());
      }
      for (unsigned int i = 0; i < parameters.size(); i++) {
        const std::string n = static_cast<IdentNode*>(parameters[i])->getIdent();
        TableManager::getInstance().insertSymbol(n, augVal[i]);

      }
    }
    result = stmts->eval();

    tm.setReturned(false);
    tm.restoreStack(currentScope);
    // tm.restoreStack(currentScope, recvTables);
    tm.popScope();
    tm.setCurrentScope(currentScope);
  }
  return result;
}

const Literal* PrintNode::eval() const {
  const Literal* temp = NULL;
  if (node) {
    temp = node->eval();
  }
  if (temp) {
    temp->print();
  }
  else {
    std::cout << "None" << std::endl;
  }
  return NULL;
}

const Literal* ReturnNode::eval() const {
  if (node == NULL) {
    // std::cout << " return null" << std::endl;
    return NULL;
  }
  else {
    return node->eval();
  }
}

// PlusAsgBinaryNode::PlusAsgBinaryNode(Node* left, Node* right) :
//   BinaryNode(left, right) {
//   const Literal* res = right->eval();
//   const std::string n = static_cast<IdentNode*>(left)->getIdent();
//   TableManager::getInstance().insert(n, res, _ADD);
// }
//
// MinusAsgBinaryNode::MinusAsgBinaryNode(Node* left, Node* right) :
//   BinaryNode(left, right) {
//   const Literal* res = right->eval();
//   const std::string n = static_cast<IdentNode*>(left)->getIdent();
//   TableManager::getInstance().insert(n, res, _MINUS);
// }
//
// MultAsgBinaryNode::MultAsgBinaryNode(Node* left, Node* right) :
//   BinaryNode(left, right) {
//   const Literal* res = right->eval();
//   const std::string n = static_cast<IdentNode*>(left)->getIdent();
//   TableManager::getInstance().insert(n, res, _MULT);
// }
//
// DivAsgBinaryNode::DivAsgBinaryNode(Node* left, Node* right) :
//   BinaryNode(left, right) {
//   const Literal* res = right->eval();
//   const std::string n = static_cast<IdentNode*>(left)->getIdent();
//   TableManager::getInstance().insert(n, res, _DIV);
// }
//
// ModAsgBinaryNode::ModAsgBinaryNode(Node* left, Node* right) :
//   BinaryNode(left, right) {
//   const Literal* res = right->eval();
//   const std::string n = static_cast<IdentNode*>(left)->getIdent();
//   TableManager::getInstance().insert(n, res, _MOD);
// }
//
// IdivAsgBinaryNode::IdivAsgBinaryNode(Node* left, Node* right) :
//   BinaryNode(left, right) {
//   const Literal* res = right->eval();
//   const std::string n = static_cast<IdentNode*>(left)->getIdent();
//   TableManager::getInstance().insert(n, res, _IDIV);
// }
//
// PowAsgBinaryNode::PowAsgBinaryNode(Node* left, Node* right) :
//   BinaryNode(left, right) {
//   const Literal* res = right->eval();
//   const std::string n = static_cast<IdentNode*>(left)->getIdent();
//   TableManager::getInstance().insert(n, res, _POW);
// }

// Add logic node
const Literal* LessThanBianryNode::eval() const {
  if( !left || !right ) {
    throw std::string("\'<\' error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* number = ( *x<*y );
  return number;
}

const Literal* LessEqualBianryNode::eval() const {
  if( !left || !right ) {
    throw std::string("\'<=\' error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* number = ( *x<=*y );
  return number;
}

const Literal* NotEqualBianryNode::eval() const {
  if( !left || !right ) {
    throw std::string("\'!=\' error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* number = ( *x!=*y );
  return number;
}

const Literal* EqualBianryNode::eval() const {
  if( !left || !right ) {
    throw std::string("\'==\' error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* number = ( *x==*y );
  return number;
}

const Literal* GreatEqualBianryNode::eval() const {
  if( !left || !right ) {
    throw std::string("\'>=\' error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* number = ( *x>=*y );
  return number;
}

const Literal* GreatThanBianryNode::eval() const {
  if( !left || !right ) {
    throw std::string("\'>\' error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* number = ( *x>*y );
  return number;
}

const Literal* IdentNode::eval() const {
  TableManager& tm = TableManager::getInstance();
  int scope = tm.getCurrentScope();

  while (tm.getCurrentScope() >= 0) {
    // std::cout << "scope: " << tm.getCurrentScope() << std::endl;
    if (tm.checkSymbol(ident)) {
      const Literal* val = tm.getSymbol(ident);
      tm.setCurrentScope(scope);
      return val;
    }
    else {
      if (tm.getCurrentScope() == 0) {
        tm.setCurrentScope(scope);
        std::cout << "NameError: name '" << ident << "' is not defined" << std::endl;
        return NULL;
      }
      else {
        tm.popScope();
      }
    }
  }
  return NULL;
}

const Literal* UnaryNode::eval() const {
  if (!num) {
    throw std::string("error");
  }
  const Literal* x = num->eval();
  if( sngs == '-' ){
    return -(*x);
  }
  else
  return +(*x);
}

const Literal* AsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* res = right->eval();

  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  // std::cout << "scope: "<< TableManager::getInstance() << "x=" << std::endl;
  TableManager::getInstance().insertSymbol(n, res);
  return res;
}

const Literal* PlusAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }

  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = TableManager::getInstance().getSymbol(n);
  return res;
}

const Literal* MinusAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = TableManager::getInstance().getSymbol(n);
  return res;
}

const Literal* MultAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = TableManager::getInstance().getSymbol(n);
  return res;
}

const Literal* DivAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = TableManager::getInstance().getSymbol(n);
  return res;
}

const Literal* ModAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = TableManager::getInstance().getSymbol(n);
  return res;
}

const Literal* IdivAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = TableManager::getInstance().getSymbol(n);
  return res;
}

const Literal* PowAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal* res = TableManager::getInstance().getSymbol(n);
  return res;
}

const Literal* AddBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  //return (*x+*y);
  return (*x).operator+(*y);
}

const Literal* SubBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)/(*y));
}

const Literal* ModBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();

  return ((*x)%(*y));
}

const Literal* IdivBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).operatorIdiv(*y));
}

const Literal* PowBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).operatorPow(*y));
}
