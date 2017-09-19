%{
// Flex handles ambiguity by matching longest string;
// in case of tie, it matches the first one.

#include <iostream>
%}
letter      [a-zA-Z]
blank       [ ]

%%
{blank}      { std::cout << " ";              }
a            { std::cout << u8"\u0250";       }
b            { std::cout << u8"\u0071";       }
c            { std::cout << u8"\u0254";       }
d            { std::cout << u8"\u0070";       }
e            { std::cout << u8"\u01DD";       }
f            { std::cout << u8"\u025F";       }
g            { std::cout << u8"\u0253";       }
h            { std::cout << u8"\u0265";       }
i            { std::cout << u8"\u0131";       }
j            { std::cout << u8"\u027E";       }
k            { std::cout << u8"\u029E";       }
l            { std::cout << u8"\u006C";       }
m            { std::cout << u8"\u026F";       }
n            { std::cout << u8"\u0075";       }
o            { std::cout << u8"\u006F";       }
p            { std::cout << u8"\u0064";       }
q            { std::cout << u8"\u0062";       }
r            { std::cout << u8"\u0279";       }
s            { std::cout << u8"\u0073";       }
t            { std::cout << u8"\u0287";       }
u            { std::cout << u8"\u006E";       }
v            { std::cout << u8"\u028C";       }
w            { std::cout << u8"\u028D";       }
x            { std::cout << u8"\u0078";       }
y            { std::cout << u8"\u028E";       }
z            { std::cout << u8"\u007A";       }
.            { }
%%
int yywrap() { return 1; }

