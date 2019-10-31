/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTVAL = 258,
     VAR = 259,
     FLOATVAL = 260,
     CHARVAL = 261,
     PRINTF = 262,
     WHILE = 263,
     IF = 264,
     FOR = 265,
     ELSE = 266,
     TYPEINT = 267,
     TYPELONG = 268,
     TYPEFLOAT = 269,
     TYPEDOUBLE = 270,
     TYPECHAR = 271,
     EQ = 272,
     SEM = 273,
     NL = 274,
     COM = 275,
     SQ = 276,
     RETURN = 277,
     MAIN = 278,
     VOID = 279
   };
#endif
/* Tokens.  */
#define INTVAL 258
#define VAR 259
#define FLOATVAL 260
#define CHARVAL 261
#define PRINTF 262
#define WHILE 263
#define IF 264
#define FOR 265
#define ELSE 266
#define TYPEINT 267
#define TYPELONG 268
#define TYPEFLOAT 269
#define TYPEDOUBLE 270
#define TYPECHAR 271
#define EQ 272
#define SEM 273
#define NL 274
#define COM 275
#define SQ 276
#define RETURN 277
#define MAIN 278
#define VOID 279




/* Copy the first part of user declarations.  */
#line 1 "compiler.y"

#include <sstream>
#include <string>
#include <map>
#include <stdio.h>
#include <stdlib.h> 
#include <algorithm>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define MAX 1000

using namespace std;

	extern FILE *yyin;
    int yylex(void);
    void yyerror(char *);
	void identifer_type(string str);
	void insert_tokentable(string str1);
	void   update_tokentable(string str2);
	string get_variable_value(string myvar);
	

	
map < string, int > typeCheck;	
int tokenCount = 0;	
bool value_flag = false;


int temp_int=0;
float temp_float=0.0;
string temp_char="";


int var_pos=0;

int int_value=0;
float float_value = 0.0;
string char_value = "";
string char_temp_value = "";

string check = "";



string var_name = "";
string var_value = "";
string var_type = "";

	
	struct tokenTable{
                 string token_Name;
                 string token_Type;
                 string token_Value;
	}token_No[MAX];
	
	
	
	


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 65 "compiler.y"
{
    float fval;
	int ival;
	char *cval;
	char *type;
}
/* Line 193 of yacc.c.  */
#line 214 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 227 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   110

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  107

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      30,    31,    27,    25,    29,    26,     2,    28,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    11,    15,    19,    23,    27,
      28,    34,    36,    38,    40,    42,    44,    46,    48,    50,
      54,    58,    62,    66,    70,    72,    74,    76,    78,    82,
      84,    88,    90,    94,    96,   100,   102,   106,   108,   112,
     114,   118,   120,   124,   126,   130,   132,   136,   138,   142,
     146,   150,   154,   158,   160,   162,   166,   170,   174,   178,
     182,   184,   186,   188,   190,   192
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      33,     0,    -1,    33,    34,    -1,    -1,    12,    37,    18,
      -1,    13,    38,    18,    -1,    14,    39,    18,    -1,    15,
      40,    18,    -1,    16,    41,    18,    -1,    -1,     4,    35,
      17,    36,    18,    -1,    50,    -1,    22,    -1,    23,    -1,
      24,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
      36,    25,    36,    -1,    36,    26,    36,    -1,    36,    27,
      36,    -1,    36,    28,    36,    -1,    30,    36,    31,    -1,
       3,    -1,     5,    -1,     6,    -1,     4,    -1,    37,    29,
      42,    -1,    42,    -1,    38,    29,    43,    -1,    43,    -1,
      39,    29,    44,    -1,    44,    -1,    40,    29,    45,    -1,
      45,    -1,    41,    29,    46,    -1,    46,    -1,     4,    17,
      47,    -1,     4,    -1,     4,    17,    47,    -1,     4,    -1,
       4,    17,    48,    -1,     4,    -1,     4,    17,    48,    -1,
       4,    -1,     4,    17,    49,    -1,     4,    -1,    47,    25,
      47,    -1,    47,    26,    47,    -1,    47,    27,    47,    -1,
      47,    28,    47,    -1,    30,    47,    31,    -1,     3,    -1,
       4,    -1,    48,    25,    48,    -1,    48,    26,    48,    -1,
      48,    27,    48,    -1,    48,    28,    48,    -1,    30,    48,
      31,    -1,     5,    -1,     3,    -1,     4,    -1,     6,    -1,
       4,    -1,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    90,    96,    98,   100,   102,   104,   106,
     106,   142,   144,   146,   148,   150,   152,   154,   156,   163,
     178,   190,   202,   237,   253,   268,   281,   293,   379,   380,
     383,   384,   387,   388,   391,   392,   395,   396,   400,   402,
     405,   407,   410,   412,   415,   417,   420,   422,   429,   430,
     431,   432,   445,   446,   447,   491,   492,   493,   494,   506,
     507,   508,   509,   542,   543,   574
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTVAL", "VAR", "FLOATVAL", "CHARVAL",
  "PRINTF", "WHILE", "IF", "FOR", "ELSE", "TYPEINT", "TYPELONG",
  "TYPEFLOAT", "TYPEDOUBLE", "TYPECHAR", "EQ", "SEM", "NL", "COM", "SQ",
  "RETURN", "MAIN", "VOID", "'+'", "'-'", "'*'", "'/'", "','", "'('",
  "')'", "$accept", "stm", "code", "@1", "expn", "varlist", "varlistlong",
  "varlistfloat", "varlistdouble", "varlistchar", "vareq", "vareqlong",
  "vareqfloat", "vareqdouble", "vareqchar", "exp", "expfloat", "expchar",
  "myprintf", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    43,    45,    42,    47,    44,
      40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    34,    34,    34,    35,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    37,    37,
      38,    38,    39,    39,    40,    40,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    45,    46,    46,    47,    47,
      47,    47,    47,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    49,    50
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     3,     3,     3,     3,     3,     0,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     9,    65,    15,    16,    17,    18,     0,
       0,     0,     0,     0,    12,    13,    14,     2,    11,     0,
      39,     0,    29,    41,     0,    31,    43,     0,    33,    45,
       0,    35,    47,     0,    37,     0,     0,     4,     0,     0,
       5,     0,     0,     6,     0,     0,     7,     0,     0,     8,
       0,    24,    27,    25,    26,     0,     0,    53,    54,     0,
      38,    28,    40,    30,    61,    62,    60,     0,    42,    32,
      44,    34,    64,    63,    46,    36,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    19,    20,    21,    22,    52,    48,    49,
      50,    51,    59,    55,    56,    57,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    17,    19,    56,    21,    24,    27,    30,    33,
      22,    25,    28,    31,    34,    60,    68,    74,    18
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -42
static const yytype_int8 yypact[] =
{
     -42,    52,   -42,   -42,   -42,   -42,   -42,   -42,   -42,    12,
      17,    21,    26,    39,   -42,   -42,   -42,   -42,   -42,    36,
      37,    -7,   -42,    38,    -6,   -42,    40,    -5,   -42,    41,
      -3,   -42,    55,     0,   -42,    -2,     6,   -42,    12,     6,
     -42,    17,     3,   -42,    21,     3,   -42,    26,    13,   -42,
      39,   -42,   -42,   -42,   -42,    -2,    53,   -42,   -42,     6,
      78,   -42,    78,   -42,   -42,   -42,   -42,     3,    82,   -42,
      82,   -42,   -42,   -42,   -42,   -42,    57,   -42,    -2,    -2,
      -2,    -2,    64,     6,     6,     6,     6,    71,     3,     3,
       3,     3,   -42,     4,     4,   -42,   -42,   -42,     7,     7,
     -42,   -42,   -42,    14,    14,   -42,   -42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -42,   -42,   -41,   -42,   -42,   -42,   -42,   -42,
      31,    29,    33,    46,    23,   -39,   -40,   -42,   -42
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      62,    51,    52,    53,    54,    70,    64,    65,    66,    57,
      58,    37,    40,    43,    76,    46,    20,    72,    49,    73,
      82,    23,    38,    41,    44,    26,    47,    87,    55,    50,
      29,    80,    81,    67,    85,    86,    59,    93,    94,    95,
      96,    90,    91,    32,    98,    99,   100,   101,   103,   104,
     105,   106,     2,    35,    36,    39,     3,    42,    45,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    61,
      63,    77,    48,    75,    14,    15,    16,    69,    78,    79,
      80,    81,    78,    79,    80,    81,     0,     0,    92,    83,
      84,    85,    86,    71,     0,    97,    88,    89,    90,    91,
       0,     0,   102,    83,    84,    85,    86,    88,    89,    90,
      91
};

static const yytype_int8 yycheck[] =
{
      39,     3,     4,     5,     6,    45,     3,     4,     5,     3,
       4,    18,    18,    18,    55,    18,     4,     4,    18,     6,
      59,     4,    29,    29,    29,     4,    29,    67,    30,    29,
       4,    27,    28,    30,    27,    28,    30,    78,    79,    80,
      81,    27,    28,     4,    83,    84,    85,    86,    88,    89,
      90,    91,     0,    17,    17,    17,     4,    17,    17,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    38,
      41,    18,    17,    50,    22,    23,    24,    44,    25,    26,
      27,    28,    25,    26,    27,    28,    -1,    -1,    31,    25,
      26,    27,    28,    47,    -1,    31,    25,    26,    27,    28,
      -1,    -1,    31,    25,    26,    27,    28,    25,    26,    27,
      28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,     0,     4,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    22,    23,    24,    34,    50,    35,
       4,    37,    42,     4,    38,    43,     4,    39,    44,     4,
      40,    45,     4,    41,    46,    17,    17,    18,    29,    17,
      18,    29,    17,    18,    29,    17,    18,    29,    17,    18,
      29,     3,     4,     5,     6,    30,    36,     3,     4,    30,
      47,    42,    47,    43,     3,     4,     5,    30,    48,    44,
      48,    45,     4,     6,    49,    46,    36,    18,    25,    26,
      27,    28,    47,    25,    26,    27,    28,    48,    25,    26,
      27,    28,    31,    36,    36,    36,    36,    31,    47,    47,
      47,    47,    31,    48,    48,    48,    48
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 89 "compiler.y"
    {}
    break;

  case 4:
#line 96 "compiler.y"
    { identifer_type("int"); }
    break;

  case 5:
#line 98 "compiler.y"
    { identifer_type("long"); }
    break;

  case 6:
#line 100 "compiler.y"
    { identifer_type("float"); }
    break;

  case 7:
#line 102 "compiler.y"
    { identifer_type("double"); }
    break;

  case 8:
#line 104 "compiler.y"
    { identifer_type("char"); }
    break;

  case 9:
#line 106 "compiler.y"
    { var_name=(yyvsp[(1) - (1)].cval); if(typeCheck[var_name]==0)
							            {
							                printf("Undefined Variable!\n");
								            cout<<"Variable Name:" <<var_name<<endl;
											exit(0);
							             }
										}
    break;

  case 10:
#line 113 "compiler.y"
    { 
                                             if(typeCheck[var_name]==1)
											   {
											      int_value = temp_int;
												  update_tokentable("int");
											   }
											 else if(typeCheck[var_name]==2)
											   {
											      int_value = temp_int;
												  update_tokentable("long");
											   }
											 else if(typeCheck[var_name]==3)
											   {
											      float_value = temp_float;
												  update_tokentable("float");
											   }
											 else if(typeCheck[var_name]==4)
											   { 
											      float_value = temp_float;
												  update_tokentable("double");
											   }
											 else if(typeCheck[var_name]==5)
											   {
											      char_value = temp_char;
												  update_tokentable("char");
											   }
																					 
							        }
    break;

  case 11:
#line 142 "compiler.y"
    {}
    break;

  case 12:
#line 144 "compiler.y"
    {identifer_type("return");}
    break;

  case 13:
#line 146 "compiler.y"
    {identifer_type("main");}
    break;

  case 14:
#line 148 "compiler.y"
    {identifer_type("void");}
    break;

  case 15:
#line 150 "compiler.y"
    {printf("while");}
    break;

  case 16:
#line 152 "compiler.y"
    {printf("if");}
    break;

  case 17:
#line 154 "compiler.y"
    {printf("for");}
    break;

  case 18:
#line 156 "compiler.y"
    {printf("else");}
    break;

  case 19:
#line 163 "compiler.y"
    {
                         
                          
						  if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
						  {
                           (yyval.ival)=(yyvsp[(1) - (3)].ival)+(yyvsp[(3) - (3)].ival);
						   temp_int = (yyval.ival);
						   }
						  else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
						  {
						   (yyval.fval)=(yyvsp[(1) - (3)].fval)+(yyvsp[(3) - (3)].fval);
						   temp_float = (yyval.fval);
						   
						  }
					   }
    break;

  case 20:
#line 178 "compiler.y"
    {
	                      if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
						  {
                           (yyval.ival)=(yyvsp[(1) - (3)].ival)-(yyvsp[(3) - (3)].ival);
						   temp_int = (yyval.ival);
						  }
						 else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
						  {
						   (yyval.fval)=(yyvsp[(1) - (3)].fval)-(yyvsp[(3) - (3)].fval);
						   temp_float = (yyval.fval);
						  }
					  }
    break;

  case 21:
#line 190 "compiler.y"
    {
	                     if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
						 {
                          (yyval.ival)=(yyvsp[(1) - (3)].ival)*(yyvsp[(3) - (3)].ival);
						  temp_int = (yyval.ival);
						 }
						 else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
						 {
						  (yyval.fval)=(yyvsp[(1) - (3)].fval)*(yyvsp[(3) - (3)].fval);
						  temp_float = (yyval.fval);
						 }
	                  }
    break;

  case 22:
#line 202 "compiler.y"
    {
	  
	                   if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
					   {
						   if((yyvsp[(3) - (3)].ival) == 0)
					         {
						        printf("Can not divide by 0\n");
						        exit(0);
						   
						     }
							 else
							 {
							  (yyval.ival)=(yyvsp[(1) - (3)].ival)/(yyvsp[(3) - (3)].ival);
							  temp_int = (yyval.ival);
							 }
						}
						
						else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
						{
					     if((yyvsp[(3) - (3)].fval) == 0)
					         {
						        printf("Can not divide by 0\n");
						        exit(0);
						     }
						  else
						  {
					        (yyval.fval)=(yyvsp[(1) - (3)].fval)/(yyvsp[(3) - (3)].fval);
							temp_float = (yyval.fval);
						  }
					    }
					   
					  }
    break;

  case 23:
#line 237 "compiler.y"
    {  
	                     if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
						 {
	                         (yyval.ival)=(yyvsp[(2) - (3)].ival);
							 temp_int = (yyval.ival);
							 
						 }
						 
					else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
					    {
	                        (yyval.fval)=(yyvsp[(2) - (3)].fval);
							temp_float = (yyval.fval);
						}
						  
				  }
    break;

  case 24:
#line 253 "compiler.y"
    {     
	                       if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
						   {
	                         (yyval.ival)=(yyvsp[(1) - (1)].ival);
							 temp_int = (yyval.ival);
							}
					 	  else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
						   {
							 (yyval.fval)=(yyvsp[(1) - (1)].ival);
							 temp_float = (yyval.fval);
						   }
							 
						  
				  }
    break;

  case 25:
#line 268 "compiler.y"
    {
                        	if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
                              {
							  printf("Float to Int Convertion!\n");
							  exit(0);
                              }							  
	                        else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
							{
	                         (yyval.fval)=(yyvsp[(1) - (1)].fval);
							 temp_float = (yyval.fval);
							}
						  
				  }
    break;

  case 26:
#line 281 "compiler.y"
    {      if(typeCheck[var_name]==5)
		                     {
	                           (yyval.cval)=(yyvsp[(1) - (1)].cval);
							   temp_char = (yyval.cval)[1];
							 }
						else
                           {
						    printf("Wrong Formation!\n");
							exit(0);
                           }						   
				  }
    break;

  case 27:
#line 293 "compiler.y"
    {   
            		string myvar = (yyvsp[(1) - (1)].cval);
		          int my_intValue;
				  float my_floatValue;
				  string my_charValue;
	                    	
		             if(typeCheck[myvar]==0)
					   {
					     cout<<"In Variable Expression -- Undefined Variable!\n"<<"Variable Name: "<<myvar<<endl;
						 exit(0);  
					   }
					 else if(typeCheck[var_name]==1 || typeCheck[var_name]==2)
					   {
					            if(typeCheck[myvar]==1 || typeCheck[myvar]==2) 
					                {
					                  std::stringstream ss(get_variable_value(myvar));
									  ss >> my_intValue;
                                      (yyval.ival) = my_intValue;	
                                      temp_int = (yyval.ival);						
					                }
								else
                                   {
								      if(typeCheck[myvar]==3 || typeCheck[myvar]==4) 
					                    {
										 cout<<"Int Variable "<<var_name<<" is trying to assign Float Variable "<<myvar<<endl;
										 exit(0);
                                        }
									  else if(typeCheck[myvar]==5) 
					                    {
										 cout<<"Int Variable "<<var_name<<" is trying to assign Character Variable "<<myvar<<endl;
										 exit(0);
                                        }
									  else
                                        {
										 cout<<"Int Variable "<<var_name<<" is trying to assign Unrecognised Type of Variable "<<myvar<<endl;
										 exit(0);
                                        }										
										
                                   }								   
						}
		              else if(typeCheck[var_name]==3 || typeCheck[var_name]==4)
					   {
					                if(typeCheck[myvar]==1 || typeCheck[myvar]==2 || typeCheck[myvar]==3 || typeCheck[myvar]==4)
									{
					                  std::stringstream ss(get_variable_value(myvar));
									  ss >> my_floatValue;
                                      (yyval.fval) = my_floatValue;	
                                      temp_float = (yyval.fval);
                                    }									  
					                else if(typeCheck[myvar]==5) 
					                    {
										 cout<<"Float Variable "<<var_name<<" is trying to assign Character Variable "<<myvar<<endl;
										 exit(0);
                                        }
									else
                                        {
										 cout<<"Float Variable "<<var_name<<" is trying to assign Unrecognised Type of Variable "<<myvar<<endl;
										 exit(0);
                                        }	
	         
				      }
					  else if(typeCheck[var_name]== 5)
					   {
					                if(typeCheck[myvar] == 5)
									{
					                   my_charValue = (get_variable_value(myvar));	
                                       temp_char = my_charValue;
                                    }									  
					                
									else
                                        {
										 cout<<"Char Variable "<<var_name<<" is trying to assign Another Type of Variable "<<myvar<<endl;
										 exit(0);
                                        }	
	         
				      }
		
		      }
    break;

  case 28:
#line 379 "compiler.y"
    {}
    break;

  case 29:
#line 380 "compiler.y"
    {}
    break;

  case 30:
#line 383 "compiler.y"
    {}
    break;

  case 31:
#line 384 "compiler.y"
    {}
    break;

  case 32:
#line 387 "compiler.y"
    {}
    break;

  case 33:
#line 388 "compiler.y"
    {}
    break;

  case 34:
#line 391 "compiler.y"
    {}
    break;

  case 35:
#line 392 "compiler.y"
    {}
    break;

  case 36:
#line 395 "compiler.y"
    {}
    break;

  case 37:
#line 396 "compiler.y"
    {}
    break;

  case 38:
#line 400 "compiler.y"
    { var_name = (yyvsp[(1) - (3)].cval); int_value = (yyvsp[(3) - (3)].ival); value_flag = true; insert_tokentable("int"); }
    break;

  case 39:
#line 402 "compiler.y"
    { var_name = (yyvsp[(1) - (1)].cval); value_flag = false; insert_tokentable("int");}
    break;

  case 40:
#line 405 "compiler.y"
    { var_name = (yyvsp[(1) - (3)].cval); int_value = (yyvsp[(3) - (3)].ival); value_flag = true; insert_tokentable("long"); }
    break;

  case 41:
#line 407 "compiler.y"
    { var_name = (yyvsp[(1) - (1)].cval); value_flag = false; insert_tokentable("long");}
    break;

  case 42:
#line 410 "compiler.y"
    { var_name = (yyvsp[(1) - (3)].cval); float_value = (yyvsp[(3) - (3)].fval); value_flag = true; insert_tokentable("float"); }
    break;

  case 43:
#line 412 "compiler.y"
    { var_name = (yyvsp[(1) - (1)].cval); value_flag = false; insert_tokentable("float");}
    break;

  case 44:
#line 415 "compiler.y"
    { var_name = (yyvsp[(1) - (3)].cval); float_value = (yyvsp[(3) - (3)].fval); value_flag = true; insert_tokentable("double"); }
    break;

  case 45:
#line 417 "compiler.y"
    { var_name = (yyvsp[(1) - (1)].cval); value_flag = false; insert_tokentable("double");}
    break;

  case 46:
#line 420 "compiler.y"
    { var_name = (yyvsp[(1) - (3)].cval); char_value = temp_char; value_flag = true; insert_tokentable("char"); }
    break;

  case 47:
#line 422 "compiler.y"
    { var_name = (yyvsp[(1) - (1)].cval); value_flag = false; insert_tokentable("char");}
    break;

  case 48:
#line 429 "compiler.y"
    {(yyval.ival)=(yyvsp[(1) - (3)].ival)+(yyvsp[(3) - (3)].ival);}
    break;

  case 49:
#line 430 "compiler.y"
    {(yyval.ival)=(yyvsp[(1) - (3)].ival)-(yyvsp[(3) - (3)].ival);}
    break;

  case 50:
#line 431 "compiler.y"
    {(yyval.ival)=(yyvsp[(1) - (3)].ival)*(yyvsp[(3) - (3)].ival);}
    break;

  case 51:
#line 432 "compiler.y"
    {
	                  if((yyvsp[(3) - (3)].ival) == 0)
					    {
						   printf("Can not divide by 0\n");
						  
						 exit(0);
						   
						}
	                 else
					   {
					      (yyval.ival)=(yyvsp[(1) - (3)].ival)/(yyvsp[(3) - (3)].ival);
					   }	
					}
    break;

  case 52:
#line 445 "compiler.y"
    {(yyval.ival)=(yyvsp[(2) - (3)].ival);}
    break;

  case 53:
#line 446 "compiler.y"
    { (yyval.ival)=(yyvsp[(1) - (1)].ival);}
    break;

  case 54:
#line 447 "compiler.y"
    {
	  
             		 string myvar = (yyvsp[(1) - (1)].cval);
		             int my_intValue;
         	
		             if(typeCheck[myvar]==0)
					   {
					     cout<<"In Variable Expression -- Undefined Variable!\n"<<"Variable Name: "<<myvar<<endl;
						 exit(0);  
					   }
					
					 else if(typeCheck[myvar]==1 || typeCheck[myvar]==2) 
					   {
					      std::stringstream ss(get_variable_value(myvar));
					      ss >> my_intValue;
                          (yyval.ival) = my_intValue;						
					    }

                     else if(typeCheck[myvar]==3 || typeCheck[myvar]==4) 
					    {
						  cout<<"In Integer Type Variabl ---> trying to assign Float Variable "<<myvar<<endl;
						  exit(0);
                        }
					else if(typeCheck[myvar]==5) 
					    {
						  cout<<"In Integer Type Variabl ---> trying to assign Character Variable "<<myvar<<endl;
						  exit(0);
                        }
					else
                        {
						  cout<<"In Integer Type Variabl ---> trying to assign Unrecognised Type of Variable "<<myvar<<endl;
						  exit(0);
                        }										
										
                       
		
		      }
    break;

  case 55:
#line 491 "compiler.y"
    {(yyval.fval)=(yyvsp[(1) - (3)].fval)+(yyvsp[(3) - (3)].fval);}
    break;

  case 56:
#line 492 "compiler.y"
    {(yyval.fval)=(yyvsp[(1) - (3)].fval)-(yyvsp[(3) - (3)].fval);}
    break;

  case 57:
#line 493 "compiler.y"
    {(yyval.fval)=(yyvsp[(1) - (3)].fval)*(yyvsp[(3) - (3)].fval);}
    break;

  case 58:
#line 494 "compiler.y"
    {
	                  if((yyvsp[(3) - (3)].fval) == 0)
					    {
						   printf("Can not divide by 0\n");
						 exit(0);
						   
						}
	                 else
					   {
					      (yyval.fval)=(yyvsp[(1) - (3)].fval)/(yyvsp[(3) - (3)].fval);
					   }	
					}
    break;

  case 59:
#line 506 "compiler.y"
    {(yyval.fval)=(yyvsp[(2) - (3)].fval);}
    break;

  case 60:
#line 507 "compiler.y"
    { (yyval.fval)=(yyvsp[(1) - (1)].fval);}
    break;

  case 61:
#line 508 "compiler.y"
    {(yyval.fval)=(yyvsp[(1) - (1)].ival);}
    break;

  case 62:
#line 509 "compiler.y"
    {   
            	       string myvar = (yyvsp[(1) - (1)].cval);
		               float my_floatValue;
				               
	                    	
		             if(typeCheck[myvar]==0)
					   {
					     cout<<"In Variable Expression -- Undefined Variable!\n"<<"Variable Name: "<<myvar<<endl;
						 exit(0);  
					   }
					 
					 else if(typeCheck[myvar]==1 || typeCheck[myvar]==2 || typeCheck[myvar]==3 || typeCheck[myvar]==4) 
					   {
					     std::stringstream ss(get_variable_value(myvar));
						 ss >> my_floatValue;
                         (yyval.fval) = my_floatValue;						
					   }
								
					 else if(typeCheck[myvar]==5) 
					   {
						 cout<<"Float Variable is trying to assign Character Variable "<<myvar<<endl;
					     exit(0);
                       }
				     else
                       {
					     cout<<"Float Variable  is trying to assign Unrecognised Type of Variable "<<myvar<<endl;
						 exit(0);
                       }										
		      }
    break;

  case 63:
#line 542 "compiler.y"
    { (yyval.cval)=(yyvsp[(1) - (1)].cval); temp_char = (yyval.cval)[1];}
    break;

  case 64:
#line 543 "compiler.y"
    {   
            		string myvar = (yyvsp[(1) - (1)].cval);
				    string my_charValue;
	                    	
		             if(typeCheck[myvar]==0)
					   {
					     cout<<"In Variable Expression -- Undefined Variable!\n"<<"Variable Name: "<<myvar<<endl;
						 exit(0);  
					   }
					  else if(typeCheck[myvar]== 5)
					   {
					     my_charValue = get_variable_value(myvar);	
                         temp_char = my_charValue;
                       }									  
					  else
                        {
						  cout<<"Char Variable "<<var_name<<" is trying to assign Another Type of Variable "<<myvar<<endl;
						  exit(0);
                        }	
	         
				      
		
		      }
    break;

  case 65:
#line 574 "compiler.y"
    {
                          identifer_type("printf");
			              
						  string myString = (string)(yyvsp[(1) - (1)].cval);
			
			              string myText = "";
			              string myResultText = "";
			              string myVariableList = "";
			
			              bool fcom = false;
			              int TextCheck = 0;
			              string  myVariable[100];
			              string myVariableValue[100];
			              string myVariableType[100];
			
					      int i=6;
					
					      while(myString[i]!=';')
					        {
					           if(TextCheck>=2)
					                 break;
					           if(myString[i]=='"')
					             {
					                TextCheck++;
						            i++;
						            continue;
					             }
					           if( TextCheck == 1)
					             {					      
						            myText += myString[i];
					             }
					          i++;
					         }
			
			             TextCheck = 0;	
                         i=0;				 
                         while(myString[i]!=';')
					       {
					          if(myString[i]=='"')
					             {
					               TextCheck++;
						           i++;
						           continue;
					             }
					          if( TextCheck >= 2 && myString[i]!=' ')
					             {
                                    if(fcom==true)               					   
						                myVariableList += myString[i];
					                if(myString[i]==',')
					                    fcom = true;
					             }
					          i++;
					       }
					
     					myVariableList[myVariableList.length()-1]='\0';

	     		        i=0; int j=0;
		    	        bool tmpflag = false;
			    
         				while(myVariableList[i]!='\0')
		        		    {
				        	   tmpflag = true;
				               if(myVariableList[i]!= ' ' && myVariableList[i]!= ',')
						          {
						              myVariable[j] += myVariableList[i];
						          }
						       if(myVariableList[i]== ',') 
					           	  {
						              j++;
					              }
						       i++;
				            }
				   
				          int totalVariable;
				          if(tmpflag == false)
				            {
				               totalVariable = 0;
				            }
				          else
				           {
				              totalVariable = j+1;
				           }
				   
				          int varCount = 0;
				          for(i=0;i<totalVariable;i++)
				             {
					            for(int k=1;k<=tokenCount;k++)
	                               {
							          if(myVariable[i]==token_No[k].token_Name)
								        {
								          myVariableValue[i] = token_No[k].token_Value;
								          myVariableType[i] = token_No[k].token_Type;
								          varCount++;
								        }
                                   }
					         }
	
				   
	    			   int  FScounter = 0;
		    		   int variableTrack=0;
				
				   for(i=0;i<myText.length();i++)
				     {
					 
					     if(myText[i]=='%')
						   {	
						       i++;					  
						       if(myText[i]=='d')
							    {
								   if(myVariableType[variableTrack]=="Identifier: Integer")
								    {
									  myResultText+=myVariableValue[variableTrack];
									  variableTrack++;
									  FScounter++;
									}
									else
									{
									  printf("Wrong Formate Specifier!\n");
									  exit(0);
									}
								}
								else if(myText[i]=='f')
								{
								    if(myVariableType[variableTrack]=="Identifier: Floating Point")
								     {
									  myResultText+=myVariableValue[variableTrack];
									  variableTrack++;
									  FScounter++;
									 }
									else
									 {
									  printf("Wrong Formate Specifier!\n");
									  exit(0);
									 }
								 }
								else if(myText[i]=='c')
								{		
								   if(myVariableType[variableTrack]=="Identifier: Character")
								    {
									  myResultText+=myVariableValue[variableTrack];
									  variableTrack++;
									  FScounter++;
									}
									else
									{
									  printf("Wrong Formate Specifier!\n");
									  exit(0);
									}
								}
								else if(myText[i]=='l')
								{
								    i++;
								           if(myText[i]=='d')
							                  {
											     
								                 if(myVariableType[variableTrack]=="Identifier: Long Integer")
								                   {
												     
									                 myResultText+=myVariableValue[variableTrack];
									                 variableTrack++;
													 FScounter++;
									               }
												  else
									                {
									                  printf("Wrong Formate Specifier!\n");
									                  exit(0);
									                }
								              }
								          else if(myText[i]=='f')
								             {
											    if(myVariableType[variableTrack]=="Identifier: Double Floating Point")
								                   {
												   
									                 myResultText+=myVariableValue[variableTrack];
									                 variableTrack++;
													 FScounter++;
									               }
												   else
									                {
									                  printf("Wrong Formate Specifier!\n");
									                  exit(0);
									                }
								             }
								          else
										    {
											   printf("Wrong Formate Specifier!\n");
									           exit(0);
										    }
								
								}
								else
								{
								    printf("Wrong Formate Specifier!\n");
								    exit(0);
								}
						   }
						   
						   
						   else
						       {
							   
							      if(myText[i]=='\\')
								   {
								     i++;
									   if(myText[i]=='n')
									     myResultText+="\n";
									   else if(myText[i]=='t')
									     myResultText+="	"; 
									  else
                                         myResultText+=myText[i];									  
									}
							      else
							         myResultText+=myText[i];
						       }
						   
					 
					 
					 }
					 
					 	
					  if(FScounter != totalVariable)
				        {
				         printf("Number of Format Specifiers or Variables are not Equal!\n");
						 exit(0);
				        }
					 
					      tokenCount++;
			              token_No[tokenCount].token_Name=myText;
			              token_No[tokenCount].token_Type="Constant: String";
			              token_No[tokenCount].token_Value=myResultText;
            }
    break;


/* Line 1267 of yacc.c.  */
#line 2394 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 813 "compiler.y"




void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
		
	exit(0);	
}



void identifer_type(string str)
{

                                 if(typeCheck["int"]==0 && str == "int")
		                             {
			                          typeCheck["int"]=6;
			                          tokenCount++;
			                          token_No[tokenCount].token_Name="int";
			                          token_No[tokenCount].token_Type="keyword: Datatype";
			                          token_No[tokenCount].token_Value="no";
									 }
								else if(typeCheck["long"]==0 && str == "long")
		                             {
			                          typeCheck["long"]=6;
			                          tokenCount++;
			                          token_No[tokenCount].token_Name="long";
			                          token_No[tokenCount].token_Type="keyword: Datatype";
			                          token_No[tokenCount].token_Value="no";
									 }
								else if(typeCheck["float"]==0 && str == "float")
		                             {
			                          typeCheck["float"]=6;
			                          tokenCount++;
			                          token_No[tokenCount].token_Name="float";
			                          token_No[tokenCount].token_Type="keyword: Datatype";
			                          token_No[tokenCount].token_Value="no";
									 }
                               else if(typeCheck["double"]==0 && str == "double")
		                             {
			                          typeCheck["double"]=6;
			                          tokenCount++;
			                          token_No[tokenCount].token_Name="double";
			                          token_No[tokenCount].token_Type="keyword: Datatype";
			                          token_No[tokenCount].token_Value="no";
									 }
                               else if(typeCheck["char"]==0 && str == "char")
		                             {
			                          typeCheck["char"]=6;
			                          tokenCount++;
			                          token_No[tokenCount].token_Name="char";
			                          token_No[tokenCount].token_Type="keyword: Datatype";
			                          token_No[tokenCount].token_Value="no";
									 }
                               else if(typeCheck["printf"]==0 && str == "printf")
		                             {
			                          typeCheck["printf"]=6;
			                          tokenCount++;
			                          token_No[tokenCount].token_Name="printf";
			                          token_No[tokenCount].token_Type="Keyword: Function";
			                          token_No[tokenCount].token_Value="no";
			                         }
                              else if(typeCheck["return"]==0 && str == "return")
		                            {
			                         typeCheck["return"]=6;
			                         tokenCount++;
			                         token_No[tokenCount].token_Name="return";
			                         token_No[tokenCount].token_Type="Keyword";
			                         token_No[tokenCount].token_Value="no";
			                        }	
                              else if(typeCheck["main"]==0 && str == "main")
		                           { 
			                        typeCheck["main"]=6;
			                        tokenCount++;
			                        token_No[tokenCount].token_Name="main";
			                        token_No[tokenCount].token_Type="Identifier: Function";
			                        token_No[tokenCount].token_Value="no";
			                       }
		                      else if(typeCheck["void"]==0 && str == "void")
			                  	   {
					                typeCheck["void"]=6;
			 		                tokenCount++;
			 		                token_No[tokenCount].token_Name="void";
			 		                token_No[tokenCount].token_Type="Keyword: Datatype";
			 		                token_No[tokenCount].token_Value="no";
			  		               }								   
    
}




void insert_tokentable(string str1)
{
                                  if(str1=="int")
								  {
								     var_pos = 1;
								      if(value_flag==true)
									    {
                                          std::stringstream ss;
                                          ss << int_value;
                                          ss >> var_value;
									    }
									  else
									      var_value = "no";
									  
									 var_type = "Identifier: Integer";
								  }
								  else if(str1=="long")
								  {
								   var_pos = 2;
                                    if(value_flag==true)
									    {
                                          std::stringstream ss;
                                          ss << int_value;
                                          ss >> var_value;
									    }
									  else
									      var_value = "no";
									 var_type = "Identifier: Long Integer";
								   }
								  else if(str1=="float")
								   {
								    var_pos = 3;
                                    if(value_flag==true)
									    {
                                          std::stringstream ss;
                                          ss << float_value;
                                          ss >> var_value;
									    }
									  else
									      var_value = "no";
									var_type = "Identifier: Floating Point";
								   }
								   else if(str1=="double")
								   {
								    var_pos = 4;
								    if(value_flag==true)
									    {
                                          std::stringstream ss;
                                          ss << float_value;
                                          ss >> var_value;
									    }
									  else
									      var_value = "no";
									 var_type = "Identifier: Double Floating Point";
								   }
								   else if(str1=="char")
								   {
								   var_pos = 5;
								   if(value_flag==true)
									    {
                                          std::stringstream ss;
                                          ss << char_value;
                                          ss >> var_value;
									    }
									  else
									      var_value = "no";
									var_type = "Identifier: Character";
								   }

                                    
								  if(typeCheck[var_name]==0)
		                             {
			                          typeCheck[var_name]=var_pos;
			                          tokenCount++;
									  token_No[tokenCount].token_Name = var_name;
			                          token_No[tokenCount].token_Type=var_type;
			                          token_No[tokenCount].token_Value=var_value;

									 }
									 
									else
									 {
									    cout<<"Duplicate Variable! \n"<<"Variable Name: "<<var_name<<endl;
										
										exit(0);
									 }

}




void   update_tokentable(string str2)
{
                               if(str2=="int" || str2 == "long")
								  {
								     std::stringstream ss;
                                     ss << int_value;
                                     ss >> var_value;  
								  }
							   else if(str2=="float" || str2=="double")
								  {
								     std::stringstream ss;
                                     ss << float_value;
                                     ss >> var_value;   
								  }
							  else if(str2=="char")
								   {
								     std::stringstream ss;
                                     ss << char_value;
                                     ss >> var_value;  
								   }

                     for(int k=1; k<=tokenCount; k++)
	                       {						  
						      if(var_name == token_No[k].token_Name )
							    {								 
						   		 token_No[k].token_Value = var_value;								
								 break;
								}
						   }
}


string get_variable_value(string myvar)
{
    string myvalue="";
                   for(int k=1; k<=tokenCount; k++)
	                       {						  
						      if( myvar == token_No[k].token_Name )
							    {								 
						   		 myvalue=token_No[k].token_Value;								
								 break;
								}
						   }
				
                    if(myvalue == "no")
                      {
					     cout<<"In Variable Expression a NULL valued variable!\n"<<"Variable Name: "<<myvar<<endl;
						 exit(0);
                       }

              return myvalue;					   
}


int main(int argc, char** argv){
    typeCheck["auto"] = typeCheck["break"] = typeCheck["case"] = typeCheck["char"] = typeCheck["const"] = typeCheck["continue"] = typeCheck["default"] = typeCheck["do"] = typeCheck["double"] = typeCheck["else"] = typeCheck["enum"] = typeCheck["extern"] = typeCheck["float"] = typeCheck["for"] = typeCheck["goto"] = typeCheck["if"] = typeCheck["int"] = typeCheck["long"] = typeCheck["register"] = typeCheck["return"] = typeCheck["short"] = typeCheck["signed"] = typeCheck["sizeof"] = typeCheck["static"] = typeCheck["struct"] = typeCheck["switch"] = typeCheck["typedef"] = typeCheck["union"] = typeCheck["unsigned"] = typeCheck["void"] = typeCheck["volatile"] = typeCheck["while"] = typeCheck["main"] = typeCheck["printf"] = 0;

   	yyin=fopen(argv[1],"r");

    yyparse();
	   
	printf("\nToken\tName\t\t\tType\t\t\tValue\n\n");
	for(int i=1;i<=tokenCount;i++)
	{
      cout<<" "<<i<<"\t"<<token_No[i].token_Name<<"\t\t"<<token_No[i].token_Type<<"\t\t"<<token_No[i].token_Value<<"\n"<<endl;
	}  
	   
	fclose(yyin);
	
	getchar();
	
	return 0;
}
