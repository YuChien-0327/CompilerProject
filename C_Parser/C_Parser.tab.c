
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "C_Parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct {
	int type; // 0: bool, 1: int, 2: char, 3: float, 4: double, 5: string
    char* name;

	bool	val_bool;
	int		val_int;
	char	val_char;
	float	val_float;
	double	val_double;
    char*	val_string;
} Variable;

Variable variables[100];
int numVariables = 0, numFunction = 3;

const char strtokSymbol[2] = "\"";
enum TYPE {
	// 0: bool, 1: int, 2: char, 3: float, 4: double, 5: string
    _BOOL,
    _INT,
    _CHAR,
    _FLOAT,
	_DOUBLE,
	_STRING
};

int yylex();
void yyerror(const char *s);
void print_endl(Variable var);
void print(Variable var);
int findVariable(char* name);


/* Line 189 of yacc.c  */
#line 114 "C_Parser.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING = 259,
     INTEGER = 260,
     FLOAT = 261,
     DOUBLE = 262,
     BOOL = 263,
     CHAR = 264,
     STRING_TYPE = 265,
     INT_TYPE = 266,
     FLOAT_TYPE = 267,
     CHAR_TYPE = 268,
     BOOL_TYPE = 269,
     DOUBLE_TYPE = 270,
     EQUALS = 271,
     SEMICOLON = 272,
     COUT = 273,
     CIN = 274,
     INSERTION_OP = 275,
     EXTRACTION_OP = 276,
     ENDL = 277,
     LOG = 278,
     ABS = 279,
     SQRT = 280
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 41 "C_Parser.y"

    char* identifier;
    char* str;
    int integer;
    float floating;
    double doulbes;
    bool boolean;
	char character;



/* Line 214 of yacc.c  */
#line 187 "C_Parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 199 "C_Parser.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNRULES -- Number of states.  */
#define YYNSTATES  266

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    30,     2,     2,
      31,    32,    28,    26,     2,    27,     2,    29,     2,     2,
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
      25
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    35,    40,    45,    47,    49,
      54,    59,    64,    69,    71,    73,    75,    77,    79,    81,
      88,    95,   102,   109,   116,   123,   130,   137,   144,   151,
     158,   165,   172,   179,   186,   193,   200,   207,   214,   221,
     228,   235,   242,   249,   256,   263,   270,   277,   284,   291,
     298,   305,   312,   319,   326,   333,   340,   347,   354,   361,
     368,   375,   382,   389,   396,   403,   410,   417,   424,   431,
     438,   445,   452,   459,   466,   473,   480,   487,   494,   501,
     508,   515,   522,   529,   536,   543,   550,   557,   564,   571,
     579,   587,   595,   603,   611,   619,   625,   629,   635,   639,
     645,   651,   657,   661,   667,   673,   677
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    -1,    34,    35,    -1,    36,    -1,
      37,    -1,    38,    -1,    39,    -1,    49,    -1,    50,    -1,
      48,    -1,    51,    -1,    52,    -1,    53,    -1,    18,    20,
       3,    20,    22,    17,    -1,    18,    20,     3,    17,    -1,
      19,    21,     3,    17,    -1,    40,    -1,    41,    -1,     3,
      16,     5,    17,    -1,     3,    16,     6,    17,    -1,     3,
      16,     7,    17,    -1,     3,    16,     4,    17,    -1,    42,
      -1,    43,    -1,    44,    -1,    45,    -1,    46,    -1,    47,
      -1,     3,    16,     3,    26,     3,    17,    -1,     3,    16,
       3,    26,     5,    17,    -1,     3,    16,     3,    26,     6,
      17,    -1,     3,    16,     3,    26,     7,    17,    -1,     3,
      16,     3,    26,     4,    17,    -1,     3,    16,     5,    26,
       3,    17,    -1,     3,    16,     5,    26,     5,    17,    -1,
       3,    16,     5,    26,     6,    17,    -1,     3,    16,     5,
      26,     7,    17,    -1,     3,    16,     6,    26,     3,    17,
      -1,     3,    16,     6,    26,     5,    17,    -1,     3,    16,
       6,    26,     6,    17,    -1,     3,    16,     6,    26,     7,
      17,    -1,     3,    16,     7,    26,     3,    17,    -1,     3,
      16,     7,    26,     5,    17,    -1,     3,    16,     7,    26,
       6,    17,    -1,     3,    16,     7,    26,     7,    17,    -1,
       3,    16,     4,    26,     4,    17,    -1,     3,    16,     3,
      27,     3,    17,    -1,     3,    16,     3,    27,     5,    17,
      -1,     3,    16,     3,    27,     6,    17,    -1,     3,    16,
       3,    27,     7,    17,    -1,     3,    16,     5,    27,     3,
      17,    -1,     3,    16,     5,    27,     5,    17,    -1,     3,
      16,     5,    27,     6,    17,    -1,     3,    16,     5,    27,
       7,    17,    -1,     3,    16,     6,    27,     3,    17,    -1,
       3,    16,     6,    27,     5,    17,    -1,     3,    16,     6,
      27,     6,    17,    -1,     3,    16,     6,    27,     7,    17,
      -1,     3,    16,     7,    27,     3,    17,    -1,     3,    16,
       7,    27,     5,    17,    -1,     3,    16,     7,    27,     6,
      17,    -1,     3,    16,     7,    27,     7,    17,    -1,     3,
      16,     3,    28,     3,    17,    -1,     3,    16,     3,    28,
       5,    17,    -1,     3,    16,     3,    28,     6,    17,    -1,
       3,    16,     3,    28,     7,    17,    -1,     3,    16,     5,
      28,     3,    17,    -1,     3,    16,     5,    28,     5,    17,
      -1,     3,    16,     5,    28,     6,    17,    -1,     3,    16,
       5,    28,     7,    17,    -1,     3,    16,     6,    28,     3,
      17,    -1,     3,    16,     6,    28,     5,    17,    -1,     3,
      16,     6,    28,     6,    17,    -1,     3,    16,     6,    28,
       7,    17,    -1,     3,    16,     7,    28,     3,    17,    -1,
       3,    16,     7,    28,     5,    17,    -1,     3,    16,     7,
      28,     6,    17,    -1,     3,    16,     7,    28,     7,    17,
      -1,     3,    16,     3,    29,     3,    17,    -1,     3,    16,
       3,    29,     5,    17,    -1,     3,    16,     3,    29,     6,
      17,    -1,     3,    16,     3,    29,     7,    17,    -1,     3,
      16,     5,    29,     3,    17,    -1,     3,    16,     5,    29,
       5,    17,    -1,     3,    16,     5,    29,     6,    17,    -1,
       3,    16,     5,    29,     7,    17,    -1,     3,    16,     6,
      29,     3,    17,    -1,     3,    16,     6,    29,     5,    17,
      -1,     3,    16,     6,    29,     6,    17,    -1,     3,    16,
       6,    29,     7,    17,    -1,     3,    16,     7,    29,     3,
      17,    -1,     3,    16,     7,    29,     5,    17,    -1,     3,
      16,     7,    29,     6,    17,    -1,     3,    16,     7,    29,
       7,    17,    -1,     3,    16,     3,    30,     3,    17,    -1,
       3,    16,     3,    30,     5,    17,    -1,     3,    16,     5,
      30,     3,    17,    -1,     3,    16,     5,    30,     5,    17,
      -1,     3,    16,    23,    31,     3,    32,    17,    -1,     3,
      16,    25,    31,     3,    32,    17,    -1,     3,    16,    24,
      31,     3,    32,    17,    -1,     3,    16,    23,    31,     5,
      32,    17,    -1,     3,    16,    25,    31,     5,    32,    17,
      -1,     3,    16,    24,    31,     5,    32,    17,    -1,    11,
       3,    16,     5,    17,    -1,    11,     3,    17,    -1,    10,
       3,    16,     4,    17,    -1,    10,     3,    17,    -1,    13,
       3,    16,     9,    17,    -1,    12,     3,    16,     6,    17,
      -1,    12,     3,    16,     5,    17,    -1,    12,     3,    17,
      -1,    15,     3,    16,     7,    17,    -1,    15,     3,    16,
       6,    17,    -1,    15,     3,    17,    -1,    14,     3,    16,
       8,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    75,    78,    79,    80,    81,    84,    85,
      86,    87,    88,    89,    92,   106,   120,   157,   158,   161,
     181,   197,   209,   223,   224,   225,   226,   227,   228,   231,
     294,   340,   380,   398,   414,   460,   484,   504,   518,   556,
     576,   596,   610,   634,   646,   658,   671,   684,   743,   789,
     829,   848,   894,   918,   938,   952,   990,  1010,  1030,  1044,
    1068,  1080,  1092,  1105,  1164,  1210,  1250,  1269,  1315,  1339,
    1359,  1373,  1411,  1431,  1451,  1465,  1489,  1501,  1513,  1526,
    1585,  1631,  1671,  1690,  1736,  1760,  1780,  1794,  1832,  1852,
    1872,  1886,  1910,  1922,  1934,  1947,  1963,  1978,  1993,  2008,
    2045,  2082,  2120,  2144,  2168,  2195,  2207,  2220,  2233,  2246,
    2261,  2273,  2285,  2298,  2310,  2322,  2335
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "INTEGER",
  "FLOAT", "DOUBLE", "BOOL", "CHAR", "STRING_TYPE", "INT_TYPE",
  "FLOAT_TYPE", "CHAR_TYPE", "BOOL_TYPE", "DOUBLE_TYPE", "EQUALS",
  "SEMICOLON", "COUT", "CIN", "INSERTION_OP", "EXTRACTION_OP", "ENDL",
  "LOG", "ABS", "SQRT", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'",
  "$accept", "program", "statement", "declaration", "cout_statement",
  "cin_statement", "assignment", "assignSingle", "operation", "add", "sub",
  "mul", "div", "mod", "function", "declare_int", "declare_str",
  "declare_char", "declare_float", "declare_double", "declare_bool", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    43,    45,    42,    47,
      37,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    34,    35,    35,    35,    35,    36,    36,
      36,    36,    36,    36,    37,    37,    38,    39,    39,    40,
      40,    40,    40,    41,    41,    41,    41,    41,    41,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    46,    46,    46,    46,    47,
      47,    47,    47,    47,    47,    48,    48,    49,    49,    50,
      51,    51,    51,    52,    52,    52,    53
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     4,     4,     1,     1,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     7,
       7,     7,     7,     7,     7,     5,     3,     5,     3,     5,
       5,     5,     3,     5,     5,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     4,     5,     6,     7,    17,    18,    23,    24,
      25,    26,    27,    28,    10,     8,     9,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,   106,     0,   112,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,    22,     0,    19,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   105,   111,   110,   109,   116,
     114,   113,     0,    29,    33,    30,    31,    32,    47,    48,
      49,    50,    63,    64,    65,    66,    79,    80,    81,    82,
      95,    96,    46,    34,    35,    36,    37,    51,    52,    53,
      54,    67,    68,    69,    70,    83,    84,    85,    86,    97,
      98,    38,    39,    40,    41,    55,    56,    57,    58,    71,
      72,    73,    74,    87,    88,    89,    90,    42,    43,    44,
      45,    59,    60,    61,    62,    75,    76,    77,    78,    91,
      92,    93,    94,     0,     0,     0,     0,     0,     0,    14,
      99,   102,   101,   104,   100,   103
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -21
static const yytype_int16 yypact[] =
{
      26,    14,    32,    40,    64,    71,    76,    81,    69,    73,
      13,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
      -3,    -5,    17,   134,    83,    88,   136,   106,   111,   -21,
     -21,   -20,   -12,    25,    30,    43,    93,    98,   103,   154,
     -21,   114,   -21,   149,   -21,   139,   131,   150,   -21,    29,
     142,    58,    12,    70,    75,    45,   -21,   156,   -21,    80,
      85,    90,    95,    63,   -21,   100,   105,   110,   115,   -21,
     120,   125,   130,   135,   140,   141,   144,   145,   146,   147,
     148,   151,   152,   153,   155,   -21,   157,   -21,   158,   159,
     160,   161,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   129,   229,
     230,   231,   232,   233,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   234,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   235,   236,   237,   238,   239,   240,   -21,
     -21,   -21,   -21,   -21,   -21,   -21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -21,   -21,   248,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      41,    42,    43,    44,    45,    66,    61,    62,    63,    64,
      65,    49,    50,    39,    67,   103,     1,   104,   105,   106,
      46,    47,    48,     2,     3,     4,     5,     6,     7,     1,
      30,     8,     9,    51,    52,    31,     2,     3,     4,     5,
       6,     7,    68,    32,     8,     9,    95,    74,   115,    96,
     116,    69,    70,    71,    72,    73,    75,    76,    77,    78,
      79,    98,    99,   100,   101,   102,   134,    33,   135,    80,
      81,    82,    83,   107,    34,   108,   109,   110,   111,    35,
     112,   113,   114,   118,    36,   119,   120,   121,   122,    37,
     123,   124,   125,   126,    38,   127,   128,   129,   130,    55,
     131,   132,   133,   136,    56,   137,   138,   139,   140,    59,
     141,   142,   143,   144,    60,   145,   146,   147,   148,    88,
     149,   150,   151,   152,    84,   153,   154,   155,   156,    85,
     157,   158,   159,   160,    86,   161,   162,   163,   164,    92,
     165,   166,   167,   168,   170,   169,   171,   172,    91,   173,
      53,    54,    57,    58,    89,    90,    93,    94,    87,    97,
     117,   253,   174,   175,   176,   177,     0,     0,   178,   179,
     180,     0,   181,     0,     0,   183,   184,   185,   186,   182,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,     0,     0,     0,     0,
       0,   259,   260,   261,   262,   263,   264,   265,    40,     0,
       0,   254,   255,   256,   257,   258
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,     7,    17,    26,    27,    28,    29,
      30,    16,    17,     0,    26,     3,     3,     5,     6,     7,
      23,    24,    25,    10,    11,    12,    13,    14,    15,     3,
      16,    18,    19,    16,    17,     3,    10,    11,    12,    13,
      14,    15,    17,     3,    18,    19,    17,    17,     3,    20,
       5,    26,    27,    28,    29,    30,    26,    27,    28,    29,
      17,     3,     4,     5,     6,     7,     3,     3,     5,    26,
      27,    28,    29,     3,     3,     5,     6,     7,     3,     3,
       5,     6,     7,     3,     3,     5,     6,     7,     3,    20,
       5,     6,     7,     3,    21,     5,     6,     7,     3,    16,
       5,     6,     7,     3,    16,     5,     6,     7,     3,     3,
       5,     6,     7,     3,     3,     5,     6,     7,     3,     5,
       5,     6,     7,     3,    31,     5,     6,     7,     3,    31,
       5,     6,     7,     3,    31,     5,     6,     7,     3,     8,
       5,     6,     7,     3,     3,     5,     5,     3,     9,     5,
      16,    17,    16,    17,     5,     6,     6,     7,     4,    17,
       4,    32,    17,    17,    17,    17,    -1,    -1,    17,    17,
      17,    -1,    17,    -1,    -1,    17,    17,    17,    17,    22,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    -1,    -1,    -1,    -1,
      -1,    17,    17,    17,    17,    17,    17,    17,    10,    -1,
      -1,    32,    32,    32,    32,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    10,    11,    12,    13,    14,    15,    18,    19,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      16,     3,     3,     3,     3,     3,     3,    20,    21,     0,
      35,     3,     4,     5,     6,     7,    23,    24,    25,    16,
      17,    16,    17,    16,    17,    16,    16,    16,    17,     3,
       3,    26,    27,    28,    29,    30,    17,    26,    17,    26,
      27,    28,    29,    30,    17,    26,    27,    28,    29,    17,
      26,    27,    28,    29,    31,    31,    31,     4,     5,     5,
       6,     9,     8,     6,     7,    17,    20,    17,     3,     4,
       5,     6,     7,     3,     5,     6,     7,     3,     5,     6,
       7,     3,     5,     6,     7,     3,     5,     4,     3,     5,
       6,     7,     3,     5,     6,     7,     3,     5,     6,     7,
       3,     5,     6,     7,     3,     5,     3,     5,     6,     7,
       3,     5,     6,     7,     3,     5,     6,     7,     3,     5,
       6,     7,     3,     5,     6,     7,     3,     5,     6,     7,
       3,     5,     6,     7,     3,     5,     6,     7,     3,     5,
       3,     5,     3,     5,    17,    17,    17,    17,    17,    17,
      17,    17,    22,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,    17,    32,    32,    32,    32,    32,    32,    17,
      17,    17,    17,    17,    17,    17
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 14:

/* Line 1455 of yacc.c  */
#line 93 "C_Parser.y"
    {
				int i;
				for (i = 0; i < numVariables; i++) {
					if (strcmp(variables[i].name, (yyvsp[(3) - (6)].identifier)) == 0){
						print_endl(variables[i]);
						break;
					}
				}
				if (i == numVariables) {
					printf(".. Variable %s not found\n", (yyvsp[(3) - (6)].identifier));
				}
			;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 107 "C_Parser.y"
    {
				int i;
				for (i = 0; i < numVariables; i++) {
					if (strcmp(variables[i].name, (yyvsp[(3) - (4)].identifier)) == 0){
						print(variables[i]);
						break;
					}
				}
				if (i == numVariables) {
					printf(".. Variable %s not found\n", (yyvsp[(3) - (4)].identifier));
				}
			;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 121 "C_Parser.y"
    {
				int i;
				for (i = 0; i < numVariables; i++) {
				 if (strcmp(variables[i].name, (yyvsp[(3) - (4)].identifier)) == 0) {
					if(variables[i].type == _BOOL){ //bool
					
					}else if(variables[i].type == _INT){
						int input;
						scanf("%d", &input);
						variables[i].val_int = input;
					}else if(variables[i].type == _CHAR){ //char
						
					}else if(variables[i].type == _FLOAT){
						float input;
						scanf("%f", &input);
						variables[i].val_float = input;
					}else if(variables[i].type == _DOUBLE){
						double input;
						scanf("%lf", &input);
						variables[i].val_double = input;
					}else if(variables[i].type == _STRING){
						char input[100];
						scanf("%s", input);
						variables[i].val_string = strdup(input);
					}else { 
						printf("Variable %s is not a type\n", variables[i].name);
					}
					break;
					}
				}
				if (i == numVariables) {
					printf("Variable %s not found\n", (yyvsp[(3) - (4)].identifier));
				}
			;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 162 "C_Parser.y"
    {
				int idx;
				for (idx = 0; idx < numVariables; idx++) 
					if (strcmp(variables[idx].name, (yyvsp[(1) - (4)].identifier)) == 0) break; 
				if (idx == numVariables) printf(".. Variable %s not found\n", (yyvsp[(1) - (4)].identifier));
				else if(variables[idx].type == _INT){
					variables[idx].val_int = (yyvsp[(3) - (4)].integer);
					printf(".. Variable %s is assigned to be %d\n", variables[idx].name, variables[idx].val_int);
				}
				else if(variables[idx].type == _FLOAT){
					variables[idx].val_float = (yyvsp[(3) - (4)].integer) / 1.0;
					printf(".. Variable %s is assigned to be %f\n", variables[idx].name, variables[idx].val_float);
				}
				else if(variables[idx].type == _DOUBLE){
					variables[idx].val_double = (double)(yyvsp[(3) - (4)].integer);
					printf(".. Variable %s is assigned to be %lf\n", variables[idx].name, variables[idx].val_double);
				}
				else printf(".. TypeError: Type of variable %s is not an integer\n", (yyvsp[(1) - (4)].identifier));
			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 182 "C_Parser.y"
    {
				int idx;
				for (idx = 0; idx < numVariables; idx++) 
					if (strcmp(variables[idx].name, (yyvsp[(1) - (4)].identifier)) == 0) break; 
				if (idx == numVariables) printf(".. Variable %s not found\n", (yyvsp[(1) - (4)].identifier));
				else if(variables[idx].type == _FLOAT){
					variables[idx].val_float = (yyvsp[(3) - (4)].floating);
					printf(".. Variable %s is assigned to be %f\n", variables[idx].name, variables[idx].val_float);
				}
				else if(variables[idx].type == _DOUBLE){
					variables[idx].val_double = (double)(yyvsp[(3) - (4)].floating);
					printf(".. Variable %s is assigned to be %lf\n", variables[idx].name, variables[idx].val_double);
				}
				else printf(".. TypeError: Type of variable %s is not a floating or double\n", (yyvsp[(1) - (4)].identifier));
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 198 "C_Parser.y"
    {
				int idx;
				for (idx = 0; idx < numVariables; idx++) 
					if (strcmp(variables[idx].name, (yyvsp[(1) - (4)].identifier)) == 0) break; 
				if (idx == numVariables) printf(".. Variable %s not found\n", (yyvsp[(1) - (4)].identifier));
				else if(variables[idx].type == _DOUBLE){
					variables[idx].val_double = (yyvsp[(3) - (4)].doulbes);
					printf(".. Variable %s is assigned to be %lf\n", variables[idx].name, variables[idx].val_double);
				}
				else printf(".. TypeError: Type of variable %s is not a double\n", (yyvsp[(1) - (4)].identifier));
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 210 "C_Parser.y"
    {
				int idx;
				for (idx = 0; idx < numVariables; idx++) 
					if (strcmp(variables[idx].name, (yyvsp[(1) - (4)].identifier)) == 0) break; 
				if (idx == numVariables) printf(".. Variable %s not found\n", (yyvsp[(1) - (4)].identifier));
				else if(variables[idx].type == _STRING){
					variables[idx].val_string = (yyvsp[(3) - (4)].str);
					printf(".. Variable %s is assigned to be %d\n", variables[idx].name, variables[idx].val_string);
				}
				else printf(".. TypeError: Type of variable %s is not a string\n", (yyvsp[(1) - (4)].identifier));
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 232 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if((variables[id3].type == _INT) && (variables[id5].type == _INT)){
						variables[id1].val_int = variables[id3].val_int + variables[id5].val_int;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT)){
						
						float f3, f5;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 + f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE)){
						
						double f3, f5;
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 + f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _STRING:
					if((variables[id3].type == _STRING) && (variables[id5].type == _STRING)){
						variables[id1].val_string = strcat(variables[id3].val_string, variables[id5].val_string);
						printf(".. Variable %s is changed to be %s\n", variables[id1].name, variables[id1].val_string);
					}
					else printf(".. TypeError: cannot change var to string\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 295 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id3].type == _INT){
						variables[id1].val_int = variables[id3].val_int + (yyvsp[(5) - (6)].integer);
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT){
						
						float f3, f5 = (yyvsp[(5) - (6)].integer) / 1.0;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						variables[id1].val_float = f3 + f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE){
						
						double f3, f5 = (double) (yyvsp[(5) - (6)].integer);
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						variables[id1].val_double = f3 + f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 341 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id3].type == _INT){
						variables[id1].val_float = variables[id3].val_int / 1.0 + (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_float = variables[id3].val_float + (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to float\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT){
						variables[id1].val_double = (double)variables[id3].val_int + (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_double = (double)variables[id3].val_float + (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _DOUBLE){
						variables[id1].val_double = variables[id3].val_double + (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to double\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 381 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){
				if(variables[id3].type == _DOUBLE){
					variables[id1].val_double = variables[id3].val_double + (yyvsp[(5) - (6)].doulbes);
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to double\n\n");
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 399 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			if(variables[id3].type == _STRING){
				char *st = strtok((yyvsp[(5) - (6)].str), strtokSymbol);
				variables[id1].val_string = strcat(variables[id3].val_string, st);
				printf(".. Variable %s is changed to be %s\n", variables[id1].name, variables[id1].val_string);
			}
			else printf(".. TypeError: cannot change var to string\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 415 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id5].type == _INT){
						variables[id1].val_int = variables[id5].val_int + (yyvsp[(3) - (6)].integer);
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						
						float f3 = (yyvsp[(3) - (6)].integer) / 1.0, f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 + f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f3 = (double) (yyvsp[(3) - (6)].integer), f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 + f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 461 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _INT:
					variables[id1].val_int = (yyvsp[(3) - (6)].integer) + (yyvsp[(5) - (6)].integer);
					printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					break;
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].integer) / 1.0 + (yyvsp[(5) - (6)].integer) / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].integer) + (double)(yyvsp[(5) - (6)].integer);;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 485 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].integer) / 1.0 + (yyvsp[(5) - (6)].floating);
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].integer) + (double)(yyvsp[(5) - (6)].floating);
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 505 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)(yyvsp[(3) - (6)].integer) + (yyvsp[(5) - (6)].doulbes);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 519 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						float  f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = (yyvsp[(3) - (6)].floating) + f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) + f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 557 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].floating) + (yyvsp[(5) - (6)].integer) / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) + (double)(yyvsp[(5) - (6)].integer);
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 577 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].floating) + (yyvsp[(5) - (6)].floating);
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) + (double)(yyvsp[(5) - (6)].floating);;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 597 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) + (yyvsp[(5) - (6)].doulbes);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 611 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){

				if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
					double f5;
					if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
					else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
					else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
					
					variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) + f5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to target type\n\n");
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 635 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) + (double)(yyvsp[(5) - (6)].integer);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 647 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) + (double)(yyvsp[(5) - (6)].floating);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 659 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) + (yyvsp[(5) - (6)].doulbes);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 672 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			char *st3 = strtok((yyvsp[(3) - (6)].str), strtokSymbol);
			char *st5 = strtok((yyvsp[(5) - (6)].str), strtokSymbol);
			variables[id1].val_string = strcat(st3, st5);
			printf(".. Variable %s is changed to be %s\n", variables[id1].name, variables[id1].val_string);
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 685 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if((variables[id3].type == _INT) && (variables[id5].type == _INT)){
						variables[id1].val_int = variables[id3].val_int - variables[id5].val_int;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT)){
						
						float f3, f5;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 - f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE)){
						
						double f3, f5;
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 - f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _STRING:
					printf("..TypeError: string type cannot be subtracted\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 744 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id3].type == _INT){
						variables[id1].val_int = variables[id3].val_int - (yyvsp[(5) - (6)].integer);
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT){
						
						float f3, f5 = (yyvsp[(5) - (6)].integer) / 1.0;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						variables[id1].val_float = f3 - f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE){
						
						double f3, f5 = (double) (yyvsp[(5) - (6)].integer);
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						variables[id1].val_double = f3 - f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 790 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id3].type == _INT){
						variables[id1].val_float = variables[id3].val_int / 1.0 - (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_float = variables[id3].val_float - (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to float\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT){
						variables[id1].val_double = (double)variables[id3].val_int - (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_double = (double)variables[id3].val_float - (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _DOUBLE){
						variables[id1].val_double = variables[id3].val_double - (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to double\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 830 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){
				if(variables[id3].type == _DOUBLE){
					variables[id1].val_double = variables[id3].val_double - (yyvsp[(5) - (6)].doulbes);
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to double\n\n");
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 849 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id5].type == _INT){
						variables[id1].val_int = variables[id5].val_int - (yyvsp[(3) - (6)].integer);
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						
						float f3 = (yyvsp[(3) - (6)].integer) / 1.0, f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 - f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f3 = (double) (yyvsp[(3) - (6)].integer), f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 - f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 895 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _INT:
					variables[id1].val_int = (yyvsp[(3) - (6)].integer) - (yyvsp[(5) - (6)].integer);
					printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					break;
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].integer) / 1.0 - (yyvsp[(5) - (6)].integer) / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].integer) - (double)(yyvsp[(5) - (6)].integer);;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 919 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].integer) / 1.0 - (yyvsp[(5) - (6)].floating);
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].integer) - (double)(yyvsp[(5) - (6)].floating);
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 939 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)(yyvsp[(3) - (6)].integer) - (yyvsp[(5) - (6)].doulbes);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 953 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						float  f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = (yyvsp[(3) - (6)].floating) - f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) - f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 991 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].floating) - (yyvsp[(5) - (6)].integer) / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) - (double)(yyvsp[(5) - (6)].integer);
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1011 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].floating) - (yyvsp[(5) - (6)].floating);
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) - (double)(yyvsp[(5) - (6)].floating);;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1031 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) - (yyvsp[(5) - (6)].doulbes);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1045 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){

				if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
					double f5;
					if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
					else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
					else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
					
					variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) - f5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to target type\n\n");
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1069 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) - (double)(yyvsp[(5) - (6)].integer);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1081 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) - (double)(yyvsp[(5) - (6)].floating);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1093 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) - (yyvsp[(5) - (6)].doulbes);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1106 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if((variables[id3].type == _INT) && (variables[id5].type == _INT)){
						variables[id1].val_int = variables[id3].val_int * variables[id5].val_int;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT)){
						
						float f3, f5;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 * f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE)){
						
						double f3, f5;
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 * f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _STRING:
					printf("..TypeError: string type cannot be multided");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1165 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id3].type == _INT){
						variables[id1].val_int = variables[id3].val_int * (yyvsp[(5) - (6)].integer);
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT){
						
						float f3, f5 = (yyvsp[(5) - (6)].integer) / 1.0;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						variables[id1].val_float = f3 * f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE){
						
						double f3, f5 = (double) (yyvsp[(5) - (6)].integer);
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						variables[id1].val_double = f3 * f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1211 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id3].type == _INT){
						variables[id1].val_float = variables[id3].val_int / 1.0 * (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_float = variables[id3].val_float * (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to float\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT){
						variables[id1].val_double = (double)variables[id3].val_int * (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_double = (double)variables[id3].val_float * (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _DOUBLE){
						variables[id1].val_double = variables[id3].val_double * (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to double\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1251 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){
				if(variables[id3].type == _DOUBLE){
					variables[id1].val_double = variables[id3].val_double * (yyvsp[(5) - (6)].doulbes);
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to double\n\n");
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1270 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id5].type == _INT){
						variables[id1].val_int = variables[id5].val_int * (yyvsp[(3) - (6)].integer);
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						
						float f3 = (yyvsp[(3) - (6)].integer) / 1.0, f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 * f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f3 = (double) (yyvsp[(3) - (6)].integer), f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 * f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1316 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _INT:
					variables[id1].val_int = (yyvsp[(3) - (6)].integer) * (yyvsp[(5) - (6)].integer);
					printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					break;
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].integer) / 1.0 * (yyvsp[(5) - (6)].integer) / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].integer) * (double)(yyvsp[(5) - (6)].integer);;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1340 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].integer) / 1.0 * (yyvsp[(5) - (6)].floating);
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].integer) * (double)(yyvsp[(5) - (6)].floating);
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1360 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)(yyvsp[(3) - (6)].integer) * (yyvsp[(5) - (6)].doulbes);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1374 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						float  f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = (yyvsp[(3) - (6)].floating) * f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) * f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1412 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].floating) * (yyvsp[(5) - (6)].integer) / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) * (double)(yyvsp[(5) - (6)].integer);
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1432 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].floating) * (yyvsp[(5) - (6)].floating);
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) * (double)(yyvsp[(5) - (6)].floating);;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1452 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) * (yyvsp[(5) - (6)].doulbes);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1466 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){

				if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
					double f5;
					if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
					else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
					else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
					
					variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) * f5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to target type\n\n");
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1490 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) * (double)(yyvsp[(5) - (6)].integer);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1502 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) * (double)(yyvsp[(5) - (6)].floating);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1514 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) * (yyvsp[(5) - (6)].doulbes);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1527 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if((variables[id3].type == _INT) && (variables[id5].type == _INT)){
						variables[id1].val_int = variables[id3].val_int / variables[id5].val_int;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT)){
						
						float f3, f5;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 / f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE)){
						
						double f3, f5;
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 / f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _STRING:
					printf("..TypeError: string type cannot be multided");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1586 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id3].type == _INT){
						variables[id1].val_int = variables[id3].val_int / (yyvsp[(5) - (6)].integer);
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT){
						
						float f3, f5 = (yyvsp[(5) - (6)].integer) / 1.0;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						variables[id1].val_float = f3 / f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE){
						
						double f3, f5 = (double) (yyvsp[(5) - (6)].integer);
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						variables[id1].val_double = f3 / f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1632 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id3].type == _INT){
						variables[id1].val_float = variables[id3].val_int / 1.0 / (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_float = variables[id3].val_float / (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to float\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT){
						variables[id1].val_double = (double)variables[id3].val_int / (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_double = (double)variables[id3].val_float / (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _DOUBLE){
						variables[id1].val_double = variables[id3].val_double / (yyvsp[(5) - (6)].floating);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to double\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1672 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){
				if(variables[id3].type == _DOUBLE){
					variables[id1].val_double = variables[id3].val_double / (yyvsp[(5) - (6)].doulbes);
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to double\n\n");
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1691 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id5].type == _INT){
						variables[id1].val_int = variables[id5].val_int / (yyvsp[(3) - (6)].integer);
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						
						float f3 = (yyvsp[(3) - (6)].integer) / 1.0, f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 / f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f3 = (double) (yyvsp[(3) - (6)].integer), f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 / f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1737 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _INT:
					variables[id1].val_int = (yyvsp[(3) - (6)].integer) / (yyvsp[(5) - (6)].integer);
					printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					break;
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].integer) / 1.0 / (yyvsp[(5) - (6)].integer) / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].integer) / (double)(yyvsp[(5) - (6)].integer);;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1761 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].integer) / 1.0 / (yyvsp[(5) - (6)].floating);
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].integer) / (double)(yyvsp[(5) - (6)].floating);
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1781 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)(yyvsp[(3) - (6)].integer) / (yyvsp[(5) - (6)].doulbes);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1795 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						float  f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = (yyvsp[(3) - (6)].floating) / f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) / f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1833 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].floating) / (yyvsp[(5) - (6)].integer) / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) / (double)(yyvsp[(5) - (6)].integer);
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1853 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = (yyvsp[(3) - (6)].floating) / (yyvsp[(5) - (6)].floating);
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) / (double)(yyvsp[(5) - (6)].floating);;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1873 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)(yyvsp[(3) - (6)].floating) / (yyvsp[(5) - (6)].doulbes);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1887 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){

				if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
					double f5;
					if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
					else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
					else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
					
					variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) / f5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to target type\n\n");
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1911 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) / (double)(yyvsp[(5) - (6)].integer);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1923 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) / (double)(yyvsp[(5) - (6)].floating);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1935 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (yyvsp[(3) - (6)].doulbes) / (yyvsp[(5) - (6)].doulbes);
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1948 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0 && id5 >= 0){
			// all variables are found
			if(variables[id1].type == _INT && variables[id3].type == _INT && variables[id5].type == _INT){
				variables[id1].val_int = variables[id3].val_int % variables[id5].val_int;
				printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
			}
			else printf(".. TypeError: cannot change var to integer\n\n"); 
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1964 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id3 = findVariable((yyvsp[(3) - (6)].identifier));

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			if(variables[id1].type == _INT && variables[id3].type == _INT){
				variables[id1].val_int = variables[id3].val_int % (yyvsp[(5) - (6)].integer);
				printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
			}
			else printf(".. TypeError: cannot change var to integer\n\n"); 
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1979 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));
		int id5 = findVariable((yyvsp[(5) - (6)].identifier));

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			if(variables[id1].type == _INT && variables[id5].type == _INT){
				variables[id1].val_int = (yyvsp[(3) - (6)].integer) % variables[id5].val_int;
				printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
			}
			else printf(".. TypeError: cannot change var to integer\n\n"); 
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1994 "C_Parser.y"
    {
		int id1 = findVariable((yyvsp[(1) - (6)].identifier));

		if(id1 >= 0){
			if(variables[id1].type == _INT){
				variables[id1].val_int = (yyvsp[(3) - (6)].integer) % (yyvsp[(5) - (6)].integer);
				printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
			}
			else printf(".. TypeError: cannot change var to integer\n\n"); 
		}
		else printf(".. VariableError: cannot find the variables\n");
	;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 2009 "C_Parser.y"
    {
			int id1 = findVariable((yyvsp[(1) - (7)].identifier));
			int id5 = findVariable((yyvsp[(5) - (7)].identifier));
			
			if(id1 >= 0 && id5 >= 0){
				switch(variables[id1].type){
					case _INT:
						if(variables[id5].type == _INT) {
							variables[id1].val_int = log10(variables[id5].val_int);
							printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
						}
						else printf(".. TypeError: function int log10(x) can only put in int\n");
						break;
					case _FLOAT:
						if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
							if(variables[id5].type == _INT) variables[id1].val_float = log10(variables[id5].val_int / 1.0);
							else if(variables[id5].type == _FLOAT) variables[id1].val_float = log10(variables[id5].val_float);
							printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
						}
						else printf(".. TypeError: float function log10(x) can only put in int/float\n");
						break;
					case _DOUBLE:
						if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
							if(variables[id5].type == _INT) variables[id1].val_double = log10((double)variables[id5].val_int);
							else if(variables[id5].type == _FLOAT) variables[id1].val_double = log10((double)variables[id5].val_float);
							else if(variables[id5].type == _DOUBLE) variables[id1].val_double = log10(variables[id5].val_double);
							printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
						}
						else printf(".. TypeError: function double log10(x) can only put in int/float/double\n");
						break;
					default:
						printf(".. TypeError: function log10(x) can only put out int/float/double\n");
				};
			}
			else printf(".. VariableError: cannot find the variables\n");
		;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 2046 "C_Parser.y"
    {
			int id1 = findVariable((yyvsp[(1) - (7)].identifier));
			int id5 = findVariable((yyvsp[(5) - (7)].identifier));
			
			if(id1 >= 0 && id5 >= 0){
				switch(variables[id1].type){
					case _INT:
						if(variables[id5].type == _INT) {
							variables[id1].val_int = sqrt(variables[id5].val_int);
							printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
						}
						else printf(".. TypeError: function int sqrt(x) can only put in int\n");
						break;
					case _FLOAT:
						if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
							if(variables[id5].type == _INT) variables[id1].val_float = sqrt(variables[id5].val_int / 1.0);
							else if(variables[id5].type == _FLOAT) variables[id1].val_float = sqrt(variables[id5].val_float);
							printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
						}
						else printf(".. TypeError: float function sqrt(x) can only put in int/float\n");
						break;
					case _DOUBLE:
						if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
							if(variables[id5].type == _INT) variables[id1].val_double = sqrt((double)variables[id5].val_int);
							else if(variables[id5].type == _FLOAT) variables[id1].val_double = sqrt((double)variables[id5].val_float);
							else if(variables[id5].type == _DOUBLE) variables[id1].val_double = sqrt(variables[id5].val_double);
							printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
						}
						else printf(".. TypeError: function double sqrt(x) can only put in int/float/double\n");
						break;
					default:
						printf(".. TypeError: function sqrt(x) can only put out int/float/double\n");
				};
			}
			else printf(".. VariableError: cannot find the variables\n");
		;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 2083 "C_Parser.y"
    {
			int id1 = findVariable((yyvsp[(1) - (7)].identifier));
			int id5 = findVariable((yyvsp[(5) - (7)].identifier));
			
			if(id1 >= 0 && id5 >= 0){
				switch(variables[id1].type){
					case _INT:
						if(variables[id5].type == _INT) {
							variables[id1].val_int = fabs(variables[id5].val_int);
							printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
						}
						else printf(".. TypeError: function int fabs(x) can only put in int\n");
						break;
					case _FLOAT:
						if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
							if(variables[id5].type == _INT) variables[id1].val_float = fabs(variables[id5].val_int / 1.0);
							else if(variables[id5].type == _FLOAT) variables[id1].val_float = fabs(variables[id5].val_float);
							printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
						}
						else printf(".. TypeError: float function fabs(x) can only put in int/float\n");
						break;
					case _DOUBLE:
						if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
							if(variables[id5].type == _INT) variables[id1].val_double = fabs((double)variables[id5].val_int);
							else if(variables[id5].type == _FLOAT) variables[id1].val_double = fabs((double)variables[id5].val_float);
							else if(variables[id5].type == _DOUBLE) variables[id1].val_double = fabs(variables[id5].val_double);
							printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
						}
						else printf(".. TypeError: function double fabs(x) can only put in int/float/double\n");
						break;
					default:
						printf(".. TypeError: function fabs(x) can only put out int/float/double\n");
				};
			}
			else printf(".. VariableError: cannot find the variables\n");
			
		;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 2121 "C_Parser.y"
    {
			int id1 = findVariable((yyvsp[(1) - (7)].identifier));
			
			if(id1 >= 0){
				switch(variables[id1].type){
					case _INT:
						variables[id1].val_int = log10((yyvsp[(5) - (7)].integer));
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
						break;
					case _FLOAT:
						variables[id1].val_float = log10((yyvsp[(5) - (7)].integer) / 1.0);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
						break;
					case _DOUBLE:
						variables[id1].val_double = log10((double)(yyvsp[(5) - (7)].integer));
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
						break;
					default:
						printf(".. TypeError: function log10(x) can only put out int/float/double\n");
				};
			}
			else printf(".. VariableError: cannot find the variables\n");
		;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 2145 "C_Parser.y"
    {
			int id1 = findVariable((yyvsp[(1) - (7)].identifier));
			
			if(id1 >= 0){
				switch(variables[id1].type){
					case _INT:
						variables[id1].val_int = sqrt((yyvsp[(5) - (7)].integer));
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
						break;
					case _FLOAT:
						variables[id1].val_float = sqrt((yyvsp[(5) - (7)].integer) / 1.0);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
						break;
					case _DOUBLE:
						variables[id1].val_double = sqrt((double)(yyvsp[(5) - (7)].integer));
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
						break;
					default:
						printf(".. TypeError: function sqrt(x) can only put out int/float/double\n");
				};
			}
			else printf(".. VariableError: cannot find the variables\n");
		;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 2169 "C_Parser.y"
    {
			int id1 = findVariable((yyvsp[(1) - (7)].identifier));

			if(id1 >= 0){
				switch(variables[id1].type){
					case _INT:
						variables[id1].val_int = fabs((yyvsp[(5) - (7)].integer));
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
						break;
					case _FLOAT:
						variables[id1].val_float = fabs((yyvsp[(5) - (7)].integer) / 1.0);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
						break;
					case _DOUBLE:
						variables[id1].val_double = fabs((double)(yyvsp[(5) - (7)].integer));
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
						break;
					default:
						printf(".. TypeError: function fabs(x) can only put out int/float/double\n");
				};
			}
			else printf(".. VariableError: cannot find the variables\n");
			
		;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 2196 "C_Parser.y"
    {
				if(findVariable((yyvsp[(2) - (5)].identifier)) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _INT;
					var.name = (yyvsp[(2) - (5)].identifier);
					var.val_int = (yyvsp[(4) - (5)].integer);
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %d\n", var.name, var.val_int);
				}
			;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 2208 "C_Parser.y"
    {
				if(findVariable((yyvsp[(2) - (3)].identifier)) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _INT;
					var.name = (yyvsp[(2) - (3)].identifier);
					var.val_int = 0;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value 0(default)\n", var.name);
				}
			;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 2221 "C_Parser.y"
    {
               	if(findVariable((yyvsp[(2) - (5)].identifier)) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _STRING;
					var.name = (yyvsp[(2) - (5)].identifier);
					char *st = strtok((yyvsp[(4) - (5)].str), strtokSymbol);
					var.val_string = st;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %s\n", var.name, var.val_string);
				}
           ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 2234 "C_Parser.y"
    {
               	if(findVariable((yyvsp[(2) - (3)].identifier)) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _STRING;
					var.name = (yyvsp[(2) - (3)].identifier);
					var.val_string = strdup("");
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value \'\\0\'\n", var.name);
				}
           ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 2247 "C_Parser.y"
    {
				if(findVariable((yyvsp[(2) - (5)].identifier)) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _CHAR;
					var.name = (yyvsp[(2) - (5)].identifier);
					var.val_char = (yyvsp[(4) - (5)].character);
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value ", var.name);
					putchar((yyvsp[(4) - (5)].character));
					printf("\n");
				}
           ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 2262 "C_Parser.y"
    {
				if(findVariable((yyvsp[(2) - (5)].identifier)) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _FLOAT;
					var.name = (yyvsp[(2) - (5)].identifier);
					var.val_float = (yyvsp[(4) - (5)].floating);
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %f\n", var.name, var.val_float);
				}
           ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 2274 "C_Parser.y"
    {
				if(findVariable((yyvsp[(2) - (5)].identifier)) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _FLOAT;
					var.name = (yyvsp[(2) - (5)].identifier);
					var.val_float = (yyvsp[(4) - (5)].integer) / 1.0;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %f\n", var.name, var.val_float);
				}
           ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 2286 "C_Parser.y"
    {
				if(findVariable((yyvsp[(2) - (3)].identifier)) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _FLOAT;
					var.name = (yyvsp[(2) - (3)].identifier);
					var.val_float = 0.0;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %f(default)\n", var.name, var.val_float);
				}
           ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 2299 "C_Parser.y"
    {
				if(findVariable((yyvsp[(2) - (5)].identifier)) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _DOUBLE;
					var.name = (yyvsp[(2) - (5)].identifier);
					var.val_double = (yyvsp[(4) - (5)].doulbes);
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %lf\n", var.name, var.val_double);
				}
           ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 2311 "C_Parser.y"
    {
				if(findVariable((yyvsp[(2) - (5)].identifier)) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _DOUBLE;
					var.name = (yyvsp[(2) - (5)].identifier);
					var.val_double = (yyvsp[(4) - (5)].floating);
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %f\n", var.name, var.val_double);
				}
           ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 2323 "C_Parser.y"
    {
				if(findVariable((yyvsp[(2) - (3)].identifier)) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _DOUBLE;
					var.name = (yyvsp[(2) - (3)].identifier);
					var.val_double = (double)0.0;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %lf(default)\n", var.name, var.val_double);
				}
           ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 2336 "C_Parser.y"
    {
				if(findVariable((yyvsp[(2) - (5)].identifier)) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _BOOL;
					var.name = (yyvsp[(2) - (5)].identifier);
					var.val_bool = (yyvsp[(4) - (5)].boolean);
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %d\n", var.name, (yyvsp[(4) - (5)].boolean));
				}
           ;}
    break;



/* Line 1455 of yacc.c  */
#line 4321 "C_Parser.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 2349 "C_Parser.y"


int main() {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf(".. TypeError: %s\n", s);
}

void print_endl(Variable var){
	if(var.type == _BOOL)	// bool
		printf("%b\n", var.val_bool);
	else if(var.type == _INT)	// int
		printf("%d\n", var.val_int);
	else if(var.type == _CHAR)	// char
		printf("%c\n", var.val_char);
	else if(var.type == _FLOAT)	// float
		printf("%f\n", var.val_float);
	else if(var.type == _DOUBLE)	// double
		printf("%lf\n", var.val_double);
	else if(var.type == _STRING)	// string
		printf("%s\n", var.val_string);
}

void print(Variable var){
	if(var.type == _BOOL)	// bool
		printf("%b", var.val_bool);
	else if(var.type == _INT)	// int
		printf("%d", var.val_int);
	else if(var.type == _CHAR)	// char
		putchar(var.val_char);
	else if(var.type == _FLOAT)	// float
		printf("%f", var.val_float);
	else if(var.type == _DOUBLE)	// double
		printf("%lf", var.val_double);
	else if(var.type == _STRING)	// string0
		printf("%s", var.val_string);
}

int findVariable(char* name){	// no find return -1
	int id = -1;
	int i = 0;
	for (i=0; i < numVariables; i++) {
		if (strcmp(variables[i].name, name) == 0) {
			id = i; 
			break;
		} 
	}
	return id;
}
