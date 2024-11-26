/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    EQ = 258,                      /* EQ  */
    SUPE = 259,                    /* SUPE  */
    INFE = 260,                    /* INFE  */
    INF = 261,                     /* INF  */
    SUP = 262,                     /* SUP  */
    AND = 263,                     /* AND  */
    OR = 264,                      /* OR  */
    NOT = 265,                     /* NOT  */
    AFFECTATION = 266,             /* AFFECTATION  */
    PVIRGULE = 267,                /* PVIRGULE  */
    POUVERT = 268,                 /* POUVERT  */
    PFERME = 269,                  /* PFERME  */
    PLUS = 270,                    /* PLUS  */
    MOIN = 271,                    /* MOIN  */
    MULT = 272,                    /* MULT  */
    DIV = 273,                     /* DIV  */
    AOUVERT = 274,                 /* AOUVERT  */
    AFERME = 275,                  /* AFERME  */
    IF = 276,                      /* IF  */
    ELSE = 277,                    /* ELSE  */
    WHILE = 278,                   /* WHILE  */
    DO = 279,                      /* DO  */
    SKIP = 280,                    /* SKIP  */
    TRUETOKEN = 281,               /* TRUETOKEN  */
    FALSETOKEN = 282,              /* FALSETOKEN  */
    DIFF = 283,                    /* DIFF  */
    NUMBER = 284,                  /* NUMBER  */
    IDENTIFIER = 285               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define EQ 258
#define SUPE 259
#define INFE 260
#define INF 261
#define SUP 262
#define AND 263
#define OR 264
#define NOT 265
#define AFFECTATION 266
#define PVIRGULE 267
#define POUVERT 268
#define PFERME 269
#define PLUS 270
#define MOIN 271
#define MULT 272
#define DIV 273
#define AOUVERT 274
#define AFERME 275
#define IF 276
#define ELSE 277
#define WHILE 278
#define DO 279
#define SKIP 280
#define TRUETOKEN 281
#define FALSETOKEN 282
#define DIFF 283
#define NUMBER 284
#define IDENTIFIER 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "rendu.y"

    int ivar;
    char * svar;     // Pour les chaînes de caractères (identifiants de variables)
    Noeud *node;    // Un seul type pour tous les éléments manipulés par Yacc sauf les variables et les entiers

#line 133 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
