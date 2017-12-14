#include "literal.h"
#include "fltLiteral.h"

class IntLiteral: public Literal {
public:
  IntLiteral(int _val): val(_val) {}
  virtual const Literal* operator+(const Literal& rhs) const;
  virtual const Literal* opPlus(float) const;
  virtual const Literal* opPlus(int lhs) const;

  virtual const Literal* operator*(const Literal& rhs) const;
  virtual const Literal* opMult(float) const;
  virtual const Literal* opMult(int lhs) const;

  virtual const Literal* operator-(const Literal& rhs) const;
  virtual const Literal* opSubt(float) const;
  virtual const Literal* opSubt(int lhs) const;

  virtual const Literal* operator/(const Literal& rhs) const;
  virtual const Literal* opDiv(float) const;
  virtual const Literal* opDiv(int lhs) const;

  virtual const Literal* operator%(const Literal& rhs) const;
  virtual const Literal* opMod(float) const;
  virtual const Literal* opMod(int lhs) const;

  virtual const Literal* operatorIdiv(const Literal& rhs) const;
  virtual const Literal* opIdiv(float) const;
  virtual const Literal* opIdiv(int lhs) const;

  virtual const Literal* operatorPow(const Literal& rhs) const;
  virtual const Literal* opPow(float) const;
  virtual const Literal* opPow(int lhs) const;

  virtual const Literal* operator+() const;
  virtual const Literal* operator-() const;

  // Add logical operator
  virtual const Literal* operator<(const Literal& rhs) const;
  virtual const Literal* opLt(float) const;
  virtual const Literal* opLt(int) const;

  virtual const Literal* operator<=(const Literal& rhs) const;
  virtual const Literal* opLe(float) const;
  virtual const Literal* opLe(int lhs) const;

  virtual const Literal* operator==(const Literal& rhs) const;
  virtual const Literal* opEq(float) const;
  virtual const Literal* opEq(int lhs) const;

  virtual const Literal* operator!=(const Literal& rhs) const;
  virtual const Literal* opNe(float) const;
  virtual const Literal* opNe(int lhs) const;

  virtual const Literal* operator>=(const Literal& rhs) const;
  virtual const Literal* opGe(float) const;
  virtual const Literal* opGe(int lhs) const;

  virtual const Literal* operator>(const Literal& rhs) const;
  virtual const Literal* opGt(float) const;
  virtual const Literal* opGt(int lhs) const;

  virtual const Literal* operator<<(const Literal& rhs) const =0;
  virtual const Literal* opLsh(float) const =0;
  virtual const Literal* opLsh(int) const =0;

  virtual const Literal* operator>>(const Literal& rhs) const =0;
  virtual const Literal* opRsh(float) const =0;
  virtual const Literal* opRsh(int) const =0;

  virtual const Literal* eval() const { return this; }
  virtual void print() const {
    std::cout << "INT:" << val << std::endl;
  }
  int getValue() const { return val; }
private:
  int val;
};
