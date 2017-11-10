%{
#include "includes/ast.h"
#include "parse.tab.h"
%}
letter      [a-zA-Z]
digit       [0-9]
digits      [+|-]?[0-9]+
udigits     [0-9]+
float       {digits}"."{udigits}
ufloat      {udigits}"."{udigits}
ident       {letter}({letter}|{digit})*
simpleop    [+-%]
complexop   [*/]{1,2}
assign      ({simpleop}|{complexop})?"="

%%
/*
"="       { return EQ;    }
"+"       { return PLUS;  }
"-"       { return MINUS; }
"*"       { return MULT;  }
"/"       { return DIV;   }
*/

{simpleop} {
            swith(yytext){
              case '+': return PLUS; break;
              case '-': return MINUS; break;
              case '%': return MOD; break;
              default : break;
            }
          }
{complexop} {
              swith(yytext){
                case '+': return PLUS; break;
                case '-': return MINUS; break;
                case '%': return MOD; break;
                default : break;
              }
          }
{assign} {

        }
{udigits}  {
            yylval.intNumber = atoi(yytext);
            return INT;
          }
{ufloat}   {
            yylval.fltNumber = atof(yytext);
            return FLOAT;
          }
{ident}   {
            yylval.id = new char[yyleng+1];
            strcpy(yylval.id, yytext);
            return IDENT;
          }
"\n"      { return CR;    }
.         {}
%%
int yywrap() {
  yylex_destroy();
  return 1;
}
