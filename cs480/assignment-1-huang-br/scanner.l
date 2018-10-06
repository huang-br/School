%{
#include <iostream>
#include <vector>
#include <set>
#include <string>

struct _word {
  std::string lexeme;
  std::string category;
};

std::vector<struct _word> _words;
std::set<std::string> _ids;
bool _error = false;

void _save_word(const std::string& lexeme, const std::string& category) {
  struct _word _word = {
    .lexeme = lexeme,
    .category = category
  };
  _words.push_back(_word);
}

int indentLevel = 0;
int currentIndentLevel = 0;

%}

%option noyywrap
%option yylineno

%%

%{
  /* No code to put at the top of yylex(). */
%}

                        
[ ]              /* Ignore whitespace. */
#.*[ \n]         /* Ignore Comments. */
^[ \t]+\n?              {
                         currentIndentLevel = yyleng;
                         if(currentIndentLevel > indentLevel)
                         {
                         	_save_word("INDENT", "");
                                indentLevel = currentIndentLevel;
                         }
                         else if(currentIndentLevel < indentLevel)
                         {
                         	_save_word("DEDENT", "");
                                indentLevel = currentIndentLevel;
                         }
                         else if(currentIndentLevel == indentLevel)
                         {	
                          	continue;
                         }
                       }                  
True                   { _save_word("BOOLEAN", "1"); }
False                  { _save_word("BOOLEAN", "0"); }
if                     { _save_word("IF", yytext); }
else                   { _save_word("ELSE", yytext); }
elif                   { _save_word("ELIF", yytext); }
and                    { _save_word("AND", yytext); }
break                  { _save_word("BREAK", yytext); }
def                    { _save_word("DEF", yytext); }
for                    { _save_word("FOR", yytext); }
not                    { _save_word("NOT", yytext); }
or                     { _save_word("OR", yytext); }
return                 { _save_word("RETURN", yytext); }
while                  { _save_word("WHILE", yytext); }
[a-zA-Z]+[0-9a-zA-Z_]* {_save_word("IDENTIFIER", yytext); _ids.insert(yytext); }

"-"?[0-9]+         { _save_word("INTEGER", yytext); }
[0-9]+("."[0-9]+)? { _save_word("FLOAT", yytext); }

"="           { _save_word("ASSIGN", yytext); }
"+"           { _save_word("PLUS", yytext); }
"-"           { _save_word("MINUS", yytext); }
"*"           { _save_word("TIMES", yytext); }
"/"           { _save_word("DIVIDEDBY", yytext); }
"=="          { _save_word("EQ", yytext); }
"!="	      { _save_word("NEG", yytext); }
">"	      { _save_word("GT", yytext); }
">="	      { _save_word("GTE", yytext); }
"<"	      { _save_word("LT", yytext); }
"<=" 	      { _save_word("LTE", yytext); }
";"           { _save_word("SEMICOLON", yytext); }
"("           { _save_word("LPAREN", yytext); }
")"           { _save_word("RPAREN", yytext); }
"," 	      { _save_word("COMMA", yytext); }
":"	      { _save_word("COLON", yytext); }
\n            { _save_word("NEWLINE", ""); }

.             {
                std::cerr << "Invalid symbol on line " << yylineno
                  << ": " << yytext << std::endl;
                _error = true;
              }

<<EOF>>       {
                if (_error) {
                  return 1;
                }
                return 0;
              }


%%

int main() {
  if (!yylex()) {
    std::vector<struct _word>::iterator wit;
    for (wit = _words.begin(); wit != _words.end(); ++wit) {
      printf("%-20s %s\n", wit->lexeme.c_str(), wit->category.c_str());
    }

    std::cout << std::endl << "Identifiers:" << std::endl;
    std::set<std::string>::iterator iit;
    for (iit = _ids.begin(); iit != _ids.end(); ++iit) {
      std::cout << *iit << std::endl;
    }
  }
}
