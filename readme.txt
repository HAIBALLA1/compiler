  Projet TP3 : 
	->Hamza LAOUNI  12212533
	->HAIBALLA El Varougou  12311447
 
 
 
 la gestion des variables et leur ajout dans une liste globale doit être faite par le parser (analyseur syntaxique), car le parser est responsable de la structure grammaticale et de l'ordonnancement logique des éléments. Le scanner (analyseur lexical) peut identifier les tokens, mais le parser est mieux placé pour gérer les structures de données complexes telles que les listes de variables.
 
 
 
On a tout fait sauf qu'il y a un probleme de comprhension dans la question derniere 

on a bien mis à jour la liste des variable afin qu'elle modifie les valeur , pour chaque affectation , sauf que cela s'opere meme dans les bloc de if et else meme si on sait pas si la condition est satisfaite ou pas 


on fait des test et des captures : dans la capture "arbre if else parite 1"  j'ai expres afficher la liste au fur et a mesure pour visualiser la liste  pour voir comment elle s'actualliser en chaque affectation .


pour compiler :     -> yacc -d rendu.y
		    -> lex rendu.l
		    -> gcc lex.yy.c y.tab.c structs.c Affichage.c -o ehm

	veuillez appuier sur ctrl + D pour le fin de flux d'entree 

Merci à vous! 
