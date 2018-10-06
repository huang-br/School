%{
#include <iostream>
#include <set>
#include <vector>

#include "parser.hpp"

extern int yylex();
void yyerror(YYLTYPE* loc, const char* err);
std::string* translate_boolean_str(std::string* boolean_str);

/*
 * Here, target_program is a string that will hold the target program being
 * generated, and symbols is a simple symbol table.
 */

std::string* target_program;
std::set<std::string> symbols;
struct ASTnode* Root;
%}

%code requires
{
	#include "AST.hpp"
}

/* Enable location tracking. */
%locations

/*
 * All program constructs will be represented as strings, specifically as
 * their corresponding C/C++ translation.
 */
/*%define api.value.type { ASTnode* }*/




%union{
	struct ASTnode* node;
	std::string* str;
}

/*
 * Because the lexer can generate more than one token at a time (i.e. DEDENT
 * tokens), we'll use a push parser.
 */
%define api.pure full
%define api.push-pull push

/*
 * These are all of the terminals in our grammar, i.e. the syntactic
 * categories that can be recognized by the lexer.
 */
%token <str> IDENTIFIER
%token <str> FLOAT INTEGER BOOLEAN
%token <node> INDENT DEDENT NEWLINE
%token <node> ND BREAK DEF ELIF ELSE FOR IF NOT OR RETURN WHILE
%token <node> ASSIGN PLUS MINUS TIMES DIVIDEDBY
%token <node> EQ NEQ GT GTE LT LTE
%token <node> LPAREN RPAREN COMMA COLON

%type <node> program statements statement
%type <node> primary_expression negated_expression
%type <node> assign_statement
%type <node> expression block condition
%type <node> if_statement elif_blocks else_block while_statement
%type <node> break_statement

/*
 * Here, we're defining the precedence of the operators.  The ones that appear
 * later have higher precedence.  All of the operators are left-associative
 * except the "not" operator, which is right-associative.
 */
%left OR
%left AND
%left PLUS MINUS
%left TIMES DIVIDEDBY
%left EQ NEQ GT GTE LT LTE
%right NOT

/* This is our goal/start symbol. */
%start program

%%

/*
 * Each of the CFG rules below recognizes a particular program construct in
 * Python and creates a new string containing the corresponding C/C++
 * translation.  Since we're allocating strings as we go, we also free them
 * as we no longer need them.  Specifically, each string is freed after it is
 * combined into a larger string.
 */
program
  : statements { Root = $1; }
  ;

statements
  : statement { $$ = $1; }
  | statements statement { $$ = $1; $$ -> children.push_back($2);}
  ;

statement
  : assign_statement { $$ = $1;}
  | if_statement { $$ = $1; }
  | while_statement { $$ = $1; }
  | break_statement { $$ = $1; }
  ;

primary_expression
  : IDENTIFIER {
		 std::string* l = new std::string("Identifier");
		 std::string* v = new std::string(*$1);
		 $$ = new ASTnode(l, v);
               }
  | FLOAT { 
	    std::string* l = new std::string("Float");
	    std::string* v = new std::string(*$1);
	    $$ = new ASTnode(l, v);
	  }
  | INTEGER { 
	      std::string* l = new std::string("Integer");
	      std::string* v = new std::string(*$1);
	      $$ = new ASTnode(l, v);
	    }
  | BOOLEAN { 
	      std::string* l = new std::string("Boolean");
              std::string* v;
              if(*$1 == "True")
              {
	      	v = new std::string("true");
              }
              else
              {
              	v = new std::string("false");
              }
	      $$ = new ASTnode(l, v);  
	    }
  | LPAREN expression RPAREN { 
			       $$ = $2; 
			     }
  ;

negated_expression
  : NOT primary_expression { 
                             std::string* l = new std::string("NOT");
                             std::string* v = new std::string("");
                             struct ASTnode* node = new ASTnode(l, v);
                             $2 -> children.push_back(node);
                             $$ = $2; 
                           }
  ;

expression
  : primary_expression { $$ = $1; }
  | negated_expression { $$ = $1; }
  | expression PLUS expression { 
				 std::string* l = new std::string("PLUS");
				 std::string* v = new std::string("");
				 struct ASTnode* node = new ASTnode(l, v);
				 node -> children.push_back($1);
				 node -> children.push_back($3);
				 $$ = node; 
			       }
  | expression MINUS expression { 
			 	  std::string* l = new std::string("MINUS");
				  std::string* v = new std::string("");
				  struct ASTnode* node = new ASTnode(l, v);
				  node -> children.push_back($1);
				  node -> children.push_back($3);
				  $$ = node; 
				}
  | expression TIMES expression { 
				  std::string* l = new std::string("TIMES");
				  std::string* v = new std::string("");
				  struct ASTnode* node = new ASTnode(l, v);;
			          node -> children.push_back($1);
			          node -> children.push_back($3);
				  $$ = node;  
				}
  | expression DIVIDEDBY expression {
                                      std::string* l = new std::string("DIVIDEBY");
				      std::string* v = new std::string("");
			              struct ASTnode* node = new ASTnode(l, v);
				      node -> children.push_back($1);
				      node -> children.push_back($3);
			              $$ = node; 
				    }
  | expression EQ expression { 
			       std::string* l = new std::string("EQ");
			       std::string* v = new std::string("");
                               struct ASTnode* node = new ASTnode(l, v);
			       node -> children.push_back($1);
			       node -> children.push_back($3);
			       $$ = node;  
			     }
  | expression NEQ expression { 
				std::string* l = new std::string("NEQ");
				std::string* v = new std::string("");
				struct ASTnode* node = new ASTnode(l, v);
				node -> children.push_back($1);
				node -> children.push_back($3);
				$$ = node;  
			      }
  | expression GT expression {
			       std::string* l = new std::string("GT");
			       std::string* v = new std::string("");
			       struct ASTnode* node = new ASTnode(l, v);
			       node -> children.push_back($1);
			       node -> children.push_back($3);
			       $$ = node; 
			     }
  | expression GTE expression { 
				std::string* l = new std::string("GTE");
				std::string* v = new std::string("");
				struct ASTnode* node = new ASTnode(l, v);
				node -> children.push_back($1);
				node -> children.push_back($3);
				$$ = node;
			      }
  | expression LT expression { 
			       std::string* l = new std::string("LT");
			       std::string* v = new std::string("");
                               struct ASTnode* node = new ASTnode(l, v);
			       node -> children.push_back($1);
			       node -> children.push_back($3);
			       $$ = node;  
		             }
  | expression LTE expression {
			        std::string* l = new std::string("LTE");
			        std::string* v = new std::string("");
			        struct ASTnode* node = new ASTnode(l, v);
				node -> children.push_back($1);
				node -> children.push_back($3);
				$$ = node;
			      }
  ;

assign_statement
  : IDENTIFIER ASSIGN expression NEWLINE { 
					   std::string* l = new std::string("Assignment");
					   std::string* v = new std::string("");
					   struct ASTnode* node = new ASTnode(l, v);
 
                                           std::string* cl = new std::string("Identifier");
                                           std::string* cv = new std::string(*$1);
                                           struct ASTnode* child = new ASTnode(cl, cv);
					   node -> children.push_back(child);
					   node -> children.push_back($2);
					   $$ = node;
					 }
  ;
			  
block
  : INDENT statements DEDENT { 
			       std::string* l = new std::string("Block");
			       std::string* v = new std::string(""); 
			       struct ASTnode* node = new ASTnode(l, v);
			       node -> children.push_back($2);
			       $$ = node;
			     }
  ;

condition
  : expression { $$ = $1; }
  | condition AND condition {
			      std::string* l = new std::string("AND");
			      std::string* v = new std::string("");
			      struct ASTnode* node = new ASTnode(l, v);
			      node -> children.push_back($1);
			      node -> children.push_back($3);
			      $$ = node; 
			    }
  | condition OR condition { 
			     std::string* l = new std::string("OR");
			     std::string* v = new std::string("");
			     struct ASTnode* node = new ASTnode(l, v);
			     node -> children.push_back($1);
			     node -> children.push_back($3);
			     $$ = node;  
			   }
  ;

if_statement
  : IF condition COLON NEWLINE block elif_blocks else_block { 
			                                      std::string* l = new std::string("IF");
							      std::string* v = new std::string("");
							      struct ASTnode* node = new ASTnode(l, v);
							      node -> children.push_back($2);
							      node -> children.push_back($5);
							      node -> children.push_back($6);
							      node -> children.push_back($7);
							      $$ = node;
							    }
  ;

elif_blocks
  : %empty {}			  
  | elif_blocks ELIF condition COLON NEWLINE block { 
                                                     std::string* l = new std::string("ELSE IF");
                                                     std::string* v = new std::string("");
                                                     struct ASTnode * node = new ASTnode(l, v);
                                                     node -> children.push_back($1);
                                                     node -> children.push_back($3);
                                                     node -> children.push_back($5);
                                                     $$ = node;
                                                   }
  ;

else_block
  : %empty {}
  | ELSE COLON NEWLINE block { 
                               std::string* l = new std::string("ELSE");
                               std::string* v = new std::string("");
                               struct ASTnode* node = new ASTnode(l, v);
                               node -> children.push_back($4);
                               $$ = node;
                             }


while_statement
  : WHILE condition COLON NEWLINE block {
					  std::string* l = new std::string("WHILE");
					  std::string* v = new std::string("");
					  struct ASTnode* node = new ASTnode(l, v);
					  node -> children.push_back($2);
					  node -> children.push_back($5);
					  $$ = node;
					}
  ;

break_statement
  : BREAK NEWLINE { 
		    std::string* l = new std::string("BREAK");
		    std::string* v = new std::string("");
		    struct ASTnode* node = new ASTnode(l, v);
		    $$ = node;
		  }
  ;

%%

void yyerror(YYLTYPE* loc, const char* err) {
  std::cerr << "Error (line " << loc->first_line << "): " << err << std::endl;
}

/*
 * This function translates a Python boolean value into the corresponding
 * C++ boolean value.
 */
std::string* translate_boolean_str(std::string* boolean_str) {
  if (*boolean_str == "True") {
    return new std::string("true");
  } else {
    return new std::string("false");
  }
}
