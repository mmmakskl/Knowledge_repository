/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 22 "sc2v_step1.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sglib.h"
#include "sc2v_step1.h"

  extern int yyparse(void);
  int yylex(void);
	
  int lineno = 1;
  int processfound = 0;
  int switchfound = 0;
  int lastswitch=0;
  int switchparenthesis[256];
  int ifdeffound = 0;
  char *processname, *processname2;
  char *fileregs;
  char *filename;
  int openedkeys = 0;
  int newline = 0;
  int reg_found = 0;
  int sigreg_found = 0;
  int reglenght = 0;
  int writelenght = 0;
  int array_size=0;
  int integer_found=0;
  int regs_end;
  int i = 0;			//for loops counter
  FILE *file;
  FILE *regs_file;
  char *regname, *regname2;
  char *lastword;		// Stores last WORD for use it in WRITE
  char *file_defines;
  FILE *FILE_DEFINES;
  char *file_writes;
  FILE *FILE_WRITES;		//FILE to store .write to know if it is a wire or reg
  int definefound = 0;
  int defineinvocationfound = 0;
  int opencorchfound = 0;
  int defineparenthesis = 0;
  int openedcase = 0;
  int writingvar=0;

  int default_break_found = 0;
  int default_found;

  int struct_found=0;
  int end_struct=0;
  int ignore_semicolon=0;
  char *structname;

//Directives variables
  int translate;
  int verilog;
  int writemethod;

  void yyerror (const char *str)
  {
    fprintf (stderr, "line: %d error: %s\n", lineno, str);
  }

  int yywrap ()
  {
    return 1;
  }

  int main ()
  {
    int i;

    defineslist = NULL;
    regslist = NULL;
    structslist = NULL;
    structsreglist = NULL;

    fprintf (stderr, "\nSystemC to Verilog Translator v0.6");
    fprintf (stderr,
	     "\nProvided by URJC(Universidad Rey Juan Carlos)\nhttp://gdhwsw.escet.urjc.es\n\n");
    fprintf (stderr, "Parsing implementation file.......\n\n");

    processname = (char *) malloc (256 * sizeof (char));
    processname2 = (char *) malloc (256 * sizeof (char));
    fileregs = (char *) malloc (256 * sizeof (char));

    file_defines = (char *) malloc (256 * sizeof (char));
    strcpy (file_defines, (char *) "file_defines.sc2v");
    FILE_DEFINES = fopen (file_defines, (char *) "w");

    file_writes = (char *) malloc (256 * sizeof (char));
    strcpy (file_writes, (char *) "file_writes.sc2v");
    FILE_WRITES = fopen (file_writes, (char *) "w");

    lastword = (char *) malloc (sizeof (char) * 256);
    structname = (char *) malloc (sizeof (char) * 256);

    for (i = 0; i < 256; i++)
      switchparenthesis[i] = 0;

    translate = 1;
    verilog = 0;
    writemethod = 0;

    FILE *yyin = stdin;
    FILE *yyout = stdout;
    yyparse();
    fclose (FILE_WRITES);
    fclose (FILE_DEFINES);

    fprintf (stderr, "\nDone\n\n");
  }


#line 185 "sc2v_step1.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sc2v_step1.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_WORD = 4,                       /* WORD  */
  YYSYMBOL_SC_REG = 5,                     /* SC_REG  */
  YYSYMBOL_SC_SIGREG = 6,                  /* SC_SIGREG  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_BIGGER = 8,                     /* BIGGER  */
  YYSYMBOL_LOWER = 9,                      /* LOWER  */
  YYSYMBOL_OPENKEY = 10,                   /* OPENKEY  */
  YYSYMBOL_CLOSEKEY = 11,                  /* CLOSEKEY  */
  YYSYMBOL_WRITE = 12,                     /* WRITE  */
  YYSYMBOL_SYMBOL = 13,                    /* SYMBOL  */
  YYSYMBOL_NEWLINE = 14,                   /* NEWLINE  */
  YYSYMBOL_ENUM = 15,                      /* ENUM  */
  YYSYMBOL_INCLUDE = 16,                   /* INCLUDE  */
  YYSYMBOL_COLON = 17,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 18,                 /* SEMICOLON  */
  YYSYMBOL_RANGE = 19,                     /* RANGE  */
  YYSYMBOL_OPENPAR = 20,                   /* OPENPAR  */
  YYSYMBOL_CLOSEPAR = 21,                  /* CLOSEPAR  */
  YYSYMBOL_TWODOUBLEPOINTS = 22,           /* TWODOUBLEPOINTS  */
  YYSYMBOL_OPENCORCH = 23,                 /* OPENCORCH  */
  YYSYMBOL_CLOSECORCH = 24,                /* CLOSECORCH  */
  YYSYMBOL_SWITCH = 25,                    /* SWITCH  */
  YYSYMBOL_CASE = 26,                      /* CASE  */
  YYSYMBOL_DEFAULT = 27,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 28,                     /* BREAK  */
  YYSYMBOL_HEXA = 29,                      /* HEXA  */
  YYSYMBOL_DEFINE = 30,                    /* DEFINE  */
  YYSYMBOL_READ = 31,                      /* READ  */
  YYSYMBOL_TRANSLATEOFF = 32,              /* TRANSLATEOFF  */
  YYSYMBOL_TRANSLATEON = 33,               /* TRANSLATEON  */
  YYSYMBOL_VERILOGBEGIN = 34,              /* VERILOGBEGIN  */
  YYSYMBOL_VERILOGEND = 35,                /* VERILOGEND  */
  YYSYMBOL_TAB = 36,                       /* TAB  */
  YYSYMBOL_DOLLAR = 37,                    /* DOLLAR  */
  YYSYMBOL_MINEQ = 38,                     /* MINEQ  */
  YYSYMBOL_VOID = 39,                      /* VOID  */
  YYSYMBOL_TTRUE = 40,                     /* TTRUE  */
  YYSYMBOL_TFALSE = 41,                    /* TFALSE  */
  YYSYMBOL_ENDFUNC = 42,                   /* ENDFUNC  */
  YYSYMBOL_INC = 43,                       /* INC  */
  YYSYMBOL_DEC = 44,                       /* DEC  */
  YYSYMBOL_INTEGER = 45,                   /* INTEGER  */
  YYSYMBOL_EQUALS = 46,                    /* EQUALS  */
  YYSYMBOL_PIFDEF = 47,                    /* PIFDEF  */
  YYSYMBOL_PIFNDEF = 48,                   /* PIFNDEF  */
  YYSYMBOL_PENDDEF = 49,                   /* PENDDEF  */
  YYSYMBOL_PELSE = 50,                     /* PELSE  */
  YYSYMBOL_COMMENT = 51,                   /* COMMENT  */
  YYSYMBOL_STRUCT = 52,                    /* STRUCT  */
  YYSYMBOL_DOT = 53,                       /* DOT  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_commands = 55,                  /* commands  */
  YYSYMBOL_command = 56,                   /* command  */
  YYSYMBOL_struct_access = 57,             /* struct_access  */
  YYSYMBOL_minorequal = 58,                /* minorequal  */
  YYSYMBOL_endfunc = 59,                   /* endfunc  */
  YYSYMBOL_voidword = 60,                  /* voidword  */
  YYSYMBOL_include = 61,                   /* include  */
  YYSYMBOL_dollar = 62,                    /* dollar  */
  YYSYMBOL_tab = 63,                       /* tab  */
  YYSYMBOL_read = 64,                      /* read  */
  YYSYMBOL_definewordsimple = 65,          /* definewordsimple  */
  YYSYMBOL_defineword = 66,                /* defineword  */
  YYSYMBOL_definenumber = 67,              /* definenumber  */
  YYSYMBOL_definemacro = 68,               /* definemacro  */
  YYSYMBOL_void = 69,                      /* void  */
  YYSYMBOL_sc_reg = 70,                    /* sc_reg  */
  YYSYMBOL_sc_sigreg = 71,                 /* sc_sigreg  */
  YYSYMBOL_integer = 72,                   /* integer  */
  YYSYMBOL_bool = 73,                      /* bool  */
  YYSYMBOL_range = 74,                     /* range  */
  YYSYMBOL_number = 75,                    /* number  */
  YYSYMBOL_increment = 76,                 /* increment  */
  YYSYMBOL_decrement = 77,                 /* decrement  */
  YYSYMBOL_word = 78,                      /* word  */
  YYSYMBOL_symbol = 79,                    /* symbol  */
  YYSYMBOL_equal = 80,                     /* equal  */
  YYSYMBOL_write = 81,                     /* write  */
  YYSYMBOL_newline = 82,                   /* newline  */
  YYSYMBOL_colon = 83,                     /* colon  */
  YYSYMBOL_semicolon = 84,                 /* semicolon  */
  YYSYMBOL_openpar = 85,                   /* openpar  */
  YYSYMBOL_closepar = 86,                  /* closepar  */
  YYSYMBOL_opencorch = 87,                 /* opencorch  */
  YYSYMBOL_closecorch = 88,                /* closecorch  */
  YYSYMBOL_openkey = 89,                   /* openkey  */
  YYSYMBOL_closekey = 90,                  /* closekey  */
  YYSYMBOL_bigger = 91,                    /* bigger  */
  YYSYMBOL_lower = 92,                     /* lower  */
  YYSYMBOL_switch = 93,                    /* switch  */
  YYSYMBOL_case_number = 94,               /* case_number  */
  YYSYMBOL_case_hexnumber = 95,            /* case_hexnumber  */
  YYSYMBOL_case_hexword = 96,              /* case_hexword  */
  YYSYMBOL_case_hexnumberword = 97,        /* case_hexnumberword  */
  YYSYMBOL_case_word = 98,                 /* case_word  */
  YYSYMBOL_case_default = 99,              /* case_default  */
  YYSYMBOL_case_only = 100,                /* case_only  */
  YYSYMBOL_break = 101,                    /* break  */
  YYSYMBOL_hexa = 102,                     /* hexa  */
  YYSYMBOL_translateoff = 103,             /* translateoff  */
  YYSYMBOL_translateon = 104,              /* translateon  */
  YYSYMBOL_verilogbegin = 105,             /* verilogbegin  */
  YYSYMBOL_verilogend = 106,               /* verilogend  */
  YYSYMBOL_ifdef = 107,                    /* ifdef  */
  YYSYMBOL_ifndef = 108,                   /* ifndef  */
  YYSYMBOL_endif = 109,                    /* endif  */
  YYSYMBOL_pelse = 110,                    /* pelse  */
  YYSYMBOL_ttrue = 111,                    /* ttrue  */
  YYSYMBOL_tfalse = 112,                   /* tfalse  */
  YYSYMBOL_comment = 113,                  /* comment  */
  YYSYMBOL_struct_dec = 114                /* struct_dec  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   94

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   142,   142,   143,   146,   148,   150,   152,   154,   156,
     158,   160,   162,   164,   166,   168,   170,   172,   174,   176,
     178,   180,   182,   184,   186,   188,   190,   192,   194,   196,
     198,   200,   202,   204,   206,   208,   210,   212,   214,   216,
     218,   220,   222,   224,   226,   228,   230,   232,   234,   236,
     238,   240,   242,   244,   246,   248,   250,   252,   254,   256,
     258,   260,   264,   290,   306,   324,   333,   342,   351,   359,
     368,   389,   412,   436,   455,   472,   487,   502,   517,   536,
     553,   571,   587,   603,   750,   772,   791,   815,   837,   861,
     895,   920,   945,   971,   997,  1028,  1083,  1102,  1122,  1154,
    1179,  1205,  1231,  1257,  1288,  1311,  1320,  1343,  1362,  1370,
    1378,  1386,  1394,  1414,  1434,  1453,  1472,  1488,  1503,  1527
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "WORD",
  "SC_REG", "SC_SIGREG", "BOOL", "BIGGER", "LOWER", "OPENKEY", "CLOSEKEY",
  "WRITE", "SYMBOL", "NEWLINE", "ENUM", "INCLUDE", "COLON", "SEMICOLON",
  "RANGE", "OPENPAR", "CLOSEPAR", "TWODOUBLEPOINTS", "OPENCORCH",
  "CLOSECORCH", "SWITCH", "CASE", "DEFAULT", "BREAK", "HEXA", "DEFINE",
  "READ", "TRANSLATEOFF", "TRANSLATEON", "VERILOGBEGIN", "VERILOGEND",
  "TAB", "DOLLAR", "MINEQ", "VOID", "TTRUE", "TFALSE", "ENDFUNC", "INC",
  "DEC", "INTEGER", "EQUALS", "PIFDEF", "PIFNDEF", "PENDDEF", "PELSE",
  "COMMENT", "STRUCT", "DOT", "$accept", "commands", "command",
  "struct_access", "minorequal", "endfunc", "voidword", "include",
  "dollar", "tab", "read", "definewordsimple", "defineword",
  "definenumber", "definemacro", "void", "sc_reg", "sc_sigreg", "integer",
  "bool", "range", "number", "increment", "decrement", "word", "symbol",
  "equal", "write", "newline", "colon", "semicolon", "openpar", "closepar",
  "opencorch", "closecorch", "openkey", "closekey", "bigger", "lower",
  "switch", "case_number", "case_hexnumber", "case_hexword",
  "case_hexnumberword", "case_word", "case_default", "case_only", "break",
  "hexa", "translateoff", "translateon", "verilogbegin", "verilogend",
  "ifdef", "ifndef", "endif", "pelse", "ttrue", "tfalse", "comment",
  "struct_dec", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-3)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,     0,    -3,    -3,    21,     6,    13,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    24,    -3,
      -3,    -3,    -3,    -3,    50,    45,    41,    -3,    56,    42,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    51,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    59,    -3,
      -3,    63,    65,    66,    68,    60,    62,    -3,    -2,    -3,
      -3,    52,    55,    -3,    57,    -3,    70,    72,    64,    -3,
      -3,    53,    69,    -3,    -3,    67,    -3,    -3,    -3,    -3,
      80,    71,    -3,    -3,    -3,    73,    -3,    -3
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    80,    83,     0,     0,    78,    96,    97,
      94,    95,    86,    84,    87,    66,    88,    89,     0,    90,
      91,    92,    93,    98,     0,     0,     0,   107,     0,     0,
     108,   109,   110,   111,    68,    67,    63,    65,   116,   117,
      64,    77,    85,   112,   113,   114,   115,   118,     0,     3,
      61,    59,     5,     6,     7,     8,     9,    10,    44,    43,
      45,    42,    27,    11,    12,    13,    15,    24,    14,    56,
      57,    16,    17,    58,    18,    19,    22,    23,    25,    26,
      28,    29,    20,    21,    30,    31,    32,    34,    35,    36,
      37,    38,    39,    33,    40,    41,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    60,     4,     0,    81,
      82,     0,     0,     0,     0,     0,     0,   105,     0,   104,
     106,    70,     0,   119,     0,    62,     0,     0,     0,    99,
     103,     0,     0,    72,    71,     0,    69,    74,    75,    76,
       0,     0,   100,   101,    73,     0,   102,    79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       2,   131,   132,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,   112,    15,    16,    17,    18,
      19,    20,   113,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,   108,   114,    41,    42,    43,    44,    45,
      46,    47,    48,   115,   116,   133,   134,   141,   119,   120,
     121,   123,   122,   124,   109,   110,   142,   125,   126,   127,
     117,   128,   135,   129,   111,   130,   136,   137,   138,   118,
     139,   140,   143,   145,   146,     0,     0,     0,   144,     0,
       0,     0,     0,     0,   147
};

static const yytype_int8 yycheck[] =
{
       0,     3,     4,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     9,    16,    17,    18,    19,
      20,    21,     9,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    22,    20,    45,    46,    47,    48,    49,
      50,    51,    52,     3,     4,     3,     4,     4,    13,    18,
       4,    10,    20,     4,    43,    44,    13,     4,     3,     3,
      20,     3,    20,    13,    53,    13,    21,    20,     8,    29,
       8,    17,    13,     3,    13,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    55,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    16,    17,    18,    19,    20,
      21,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    45,    46,    47,    48,    49,    50,    51,    52,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    22,    43,
      44,    53,     9,     9,    20,     3,     4,    20,    29,    13,
      18,     4,    20,    10,     4,     4,     3,     3,     3,    13,
      13,     3,     4,     3,     4,    20,    21,    20,     8,     8,
      17,     4,    13,    13,    21,     3,    13,    21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     4,     4,     4,     4,     1,     1,     6,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     5,     3,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 62: /* struct_access: WORD DOT WORD  */
#line 265 "sc2v_step1.y"
{

/*Struct access
 Check if it is a var acess or a reg*/
 if (newline){
   for (i = 0; i < openedkeys; i++)
      fprintf (file, "   ");
 }

 strcpy(structname,(char *)yyvsp[0]);
 strcat(structname,(char *)yyvsp[-2]);   	     
 regname2 = IsReg (regslist, structname);

 if (regname2 == NULL){
  fprintf (file, "%s ", structname);
 }else{
  fprintf (file, "%s", regname2);
}
  newline = 0;

 
 /*printf("Access to struct %s.%s\n",(char *)$1,(char *)$3);*/
}
#line 1422 "sc2v_step1.tab.c"
    break;

  case 63: /* minorequal: MINEQ  */
#line 291 "sc2v_step1.y"
{
 //This rule is needed because <= in the step two could be confused with a non-blocking assignment
 defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  fprintf (file, "<1+");
	}
    }
  else if (verilog == 1)
    fprintf (file, "<=");
}
#line 1440 "sc2v_step1.tab.c"
    break;

  case 64: /* endfunc: ENDFUNC  */
#line 307 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  for (i = 0; i < openedkeys; i++)
	    fprintf (file, "   ");
	  fprintf (file, "%s = ", processname);
	}
    }
  else if (verilog == 1)
    fprintf (file, "return ");
}
#line 1459 "sc2v_step1.tab.c"
    break;

  case 65: /* voidword: VOID  */
#line 325 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (verilog == 1)
    fprintf (file, " void");
}
#line 1469 "sc2v_step1.tab.c"
    break;

  case 66: /* include: INCLUDE  */
#line 334 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (verilog == 1)
    fprintf (file, " #include");
}
#line 1479 "sc2v_step1.tab.c"
    break;

  case 67: /* dollar: DOLLAR  */
#line 343 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (verilog == 1)
    fprintf (file, " $");
}
#line 1489 "sc2v_step1.tab.c"
    break;

  case 68: /* tab: TAB  */
#line 352 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (verilog == 1)
    fprintf (file, " \t");
}
#line 1499 "sc2v_step1.tab.c"
    break;

  case 69: /* read: READ OPENPAR CLOSEPAR  */
#line 360 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (verilog == 1)
    fprintf (file, ".read()");

}
#line 1510 "sc2v_step1.tab.c"
    break;

  case 70: /* definewordsimple: DEFINE WORD  */
#line 369 "sc2v_step1.y"
{

  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  fprintf (file, "`define %s\n", (char *) yyvsp[0]);
	}
      else
	{
	  fprintf (FILE_DEFINES, "`define %s\n", (char *) yyvsp[0]);
	}
    }
  else if (verilog == 1)
    fprintf (file, "#define %s\n", (char *) yyvsp[0]);

}
#line 1533 "sc2v_step1.tab.c"
    break;

  case 71: /* defineword: DEFINE WORD WORD  */
#line 390 "sc2v_step1.y"
{

  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  fprintf (file, "`define %s %s\n", (char *) yyvsp[-1], (char *) yyvsp[0]);
	  defineslist = InsertDefine (defineslist, (char *) yyvsp[-1]);
	}
      else
	{
	  fprintf (FILE_DEFINES, "`define %s %s\n", (char *) yyvsp[-1], (char *) yyvsp[0]);
	  defineslist = InsertDefine (defineslist, (char *) yyvsp[-1]);
	}
    }
  else if (verilog == 1)
    fprintf (file, "#define %s %s\n", (char *) yyvsp[-1], (char *) yyvsp[0]);

}
#line 1558 "sc2v_step1.tab.c"
    break;

  case 72: /* definenumber: DEFINE WORD NUMBER  */
#line 413 "sc2v_step1.y"
{

  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  fprintf (file, "`define %s %d\n", (char *) yyvsp[-1], (int) yyvsp[0]);
	  defineslist = InsertDefine (defineslist, (char *) yyvsp[-1]);
	}
      else
	{
	  fprintf (FILE_DEFINES, "`define %s %d\n", (char *) yyvsp[-1], (int) yyvsp[0]);
	  defineslist = InsertDefine (defineslist, (char *) yyvsp[-1]);
	}
    }
  else if (verilog == 1)
    fprintf (file, "#define %s %d\n", (char *) yyvsp[-1], (int) yyvsp[0]);

}
#line 1583 "sc2v_step1.tab.c"
    break;

  case 73: /* definemacro: DEFINE WORD OPENPAR CLOSEPAR  */
#line 437 "sc2v_step1.y"
{
  defineparenthesis = 0;
  //Macro found
  if (translate == 1 && verilog == 0)
    {
      defineslist = InsertDefine (defineslist, (char *) yyvsp[-2]);

      definefound = 1;
      if (processfound)
	fprintf (file, "`define %s ", (char *) yyvsp[-2]);
      else
	fprintf (FILE_DEFINES, "`define %s ", (char *) yyvsp[-2]);
    }
  else if (verilog == 1)
    fprintf (file, "#define %s ()", (char *) yyvsp[-2]);
}
#line 1604 "sc2v_step1.tab.c"
    break;

  case 74: /* void: WORD TWODOUBLEPOINTS WORD OPENPAR  */
#line 456 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      strcpy (processname, (char *) yyvsp[0]);
      strcpy (processname2, (char *) yyvsp[0]);
      strcat (processname2, (char *) ".sc2v");
      strcpy (fileregs, (char *) yyvsp[0]);
      strcat (fileregs, (char *) "_regs.sc2v");
    }
  else if (verilog == 1)
    fprintf (file, " %s::%s()", (char *) yyvsp[-3], (char *) yyvsp[-1]);

}
#line 1623 "sc2v_step1.tab.c"
    break;

  case 75: /* sc_reg: SC_REG LOWER NUMBER BIGGER  */
#line 473 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  writelenght=1;
	  reglenght = yyvsp[-1];
	  reg_found = 1;
	}
    }
}
#line 1640 "sc2v_step1.tab.c"
    break;

  case 76: /* sc_sigreg: SC_SIGREG LOWER NUMBER BIGGER  */
#line 488 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  writelenght=1;
	  reglenght = yyvsp[-1];
	  sigreg_found = 1;
	}
    }
}
#line 1657 "sc2v_step1.tab.c"
    break;

  case 77: /* integer: INTEGER  */
#line 503 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  fprintf (regs_file, "integer ");
	  integer_found = 1;
	}
    }
}
#line 1673 "sc2v_step1.tab.c"
    break;

  case 78: /* bool: BOOL  */
#line 518 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
  	  writelenght=1;
	  reglenght=0;
	  reg_found = 1;
	}
    }
  else if (verilog == 1)
    fprintf (file, "bool");
}
#line 1692 "sc2v_step1.tab.c"
    break;

  case 79: /* range: RANGE OPENPAR NUMBER COLON NUMBER CLOSEPAR  */
#line 537 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	fprintf (file, "[%d:%d]", yyvsp[-3], yyvsp[-1]);
      else if (definefound)
	fprintf (FILE_DEFINES, "[%d:%d]", yyvsp[-3], yyvsp[-1]);
    }
  else if (verilog == 1)
    fprintf (file, ".range(%d,%d)", yyvsp[-3], yyvsp[-1]);
}
#line 1709 "sc2v_step1.tab.c"
    break;

  case 80: /* number: NUMBER  */
#line 554 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
       if(opencorchfound && (reg_found || sigreg_found))
        fprintf (regs_file, "%d:0",yyvsp[0]-1);
       else
	fprintf (file, "%d", yyvsp[0]);
      else if (definefound)
	fprintf (FILE_DEFINES, "%d", yyvsp[0]);
    }
  else if (verilog == 1)
    fprintf (file, "%d", yyvsp[0]);
}
#line 1729 "sc2v_step1.tab.c"
    break;

  case 81: /* increment: WORD INC  */
#line 572 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
       if (processfound){
        regname2 = IsReg (regslist, (char *) yyvsp[-1]);
        if (regname2 == NULL){
            fprintf (file, "%s=%s+1", (char *) yyvsp[-1],(char *)yyvsp[-1]);
        }else
	    fprintf (file, "%s=%s+1", regname2,regname2);
       }
  else if (verilog == 1)
    fprintf (file, "%s++ ", (char *) yyvsp[-1]);
}
#line 1747 "sc2v_step1.tab.c"
    break;

  case 82: /* decrement: WORD DEC  */
#line 588 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
      if (processfound){
        regname2 = IsReg (regslist, (char *) yyvsp[-1]);
        if (regname2 == NULL){
            fprintf (file, "%s=%s+1", (char *) yyvsp[-1],(char *)yyvsp[-1]);
        }else
	    fprintf (file, "%s=%s+1", regname2,regname2);
      }
  else if (verilog == 1)
    fprintf (file, "%s-- ", (char *) yyvsp[-1]);
}
#line 1765 "sc2v_step1.tab.c"
    break;

  case 83: /* word: WORD  */
#line 604 "sc2v_step1.y"
{

  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
	  if(opencorchfound==0){
		strcpy (lastword, (char *) yyvsp[0]);
	  }
	
      if (processfound)
	{
	  if(lastswitch){
	    openedcase=0;
	  }else if (openedcase){
	      fprintf (file, " :\n");

	      for (i = 0; i < openedkeys; i++)
		fprintf (file, "   ");

              fprintf(file,"begin\n");
	      openedcase=0;
	  }
          if (end_struct){
             end_struct=0;
	     struct_found=0;
	     ignore_semicolon=1;
             structslist=InsertStruct(structslist,(char *)yyvsp[0],structsreglist);

             //ShowStructs(structslist);

             /*Now we should convert all the elements of the struct into regs*/
             StructRegNode *srll;
 	     SGLIB_LIST_MAP_ON_ELEMENTS (StructRegNode,structsreglist, srll,next,
	     {
               if(srll->length==0)
  	         fprintf (regs_file, "reg ");
	       else
   	         fprintf (regs_file, "reg[%d:0] ", (-1 +srll->length));
                 
               regname =(char *) malloc (sizeof (char) * (strlen (srll->name) + 1));
               regname2 = (char *) malloc (sizeof (char) * (strlen (srll->name) + strlen (processname)+strlen((char *)yyvsp[0])) + 1);
	       strcpy (regname, srll->name);
	       strcpy (regname2, srll->name);
	       strcat (regname, (char *)yyvsp[0]);
               strcat (regname2, (char *)yyvsp[0]);
               strcat (regname2, processname);
               fprintf (regs_file, "%s;\n", regname2); /*By the moment no arrays inside the struct supported*/
	     
 	       regslist = InsertReg (regslist, regname, regname2);
  	       free (regname);
	       free (regname2);
               structsreglist=NULL;
	       reg_found=0; /*To avoid arrays in sructs the interpretation finish here*/
          sigreg_found = 0;
             );}

          }else if(struct_found && (reg_found || sigreg_found)){
              structsreglist=InsertStructReg(structsreglist,(char *)yyvsp[0],reglenght);
              
          }else if (reg_found || sigreg_found){
	      if(writelenght){
	       writelenght=0;
  	       if(reglenght==0)
            if(sigreg_found) 
 	            fprintf (regs_file, "reg signed");
            else
               fprintf (regs_file, "reg ");
	       else
            if(sigreg_found)
               fprintf (regs_file, "reg signed [%d:0] ", (-1 +reglenght));
            else
   	        fprintf (regs_file, "reg [%d:0] ", (-1 +reglenght));
	      } 
         
	      regname =	(char *) malloc (sizeof (char) * (strlen ((char *) yyvsp[0]) + 1));
	      regname2 = (char *) malloc (sizeof (char) * (strlen ((char *) yyvsp[0]) + strlen (processname)) + 1);
	      strcpy (regname, (char *) yyvsp[0]);
	      strcpy (regname2, (char *) yyvsp[0]);
	      strcat (regname2, processname);
	      fprintf (regs_file, "%s", regname2);

	      regslist = InsertReg (regslist, regname, regname2);
	      free (regname);
	      free (regname2);
	  }else if(integer_found){
	      regname =	(char *) malloc (sizeof (char) * (strlen ((char *) yyvsp[0]) + 1));
	      regname2 = (char *) malloc (sizeof (char) * (strlen ((char *) yyvsp[0]) + strlen (processname)) + 1);
	      strcpy (regname, (char *) yyvsp[0]);
	      strcpy (regname2, (char *) yyvsp[0]);
	      strcat (regname2, processname);
	      fprintf (regs_file, "%s;\n", regname2);

	      regslist = InsertReg (regslist, regname, regname2);

	      //After adding to list print it
	      fprintf (file, "%s ", regname2);
              integer_found=0;
	      free (regname);
	      free (regname2);
     
	  }else{
              
	      if (newline){
                for (i = 0; i < openedkeys; i++)
                  fprintf (file, "   ");
              }
	     
	      regname2 = IsReg (regslist, (char *) yyvsp[0]);
	      if (regname2 == NULL){
                if (IsDefine (defineslist, (char *) yyvsp[0])){
		   if (ifdeffound == 0){
                      fprintf (file, "`%s", (char *) yyvsp[0]);
                      defineinvocationfound = 1;
                   }else{
                      fprintf (file, "%s", (char *) yyvsp[0]);
                      ifdeffound = 0;
                   }
                }else{
	           fprintf (file, "%s ", (char *) yyvsp[0]);
	        }
             }else
		fprintf (file, "%s", regname2);

             newline = 0;
	  }

        }else if (definefound)
	{

	  if (IsDefine (defineslist, (char *) yyvsp[0]))
	    {

	      fprintf (FILE_DEFINES, "`%s", (char *) yyvsp[0]);
	    }
	  else
	    {
	      fprintf (FILE_DEFINES, "%s ", (char *) yyvsp[0]);
	    }
	}
    }
  else if (verilog == 1)
    fprintf (file, "%s ", (char *) yyvsp[0]);
  lastswitch=0;
}
#line 1914 "sc2v_step1.tab.c"
    break;

  case 84: /* symbol: SYMBOL  */
#line 751 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  if (reg_found || sigreg_found)
	    fprintf (regs_file, "%s", (char *) yyvsp[0]);
	  else
	    fprintf (file, "%s", (char *) yyvsp[0]);
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, "%s", (char *) yyvsp[0]);
	}
    }
  else if (verilog == 1)
    fprintf (file, "%s", (char *) yyvsp[0]);
}
#line 1938 "sc2v_step1.tab.c"
    break;

  case 85: /* equal: EQUALS  */
#line 773 "sc2v_step1.y"
{
  defineparenthesis = 0;
  reg_found=0;
  sigreg_found=0;
  if (translate == 1 && verilog == 0)
  {
   if (processfound)
	fprintf (file, "=");
	writingvar=1;
  }
  else if (definefound)
    fprintf (FILE_DEFINES, "=");
  else if (verilog == 1)
    fprintf (file, "=");
    
}
#line 1959 "sc2v_step1.tab.c"
    break;

  case 86: /* write: WRITE  */
#line 792 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      writemethod = 1;
      if (processfound)
	{
	  fprintf (file, " <= ");
	  fprintf (FILE_WRITES, "%s\n", lastword);
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, " <= ");
	}

    }
  else if (verilog == 1)
    {
      fprintf (file, ".write");
    }
}
#line 1985 "sc2v_step1.tab.c"
    break;

  case 87: /* newline: NEWLINE  */
#line 816 "sc2v_step1.y"
{
  defineparenthesis = 0;
  writingvar=0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound & !reg_found & !openedcase & !sigreg_found)
	{
	  fprintf (file, "\n");
	  newline = 1;
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, "\n");
	}

    }
  else if (verilog == 1)
    fprintf (file, "\n");
}
#line 2009 "sc2v_step1.tab.c"
    break;

  case 88: /* colon: COLON  */
#line 838 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  if (reg_found || sigreg_found)
	    {
	      fprintf (regs_file, ",");
	    }
	  else
	    fprintf (file, ",");
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, ",");
	}
    }
  else if (verilog == 1)
    fprintf (file, ",");
}
#line 2035 "sc2v_step1.tab.c"
    break;

  case 89: /* semicolon: SEMICOLON  */
#line 862 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound && !struct_found && !ignore_semicolon)
	{
	  if (reg_found || sigreg_found)
	    {
	      fprintf (regs_file, ";\n");
	      reg_found = 0;
         sigreg_found = 0;
	    }
	  else
	    {
	    if (defineinvocationfound == 0 || writingvar)
		  fprintf (file, ";");
	    }
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, ";");
	}
    }
  else if (verilog == 1)
    fprintf (file, ";");
  
  writingvar=0;
  defineinvocationfound = 0;
  ignore_semicolon=0;
}
#line 2070 "sc2v_step1.tab.c"
    break;

  case 90: /* openpar: OPENPAR  */
#line 896 "sc2v_step1.y"
{
  defineparenthesis = 1;
  if (translate == 1 && verilog == 0 && defineinvocationfound == 0)
    {
      if (processfound)
	{
	  fprintf (file, "(");
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, "(");
	}

    }
  else if (verilog == 1)
    {
      fprintf (file, "(");
    }
  //If par after a sc_reg declaration the declaration is a type cast  
  reg_found=0;
  sigreg_found=0;
}
#line 2097 "sc2v_step1.tab.c"
    break;

  case 91: /* closepar: CLOSEPAR  */
#line 921 "sc2v_step1.y"
{
  if (translate == 1 && verilog == 0)
    {

      if (processfound)
	{
	  if (defineparenthesis == 0)
	    {
	      fprintf (file, ")");
	      defineinvocationfound = 0;
	    }
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, ")");
	}
    }
  else if (verilog == 1)
    fprintf (file, ")");

}
#line 2123 "sc2v_step1.tab.c"
    break;

  case 92: /* opencorch: OPENCORCH  */
#line 946 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  opencorchfound = 1;
	  if (reg_found || sigreg_found)
	    {
	      fprintf (regs_file, "[");
	    }
	  else
	    fprintf (file, "[");
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, "[");

	}
    }
  else if (verilog == 1)
    fprintf (file, "[");
}
#line 2151 "sc2v_step1.tab.c"
    break;

  case 93: /* closecorch: CLOSECORCH  */
#line 972 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	  { 
	  opencorchfound = 0;
	  if (reg_found || sigreg_found)
	    {
	      fprintf (regs_file, "]");
	    }
	  else
	    fprintf (file, "]");
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, "]");
	}
    }
  else if (verilog == 1)
    fprintf (file, "]");
}
#line 2178 "sc2v_step1.tab.c"
    break;

  case 94: /* openkey: OPENKEY  */
#line 998 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      openedkeys++;
      if (!definefound)
	{
	  if (openedkeys == 1)
	    {
	      printf ("Found process %s\n", processname);
	      file = fopen (processname2, (char *) "w");
	      regs_file = fopen (fileregs, (char *) "w");
	      processfound = 1;
	    }
	  if (processfound)
	    if (openedkeys != switchparenthesis[switchfound])
	      {
		fprintf (file, "\n");
		for (i = 0; i < openedkeys; i++)
		  fprintf (file, "   ");
		fprintf (file, "begin\n");
		newline = 1;
	      }
	}
    }
  else if (verilog == 1)
    fprintf (file, "{");
}
#line 2211 "sc2v_step1.tab.c"
    break;

  case 95: /* closekey: CLOSEKEY  */
#line 1029 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if(struct_found){
    end_struct=1;
  }else if (translate == 1 && verilog == 0){
      if (processfound && !definefound){
	  if (openedkeys == switchparenthesis[switchfound] && switchfound > 0){
	      fprintf (file, "\n");
	      if (default_found & !default_break_found){
		  for (i = 0; i < openedkeys - 1; i++)
		    fprintf (file, "   ");
		  fprintf (file, "end\n");
		  default_found = 0;
              }
	      for (i = 0; i < openedkeys - 1; i++)
                fprintf (file, "   ");

              fprintf (file, "endcase\n");
              newline = 1;
              switchparenthesis[switchfound] = 0;
              switchfound--;
          }else{
	      fprintf (file, "\n");
	      for (i = 0; i < openedkeys; i++)
		fprintf (file, "   ");
	      fprintf (file, "end\n");
	      newline = 1;
	  }
      }

      openedkeys--;
      if (definefound)
	{
	  definefound = 0;
	  if (processfound)
	    fprintf (file, "\n//Dummy Comment\n");
	  else
	    fprintf (FILE_DEFINES, "\n//Dummy Comment\n");
	}
      else if (openedkeys == 0)
	{
	  fclose (file);
	  fclose (regs_file);
	  processfound = 0;
          /*Clear process struct list*/
          structslist=NULL;
	}
    }
  else if (verilog == 1)
    fprintf (file, "}");
}
#line 2267 "sc2v_step1.tab.c"
    break;

  case 96: /* bigger: BIGGER  */
#line 1084 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  fprintf (file, ">");
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, ">");
	}
    }
  else if (verilog == 1)
    fprintf (file, ">");
}
#line 2288 "sc2v_step1.tab.c"
    break;

  case 97: /* lower: LOWER  */
#line 1103 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  fprintf (file, "<");
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, "<");
	}
    }
  else if (verilog == 1)
    fprintf (file, "<");
}
#line 2309 "sc2v_step1.tab.c"
    break;

  case 98: /* switch: SWITCH  */
#line 1123 "sc2v_step1.y"
  {
    defineparenthesis = 0;
    lastswitch=1;
    if (translate == 1 && verilog == 0)
      {
	if (processfound && !openedcase)
	  {
	    fprintf (file, "\n");
	    for (i = 0; i < openedkeys; i++)
	      fprintf (file, "   ");
	    fprintf (file, "case");
	    switchfound++;
	    switchparenthesis[switchfound] = openedkeys + 1;
	  }else if (processfound)
	  {
  	    fprintf (file, ":\n");
            for (i = 0; i < openedkeys; i++)
	      fprintf (file, "   ");
	    fprintf(file,"begin\n");
	    for (i = 0; i < openedkeys; i++)
	      fprintf (file, "   ");
	    fprintf (file, "case");
	    switchfound++;
	    switchparenthesis[switchfound] = openedkeys + 1;
	  }
      }
    else if (verilog == 1)
      fprintf (file, "switch");
  }
#line 2343 "sc2v_step1.tab.c"
    break;

  case 99: /* case_number: CASE NUMBER SYMBOL  */
#line 1155 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	 if (!openedcase)
	  for (i = 0; i < openedkeys; i++)
	    fprintf (file, "   ");
	  if (openedcase)
	    fprintf (file, ", %d", yyvsp[-1]);
	  else
	    fprintf (file, "%d", yyvsp[-1]);

	  newline = 1;
	  openedcase = 1;

	}
    }
  else if (verilog == 1)
    fprintf (file, "case %d %s", yyvsp[-1], (char *) yyvsp[0]);
}
#line 2370 "sc2v_step1.tab.c"
    break;

  case 100: /* case_hexnumber: CASE HEXA NUMBER SYMBOL  */
#line 1180 "sc2v_step1.y"
{
  //Is a dec number
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	 if (!openedcase)
	  for (i = 0; i < openedkeys; i++)
	    fprintf (file, "   ");
	  if (openedcase)
	    fprintf (file, ", 'h%d", yyvsp[-1]);
	  else
	    fprintf (file, "'h%d", yyvsp[-1]);

	  newline = 1;
	  openedcase = 1;

	}
    }
  else if (verilog == 1)
    fprintf (file, "case %d %s", yyvsp[-1], (char *) yyvsp[0]);
}
#line 2398 "sc2v_step1.tab.c"
    break;

  case 101: /* case_hexword: CASE HEXA WORD SYMBOL  */
#line 1206 "sc2v_step1.y"
{
  //Begin with a-F
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	 if (!openedcase)
	  for (i = 0; i < openedkeys; i++)
	    fprintf (file, "   ");
	  if (openedcase)
	    fprintf (file, ", 'h%s", (char *)yyvsp[-1]);
	  else
	    fprintf (file, "'h%s", (char *)yyvsp[-1]);

	  newline = 1;
	  openedcase = 1;

	}
    }
  else if (verilog == 1)
    fprintf (file, "case 0x%s %s", (char *)yyvsp[-1], (char *) yyvsp[0]);
}
#line 2426 "sc2v_step1.tab.c"
    break;

  case 102: /* case_hexnumberword: CASE HEXA NUMBER WORD SYMBOL  */
#line 1232 "sc2v_step1.y"
{
  //Hex number beginning with dec number
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	 if (!openedcase)
	  for (i = 0; i < openedkeys; i++)
	    fprintf (file, "   ");
	  if (openedcase)
	    fprintf (file, ", 'h%d%s", yyvsp[-2],(char *)yyvsp[-1]);
	  else
	    fprintf (file, "'h%d%s", yyvsp[-2],(char *)yyvsp[-1]);

	  newline = 1;
	  openedcase = 1;

	}
    }
  else if (verilog == 1)
    fprintf (file, "case %d%s %s", yyvsp[-2], (char *) yyvsp[-1], (char *)yyvsp[0]);
}
#line 2454 "sc2v_step1.tab.c"
    break;

  case 103: /* case_word: CASE WORD SYMBOL  */
#line 1258 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	 if (!openedcase)
	  for (i = 0; i < openedkeys; i++)
	    fprintf (file, "   ");
	  if (openedcase){
	    if (IsDefine (defineslist, (char *) yyvsp[-1]))
	      fprintf (file, ", `%s", (char *) yyvsp[-1]);
		else
		  fprintf (file, ", %s", (char *) yyvsp[-1]);
	  }else{
	    if (IsDefine (defineslist, (char *) yyvsp[-1]))
	      fprintf (file, "`%s", (char *) yyvsp[-1]);
		else
		  fprintf (file, "%s", (char *) yyvsp[-1]);
      }
	  newline = 1;
	  openedcase = 1;

	}
    }
  else if (verilog == 1)
    fprintf (file, "case %s %s", (char *) yyvsp[-1], (char *) yyvsp[0]);
}
#line 2487 "sc2v_step1.tab.c"
    break;

  case 104: /* case_default: DEFAULT SYMBOL  */
#line 1289 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	 if (!openedcase)
	  for (i = 0; i < openedkeys; i++)
	    fprintf (file, "   ");
	  fprintf (file, "default:\n");
	  for (i = 0; i < openedkeys; i++)
	    fprintf (file, "   ");
	  fprintf (file, "begin\n");
	  newline = 1;
	  default_found = 1;
	}
    }
  else if (verilog == 1)
    fprintf (file, "default %s", (char *) yyvsp[0]);
}
#line 2512 "sc2v_step1.tab.c"
    break;

  case 105: /* case_only: CASE OPENPAR  */
#line 1312 "sc2v_step1.y"
{
  defineparenthesis = 0;
  //This rule occurs when in Verilog mode a case appears
  if (verilog == 1)
    fprintf (file, "case(");
}
#line 2523 "sc2v_step1.tab.c"
    break;

  case 106: /* break: BREAK SEMICOLON  */
#line 1321 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  if (newline == 0)
	    fprintf (file, "\n");
	  for (i = 0; i < openedkeys; i++)
	    fprintf (file, "   ");
	  fprintf (file, "end\n");
	  if (default_found)
	    {
	      default_break_found = 1;
	    }
	}
    }
  else if (verilog == 1)
    fprintf (file, "break;");
}
#line 2548 "sc2v_step1.tab.c"
    break;

  case 107: /* hexa: HEXA  */
#line 1344 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  fprintf (file, "'h");
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, "'h");
	}
    }
  else if (verilog == 1)
    fprintf (file, "0x");
}
#line 2569 "sc2v_step1.tab.c"
    break;

  case 108: /* translateoff: TRANSLATEOFF  */
#line 1363 "sc2v_step1.y"
{
  defineparenthesis = 0;
  translate = 0;
  fprintf (stderr, "line: %d Found Translate off directive \n", lineno);
}
#line 2579 "sc2v_step1.tab.c"
    break;

  case 109: /* translateon: TRANSLATEON  */
#line 1371 "sc2v_step1.y"
{
  defineparenthesis = 0;
  translate = 1;
  fprintf (stderr, "line: %d Found Translate on directive \n", lineno);
}
#line 2589 "sc2v_step1.tab.c"
    break;

  case 110: /* verilogbegin: VERILOGBEGIN  */
#line 1379 "sc2v_step1.y"
{
  defineparenthesis = 0;
  verilog = 1;
  fprintf (stderr, "line: %d Found Verilog Begin directive \n", lineno);
}
#line 2599 "sc2v_step1.tab.c"
    break;

  case 111: /* verilogend: VERILOGEND  */
#line 1387 "sc2v_step1.y"
{
  defineparenthesis = 0;
  verilog = 0;
  fprintf (stderr, "line: %d Found Verilog End directive \n", lineno);
}
#line 2609 "sc2v_step1.tab.c"
    break;

  case 112: /* ifdef: PIFDEF  */
#line 1395 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  ifdeffound = 1;
	  fprintf (file, "`ifdef");
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, "`ifdef");
	}
    }
  else if (verilog == 1)
    fprintf (file, "#ifdef");
}
#line 2631 "sc2v_step1.tab.c"
    break;

  case 113: /* ifndef: PIFNDEF  */
#line 1415 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  ifdeffound = 1;
	  fprintf (file, "`ifndef");
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, "`ifndef");
	}
    }
  else if (verilog == 1)
    fprintf (file, "#ifndef");
}
#line 2653 "sc2v_step1.tab.c"
    break;

  case 114: /* endif: PENDDEF  */
#line 1435 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  fprintf (file, "`endif");
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, "`endif");
	}
    }
  else if (verilog == 1)
    fprintf (file, "#endif");
}
#line 2674 "sc2v_step1.tab.c"
    break;

  case 115: /* pelse: PELSE  */
#line 1454 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  fprintf (file, "`else");
	}
      else if (definefound)
	{
	  fprintf (FILE_DEFINES, "`else");
	}
    }
  else if (verilog == 1)
    fprintf (file, "#else");
}
#line 2695 "sc2v_step1.tab.c"
    break;

  case 116: /* ttrue: TTRUE  */
#line 1473 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  fprintf (file, "1");
	}
    }
  else if (verilog == 1)
    fprintf (file, "1");
}
#line 2712 "sc2v_step1.tab.c"
    break;

  case 117: /* tfalse: TFALSE  */
#line 1489 "sc2v_step1.y"
{
  defineparenthesis = 0;
  if (translate == 1 && verilog == 0)
    {
      if (processfound)
	{
	  fprintf (file, "0");
	}
    }
  else if (verilog == 1)
    fprintf (file, "0");
}
#line 2729 "sc2v_step1.tab.c"
    break;

  case 118: /* comment: COMMENT  */
#line 1504 "sc2v_step1.y"
{
if(processfound){
  //To manage comments inside switch statements
  if(lastswitch){
	openedcase=0;
  }else if (openedcase){
	fprintf (file, " :\n");
      for (i = 0; i < openedkeys; i++)
		fprintf (file, "   ");
        fprintf(file,"begin\n");
        openedcase=0;
  }
  //indent
  if(newline){
    for (i = 0; i < openedkeys; i++)
	  fprintf (file, "   ");
	newline=0;
  }
  fprintf (file, " %s", (char *)yyvsp[0]);
 }
}
#line 2755 "sc2v_step1.tab.c"
    break;

  case 119: /* struct_dec: STRUCT OPENKEY  */
#line 1528 "sc2v_step1.y"
{
  struct_found=1;
}
#line 2763 "sc2v_step1.tab.c"
    break;


#line 2767 "sc2v_step1.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

