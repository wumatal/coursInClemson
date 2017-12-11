#include "literal.h"
#include "fltLiteral.h"

class FloatLiteral: public Literal {
public:
  FloatLiteral(float _val): val(_val) {}

  virtual const Literal* operator+(const Literal& rhs) const;
  virtual const Literal* opPlus(float lhs) const;
  virtual const Literal* opPlus(int lhs) const;

  virtual const Literal* operator-(const Literal& rhs) const;
  virtual const Literal* opSubt(float lhs) const;
  virtual const Literal* opSubt(int lhs) const;

  virtual const Literal* operator*(const Literal& rhs) const;
  virtual const Literal* opMult(float lhs) const;
  virtual const Literal* opMult(int lhs) const;

  virtual const Literal* operator/(const Literal& rhs) const;
  virtual const Literal* opDiv(float lhs) const;
  virtual const Literal* opDiv(int lhs) const;

  virtual const Literal* operator%(const Literal& rhs) const;
  virtual const Literal* opMod(float lhs) const;
  virtual const Literal* opMod(int lhs) const;

  virtual const Literal* operatorIdiv(const Literal& rhs) const;
  virtual const Literal* opIdiv(float lhs) const;
  virtual const Literal* opIdiv(int lhs) const;

  virtual const Literal* operatorPow(const Literal& rhs) const;
  virtual const Literal* opPow(float lhs) const;
  virtual const Literal* opPow(int lhs) const;

  virtual const Literal* operator+() const;
  virtual const Literal* operator-() const;

  virtual const Literal* operator<(const Literal& rhs);
  virtual const Literal* opLt(float lhs) const;
  virtual const Literal* opLt(int lhs) const;

  virtual const Literal* operator<=(const Literal& rhs) const;
  virtual const Literal* opLe(float lhs) const;
  virtual const Literal* opLe(int lhs) const;

  virtual const Literal* operator==(const Literal& rhs) const;
  virtual const Literal* opEq(float lhs) const;
  virtual const Literal* opEq(int lhs) const;

  virtual const Literal* operator!=(const Literal& rhs) const;
  virtual const Literal* opNe(float lhs) const;
  virtual const Literal* opNe(int lhs) const;

  virtual const Literal* operator>=(const Literal& rhs) const;
  virtual const Literal* opGe(float lhs) const;
  virtual const Literal* opGe(int lhs) const;

  virtual const Literal* operator>(const Literal& rhs) const;
  virtual const Literal* opGt(float lhs) const;
  virtual const Literal* opGt(int lhs) const;

  virtual const Literal* operator<<(const Literal& rhs) const =0;
  virtual const Literal* opLsh(float) const =0;
  virtual const Literal* opLsh(int) const =0;

  virtual const Literal* operator>>(const Literal& rhs) const =0;
  virtual const Literal* opRsh(float) const =0;
  virtual const Literal* opRsh(int) const =0;

  virtual const Literal* eval() const { return this; }
  virtual void print() const {
    std::cout << "FLOAT: " << val << std::endl;
  }

  float getValue() const { return val;  }
private:
  float val;
};
