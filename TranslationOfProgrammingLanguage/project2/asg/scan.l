%{
// Flex handles ambiguity by matching longest string;
// in case of tie, it matches the first one.

#include <iostream>
#include <fstream>
#include <stack>
#include <map>
#include <string>

std::map<char, std::string> unicode_trans;

void transTableBuild();
void updnBkwdsOutput(char * word);
%}
letter      [a-zA-Z0-9&_?!"'`,;=*<>(){}| ]


%%
{letter}+    { updnBkwdsOutput(yytext);   }
.            { }
%%


void updnBkwdsOutput(char * word) {
  std::stack<std::string> updn_bkwds_output;
  int i = 0;
  char character;

  // If the map is empty, init it  
  if (unicode_trans.empty()) {
    transTableBuild();
  }
  
  // Print the upside down text until an enter got.
  while ( i < yyleng ) {
    character = word[i];
    // If the it is in map, push its couterpart into stack.
    auto search = unicode_trans.find(character);
    if (search != unicode_trans.end()) {
      updn_bkwds_output.push(search->second);
    }
    // Or just push itself in. 
    else {
      updn_bkwds_output.push(std::string(1, character));
    }
    i++;
  }
  
  while (!updn_bkwds_output.empty()) {
    std::cout << updn_bkwds_output.top();
    updn_bkwds_output.pop();
  }
  std::cout << std::endl;
}

int yywrap() { 
  yylex_destroy();
  return 1; 
}

void transTableBuild() {
  //std::cout << "Dictionary init..." << std::endl;
  unicode_trans['a'] = u8"\u0250";
  unicode_trans['b'] = u8"\u0071";
  unicode_trans['c'] = u8"\u0254";
  unicode_trans['d'] = u8"\u0070";
  unicode_trans['e'] = u8"\u01DD";
  unicode_trans['f'] = u8"\u025F";
  unicode_trans['g'] = u8"\u0253";
  unicode_trans['h'] = u8"\u0265";
  unicode_trans['i'] = u8"\u0131";
  unicode_trans['j'] = u8"\u027E";
  unicode_trans['k'] = u8"\u029E";
  unicode_trans['l'] = u8"\u006C";
  unicode_trans['m'] = u8"\u026F";
  unicode_trans['n'] = u8"\u0075";
  unicode_trans['o'] = u8"\u006F";
  unicode_trans['p'] = u8"\u0064";
  unicode_trans['q'] = u8"\u0062";
  unicode_trans['r'] = u8"\u0279";
  unicode_trans['s'] = u8"\u0073";
  unicode_trans['t'] = u8"\u0287";
  unicode_trans['u'] = u8"\u006E";
  unicode_trans['v'] = u8"\u028C";
  unicode_trans['w'] = u8"\u028D";
  unicode_trans['x'] = u8"\u0078";
  unicode_trans['y'] = u8"\u028E";
  unicode_trans['z'] = u8"\u007A";
  unicode_trans['A'] = u8"\u2200";
  unicode_trans['B'] = u8"\u15FA";
  unicode_trans['C'] = u8"\u0186";
  unicode_trans['D'] = u8"\u15E1";
  unicode_trans['E'] = u8"\u018E";
  unicode_trans['F'] = u8"\u2132";
  unicode_trans['G'] = u8"\u2141";
  unicode_trans['H'] = u8"\u0048";
  unicode_trans['I'] = u8"\u0049";
  unicode_trans['J'] = u8"\u017F";
  unicode_trans['K'] = u8"\u22CA";
  unicode_trans['L'] = u8"\u2142";
  unicode_trans['M'] = u8"\u0057";
  unicode_trans['N'] = u8"\u004E";
  unicode_trans['O'] = u8"\u004F";
  unicode_trans['P'] = u8"\u0500";
  unicode_trans['Q'] = u8"\u038C";
  unicode_trans['R'] = u8"\u1D1A";
  unicode_trans['S'] = u8"\u0053";
  unicode_trans['T'] = u8"\u22A5";
  unicode_trans['U'] = u8"\u2229";
  unicode_trans['V'] = u8"\u039B";
  unicode_trans['W'] = u8"\u004D";
  unicode_trans['X'] = u8"\u0058";
  unicode_trans['Y'] = u8"\u2144";
  unicode_trans['Z'] = u8"\u005A";
  unicode_trans['1'] = u8"\u21C2";
  unicode_trans['2'] = u8"\u1614";
  unicode_trans['3'] = u8"\u0190";
  unicode_trans['4'] = u8"\u07C8";
  unicode_trans['5'] = u8"\u03DA";
  unicode_trans['6'] = u8"\u0039";
  unicode_trans['7'] = u8"\u3125";
  unicode_trans['8'] = u8"\u0038";
  unicode_trans['9'] = u8"\u0036";
  unicode_trans['0'] = u8"\u0030";
  unicode_trans['&'] = u8"\u214B";
  unicode_trans['_'] = u8"\u203E";
  unicode_trans['?'] = u8"\u00BF";
  unicode_trans['!'] = u8"\u00A1";
  unicode_trans['\"'] = u8"\u201E";
  unicode_trans['\''] = u8"\u002C";
  unicode_trans['`'] = u8"\u02D9";
  unicode_trans[','] = u8"\u0027";
  unicode_trans[';'] = u8"\u061B";
  unicode_trans['['] = u8"]";
  unicode_trans[']'] = u8"[";
  unicode_trans['{'] = u8"}";
  unicode_trans['}'] = u8"{";
  unicode_trans['('] = u8")";
  unicode_trans[')'] = u8"(";
  unicode_trans['/'] = u8"\\";
  unicode_trans['\\'] = u8"/";
  unicode_trans['>'] = u8"<";
  unicode_trans['<'] = u8">";
}
