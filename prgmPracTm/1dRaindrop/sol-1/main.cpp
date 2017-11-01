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
      std::cout << "pos" << pos << " : "<< std::endl;
      if( !bars.empty() )
        if ( bars.back().height >= n ) 
          drops += (pos - bars.back().pos - 1) * (bars.back().height - n);
      else {
        while( bars.back().height < n ){
          drops += (bars.back().height - height) * (pos - bars.back().pos -1);
          height = bars.back().height;
          bars.pop_back();
        }
      }
       
      b.height = n;
      b.pos = pos;
      bars.push_back(b);

      pos ++ ;
      // std::cout << " the bars : ";
      // for(std::vector<bar>::const_iterator i = bars.begin(); i != bars.end(); i++){
      //   std::cout << i->height << ' ';
      //   //std::cout << "(n: " << n << ") ";

      // }
      // std::cout << std::endl;
    }
    std::cout << drops << std: :endl;
  }
}
