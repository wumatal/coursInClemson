%{
#include "includes/ast.h"
#include "parse.tab.h"
%}
letter      [a-zA-Z]
digit       [0-9]
digits      [0-9]+
float       {digits}"."{digits}
ident       {letter}({letter}|{digit})*

%%

"="       { return EQ;        }
"+"       { return PLUS;      }
"-"       { return MINUS;     }
"*"       { return MULT;      }
"/"       { return DIV;       }
"%"       { return MOD;       }
"("       { return LPAR;      }
")"       { return RPAR;      }
"//"      { return IDIV;      }
"**"      { return POWER;     }
"+="      { return PLUSEQ;    }
"-="      { return MINUSEQ;   }
"*="      { return MULTEQ;    }
"/="      { return DIVEQ;     }
"%="      { return MODEQ;     }
"//="     { return IDIVEQ;    }
"**="     { return POWEQ;     }

{digits}  {
            yylval.intNumber = atoi(yytext);
            return INT;
          }
{float}   {
            yylval.fltNumber = atof(yytext);
            return FLOAT;
          }
{ident}   {
            if( !strcmp(yytext, "print") || !strcmp(yytext, "PRINT") ){
              yylval.id = new char[yyleng+1];
              return PRT;
            }
            else{
              yylval.id = new char[yyleng+1];
              strcpy(yylval.id, yytext);
              return IDENT;
            }
          }
"\n"      { return CR;    }
.         {}
%%
int yywrap() {
  yylex_destroy();
  return 1;
}
