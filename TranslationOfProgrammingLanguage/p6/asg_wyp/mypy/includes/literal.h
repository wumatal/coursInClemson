#include <cmath>
#include "node.h"
#include "poolOfNodes.h"

const int _ADD   = 1;
const int _MINUS = 2;
const int _MULT  = 3;
const int _DIV   = 4;
const int _MOD   = 5;
const int _IDIV  = 6;
const int _POW   = 7;

class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual const Literal* operator+(const Literal& rhs) const = 0;
  virtual const Literal* opPlus(float) const = 0;
  virtual const Literal* opPlus(int lhs) const = 0;

  virtual const Literal* operator*(const Literal& rhs) const = 0;
  virtual const Literal* opMult(float) const = 0;
  virtual const Literal* opMult(int lhs) const = 0;

  virtual const Literal* operator-(const Literal& rhs) const = 0;
  virtual const Literal* opSubt(float) const = 0;
  virtual const Literal* opSubt(int lhs) const = 0;

  virtual const Literal* operator/(const Literal& rhs) const = 0;
  virtual const Literal* opDiv(float) const = 0;
  virtual const Literal* opDiv(int lhs) const = 0;

  virtual const Literal* operator%(const Literal& rhs) const = 0;
  virtual const Literal* opMod(float) const = 0;
  virtual const Literal* opMod(int lhs) const = 0;

  virtual const Literal* operatorIdiv(const Literal& rhs) const = 0;
  virtual const Literal* opIdiv(float) const = 0;
  virtual const Literal* opIdiv(int lhs) const = 0;

  virtual const Literal* operatorPow(const Literal& rhs) const = 0;
  virtual const Literal* opPow(float) const = 0;
  virtual const Literal* opPow(int lhs) const = 0;

  virtual const Literal* operator+() const = 0;
  virtual const Literal* operator-() const = 0;

  // Add logical operator
  virtual const Literal* operator<(const Literal& rhs) const = 0;
  virtual const Literal* opLt(float) const = 0;
  virtual const Literal* opLt(int) const = 0;

  virtual const Literal* operator<=(const Literal& rhs) const = 0;
  virtual const Literal* opLe(float) const = 0;
  virtual const Literal* opLe(int lhs) const = 0;

  virtual const Literal* operator==(const Literal& rhs) const = 0;
  virtual const Literal* opEq(float) const = 0;
  virtual const Literal* opEq(int lhs) const = 0;

  virtual const Literal* operator!=(const Literal& rhs) const = 0;
  virtual const Literal* opNe(float) const = 0;
  virtual const Literal* opNe(int lhs) const = 0;

  virtual const Literal* operator>=(const Literal& rhs) const = 0;
  virtual const Literal* opGe(float) const = 0;
  virtual const Literal* opGe(int lhs) const = 0;

  virtual const Literal* operator>(const Literal& rhs) const = 0;
  virtual const Literal* opGt(float) const = 0;
  virtual const Literal* opGt(int lhs) const = 0;

  // Add shift if time permits.
  // virtual const Literal* operator<<(const Literal& rhs) const =0;
  // virtual const Literal* opLsh(float) const =0;
  // virtual const Literal* opLsh(int) const =0;
  //
  // virtual const Literal* operator>>(const Literal& rhs) const =0;
  // virtual const Literal* opRsh(float) const =0;
  // virtual const Literal* opRsh(int) const =0;

  virtual const Literal* eval(std::string) const = 0;
  virtual void print() const {
    std::cout << "No Way" << std::endl;
  }
};

class FloatLiteral: public Literal {
public:
  FloatLiteral(float _val): val(_val) {}

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(lhs) * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opMod(val);
  }
  virtual const Literal* opMod(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node;
    float res = std::fmod(lhs, val);
    if( ( val < 0 && res > 0 ) || ( val > 0 && res < 0 ) )
      node = new FloatLiteral( val + res);
    else
      node = new FloatLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node;
    float res = std::fmod(lhs, val);
    if( ( val < 0 && res > 0 ) || ( val > 0 && res < 0 ) )
      node = new FloatLiteral( val + res);
    else
      node = new FloatLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operatorIdiv(const Literal& rhs) const  {
    return rhs.opIdiv(val);
  }
  virtual const Literal* opIdiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(std::floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opIdiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(std::floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operatorPow(const Literal& rhs) const  {
    return rhs.opPow(val);
  }
  virtual const Literal* opPow(float lhs) const  {
    const Literal* node = new FloatLiteral(std::pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPow(int lhs) const  {
    const Literal* node = new FloatLiteral(std::pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator+() const {
    const Literal* node = new FloatLiteral(val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-() const {
    const Literal* node = new FloatLiteral(-(val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator<(const Literal& rhs) const {
    return rhs.opLt(val);
  }
  virtual const Literal* opLt(float lhs) const {
    const Literal* node = new FloatLiteral( val > lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opLt(int lhs) const {
    const Literal* node = new FloatLiteral( val > lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator<=(const Literal& rhs) const {
    return rhs.opLe(val);
  }
  virtual const Literal* opLe(float lhs) const {
    const Literal* node = new FloatLiteral( val >= lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* opLe(int lhs) const {
    const Literal* node = new FloatLiteral( val >= lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator==(const Literal& rhs) const {
    return rhs.opEq(val);
  }
  virtual const Literal* opEq(float lhs) const {
    const Literal* node = new FloatLiteral( val == lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opEq(int lhs) const {
    const Literal* node = new FloatLiteral( val == lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator!=(const Literal& rhs) const {
    return rhs.opNe(val);
  }
  virtual const Literal* opNe(float lhs) const {
    const Literal* node = new FloatLiteral( val != lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opNe(int lhs) const {
    const Literal* node = new FloatLiteral( val != lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator>=(const Literal& rhs) const {
    return rhs.opGe(val);
  }
  virtual const Literal* opGe(float lhs) const {
    const Literal* node = new FloatLiteral( val <= lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opGe(int lhs) const {
    const Literal* node = new FloatLiteral( val <= lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator>(const Literal& rhs) const {
    return rhs.opGt(val);
  }
  virtual const Literal* opGt(float lhs) const {
    const Literal* node = new FloatLiteral( val < lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opGt(int lhs) const {
    const Literal* node = new FloatLiteral( val < lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  // virtual const Literal* operator<<(const Literal& rhs) const {
  //   return rhs.opLsh(val);
  // }
  // virtual const Literal* opLsh(float lhs) const {
  //   std::cout << "TypeError: unsupported operand type(s) for <<: 'float' and 'float'" << std::endl;
  //   return nullptr;
  // }
  // virtual const Literal* opLsh(int lhs) const {
  //   std::cout << "TypeError: unsupported operand type(s) for <<: 'int' and 'float'" << std::endl;
  //   return nullptr;
  // }
  //
  // virtual const Literal* operator>>(const Literal& rhs) const {
  //   return rhs.opRsh(val);
  // }
  // virtual const Literal* opRsh(float lhs) const {
  //   std::cout << "TypeError: unsupported operand type(s) for <<: 'float' and 'float'" << std::endl;
  //   return nullptr;
  // }
  // virtual const Literal* opRsh(int lhs) const {
  //   std::cout << "TypeError: unsupported operand type(s) for <<: 'int' and 'float'" << std::endl;
  //   return nullptr;
  // }

  virtual const Literal* eval(std::string caller) const { caller.size();return this; }
  virtual void print() const {
    std::cout << "FLOAT: " << val << std::endl;
  }

  float getValue() const { return val;  }
private:
  float val;
};

class IntLiteral: public Literal {
public:
  IntLiteral(int _val): val(_val) {}
  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(val) + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new IntLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new IntLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new IntLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new IntLiteral(std::floor((float)lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opMod(val);
  }
  virtual const Literal* opMod(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node;
    float res = std::fmod(lhs, val);
    if( ( val < 0 && res > 0 ) || ( val > 0 && res < 0 ) )
      node = new FloatLiteral( val + res);
    else
      node = new FloatLiteral(res);
    // const Literal* node = new FloatLiteral(std::fmod(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node;
    int res = lhs % val;
    if( ( val < 0 && res > 0 ) || ( val > 0 && res < 0 ) )
      node = new IntLiteral( val + res);
    else
      node = new IntLiteral(res);
    // const Literal* node = new IntLiteral(lhs % val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operatorIdiv(const Literal& rhs) const  {
    return rhs.opIdiv(val);
  }
  virtual const Literal* opIdiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(std::floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opIdiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new IntLiteral(std::floor((float)lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operatorPow(const Literal& rhs) const  {
    return rhs.opPow(val);
  }
  virtual const Literal* opPow(float lhs) const  {
    const Literal* node = new FloatLiteral(std::pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPow(int lhs) const  {
    const Literal* node = new IntLiteral(std::pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator+() const {
    const Literal* node = new IntLiteral(val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-() const {
    const Literal* node = new IntLiteral(-(val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator<(const Literal& rhs) const {
    return rhs.opLt(val);
  }
  virtual const Literal* opLt(float lhs) const {
    const Literal* node = new IntLiteral( val > lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opLt(int lhs) const {
    const Literal* node = new IntLiteral( val > lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator<=(const Literal& rhs) const {
    return rhs.opLe(val);
  }
  virtual const Literal* opLe(float lhs) const {
    const Literal* node = new IntLiteral( val >= lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* opLe(int lhs) const {
    const Literal* node = new IntLiteral( val >= lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator==(const Literal& rhs) const {
    return rhs.opEq(val);
  }
  virtual const Literal* opEq(float lhs) const {
    const Literal* node = new IntLiteral( val == lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opEq(int lhs) const {
    const Literal* node = new IntLiteral( val == lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator!=(const Literal& rhs) const {
    return rhs.opNe(val);
  }
  virtual const Literal* opNe(float lhs) const {
    const Literal* node = new IntLiteral( val != lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opNe(int lhs) const {
    const Literal* node = new IntLiteral( val != lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator>=(const Literal& rhs) const {
    return rhs.opGe(val);
  }
  virtual const Literal* opGe(float lhs) const {
    const Literal* node = new IntLiteral( val <= lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opGe(int lhs) const {
    const Literal* node = new IntLiteral( val <= lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator>(const Literal& rhs) const {
    return rhs.opGt(val);
  }
  virtual const Literal* opGt(float lhs) const {
    const Literal* node = new IntLiteral( val < lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opGt(int lhs) const {
    const Literal* node = new IntLiteral( val < lhs );
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  // const Literal* operator<<(const Literal& rhs) const {
  //   // return rhs.opLsh(val);
  //   const Literal* node = new IntLiteral(val * std::pow(2, rhs->getValue()));
  //   PoolOfNodes::getInstance().add(node);
  //   return node;
  // }
  // virtual const Literal* opLsh(float lhs) const {
  //   std::cout << "TypeError: unsupported operand type(s) for <<: 'float' and 'float'" << std::endl;
  //   return nullptr;
  // }
  // const Literal* opLsh(int lhs) const {
  // }

  // virtual const Literal* operator>>(const Literal& rhs) const {
  //   // return rhs.opRsh(val);
  //   const Literal* node = new IntLiteral(val / std::pow(2, rhs->getValue()));
  //   PoolOfNodes::getInstance().add(node);
  //   return node;
  // }
  // virtual const Literal* opRsh(float lhs) const {
  //   std::cout << "TypeError: unsupported operand type(s) for <<: 'float' and 'float'" << std::endl;
  //   return nullptr;
  // }
  // const Literal* opRsh(int lhs) const {
  // }


  virtual const Literal* eval(std::string caller) const { caller.size();return this; }
  virtual void print() const {
    std::cout << "INT: " << val << std::endl;
  }
  int getValue() const { return val; }
private:
  int val;
};
