#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

struct bar{
  int height;
  int pos;
} b;

int main() {
  std::ifstream file("input.txt");
  std::string str;
  int n;
  int drops;
  int pos;
  int height;
  std::vector<bar> bars;

  while (std::getline(file, str)) {
    drops = 0;
    pos = 0;
    height = 0;
    if ( !bars.empty() ) {
      bars.clear();
    }
    std::stringstream stream(str);
    while(stream >> n){

      while( !bars.empty() ){
        if( bars.back().height <= n ){
          drops += (bars.back().height - height) * (pos - bars.back().pos -1);
          height = bars.back().height;
          bars.pop_back();
        }
        else {
          if ( pos - bars.back().pos > 1)
            drops += (pos - bars.back().pos - 1) * ( n - height);
          break;
        }
      }

      b.height = n;
      b.pos = pos;
      bars.push_back(b);

      pos ++ ;

    }
    std::cout << drops << std::endl;
  }
}
