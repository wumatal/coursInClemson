#include "tokenNode.h"

const Literal* PrintNode::eval() const {
  if( !node ) {
    std::cout << std::endl;
    return nullptr;
  }
  node->eval()->print();
  return nullptr;
}

const Literal* IfNode::eval() const {
  if( !test ) {
    return 0;
  }
  TableManager& tm = TableManager::getInstance();

  const Literal* lit = test->eval();
  lit = dynamic_cast<const Literal*>(lit);
  if ( !lit )
    throw std::string("Could not evaluate test in IfNode.");

  bool flag = lit->eval()->isTrue();
  if( flag ) {
    if( !thenSuite )
      throw std::string("thenSuite is null!");
    tm.pushScope();
    thenSuite->eval();
    if( tm.checkName("__RETURN__")) {
      const Literal* ret = tm.getEntry("__RETURN__");
      tm.popScope();
      tm.insertSymb("__RETURN__", ret);
    }
    else {
      tm.popScope();
    }
  }
  else if( !flag ){
    if( !elseSuite ) {
      return nullptr;
    }
    tm.pushScope();
    elseSuite->eval();
    if( tm.checkName("__RETURN__")) {
      const Literal* ret = tm.getEntry("__RETURN__");
      tm.popScope();
      tm.insertSymb("__RETURN__", ret);
    }
    else {
      tm.popScope();
    }
  }
  else {
    throw std::string ("Neither true nor false");
  }

  return nullptr;
}

const Literal* CallNode::eval() const {
  TableManager& tm = TableManager::getInstance();
  if( !tm.checkFunc(ident) ) {
    std::cout << "function" << ident << "NOT FOUND!" << std::endl;
    std::exeption up = std::exception();
    throw up;
  }

  tm.pushScope();
  tm.getSuite(ident)->eval();
  const Literal* res = TableManager::getInstance().getEntry("__RETURN__");
  tm.popScope();

  return res;
}

FuncNode::FuncNode( const std::string id, Node* stmts ) : Node(), ident(id), suite(stmts) {
  // TableManager::getInstance().insert( id, suite );
}

const Literal* FuncNode::eval() const {
  TableManager::getInstance().insertFunc( ident, suite );
  return nullptr;
}

const Literal* SuiteNode::eval() const {
  for(const Node* n : stmts) {
    if(!n)
      throw std::string("SuiteNode is nullptr");

    n->eval();
    if( TableManager::getInstance().checkName("__RETURN__") )
      break;
  }
  return nullptr;
}
