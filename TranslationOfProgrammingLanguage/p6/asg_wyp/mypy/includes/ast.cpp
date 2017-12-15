#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"



const Literal* IfNode::eval(std::string caller) const {
  int testFlag;
  const IntLiteral* testptr = dynamic_cast<const IntLiteral*>(test->eval(caller));
  if (testptr) {
    // std::cout << "Int Bool: " << ptr->getSymbol() << std::endl;
    testFlag = testptr->getValue();
  }
  else {
    // std::cout << "Float Bool: " << static_cast<const FloatLiteral*>(test->eval(caller))->getSymbol() << std::endl;
    const FloatLiteral* ftestptr = static_cast<const FloatLiteral*>(test->eval(caller));
    testFlag = static_cast<int>(ftestptr->getValue());
  }
  const Literal* res = NULL;


  if (testFlag) {
    const SuiteNode* stmts = static_cast<const SuiteNode*> (suite);
    res = stmts->eval(caller);
  }
  else if( elseSuite ){
    const SuiteNode* stmts = static_cast<const SuiteNode*> (elseSuite);
    res = stmts->eval(caller);
  }

  return res;
}

const Literal* FuncNode::eval(std::string creater) const {
  creater.size();
  TableManager::getInstance().insertFunction(ident, para, suite);
  return NULL;
}

const Literal* ActParaNode::eval(std::string caller) const {

  caller.size();
  return NULL;

}

const Literal* FmlParaNode::eval(std::string caller) const {
  // std::cout << "suite" << std::endl;
  caller.size();
  const Literal* result = NULL;
  return result;
}

const Literal* SuiteNode::eval(std::string caller) const {
  // std::cout << "suite" << std::endl;
  const Literal* result = NULL;
  for (const Node* node : stmts) {
    // if(!n)
    // throw std::string("SuiteNode is nullptr");
    if ( node ) {
      if (TableManager::getInstance().getReturned()) {
        break;
      }
      result = node->eval(caller);
      const ReturnNode* ptr = dynamic_cast<const ReturnNode*>(node);
      if (ptr) {
        TableManager::getInstance().setReturned(true);
        break;
      }
    }
  }
  return result;
}

const Literal* CallNode::eval(std::string caller) const {
  caller.size();
  TableManager& tm = TableManager::getInstance();
  // tm.display();
  const Literal* result = NULL;
  int startScope = tm.checkFuncName(ident);


  int currentScope = tm.getCurrentScope();
  // protect site
  if (startScope != -1) {

    std::vector<Node*> parameters;
    const FmlParaNode* para = static_cast<const FmlParaNode*>(tm.getPara(ident, startScope));
    // tm.display();
    if( ident != caller ) {
      tm.setCurrentScope(startScope);
      tm.pushScope();
      tm.protectStack(currentScope);
    }
    else{
      tm.pushScope();
    }
    const SuiteNode* stmts = static_cast<const SuiteNode*> (tm.getSuite(ident, startScope));
    // std::vector<std::map<std::string, const Literal*>> recvTables = tm.protectStack(currentScope);
    // tm.pushScope(ident);
    if( para ) {
      parameters = static_cast<const FmlParaNode*>(tm.getPara(ident, startScope))->getValue();

      std::vector<Node*> argVec;
      if ( acts == NULL ) throw std::string("Parameter Match Failed!");
      argVec = static_cast<const ActParaNode*>(acts)->getValue();
      std::vector<const Literal*> augVal;
      if ( argVec.size() != parameters.size() ) throw std::string("Parameter Match Failed!");
      for (unsigned int i = 0; i < parameters.size(); i++) {
        augVal.push_back(argVec[i]->eval(ident));
      }
      for (unsigned int i = 0; i < parameters.size(); i++) {
        const std::string n = static_cast<IdentNode*>(parameters[i])->getIdent();
        TableManager::getInstance().insertSymbol(n, augVal[i]);

      }
    }
    result = stmts->eval(ident);

    tm.setReturned(false);
    if( ident != caller ) {
      tm.restoreStack(currentScope);
      // tm.restoreStack(currentScope, recvTables);
      tm.popScope();
      tm.setCurrentScope(currentScope);
    }
    else{
      tm.popScope();
    }
  }
  return result;
}

const Literal* PrintNode::eval(std::string caller) const {
  const Literal* temp = NULL;
  if (node) {
    temp = node->eval(caller);
  }
  if (temp) {
    temp->print();
  }
  else {
    std::cout << "None" << std::endl;
  }
  return NULL;
}

const Literal* ReturnNode::eval(std::string caller) const {
  if (node == NULL) {
    // std::cout << " return null" << std::endl;
    return NULL;
  }
  else {
    return node->eval(caller);
  }
}


// Add logic node
const Literal* LessThanBianryNode::eval(std::string caller) const {
  if( !left || !right ) {
    throw std::string("\'<\' error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);
  const Literal* number = ( *x<*y );
  return number;
}

const Literal* LessEqualBianryNode::eval(std::string caller) const {
  if( !left || !right ) {
    throw std::string("\'<=\' error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);
  const Literal* number = ( *x<=*y );
  return number;
}

const Literal* NotEqualBianryNode::eval(std::string caller) const {
  if( !left || !right ) {
    throw std::string("\'!=\' error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);
  const Literal* number = ( *x!=*y );
  return number;
}

const Literal* EqualBianryNode::eval(std::string caller) const {
  if( !left || !right ) {
    throw std::string("\'==\' error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);
  const Literal* number = ( *x==*y );
  return number;
}

const Literal* GreatEqualBianryNode::eval(std::string caller) const {
  if( !left || !right ) {
    throw std::string("\'>=\' error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);
  const Literal* number = ( *x>=*y );
  return number;
}

const Literal* GreatThanBianryNode::eval(std::string caller) const {
  if( !left || !right ) {
    throw std::string("\'>\' error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);
  const Literal* number = ( *x>*y );
  return number;
}

const Literal* IdentNode::eval(std::string caller) const {
  caller.size();
  TableManager& tm = TableManager::getInstance();
  int scope = tm.getCurrentScope();
  // const Literal* val = NULL;
  // if( tm.checkSymbol(ident) ) {
  //    val = tm.getSymbol(ident);
  // }
  // return val;

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

const Literal* UnaryNode::eval(std::string caller) const {
  if (!num) {
    throw std::string("error");
  }
  const Literal* x = num->eval(caller);
  if( sngs == '-' ){
    return -(*x);
  }
  else
  return +(*x);
}

const Literal* AsgBinaryNode::eval(std::string caller) const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* res = right->eval(caller);

  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  // std::cout << "scope: "<< TableManager::getInstance() << "x=" << std::endl;
  TableManager::getInstance().insertSymbol(n, res);
  return res;
}


const Literal* AddBinaryNode::eval(std::string caller) const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);
  //return (*x+*y);
  return (*x).operator+(*y);
}

const Literal* SubBinaryNode::eval(std::string caller) const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval(std::string caller) const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval(std::string caller) const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);
  return ((*x)/(*y));
}

const Literal* ModBinaryNode::eval(std::string caller) const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);

  return ((*x)%(*y));
}

const Literal* IdivBinaryNode::eval(std::string caller) const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);
  return ((*x).operatorIdiv(*y));
}

const Literal* PowBinaryNode::eval(std::string caller) const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval(caller);
  const Literal* y = right->eval(caller);
  return ((*x).operatorPow(*y));
}
