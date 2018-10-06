%{
#include <iostream>
#include <map>

#include "parser.hpp"

std::map<std::string, float> symbols;

std::string* prog;
bool _error = false; 

void yyerror(YYLTYPE* loc, const char* err);
extern int yylex();
%}

%union {
  float value;
  std::string* str;
  int token;
}

/* %define api.value.type { std::string* } */

%locations

%define api.pure full
%define api.push-pull push

%token <str> IDENTIFIER
%token <token> AND BREAK DEF ELIF ELSE FOR IF NOT OR RETURN WHILE
%token <str> NEWLINE
%token <value> NUMBER
%token <token> ASSIGN PLUS MINUS TIMES DIVIDEBY EQ NEQ GT GTE LT LTE
%token <token> LPAREN RPAREN COMMA COLON INDENT DEDENT TRUE FALSE

%type <str> program
%type <str> statement
%type <str> conditions
%type <str> expression
%type <token> terminals

%left PLUS MINUS
%left TIMES DIVIDEDBY

%start program

%%

program
  : program statement { prog = new std::string(*$1 + *$2); std::cout << *$$; delete $1; delete $2; }
  | statement { prog = new std::string(*$1); std::cout << *$$; delete $1; } 
  ;

conditions
  : IDENTIFIER EQ expression { delete $1; }
  | IDENTIFIER GT expression { delete $1; } 
  | IDENTIFIER GTE expression { delete $1; }
  | IDENTIFIER LT expression { delete $1; }
  | IDENTIFIER LTE expression { delete $1; }
  | IDENTIFIER { delete $1; }
  ;

statement
  : IDENTIFIER ASSIGN expression { std::cout << $2 << std::endl; delete $1; }
  | IF conditions COLON NEWLINE INDENT statement DEDENT
  | ELIF conditions COLON NEWLINE INDENT statement DEDENT
  | ELSE conditions COLON NEWLINE INDENT statement DEDENT
  | WHILE conditions COLON NEWLINE INDENT statement DEDENT
  | error { std::cerr << "Error : bad statement on line " << @1.first_line << std::endl; _error = true; }
  ;

expression
  : LPAREN expression RPAREN 
  | expression PLUS expression 
  | expression MINUS expression 
  | expression TIMES expression 
  | expression DIVIDEDBY expression
  | IDENTIFIER { delete $1; }
  | terminlas
  ;

terminals
  : NUMBER
  | TRUE
  | FALSE
  | BREAK
  ;

%%

void yyerror(YYLTYPE* loc, const char* err) {
  std::cerr << "Error: " << err << std::endl;
}
