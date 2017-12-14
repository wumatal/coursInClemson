#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "tableManager.h"
// #include "symbolTable.h"

const Literal* IdentNode::eval() const {
  TableManager& tm = TableManager::getInstance();
  // const Literal* val = SymbolTable::getInstance().getValue(ident);
  int scope = tm.getCurrentScope();

  while (tm.getCurrentScope() >= 0) {
    // std::cout << "search scope: " << tm.getCurrentScope() << std::endl;
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
      // scope--;
      else {
        tm.popScope();
      }
    }
  }
  // std::cout << "search scope: " << tm.getCurrentScope() << std::endl;
  // if (tm.checkSymbol(ident)) {
  //
  // }

  // if (tm.getCurrentScope() < 0) {
  //     }

  // const Literal* val = TableManager::getInstance().getSymbol(ident);
  return NULL;
}

const Literal* SuiteNode::eval() const {
  //std::cout << "-------SuiteNode-------" << std::endl;
  const Literal* result = NULL;
  for (const Node* n : stmts) {
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

const Literal* FuncNode::eval() const {
  //std::cout << "-------FuncNode::eval()---1----" << std::endl;
  // suite->eval();
  TableManager& tm = TableManager::getInstance();
  tm.insertFunction(ident, parameter, suite);
  // if (parameter) {
  //   std::cout << " parameter " << std::endl;
  //   tm.pushScope();
  //   parameter->eval();
  //   tm.popScope();
  // }
  //std::cout << "-------FuncNode::eval()----2---" << std::endl;
  return NULL;
}

const Literal* ParaNode::eval() const {
  // for (const Node* param : params) {
  //   if (param) {
  //     param->eval();
  //   }
  // }
  return NULL;

}

const Literal* CallNode::eval() const {
  //std::cout << "-------CallNode::eval()---1----" << std::endl;
  TableManager& tm = TableManager::getInstance();
  const Literal* result = NULL;
  // tm.setReturned(false);
  // std::cout << tm.checkFuncName(ident) << std::endl;
  if (tm.checkFuncName(ident)) {
    // std::cout << "-------CallNode::eval()---2----" << std::endl;
    // std::cout << "currentScope: " << tm.getCurrentScope() << std::endl
    std::vector<Node*> paramVec;
    const SuiteNode *st = static_cast<const SuiteNode*> (tm.getSuite(ident));
    if ( tm.getParam(ident) ) {
      paramVec = static_cast<const ParaNode*>(tm.getParam(ident))->getValue();
      std::vector<Node*> argVec;
      if (argNode ) {
        argVec = static_cast<const ArgNode*>(argNode)->getValue();
      }
      // std::cout << "-------CallNode::eval()---3----" << std::endl;

      std::vector<const Literal*> augVal;
      for (unsigned int i = 0; i < paramVec.size(); i++) {
        augVal.push_back(argVec[i]->eval());
      }

      tm.pushScope(ident);
      for (unsigned int i = 0; i < paramVec.size(); i++) {
        const std::string n = static_cast<IdentNode*>(paramVec[i])->getIdent();
        TableManager::getInstance().insertSymbol(n, augVal[i]);
        // std::cout <<"x: " << n  << ", res:"  << std::endl;
        // res->eval()->print();
      }

    }
    result = st->eval();
    tm.setReturned(false);

    tm.popScope();
  }//if
  return result;
}

const Literal* ArgNode::eval() const {
  return NULL;
}

const Literal* PrintNode::eval() const {
  const Literal* temp = NULL;
  if (node) {
    temp = node->eval();
  }
  // std::cout << "print" << std::endl;
  if (temp) {
    temp->print();
    // std::cout << "CCCCCurrentScope: " << TableManager::getInstance().getCurrentScope() << std::endl;
    // std::cout << "print11" << std::endl;
    // node->eval()->print();
  }
  else {
    std::cout << "None" << std::endl;
  }
  return NULL;
}

const Literal* IfNode::eval() const {
  // std::cout << "Bool: " << static_cast<const IntLiteral*>(test->eval())->getValue() << std::endl;
  int testFlag;
  const IntLiteral* ptr = dynamic_cast<const IntLiteral*>(test->eval());
  if (ptr) {
    // std::cout << "Int Bool: " << ptr->getValue() << std::endl;
    testFlag = ptr->getValue();
  }
  else {
    // std::cout << "Float Bool: " << static_cast<const FloatLiteral*>(test->eval())->getValue() << std::endl;
    const FloatLiteral* fptr = static_cast<const FloatLiteral*>(test->eval());
    testFlag = static_cast<int>(fptr->getValue());
  }
  const Literal* res = nullptr;


  if (testFlag) {
    res = suite->eval();
  }
  else {
    res = elseSuite->eval();
  }

  return res;
  // static_cast<const IntLiteral*>($2->eval())->print() ;
  //
  // if ((static_cast<const IntLiteral*>($2->eval()))->getValue() == 0) {
  //   std::cout << (static_cast<const IntLiteral*>($2->eval()))->getValue() << std::endl;
  // }
}

const Literal* ReturnNode::eval() const {
  // std::cout << "ReturnNode::eval() ReturnNode::eval() ReturnNode::eval()" << std::endl;
  if (result == NULL) {
    // std::cout << " return null" << std::endl;
    return NULL;
  }
  else {
    return result->eval();
  }
}

const Literal* MinusUnaryNode::eval() const {
  if (!right) {
    throw std::string("error");
  }
  const Literal* x = right->eval();
  const Literal* zero = new IntLiteral(0);
  return *zero-(*x);
}

const Literal* TildeUnaryNode::eval() const {
  if (!right) {
    throw std::string("error");
  }
  const Literal* x = right->eval();
  const Literal* minusOne = new IntLiteral(-1);
  return *minusOne-(*x);
}

AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  // const Literal* res = right->eval();
  // const std::string n = static_cast<IdentNode*>(left)->getIdent();
  // SymbolTable::getInstance().setValue(n, res);
  // TableManager::getInstance().insertSymbol(n, res);
}

const Literal* AsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* res = right->eval();

  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  // SymbolTable::getInstance().setValue(n, res);
// std::cout << n << std::endl;
  TableManager::getInstance().insertSymbol(n, res);
  // std::cout << "eyes1" << std::endl;
  return res;
}

const Literal* AddBinaryNode::eval() const {
  // std::cout << "printadd" << std::endl;
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x+*y);
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

const Literal* FlrDivBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return x->floorDivide(*y);
}

const Literal* PowBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return x->pow(*y);
}

const Literal* LShiftBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)<<(*y);
}

const Literal* RShiftBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)>>(*y);
}

const Literal* EqEqualBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)==(*y);
}

const Literal* LessBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)<(*y);
}

const Literal* GreaterBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)>(*y);
}

const Literal* LessEqualBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)<=(*y);
}

const Literal* GreaterEqualBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)>=(*y);
}

const Literal* NotEqualBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)!=(*y);
}
