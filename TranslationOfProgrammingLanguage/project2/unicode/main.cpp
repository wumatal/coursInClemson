#include <iostream>
#include <string>
#include <map>
#include <stack>

int main() {
  std::string letter = u8"\u0250";
  std::cout << "ch is: " << letter << std::endl;

  std::map<char, std::string> letters;
  letters['a'] = letter;
  std::cout << "ch is: " << letters['a'] << std::endl;

  std::stack<std::string> stk;
  stk.push("one");
  stk.push("two");
  std::cout << stk.top() << std::endl;
  stk.pop();
  std::cout << stk.top() << std::endl;
}
