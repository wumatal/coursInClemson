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
  if (testFlag) {
    suite->eval();
  }
  else {
    elseSuite->eval();
  }


  return NULL;
}

const Literal* FuncNode::eval() const {
  TableManager::getInstance().insertFunction(ident, suite);
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
  // for (const Node* n : fmls) {
  //   // if(!n)
  //   // throw std::string("SuiteNode is nullptr");
  //   if (n) {
  //     if (TableManager::getInstance().getReturned()) {
  //       break;
  //     }
  //     result = n->eval();
  //     const ReturnNode* ptr = dynamic_cast<const ReturnNode*>(n);
  //     if (ptr) {
  //       TableManager::getInstance().setReturned(true);
  //       break;
  //     }
  //   }
  // }
  return result;
}

const Literal* SuiteNode::eval() const {
  // std::cout << "suite" << std::endl;
  const Literal* result = NULL;
  for (const Node* n : stmts) {
    // if(!n)
    // throw std::string("SuiteNode is nullptr");
    if (n) {
      if (TableManager::getInstance().getReturned()) {
        break;
      }
      result = n->eval();
      const ReturnNode* ptr = dynamic_cast<const ReturnNode*>(n);
      if (ptr) {
        TableManager::getInstance().setReturned(true);
        break;
      }
    }
  }
  return result;
}

const Literal* CallNode::eval() const {
  // std::cout << ident << std::endl;
  TableManager& tm = TableManager::getInstance();
  // std::cout << tm.checkFuncName(ident) << std::endl;
  // std::cout << ident << std::endl;
  // tm.display();
  const Literal* result = NULL;
  int startScope = tm.checkFuncName(ident);
  // int temp = tm.getCurrentScope();
  // std::cout << "startScope" << startScope << std::endl;
  if (startScope != -1) {
    tm.pushScope();
    // std::cout << ident << " "<< startScope <<":" << std::endl;
    result = tm.getSuite(ident, startScope)->eval();
    tm.setReturned(false);
    // const Literal* returnLit = tm.getSymbol("__RETURN__");
    tm.popScope();
  }
  return result;
}

const Literal* PrintNode::eval() const {
  const Literal* temp = node->eval();
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
