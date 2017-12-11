#include "fltLiteral.h"
#include "intLiteral.h"
#include "boolLiteral.h"

const Literal* FloatLiteral::operator+(const Literal& rhs) const  {
  return rhs.opPlus(val);
}
const Literal* FloatLiteral::opPlus(float lhs) const  {
  const Literal* node = new FloatLiteral(lhs + val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const Literal* FloatLiteral::opPlus(int lhs) const  {
  const Literal* node = new FloatLiteral(lhs + val);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator-(const Literal& rhs) const  {
  return rhs.opSubt(val);
}
const Literal* FloatLiteral::opSubt(float lhs) const  {
  const Literal* node = new FloatLiteral(lhs - val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const Literal* FloatLiteral::opSubt(int lhs) const  {
  const Literal* node = new FloatLiteral(lhs - val);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator*(const Literal& rhs) const  {
  return rhs.opMult(val);
}
const Literal* FloatLiteral::opMult(float lhs) const  {
  const Literal* node = new FloatLiteral(lhs * val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const Literal* FloatLiteral::opMult(int lhs) const  {
  const Literal* node = new FloatLiteral(static_cast<float>(lhs) * val);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator/(const Literal& rhs) const  {
  return rhs.opDiv(val);
}
const Literal* FloatLiteral::opDiv(float lhs) const  {
  if ( val == 0 ) throw std::string("Zero Division Error");
  const Literal* node = new FloatLiteral(lhs / val);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const Literal* FloatLiteral::opDiv(int lhs) const  {
  if ( val == 0 ) throw std::string("Zero Division Error");
  const Literal* node = new FloatLiteral(lhs / val);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator%(const Literal& rhs) const  {
  return rhs.opMod(val);
}
const Literal* FloatLiteral::opMod(float lhs) const  {
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
const Literal* FloatLiteral::opMod(int lhs) const  {
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

const Literal* FloatLiteral::operatorIdiv(const Literal& rhs) const  {
  return rhs.opIdiv(val);
}
const Literal* FloatLiteral::opIdiv(float lhs) const  {
  if ( val == 0 ) throw std::string("Zero Division Error");
  const Literal* node = new FloatLiteral(std::floor(lhs / val));
  PoolOfNodes::getInstance().add(node);
  return node;
}
const Literal* FloatLiteral::opIdiv(int lhs) const  {
  if ( val == 0 ) throw std::string("Zero Division Error");
  const Literal* node = new FloatLiteral(std::floor(lhs / val));
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operatorPow(const Literal& rhs) const  {
  return rhs.opPow(val);
}
const Literal* FloatLiteral::opPow(float lhs) const  {
  const Literal* node = new FloatLiteral(std::pow(lhs, val));
  PoolOfNodes::getInstance().add(node);
  return node;
}
const Literal* FloatLiteral::opPow(int lhs) const  {
  const Literal* node = new FloatLiteral(std::pow(lhs, val));
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator+() const {
  const Literal* node = new FloatLiteral(val);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator-() const {
  const Literal* node = new FloatLiteral(-(val));
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator<(const Literal& rhs) const {
  return rhs.opLt(val);
}
const Literal* FloatLiteral::opLt(float lhs) const {
  const Literal* node = new BoolLiteral( val < lhs );
  PoolOfNodes::getInstance().add(node);
  return node;
}
const Literal* FloatLiteral::opLt(int lhs) const {
  const Literal* node = new BoolLiteral( val < lhs );
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator<=(const Literal& rhs) const {
  return rhs.opLe(val);
}
const Literal* FloatLiteral::opLe(float lhs) const {
  const Literal* node = new BoolLiteral( val <= lhs );
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::opLe(int lhs) const {
  const Literal* node = new BoolLiteral( val <= lhs );
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator==(const Literal& rhs) const {
  return rhs.opEq(val);
}
const Literal* FloatLiteral::opEq(float lhs) const {
  const Literal* node = new BoolLiteral( val == lhs );
  PoolOfNodes::getInstance().add(node);
  return node;
}
const Literal* FloatLiteral::opEq(int lhs) const {
  const Literal* node = new BoolLiteral( val == lhs );
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator!=(const Literal& rhs) const {
  return rhs.opNe(val);
}
const Literal* FloatLiteral::opNe(float lhs) const {
  const Literal* node = new BoolLiteral( val != lhs );
  PoolOfNodes::getInstance().add(node);
  return node;
}
const Literal* FloatLiteral::opNe(int lhs) const {
  const Literal* node = new BoolLiteral( val != lhs );!=
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator>=(const Literal& rhs) const {
  return rhs.opGe(val);
}
const Literal* FloatLiteral::opGe(float lhs) const {
  const Literal* node = new BoolLiteral( val >= lhs );
  PoolOfNodes::getInstance().add(node);
  return node;
}
const Literal* FloatLiteral::opGe(int lhs) const {
  const Literal* node = new BoolLiteral( val >= lhs );
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator>(const Literal& rhs) const {
  return rhs.opGt(val);
}
const Literal* FloatLiteral::opGt(float lhs) const {
  const Literal* node = new BoolLiteral( val > lhs );
  PoolOfNodes::getInstance().add(node);
  return node;
}
const Literal* FloatLiteral::opGt(int lhs) const {
  const Literal* node = new BoolLiteral( val > lhs );
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* operator<<(const Literal& rhs) const {
  return rhs.opLsh(val);
}
const Literal* opLsh(float lhs) const {
  std::cout << "TypeError: unsupported operand type(s) for <<: 'float' and 'float'" << std::endl;
  return nullptr;
}
const Literal* opLsh(int lhs) const {
  std::cout << "TypeError: unsupported operand type(s) for <<: 'int' and 'float'" << std::endl;
  return nullptr;
}

const Literal* operator>>(const Literal& rhs) const {
  return rhs.opRsh(val);
}
const Literal* opRsh(float lhs) const {
  std::cout << "TypeError: unsupported operand type(s) for <<: 'float' and 'float'" << std::endl;
  return nullptr;
}
const Literal* opRsh(int lhs) const {
  std::cout << "TypeError: unsupported operand type(s) for <<: 'int' and 'float'" << std::endl;
  return nullptr;
}
