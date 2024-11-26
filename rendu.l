%{
#include <stdlib.h>
#include "structs.h"
#include "y.tab.h"
%}
DIGIT       [0-9]
LETTER      [a-zA-Z]
WHITESPACE  [ \t\n]
%%

{WHITESPACE}+    { /* Ignorer les espaces blancs */ }
{LETTER}{DIGIT}{0,2}       { yylval.svar = strdup(yytext); return IDENTIFIER; }
{DIGIT}+                 { yylval.ivar = atoi(yytext); return NUMBER; }
"=="            { return EQ; }
"<="            { return SUPE; }
">="            { return INFE; }
"<"             { return INF; }
">"             { return SUP; }
"&&"           { return AND; }
"||"            { return OR; }
"!="          { return DIFF;}
"!"           { return NOT; }
"="             { return AFFECTATION; }
";"             { return PVIRGULE; }
"("             { return POUVERT; }
")"             { return PFERME; }
"+"             { return PLUS; }
"-"             { return MOIN; }
"*"             { return MULT; }
"/"             { return DIV; }
"{"             { return AOUVERT; }
"}"             { return AFERME; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"do"            { return DO; }
"skip"          { return SKIP; }
"TRUE"          { return TRUETOKEN;}
"FALSE"         {return FALSETOKEN;}
.                      { /* Gérer les caractères inattendus */ }

%%

int yywrap() {
  return 1;
}
