#include <iostream>
#include <cstring>

class string {
public:
  // string(){
  //   std::cout << "default" << '\n';
  // }
  // string(const char* c){
  //   std::cout << "convert" << '\n';
  // }
  // string(const string& ) {
  //   std::cout << "copy" << '\n';
  //
  // }
  // string& operator=(const string& rhs) {
  //   std::cout << "assign" << '\n';
  //   return * this;
  // }
  // ~string() {
  //   std::cout << "destructor" << '\n';
  //
  // }
  // string() : buf(new char[1]) {
  //   buf[0] = '\0';
  //   std::cout << "default" << '\n';
  // }
  string(const char* c) : buf(new char[strlen(c) + 1 ]){
    std::cout << "convert" << '\n';
    strcpy(buf, c);
  }
  // string(const string& s) : buf(new char[strlen(s.buf) + 1 ]){
  //   std::cout << "copy" << '\n';
  //   strcpy(buf, s.buf);
  // }
  // string& operator=(const string& rhs) {
  //   std::cout << "assign" << '\n';
  //   if( this == &rhs) return *this;
  //   delete [] buf;
  //   buf = new char[strlen(rhs.buf) + 1];
  //   strcpy(buf, rhs.buf);
  //   return * this;
  // }
  ~string() {
    std::cout << "destructor" << '\n';
    delete [] buf;
  }
  const char* getBuf() const {
    return buf;
  }
  std::ostream& operator<<( std::ostream& out ) {
    return out << buf;
  }
private:
  char* buf;
  string& operator=(const string&);
  string(const string&);
};

// std::ostream& operator<<( std::ostream& out, const string& s ) {
//   return out << s.getBuf();
// }

int main() {
  string a("cat");
  a << std::cout << std::endl;
  // string* rope = new string("twisted");
  // std::cout << a << '\n';
  // delete rope;
  return 0;
}

// void incrCount( int count ){
//   ++count;
// }
//
// void makeSwitch( int& count ) {
//   switch ( count ) {
//     case 3  : ++count;
//     case 4  : ++count;
//     case 5  : ++count;
//     case 6  : ++count;
//     default : ++count;
//   }
// }
// int main() {
//   int count = 2;
//   incrCount( count );
//   std::cout << count << '\n';
//
//   count = 2;
//   count = ( count % 2 ) ? 2 : 3;
//   makeSwitch( count );
//   std::cout << count << '\n';
//
//   return 0;
// }
