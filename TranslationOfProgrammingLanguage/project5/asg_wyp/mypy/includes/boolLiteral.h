#include "intLiteral.h"

class BoolLiteral : public IntLiteral {
public:
  BoolLiteral(std::string boolval){
    if(!strcmp(boolval, "True"))
      val = 1;
    else if(!strcmp(boolval, "False"))
      val = 0;
    else
      throw std::string("Wrong boolean value");
  }
  virtual const Literal* eval() const { return this; }
  virtual void print() const {
    std::cout << "BOOL:" << (val ? "True" : "False") << std::endl;
  }
private:
  int val;
};
