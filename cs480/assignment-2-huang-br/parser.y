%{
#include <iostream>
#include <map>

#include "parser.hpp"

std::map<std::string, std::string> symbols;

std::string* prog;
bool _error = false; 

void yyerror(YYLTYPE* loc, const char* err);
extern int yylex();
%}

%union {
  std::string* str;
}

%locations

%define api.pure full
%define api.push-pull push

%token <str> IDENTIFIER
%token <str> AND BREAK DEF ELIF ELSE FOR IF NOT OR RETURN WHILE
%token <str> NEWLINE
%token <str> NUMBER FLOAT
%token <str> ASSIGN PLUS MINUS TIMES DIVIDEBY EQ NEQ GT GTE LT LTE
%token <str> LPAREN RPAREN COMMA COLON INDENT DEDENT TRUE FALSE

%type <str> program
%type <str> statement
%type <str> conditions
%type <str> expression

%left PLUS MINUS
%left TIMES DIVIDEDBY

%start program

%%

program
  : program statement NEWLINE { $$ = new std::string(*$1 + *$2 + "\n"); prog = $$; delete $1; delete$2; }
  | statement NEWLINE { $$ = new std::string(*$1 + "\n"); delete $1; } 
  | statement { $$ = new std::string(*$1); delete $1; } 
  ;

conditions
  : IDENTIFIER EQ expression { $$ = new std::string(*$1 + "==" + *$2); delete $1; delete $2; }
  | IDENTIFIER GT expression {  $$ = new std::string(*$1 + ">" + *$2); delete $1; delete $2; } 
  | IDENTIFIER GTE expression { $$ = new std::string(*$1 + ">=" + *$2); delete $1; delete $2;  }
  | IDENTIFIER LT expression {  $$ = new std::string(*$1 + "<" + *$2); delete $1; delete $2; }
  | IDENTIFIER LTE expression {  $$ = new std::string(*$1 + "<=" + *$2); delete $1; delete $2; }
  ;
  
statement
  : IDENTIFIER ASSIGN expression  { symbols[*$1] = *$3;}
  | IF conditions COLON NEWLINE INDENT program DEDENT { $$ = new std::string("if(" + *$2 + "){" + "\n" + "\t" + *$6 + "\n" + "}"); delete $2; delete $6; }
  | ELIF conditions COLON NEWLINE INDENT program DEDENT { $$ = new std::string("else if(" + *$2 + "){" + "\n" + "\t" + *$6 + "\n" + "}"); delete $2; delete $6; }
  | ELSE conditions COLON NEWLINE INDENT program DEDENT { $$ = new std::string("else(" + *$2 + "){" + "\n" + "\t" + *$6 + "\n" + "}"); delete $2; delete $6; }
  | WHILE conditions COLON NEWLINE INDENT program DEDENT { $$ = new std::string("while(" + *$2 + "){" + "\n" + "\t" + *$6 + "\n" + "}"); delete $2; delete $6; }
  | error { std::cerr << "Error : bad statement on line " << @1.first_line << std::endl; _error = true; }
  ;

expression
  : LPAREN expression RPAREN { $$ = new std::string("(" + *$2 + ")"); delete $2; }
  | expression PLUS expression { $$ = new std::string(*$1 + "+" + *$3); delete $1; delete $3; }
  | expression MINUS expression { $$ = new std::string(*$1 + "-" + *$3); delete $1; delete $3; }
  | expression TIMES expression { $$ = new std::string(*$1 + "*" + *$3); delete $1; delete $3; }
  | expression DIVIDEDBY expression { $$ = new std::string(*$1 + "/" + *$3); delete $1; delete $3; }
  | IDENTIFIER { $$ = new std::string(*$1); delete $1; }
  | NUMBER { $$ = $1; }
  | FLOAT { $$ = $1; }
  | BREAK NEWLINE { $$ = $1; }
  | TRUE { $$ = new std::string("true"); } 
  | FALSE { $$ = new std::string("false"); }
  ;

%%

void yyerror(YYLTYPE* loc, const char* err) {
  std::cerr << "Error: " << err << std::endl;
}
