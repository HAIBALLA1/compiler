%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "structs.h"
#include "Affichage.h"

extern int yylex();
Noeud *root; // variable globale
liste_v  *l;
 //liste de variable globale

void yyerror(const char *s)
{
  fprintf(stderr, "Error: %s\n", s);
  free_variable_list(l);
}



%}

%union {
    int ivar;
    char * svar;     // Pour les chaînes de caractères (identifiants de variables)
    Noeud *node;    // Un seul type pour tous les éléments manipulés par Yacc sauf les variables et les entiers
}


%token  EQ SUPE INFE INF SUP AND OR NOT AFFECTATION PVIRGULE POUVERT PFERME PLUS MOIN MULT DIV AOUVERT AFERME IF ELSE WHILE DO SKIP TRUETOKEN FALSETOKEN DIFF
%token <ivar> NUMBER
%token <svar> IDENTIFIER
%type <node> expression statement program statement_list

%left OR
%left AND
%left EQ DIFF
%left INF INFE SUP SUPE
%left PLUS MOIN
%left MULT DIV
%right NOT
%right AFFECTATION

%%
program : statement
{
  
  root = $1; // c'est là que root est initialisée
  
  print_variable_list(l); // Affichez la liste des variables
  // Libérez la liste des variables
  
};

statement : 
    PVIRGULE {$$=CreerOpArith(0,NULL,NULL); }
  | IDENTIFIER AFFECTATION expression PVIRGULE { if(l==NULL) { l=creer_liste();} $$ = CreerAffectation(createVARNoeud($1), $3); ajouter_variable($1,getValue($3,l),l);print_variable_list(l);} // Insérez la variable dans la liste  
  | SKIP PVIRGULE { $$ = CreerSkipNode(); }
  | IF POUVERT expression PFERME AOUVERT statement_list AFERME ELSE AOUVERT statement_list AFERME { $$ = createIfElseNoeud($3, $6, $10); }
  | WHILE POUVERT  expression PFERME DO AOUVERT statement_list AFERME { $$ = createWhileNoeud($3, $7); }
  | AOUVERT statement_list AFERME {$$=$2;}

statement_list : 
    statement { $$ = $1; }
  | statement_list statement { $$ = creerSequenceNoeud($1, $2); };

expression : 
    NUMBER {  $$=createINTNoeud($1); }
  | IDENTIFIER {  $$=createVARNoeud($1);}
  | TRUETOKEN { $$ = createINTNoeud(1); }
  | FALSETOKEN { $$ = createINTNoeud(0); }
  | expression PLUS expression { $$ = CreerOpArith(op_PLUS, $1, $3); }
  | expression MOIN expression { $$ = CreerOpArith(op_MOIN, $1, $3); }
  | expression MULT expression { $$ = CreerOpArith(op_MULT, $1, $3); }
  | expression DIV expression { $$ = CreerOpArith(op_DIV, $1, $3); }
  | expression EQ expression { $$ = CreerOpBool(op_EQ, $1, $3); }
  | expression DIFF expression { $$ = CreerOpBool(op_DIFF, $1, $3); }
  | expression INF expression { $$ = CreerOpBool(op_INF, $1, $3); }
  | expression INFE expression { $$ = CreerOpBool(op_INFE, $1, $3); }
  | expression SUP expression { $$ = CreerOpBool(op_SUP, $1, $3); }
  | expression SUPE expression { $$ = CreerOpBool(op_SUPE, $1, $3); }
  | expression AND expression { $$ = CreerOpBool(op_AND, $1, $3); }
  | expression OR expression { $$ = CreerOpBool(op_OR, $1, $3); }
  | NOT expression { $$ = CreerOpBool(op_NOT,0, $2); }
  | POUVERT expression PFERME { $$ = $2; };


%%
int main()
{

  if (yyparse() == 0)
  {

    printf("Parsing completed successfully.\n");
    printf("\n");
    printf("Arbre : \n");
    printf("-------\n");
    printf("\n");
    printNode(root,l);
    free_variable_list(l);
    
     // Décommentez si vous avez une fonction pour imprimer l'arbre
  }
  return 0;
}
