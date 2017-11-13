%{
#include <iostream>
#include <map>
#include <cmath>
#include "includes/ast.h"
#include "includes/symbolTable.h"

extern int yylex();
void yyerror(const char * msg);

PoolOfNodes& pool = PoolOfNodes::getInstance();
%}

%union {
  Node* node;
  int intNumber;
  float fltNumber;
  char *id;
}

%token CR EQ
%token<intNumber> INT
%token<fltNumber> FLOAT
%token<id> IDENT PRT
%type<node> lines expr equat
%left PLUS MINUS 
%left MULT DIV MOD IDIV POWER
%left PLUSEQ MINUSEQ MULTEQ DIVEQ MODEQ IDIVEQ POWEQ
%left LPAR RPAR

%%
lines   : lines PRT expr CR
          {
            ($3)->eval()->print();
            delete [] $2;
          }
        | lines expr CR
          {
            ($2)->eval();
          }
        | lines equat CR
        | lines PRT equat CR
          {
            ($3)->eval()->print();
            delete [] $2;
          }
        | lines PRT CR
          {
            delete [] $2;
          }
        | lines CR
        | { ; }
        ;

expr    : expr PLUS expr   { $$ = new AddBinaryNode($1, $3);
                             pool.add($$);
                           }
        | expr MINUS expr  { $$ = new SubBinaryNode($1, $3);
                             pool.add($$);
                           }
        | expr MULT expr   { $$ = new MulBinaryNode($1, $3);
                             pool.add($$);
                           }
        | expr DIV expr    { $$ = new DivBinaryNode($1, $3);
                             pool.add($$);
                           }
        | expr MOD expr    { $$ = new ModBinaryNode($1, $3);
                             pool.add($$);
                           }
        | expr IDIV expr   { $$ = new IdivBinaryNode($1, $3);
                             pool.add($$);
                           }
        | expr POWER expr  { $$ = new PowBinaryNode($1, $3);
                             pool.add($$);
                           }
        | LPAR expr RPAR   {
                             $$ = $2;
                           }

        | INT              { $$ = new IntLiteral($1);
                             pool.add($$);
                           }
        | FLOAT            { $$ = new FloatLiteral($1);
                             pool.add($$);
                           }
        | IDENT            { $$ = new IdentNode($1);
                             delete [] $1;
                             pool.add($$);
                           }
        ;
equat   : IDENT EQ expr    {
                             Node* lhs = new IdentNode($1);
                             $$ = new AsgBinaryNode(lhs, $3);
                             pool.add(lhs);
                             pool.add($$);
                             delete [] $1;
                           }
        | IDENT PLUSEQ expr{
                             Node* n_val = new IdentNode($1);
                             $$ = new PlusAsgBinaryNode(n_val, $3);
                             pool.add($$);
                             pool.add(n_val);
                             delete [] $1;
                           }
        | IDENT MINUSEQ expr{
                             Node* n_val = new IdentNode($1);
                             $$ = new MinusAsgBinaryNode(n_val, $3);
                             pool.add($$);
                             pool.add(n_val);
                             delete [] $1;
                           }
        | IDENT MULTEQ expr{
                             Node* n_val = new IdentNode($1);
                             $$ = new MultAsgBinaryNode(n_val, $3);
                             pool.add($$);
                             pool.add(n_val);
                             delete [] $1;
                           }
        | IDENT DIVEQ expr{
                             Node* n_val = new IdentNode($1);
                             $$ = new DivAsgBinaryNode(n_val, $3);
                             pool.add($$);
                             pool.add(n_val);
                             delete [] $1;
                           }
        | IDENT MODEQ expr{
                             Node* n_val = new IdentNode($1);
                             $$ = new ModAsgBinaryNode(n_val, $3);
                             pool.add($$);
                             pool.add(n_val);
                             delete [] $1;
                           }
        | IDENT IDIVEQ expr{
                             Node* n_val = new IdentNode($1);
                             $$ = new IdivAsgBinaryNode(n_val, $3);
                             pool.add($$);
                             pool.add(n_val);
                             delete [] $1;
                           }
        | IDENT POWEQ expr{
                             Node* n_val = new IdentNode($1);
                             $$ = new PowAsgBinaryNode(n_val, $3);
                             pool.add($$);
                             pool.add(n_val);
                             delete [] $1;
                           }
        ;
%%
void yyerror(const char * msg) { std::cout << msg << std::endl; }
