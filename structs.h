
#ifndef STRUCTS_H
#define STRUCTS_H
#include "tokens.h"
#include <string.h>
typedef enum
{
  Sequencecommande,
  affectation,
  skip,
  ifelse,
  whiledo,
  variable,
  expr_arith,
  expr_bool,
  entier,
  none
} TypeNoeud;

// je vais utiliser l'union pour que tout les type de noeud herites en sorte de type noeud comme en orientee objet

typedef struct Noeud
{
  // type de noeud
  TypeNoeud type;
  union
  {
    struct
    {
      struct Noeud *gauche;
      struct Noeud *droite;
      int op; // '+', '-', '*', '/' ,  etc. qui peut etre arithmetique
    } oper_arith;
    struct
    {
      struct Noeud *gauche;
      struct Noeud *droite;
      int op; // '==', '<', '>', etc. qui peut etre  booleane
    } oper_bool;

    struct
    {
      struct Noeud *variable; // Nœud pour la variable
      struct Noeud *valeur;   // Nœud pour la valeur ou l'expression arithmetique à assigner
    } affectation;
    struct
    {
      struct Noeud *condition;
      struct Noeud *siVrai;
      struct Noeud *siFaux;
    } ifelseNoeud;
    struct
    {
      struct Noeud *condition;
      struct Noeud *leDo;
    } whileDONoeud;
    struct
    {
      struct Noeud *premiere;
      struct Noeud *deuxieme;
    } suiteDeCommande;
    int i;         // une valeur
    char *varname; // variable
  } lunion;

} Noeud;
typedef struct maillon
{
  int num_var;
  char nomvar[10]; // ca va depasser 3
  int value;
  struct maillon *suivant;

} maillon;
typedef struct liste_v
{
  int taille;
  maillon *tete;
} liste_v;
liste_v *creer_liste();
int ajouter_variable(char nomvar[], int value, liste_v *l);
int getValeurAssociee(char nomvar[], liste_v *l);
void print_variable_list(liste_v *l);
void free_variable_list(liste_v *l);
Noeud *CreerOpArith(int op, Noeud *gauche, Noeud *droite);
Noeud *CreerSkipNode();
Noeud *CreerOpBool(int op, Noeud *gauche, Noeud *droite);
Noeud *CreerAffectation(Noeud *varname, Noeud *valeurdevar);
Noeud *createIfElseNoeud(Noeud *condition, Noeud *siVrai, Noeud *siFaux);
Noeud *createWhileNoeud(Noeud *condition, Noeud *leDo);
Noeud *createINTNoeud(int i);
Noeud *createVARNoeud(char *varname);
Noeud *creerSequenceNoeud(Noeud *premiere, Noeud *deuxieme);
// Fonction pour obtenir le type d'un noeud
TypeNoeud getNodeType(Noeud *node);
// Fonctions pour obtenir les fils d'un nœud, dépendant du type
Noeud *getNodeLeftChild(Noeud *node);
Noeud *getNodeRightChild(Noeud *node);
Noeud *getNodeMiddleChild(Noeud *node);
int getValue(Noeud *n, liste_v *l);
#endif // STRUCTS_H
