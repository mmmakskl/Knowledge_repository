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

#ifndef YY_YY_SC2V_STEP1_TAB_H_INCLUDED
# define YY_YY_SC2V_STEP1_TAB_H_INCLUDED
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
    NUMBER = 258,                  /* NUMBER  */
    WORD = 259,                    /* WORD  */
    SC_REG = 260,                  /* SC_REG  */
    SC_SIGREG = 261,               /* SC_SIGREG  */
    BOOL = 262,                    /* BOOL  */
    BIGGER = 263,                  /* BIGGER  */
    LOWER = 264,                   /* LOWER  */
    OPENKEY = 265,                 /* OPENKEY  */
    CLOSEKEY = 266,                /* CLOSEKEY  */
    WRITE = 267,                   /* WRITE  */
    SYMBOL = 268,                  /* SYMBOL  */
    NEWLINE = 269,                 /* NEWLINE  */
    ENUM = 270,                    /* ENUM  */
    INCLUDE = 271,                 /* INCLUDE  */
    COLON = 272,                   /* COLON  */
    SEMICOLON = 273,               /* SEMICOLON  */
    RANGE = 274,                   /* RANGE  */
    OPENPAR = 275,                 /* OPENPAR  */
    CLOSEPAR = 276,                /* CLOSEPAR  */
    TWODOUBLEPOINTS = 277,         /* TWODOUBLEPOINTS  */
    OPENCORCH = 278,               /* OPENCORCH  */
    CLOSECORCH = 279,              /* CLOSECORCH  */
    SWITCH = 280,                  /* SWITCH  */
    CASE = 281,                    /* CASE  */
    DEFAULT = 282,                 /* DEFAULT  */
    BREAK = 283,                   /* BREAK  */
    HEXA = 284,                    /* HEXA  */
    DEFINE = 285,                  /* DEFINE  */
    READ = 286,                    /* READ  */
    TRANSLATEOFF = 287,            /* TRANSLATEOFF  */
    TRANSLATEON = 288,             /* TRANSLATEON  */
    VERILOGBEGIN = 289,            /* VERILOGBEGIN  */
    VERILOGEND = 290,              /* VERILOGEND  */
    TAB = 291,                     /* TAB  */
    DOLLAR = 292,                  /* DOLLAR  */
    MINEQ = 293,                   /* MINEQ  */
    VOID = 294,                    /* VOID  */
    TTRUE = 295,                   /* TTRUE  */
    TFALSE = 296,                  /* TFALSE  */
    ENDFUNC = 297,                 /* ENDFUNC  */
    INC = 298,                     /* INC  */
    DEC = 299,                     /* DEC  */
    INTEGER = 300,                 /* INTEGER  */
    EQUALS = 301,                  /* EQUALS  */
    PIFDEF = 302,                  /* PIFDEF  */
    PIFNDEF = 303,                 /* PIFNDEF  */
    PENDDEF = 304,                 /* PENDDEF  */
    PELSE = 305,                   /* PELSE  */
    COMMENT = 306,                 /* COMMENT  */
    STRUCT = 307,                  /* STRUCT  */
    DOT = 308                      /* DOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SC2V_STEP1_TAB_H_INCLUDED  */
