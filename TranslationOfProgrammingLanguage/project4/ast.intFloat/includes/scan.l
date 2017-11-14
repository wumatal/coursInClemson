%{
#include "includes/ast.h"
#include "parse.tab.h"
%}
letter      [a-zA-Z]
digit       [0-9]
digits      [0-9]+
float       {digits}"."{digits}
ident       {letter}({letter}|{digit})*
sign        ("+"|"-")+
%%

"="        { return EQ;        }
"*"        { return MULT;      }
"/"        { return DIV;       }
"%"        { return MOD;       }
"("        { return LPAR;      }
")"        { return RPAR;      }
"//"       { return IDIV;      }
"**"       { return POWER;     }
"+="       { return PLUSEQ;    }
"-="       { return MINUSEQ;   }
"*="       { return MULTEQ;    }
"/="       { return DIVEQ;     }
"%="       { return MODEQ;     }
"//="      { return IDIVEQ;    }
"**="      { return POWEQ;     }

{sign}     {
             yylval.id = new char[yyleng+1];
             return SNG;
           }

{digits}   {
             yylval.intNumber = atoi(yytext);
             return INT;
           }
{float}    {
             yylval.fltNumber = atof(yytext);
             return FLOAT;
           }
{ident}    {
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
"\n"       { return CR;    }
.          {}
%%
int yywrap() {
  yylex_destroy();
  return 1;
}
