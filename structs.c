

#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "structs.h"

liste_v *creer_liste()
{
  liste_v *l = malloc(sizeof(liste_v));
  if (l == NULL)
  {
    return NULL; // Gestion de l'échec de l'allocation de mémoire
  }
  l->taille = 0;
  l->tete = NULL;
  return l;
}
int ajouter_variable(char nomvar[], int value, liste_v *l)
{
  if (l == NULL)
  {
    printf("viiiiide\n"); // Liste non initialisée
  }

  maillon *courant = l->tete;
  maillon *precedent = NULL;
  while (courant != NULL)
  {
    if ((strcmp(courant->nomvar, nomvar) == 0) && (courant->value != value)) // en cas de changement ou d'incrementation
    {
      courant->value = value;
      // printf("%s ->%d   ", courant->nomvar, courant->value);
      return 1;
    }
    else if ((strcmp(courant->nomvar, nomvar) == 0) && (courant->value == value))
    {
      return 0;
    }

    precedent = courant;
    courant = courant->suivant;
  }

  maillon *nouveau = malloc(sizeof(maillon));
  if (nouveau == NULL)
  {
    return 0; // Gestion de l'échec de l'allocation de mémoire
  }
  strcpy(nouveau->nomvar, nomvar);
  nouveau->value = value;
  nouveau->num_var = (precedent == NULL ? 1 : precedent->num_var + 1);
  nouveau->suivant = NULL;

  if (precedent == NULL)
  {
    l->tete = nouveau; // Ajout du premier maillon
  }
  else
  {
    precedent->suivant = nouveau;
  }
  l->taille++;
  return 1;
}

int getValeurAssociee(char nomvar[], liste_v *l)
{
  // printf("taille : %d \n", l->taille);
  maillon *temp = l->tete;
  while (temp != NULL)
  {
    // printf("%s . ", temp->nomvar);
    if (strcmp(temp->nomvar, nomvar) == 0)
    {
      return temp->value;
    }
    temp = temp->suivant;
  }
  return 0;
}
void print_variable_list(liste_v *l)
{
  if (l == NULL)
  {
    printf("vide\n");
  }

  printf("Variables:\n");
  printf("-----------\n");
  maillon *courant = l->tete;
  while (courant != NULL)
  {
    printf("%s --> %d , ", courant->nomvar, courant->value);
    courant = courant->suivant;
  }
  printf("\n");
}

void free_variable_list(liste_v *l)
{
  maillon *courant = l->tete;
  maillon *temp;
  while (courant != NULL)
  {

    temp = courant->suivant;

    free(courant);
    courant = temp;
  }
  free(l);
}
Noeud *CreerOpArith(int op, Noeud *gauche, Noeud *droite)
{

  Noeud *n = (Noeud *)malloc(sizeof(Noeud));
  n->type = expr_arith;
  n->lunion.oper_arith.op = op;
  n->lunion.oper_arith.gauche = gauche;
  n->lunion.oper_arith.droite = droite;
  return n;
}
Noeud *CreerSkipNode()
{

  Noeud *n = (Noeud *)malloc(sizeof(Noeud));
  n->type = skip;
  return n;
}
Noeud *CreerOpBool(int op, Noeud *gauche, Noeud *droite)
{

  Noeud *n = (Noeud *)malloc(sizeof(Noeud));
  n->type = expr_bool;
  n->lunion.oper_bool.op = op;
  n->lunion.oper_bool.gauche = gauche;
  n->lunion.oper_bool.droite = droite;
  return n;
}

Noeud *CreerAffectation(Noeud *varname, Noeud *valeurdevar)
{

  Noeud *n = (Noeud *)malloc(sizeof(Noeud));
  n->type = affectation;
  n->lunion.affectation.valeur = valeurdevar;
  n->lunion.affectation.variable = varname;
  return n;
}
Noeud *createIfElseNoeud(Noeud *condition, Noeud *siVrai, Noeud *siFaux)
{
  Noeud *n = (Noeud *)malloc(sizeof(Noeud));
  n->type = ifelse;
  n->lunion.ifelseNoeud.condition = condition;
  n->lunion.ifelseNoeud.siVrai = siVrai;
  n->lunion.ifelseNoeud.siFaux = siFaux;
  return n;
}
Noeud *createWhileNoeud(Noeud *condition, Noeud *leDo)
{
  Noeud *n = (Noeud *)malloc(sizeof(Noeud));
  n->type = whiledo;
  n->lunion.whileDONoeud.condition = condition;
  n->lunion.whileDONoeud.leDo = leDo;
  return n;
}
Noeud *createINTNoeud(int i)
{
  Noeud *n = (Noeud *)malloc(sizeof(Noeud));
  n->type = entier;
  n->lunion.i = i;
  return n;
}
Noeud *createVARNoeud(char *varname)
{
  Noeud *n = (Noeud *)malloc(sizeof(Noeud));
  n->type = variable;
  n->lunion.varname = varname;
  return n;
}

Noeud *creerSequenceNoeud(Noeud *premiere, Noeud *deuxieme)
{
  Noeud *n = (Noeud *)malloc(sizeof(Noeud));
  n->type = Sequencecommande;
  n->lunion.suiteDeCommande.premiere = premiere;
  n->lunion.suiteDeCommande.deuxieme = deuxieme;
  return n;
}

// Fonction pour obtenir le type d'un noeud
TypeNoeud getNodeType(Noeud *node)
{
  if (node != NULL)
  {
    return node->type; // Retourne une valeur négative pour indiquer une erreur
  }
  else
  {
    return none;
  }
}

// Fonctions pour obtenir les fils d'un nœud, dépendant du type
Noeud *getNodeLeftChild(Noeud *node)
{
  if (node == NULL)
  {
    return NULL;
  }
  switch (node->type)
  {
  case expr_arith:
    return node->lunion.oper_arith.gauche;
  case expr_bool:
    return node->lunion.oper_bool.gauche;
  case ifelse:
    return node->lunion.ifelseNoeud.condition;
  case whiledo:
    return node->lunion.whileDONoeud.condition;

  case Sequencecommande:
    return node->lunion.suiteDeCommande.premiere;
  case affectation:

    return node->lunion.affectation.variable;

  default:
    return NULL;
  }
}
Noeud *getNodeRightChild(Noeud *node)
{
  if (node == NULL)
  {
    return NULL;
  }
  switch (node->type)
  {
  case expr_arith:
    return node->lunion.oper_arith.droite;
  case expr_bool:
    return node->lunion.oper_bool.droite;
  case ifelse:
    return node->lunion.ifelseNoeud.siFaux;
  case whiledo:
    return node->lunion.whileDONoeud.leDo;
  case affectation:

    return node->lunion.affectation.valeur;

  case Sequencecommande:
    return node->lunion.suiteDeCommande.deuxieme;

  default:
    return NULL;
  }
}
Noeud *getNodeMiddleChild(Noeud *node)
{
  if (node == NULL && node->type != ifelse)
  {
    return NULL;
  }
  return node->lunion.ifelseNoeud.siVrai;
}
int getValue(Noeud *n, liste_v *l)
{
  // printf("je pass par la fonction getValue recurssivement \n");
  if (n != NULL)
  {
    if (n->type == affectation) // dans un bloc if( i1=1 ) alors i1=1 retourne 1 -> vrai
    {
      return 1;
    }
    else if (n->type == entier)
    {
      return n->lunion.i;
    }
    else if (n->type == variable) // parc exemple if( i1 == i2) en va avoir recours au liste de variable pour savoir la valeur
    {
      return getValeurAssociee(n->lunion.varname, l);
    }
    else if (n->type == expr_arith)
    {
      switch (n->lunion.oper_arith.op)
      {
      case op_PLUS:
        // printf("la valeur assosier à %s est %d et la somme  est %d", n->lunion.oper_arith.gauche->lunion.varname, getValeurAssociee(n->lunion.oper_arith.gauche->lunion.varname, l), getValue(n->lunion.oper_arith.gauche, l) + getValue(n->lunion.oper_arith.droite, l));
        return getValue(n->lunion.oper_arith.gauche, l) + getValue(n->lunion.oper_arith.droite, l);
      case op_MULT:
        return getValue(n->lunion.oper_arith.gauche, l) * getValue(n->lunion.oper_arith.droite, l);
      case op_DIV:
        return getValue(n->lunion.oper_arith.gauche, l) / getValue(n->lunion.oper_arith.droite, l);
      case op_MOIN:
        return getValue(n->lunion.oper_arith.gauche, l) - getValue(n->lunion.oper_arith.droite, l);
      }
    }
    else if (n->type == expr_bool) // ici ca peut etre une op_bool entre deux expression arith
    {
      Noeud *g = getNodeLeftChild(n);
      int valeurG = getValue(g, l);
      Noeud *d = getNodeRightChild(n);
      int valeurD = getValue(d, l);
      if (g != NULL && d != NULL)
      { // tout les cas sauf le NON !
        switch (n->lunion.oper_bool.op)
        {
        case op_AND:
          if (valeurG > 0 && valeurD > 0)
          {
            return 1;
          }
          else
          {
            return 0;
          }
        case op_OR:
          if (valeurG > 0 || valeurD > 0)
          {
            return 1;
          }
          else
          {
            return 0;
          }
        case op_DIFF:
          if (valeurG != valeurD)
          {
            return 1;
          }
          else
          {
            return 0;
          }
        case op_EQ:
          if (valeurG == valeurD)
          {
            return 1;
          }
          else
          {
            return 0;
          }
        case op_SUP:
          if (valeurG > valeurD)
          {
            return 1;
          }
          else
          {
            return 0;
          }
        case op_SUPE:
          if (valeurG >= valeurD)
          {
            return 1;
          }
          else
          {
            return 0;
          }
        case op_INF:
          if (valeurG < valeurD)
          {
            return 1;
          }
          else
          {
            return 0;
          }
        case op_INFE:
          if (valeurG <= valeurD)
          {
            return 1;
          }
          else
          {
            return 0;
          }
        }
      }
      else if (d != NULL && n->lunion.oper_bool.op == op_NOT)
      {
        return valeurG + 1 % 2;
      }
    }
  }
}
