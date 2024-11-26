#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "Affichage.h"

void printNode(Noeud *root, liste_v *l)
{

  if (root == NULL)
  {
    printf("videe\n");
  }
  switch (root->type)
  {
  case variable:
    printf("VARIABLE : %s   \n", root->lunion.varname);

    break;
  case entier:
    printf("ENTIER :  %d\n", root->lunion.i);
    break;

  case skip:
    printf("BREAK\n");
    break;
    /* case Sequencecommande:
       printf("COMMANDE SEQUENC : \n");
       printf("  ACCOLADE_O\n");
       printNode(getNodeLeftChild(root), l);
       printNode(getNodeRightChild(root), l);
       printf("  ACOLLADE_F\n");
       break;
       */
  case affectation:
    printf("AFFETATION : \n"); // on appel printnode sur noeud g puis noeud droite le droite peut etre une expression arithmetique
    printf("    ");
    printNode(getNodeLeftChild(root), l);
    printf("    ");
    printNode(getNodeRightChild(root), l);
    break;
  case Sequencecommande:
    printNode(getNodeLeftChild(root), l);
    printNode(getNodeRightChild(root), l);
    break;
  case expr_arith:
    printf("EXPRESSION ARITHMETIQUE : \n");
    printf("  PARTIE GAUCHE:");
    printf("        ");
    printNode(getNodeLeftChild(root), l);
    printf("        ");
    switch (root->lunion.oper_arith.op)
    {
    case '+':
      printf("OP_PLUS");
      break;
    case '-':
      printf("OP_MOIN");
      break;
    case '*':
      printf("OP_MULT");
      break;
    case '/':
      printf("OP_DIV");
      break;
    }
    printf("\n");
    printf("  PARTIE DROITE:");
    printf("        ");
    printNode(getNodeRightChild(root), l);
    printf("\n");
    break;
  case expr_bool:
    printf("EXPRESSION BOOL : \n");
    printf("  PARTIE GAUCHE:");
    printf("        ");
    printNode(getNodeLeftChild(root), l);
    printf("        ");
    switch (root->lunion.oper_arith.op)
    {
    case op_SUP:
      printf("OP_SUP");
      break;
    case op_SUPE:
      printf("OP_SUPE");
      break;
    case op_INF:
      printf("OP_INF");
      break;
    case op_INFE:
      printf("OP_INFE");
      break;
    case op_EQ:
      printf("OP_EQ");
      break;
    case op_DIFF:
      printf("OP_DIFF");
      break;
    case op_NOT:
      printf("OP_NOT");
      break;
    }
    if (root->lunion.oper_bool.droite != NULL)
    {
      printf("\n");
      printf("  PARTIE Droite:");
      printf("        ");
      printNode(getNodeRightChild(root), l);
    }
    printf("\n");
    break;

  case whiledo:
    printf("WHILE : \n");
    printf("  PARENTH_O\n");
    printf("  CONDITION : \n");
    printf("    ");
    printNode(getNodeLeftChild(root), l);
    printf("  PARENTH_F");
    printf("  DO BODY : \n");
    printNode(getNodeRightChild(root), l);
    printf("\n");
    break;
  case ifelse:
    printf("IF : \n");
    printf("  CONDITION : \n");
    printf("    ");
    printNode(getNodeLeftChild(root), l);
    printf("THEN : \n");
    printf("  BLOC SI VRAI : \n");
    printf("  ACCOLADE_O\n");
    printNode(getNodeMiddleChild(root), l);
    printf("  ACCOLADE_F\n");
    printf("ELSE : \n");
    printf("  BLOC SI FAUX : \n");
    printf("  ACCOLADE_O\n");
    printNode(getNodeRightChild(root), l);
    printf("  ACCOLADE_F\n");
    printf("\n");
    break;
  }
}