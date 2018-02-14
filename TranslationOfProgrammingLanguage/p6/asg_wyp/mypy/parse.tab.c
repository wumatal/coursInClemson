/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "includes/parse.y" /* yacc.c:339  */

	#include "includes/ast.h"
  #include <cmath>
  #include <iostream>
  #include <vector>

	int yylex (void);
	extern char *yytext;
	void yyerror (const char *);
	PoolOfNodes& pool = PoolOfNodes::getInstance();

#line 78 "parse.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AMPEREQUAL = 258,
    AMPERSAND = 259,
    AND = 260,
    AS = 261,
    ASSERT = 262,
    AT = 263,
    BACKQUOTE = 264,
    BAR = 265,
    BREAK = 266,
    CIRCUMFLEX = 267,
    CIRCUMFLEXEQUAL = 268,
    CLASS = 269,
    COLON = 270,
    COMMA = 271,
    CONTINUE = 272,
    DEDENT = 273,
    DEF = 274,
    DEL = 275,
    DOT = 276,
    DOUBLESLASHEQUAL = 277,
    DOUBLESTAREQUAL = 278,
    ELIF = 279,
    ELSE = 280,
    ENDMARKER = 281,
    EQEQUAL = 282,
    EXCEPT = 283,
    EXEC = 284,
    FINALLY = 285,
    FOR = 286,
    FROM = 287,
    GLOBAL = 288,
    GREATER = 289,
    GREATEREQUAL = 290,
    GRLT = 291,
    IF = 292,
    IMPORT = 293,
    IN = 294,
    INDENT = 295,
    IS = 296,
    LAMBDA = 297,
    LBRACE = 298,
    LEFTSHIFTEQUAL = 299,
    LESS = 300,
    LESSEQUAL = 301,
    LPAR = 302,
    LSQB = 303,
    MINEQUAL = 304,
    NEWLINE = 305,
    NOT = 306,
    NOTEQUAL = 307,
    NUMBER = 308,
    OR = 309,
    PASS = 310,
    PERCENTEQUAL = 311,
    PLUSEQUAL = 312,
    PRINT = 313,
    RAISE = 314,
    RBRACE = 315,
    RETURN = 316,
    RIGHTSHIFTEQUAL = 317,
    RPAR = 318,
    RSQB = 319,
    SEMI = 320,
    SLASHEQUAL = 321,
    STAREQUAL = 322,
    STRING = 323,
    TILDE = 324,
    TRY = 325,
    VBAREQUAL = 326,
    WHILE = 327,
    WITH = 328,
    YIELD = 329,
    EQUAL = 330,
    DOUBLESTAR = 331,
    LEFTSHIFT = 332,
    RIGHTSHIFT = 333,
    PLUS = 334,
    MINUS = 335,
    STAR = 336,
    SLASH = 337,
    PERCENT = 338,
    DOUBLESLASH = 339,
    NAME = 340,
    INT = 341,
    FLOAT = 342
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 14 "includes/parse.y" /* yacc.c:355  */

  Node* node;
  int intNumber;
  float fltNumber;
  char *id;
	std::vector<Node*>* vec;

#line 214 "parse.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "parse.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   969

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  140
/* YYNRULES -- Number of rules.  */
#define YYNRULES  316
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  480

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    64,    67,    68,    72,    74,    78,    79,
      82,    84,    88,    89,    92,    93,    96,   103,   109,   113,
     117,   131,   133,   137,   142,   146,   147,   150,   151,   154,
     156,   160,   166,   170,   171,   174,   175,   178,   180,   184,
     186,   190,   192,   196,   198,   200,   202,   204,   206,   208,
     210,   212,   216,   292,   299,   303,   305,   309,   314,   318,
     320,   322,   324,   326,   328,   330,   332,   334,   336,   338,
     340,   344,   350,   358,   360,   364,   366,   370,   371,   374,
     375,   378,   381,   384,   386,   388,   390,   392,   396,   399,
     402,   407,   416,   419,   420,   423,   424,   427,   428,   431,
     432,   435,   438,   441,   442,   445,   446,   447,   450,   451,
     454,   455,   458,   459,   462,   463,   466,   467,   470,   471,
     474,   477,   478,   481,   482,   485,   486,   489,   491,   493,
     495,   497,   499,   501,   503,   507,   517,   529,   530,   533,
     534,   537,   538,   541,   542,   545,   546,   549,   550,   553,
     554,   557,   560,   561,   564,   565,   568,   569,   572,   573,
     576,   577,   580,   581,   590,   595,   603,   604,   607,   608,
     611,   612,   615,   616,   619,   621,   625,   627,   631,   633,
     637,   639,   643,   645,   649,   651,   688,   690,   692,   694,
     696,   698,   700,   702,   704,   706,   708,   712,   714,   717,
     719,   722,   724,   727,   729,   743,   745,   749,   751,   765,
     767,   771,   773,   797,   799,   801,   803,   807,   815,   821,
     823,   825,   829,   834,   848,   850,   854,   856,   858,   860,
     862,   868,   873,   878,   880,   884,   886,   890,   892,   896,
     897,   900,   901,   904,   905,   908,   909,   912,   914,   918,
     919,   922,   934,   936,   940,   941,   944,   945,   948,   949,
     950,   953,   954,   957,   958,   961,   962,   965,   966,   969,
     970,   973,   975,   979,   980,   983,   984,   987,   988,   991,
     992,   995,   996,   999,  1000,  1003,  1015,  1025,  1029,  1030,
    1033,  1034,  1037,  1039,  1041,  1045,  1047,  1051,  1052,  1055,
    1056,  1059,  1060,  1063,  1064,  1067,  1068,  1071,  1073,  1077,
    1078,  1081,  1082,  1085,  1087,  1091,  1092
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AMPEREQUAL", "AMPERSAND", "AND", "AS",
  "ASSERT", "AT", "BACKQUOTE", "BAR", "BREAK", "CIRCUMFLEX",
  "CIRCUMFLEXEQUAL", "CLASS", "COLON", "COMMA", "CONTINUE", "DEDENT",
  "DEF", "DEL", "DOT", "DOUBLESLASHEQUAL", "DOUBLESTAREQUAL", "ELIF",
  "ELSE", "ENDMARKER", "EQEQUAL", "EXCEPT", "EXEC", "FINALLY", "FOR",
  "FROM", "GLOBAL", "GREATER", "GREATEREQUAL", "GRLT", "IF", "IMPORT",
  "IN", "INDENT", "IS", "LAMBDA", "LBRACE", "LEFTSHIFTEQUAL", "LESS",
  "LESSEQUAL", "LPAR", "LSQB", "MINEQUAL", "NEWLINE", "NOT", "NOTEQUAL",
  "NUMBER", "OR", "PASS", "PERCENTEQUAL", "PLUSEQUAL", "PRINT", "RAISE",
  "RBRACE", "RETURN", "RIGHTSHIFTEQUAL", "RPAR", "RSQB", "SEMI",
  "SLASHEQUAL", "STAREQUAL", "STRING", "TILDE", "TRY", "VBAREQUAL",
  "WHILE", "WITH", "YIELD", "EQUAL", "DOUBLESTAR", "LEFTSHIFT",
  "RIGHTSHIFT", "PLUS", "MINUS", "STAR", "SLASH", "PERCENT", "DOUBLESLASH",
  "NAME", "INT", "FLOAT", "$accept", "start", "file_input",
  "pick_NEWLINE_stmt", "star_NEWLINE_stmt", "decorator", "opt_arglist",
  "decorators", "decorated", "funcdef", "parameters", "varargslist",
  "opt_EQUAL_test", "star_fpdef_COMMA", "opt_DOUBLESTAR_NAME",
  "pick_STAR_DOUBLESTAR", "opt_COMMA", "fpdef", "fplist",
  "star_fpdef_notest", "stmt", "simple_stmt", "star_SEMI_small_stmt",
  "small_stmt", "expr_stmt", "pick_yield_expr_testlist", "star_EQUAL",
  "augassign", "print_stmt", "star_COMMA_test", "opt_test",
  "plus_COMMA_test", "opt_test_2", "del_stmt", "pass_stmt", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "yield_stmt", "raise_stmt",
  "opt_COMMA_test", "opt_test_3", "import_stmt", "import_name",
  "import_from", "pick_dotted_name", "pick_STAR_import", "import_as_name",
  "dotted_as_name", "import_as_names", "star_COMMA_import_as_name",
  "dotted_as_names", "dotted_name", "global_stmt", "star_COMMA_NAME",
  "exec_stmt", "assert_stmt", "compound_stmt", "if_stmt", "star_ELIF",
  "while_stmt", "for_stmt", "try_stmt", "plus_except", "opt_ELSE",
  "opt_FINALLY", "with_stmt", "star_COMMA_with_item", "with_item",
  "except_clause", "pick_AS_COMMA", "opt_AS_COMMA", "suite", "plus_stmt",
  "testlist_safe", "plus_COMMA_old_test", "old_test", "old_lambdef",
  "test", "opt_IF_ELSE", "or_test", "and_test", "not_test", "comparison",
  "comp_op", "expr", "xor_expr", "and_expr", "shift_expr",
  "pick_LEFTSHIFT_RIGHTSHIFT", "arith_expr", "pick_PLUS_MINUS", "term",
  "pick_multop", "factor", "pick_unop", "power", "star_trailer", "atom",
  "pick_yield_expr_testlist_comp", "opt_yield_test", "opt_listmaker",
  "opt_dictorsetmaker", "plus_STRING", "listmaker", "testlist_comp",
  "lambdef", "trailer", "subscriptlist", "star_COMMA_subscript",
  "subscript", "opt_test_only", "opt_sliceop", "sliceop", "exprlist",
  "star_COMMA_expr", "testlist", "dictorsetmaker", "star_test_COLON_test",
  "pick_for_test_test", "pick_for_test", "classdef", "opt_testlist",
  "arglist", "star_argument_COMMA", "star_COMMA_argument",
  "opt_DOUBLESTAR_test", "pick_argument", "argument", "opt_comp_for",
  "list_iter", "list_for", "list_if", "comp_iter", "comp_for", "comp_if",
  "testlist1", "yield_expr", "star_DOT", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342
};
# endif

#define YYPACT_NINF -338

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-338)))

#define YYTABLE_NINF -263

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -338,    44,  -338,   401,  -338,   813,    17,   813,  -338,    26,
    -338,    39,   131,  -338,   131,   131,  -338,    43,   813,    17,
      52,   813,    74,   813,  -338,   312,  -338,  -338,   289,   813,
     813,  -338,  -338,    64,   813,   813,   813,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,   104,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,     5,   129,  -338,   390,   136,   137,   151,
     -29,    65,   114,  -338,   131,  -338,  -338,    88,  -338,   894,
    -338,  -338,   141,  -338,     4,  -338,    71,    28,   117,   136,
    -338,    30,   126,   130,    -1,  -338,   154,  -338,   156,    32,
     813,   158,   -13,    31,   120,  -338,   146,  -338,   122,  -338,
    -338,   157,   125,  -338,  -338,   813,  -338,  -338,   175,  -338,
     644,   178,  -338,   195,  -338,  -338,  -338,  -338,     0,   187,
     312,   312,  -338,   312,  -338,  -338,  -338,  -338,  -338,   153,
    -338,  -338,   168,  -338,   131,   131,   131,   131,  -338,  -338,
     131,  -338,  -338,   131,  -338,  -338,  -338,  -338,   131,  -338,
      10,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,    74,    74,   813,   138,   145,  -338,
    -338,   813,   644,   813,   149,   200,   205,   813,   813,    -8,
     184,   204,   210,   644,    17,   143,  -338,   813,   -15,   144,
     148,  -338,  -338,   155,   813,   131,   215,  -338,  -338,  -338,
     215,  -338,  -338,   131,   215,  -338,  -338,   222,   215,   813,
    -338,   199,  -338,    76,   644,   123,   131,  -338,   708,   813,
      22,   129,  -338,  -338,  -338,   136,   137,   151,   -29,    65,
     114,  -338,   160,   145,   759,   131,  -338,   166,  -338,  -338,
    -338,  -338,  -338,  -338,   179,  -338,    13,  -338,  -338,  -338,
     180,  -338,   188,   644,   131,   234,   232,   169,  -338,   247,
    -338,  -338,  -338,   170,  -338,  -338,  -338,  -338,  -338,   193,
    -338,   242,   813,   243,   146,   221,   813,  -338,  -338,   224,
    -338,   813,   248,  -338,  -338,   234,   563,   813,   250,   107,
     252,   244,   644,   813,   136,  -338,  -338,  -338,   813,  -338,
     207,   251,   253,   213,  -338,   256,  -338,    74,   230,   813,
     813,    -4,  -338,   265,   268,  -338,  -338,   136,   813,  -338,
     644,   223,   203,   269,  -338,   127,   273,  -338,   214,  -338,
    -338,    11,  -338,   276,  -338,  -338,   312,   826,  -338,   813,
    -338,  -338,  -338,   482,    72,   644,   278,   264,   291,   644,
     297,  -338,  -338,  -338,  -338,   293,  -338,   299,   813,  -338,
    -338,  -338,  -338,   813,  -338,  -338,   257,  -338,   644,  -338,
     294,  -338,  -338,   169,   813,   307,   -15,   238,   813,  -338,
      77,   313,    59,   311,  -338,   280,  -338,  -338,  -338,  -338,
    -338,   813,  -338,  -338,   644,   315,  -338,   644,  -338,   644,
    -338,   231,  -338,   320,   322,  -338,  -338,   324,  -338,   326,
     644,  -338,  -338,   328,   826,  -338,  -338,  -338,   826,   329,
     826,  -338,  -338,  -338,   826,   330,  -338,  -338,   644,  -338,
    -338,  -338,   813,  -338,  -338,   772,  -338,   644,   644,  -338,
     813,    78,  -338,   826,    59,  -338,   826,  -338,  -338,  -338,
     813,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       7,     0,     2,     0,     1,     0,     0,     0,    88,     0,
      89,     0,     0,     3,     0,     0,   316,     0,     0,     0,
      24,   242,   238,   240,     4,     0,   233,    82,    76,    94,
      91,   244,   221,     0,     0,     0,   314,   219,   220,   230,
     231,   232,     6,    13,     0,   134,   132,     5,    37,    42,
      43,    44,    45,    46,    47,    83,    84,    85,    87,    86,
      48,    99,   100,    49,    50,    51,    38,   127,   128,   129,
     130,   131,    74,   177,   178,   180,   183,   184,   197,   199,
     201,   203,   207,   211,     0,   218,   225,   234,   175,    54,
     133,    92,   126,   118,     0,   311,     0,     0,     0,   270,
      81,   124,     0,     0,     0,   122,     0,   116,   101,   111,
       0,     0,     0,    74,     0,   241,    74,   237,     0,   236,
     235,    74,     0,   239,   182,     0,    71,    74,    98,    90,
       0,     0,   153,   155,   313,    12,    15,    14,     0,   272,
       0,     0,   174,     0,   188,   187,   189,   191,   193,   195,
     186,   190,     0,   192,     0,     0,     0,     0,   205,   206,
       0,   209,   210,     0,   213,   214,   215,   216,     0,   217,
     223,   243,    64,    66,    70,    69,    67,    60,    63,    59,
      68,    62,    61,    65,     0,     0,     0,     0,   287,     9,
     229,     0,     0,   284,    24,     0,   268,     0,     0,     0,
     315,   103,   120,     0,     0,     0,   250,     0,     0,     0,
       0,    31,    19,    22,     0,     0,    30,   274,   279,   228,
      30,   247,   226,     0,    30,   245,   227,    80,    30,     0,
      93,     0,   162,     0,     0,     0,     0,    40,     0,   271,
       0,   179,   181,   196,   194,   185,   198,   200,   202,   204,
     208,   212,     0,   287,   262,     0,   224,    58,    53,    56,
      55,    52,   125,   119,     0,    10,     0,   312,   282,   283,
       0,    18,     0,     0,   267,    96,     0,     0,   105,   109,
     102,   115,   107,     0,   138,   117,   110,   249,    36,     0,
      28,    26,     0,    30,   276,     0,    29,   280,   248,     0,
     246,     0,    30,    72,    75,    96,     0,   157,     0,   148,
       0,   140,     0,     0,   154,    39,    41,    73,     0,   253,
       0,     0,   259,     0,   257,     0,   222,     0,     0,     0,
       0,   298,   285,    30,     0,    17,    16,   269,     0,   123,
       0,     0,     0,   113,   121,   136,    34,    32,     0,    27,
      21,    23,    20,    30,   273,   277,     0,     0,    78,    29,
      79,    97,   165,     0,   161,     0,     0,   150,     0,     0,
       0,   151,   152,   176,   251,     0,   252,   255,   262,    57,
       8,   294,   289,     0,   295,   297,   286,   292,     0,    95,
     142,   106,   108,   112,     0,     0,    33,     0,    29,   278,
     308,    24,   302,   167,   171,   170,    77,   163,   164,   158,
     159,     0,   156,   144,     0,     0,   143,     0,   146,     0,
     258,   254,   261,   264,   291,   296,   281,     0,   114,     0,
       0,    35,    25,     0,     0,   307,   305,   306,     0,     0,
       0,   301,   299,   300,     0,    30,   160,   147,     0,   145,
     139,   256,   266,   260,   263,     0,   293,     0,     0,   135,
       0,   310,   173,     0,   304,   169,    29,   166,   149,   265,
       0,   288,   141,   137,   275,   309,   172,   303,   168,   290
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -338,  -338,  -338,  -338,  -338,   301,    94,  -338,  -338,   304,
    -338,  -187,  -338,  -338,  -338,  -338,  -183,  -202,  -338,  -338,
    -278,    -2,  -338,   111,  -338,   165,    24,  -338,  -338,    20,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,    47,  -338,  -338,  -338,  -338,  -338,  -338,   -40,   152,
      85,  -338,  -338,     9,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,    51,
      57,  -338,  -338,  -182,  -338,  -338,  -338,  -337,  -338,    -5,
    -338,  -137,   229,    -6,  -338,  -338,    21,   216,   226,   220,
    -338,   212,  -338,   225,  -338,   -73,  -338,  -338,  -338,  -338,
    -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,  -338,
    -338,   -42,     6,  -338,  -338,   -10,  -338,   -22,  -338,  -338,
    -338,  -338,   339,  -338,  -338,  -338,  -338,  -338,  -338,   -70,
    -338,   -78,   266,  -338,   -71,  -104,  -338,  -338,   -18,  -338
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    42,     3,    43,   264,    44,    45,    46,
     195,   111,   293,   112,   349,   212,   297,   213,   289,   346,
      47,   232,   138,    49,    50,   257,   258,   185,    51,   139,
     126,   302,   303,    52,    53,    54,    55,    56,    57,    58,
      59,   339,   230,    60,    61,    62,   103,   280,   281,   107,
     282,   343,   108,   109,    63,   202,    64,    65,    66,    67,
     345,    68,    69,    70,   309,   367,   416,    71,   235,   132,
     310,   411,   412,   233,   363,   402,   445,   403,   404,    72,
     142,    73,    74,    75,    76,   154,    77,    78,    79,    80,
     160,    81,   163,    82,   168,    83,    84,    85,   170,    86,
     117,   118,   122,   114,    87,   123,   119,    88,   256,   323,
     377,   324,   325,   453,   454,   100,   196,    89,   115,   353,
     354,   217,    90,   270,   265,   266,   424,   456,   332,   333,
     384,   441,   442,   443,   435,   436,   437,    96,    91,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,    48,    95,   240,   120,   102,   288,   272,   129,   218,
     268,   169,   221,   106,   134,    94,   113,   116,   121,   124,
     200,   284,     7,   127,   128,   187,   -29,   215,   362,   131,
     133,   252,   208,    99,   208,   101,    99,   298,   205,   277,
     155,   300,   140,   192,     4,   304,   214,   318,   158,   159,
     237,   188,   311,   187,   189,    20,    21,   253,   254,   141,
      22,    23,   215,   209,    25,   238,    26,   110,   210,   197,
     211,   383,   211,   278,   -29,   193,   141,   279,   409,   130,
     190,    31,    32,     7,    93,   408,   255,   191,   410,   329,
     223,   336,    37,    38,   330,   251,   440,   461,    39,    40,
      41,   462,    93,   464,   307,   206,   308,   465,   215,   215,
     352,    97,     6,   201,   434,   434,    20,    21,     9,   360,
     227,    22,    23,    11,    98,    25,   476,    26,   105,   478,
     371,   141,   366,   216,   143,   307,   220,   242,   312,   313,
       7,   224,    31,    32,   161,   162,   155,   228,    36,   156,
     387,   394,   395,    37,    38,   157,   171,   186,   390,    39,
      40,    41,   259,   259,   194,   198,   260,   260,   199,   203,
     399,   269,   204,   207,    21,   245,   276,   215,    22,    23,
     219,   262,   326,   413,    26,   222,   267,   418,   223,   226,
     355,   229,   275,   234,   431,   164,   165,   166,   167,    31,
      32,   236,   287,   239,   243,   295,   426,   244,   -11,   294,
      37,    38,   271,   299,   439,   273,    39,    40,    41,   400,
     405,   274,  -104,   263,   305,   187,   283,   385,   286,   290,
     292,   296,   447,   291,   317,   449,    99,   450,   301,   306,
       7,   327,   328,   334,    99,   319,  -262,   340,   459,   322,
     338,   335,   321,   342,   279,   344,   347,   314,   348,   351,
     356,   331,   467,   357,   359,   365,   468,   369,  -261,   370,
     374,   378,   375,    20,    21,   472,   473,   376,    22,    23,
     380,   386,    25,   388,    26,   393,   391,   350,   392,   396,
     397,   317,   398,   414,   415,   337,   358,   405,     7,    31,
      32,   405,   364,   405,    48,   259,   417,   405,   133,   260,
      37,    38,   419,   373,   420,   421,    39,    40,    41,   427,
     -29,     7,   430,   432,   381,   382,   405,   444,   438,   405,
     448,    20,    21,   389,   141,   452,    22,    23,   455,   457,
      25,   458,    26,   460,   463,   135,   466,   320,   136,   316,
     261,   379,   361,   428,   406,    21,   285,    31,    32,    22,
      23,    48,   341,    25,   372,    26,   368,   125,    37,    38,
     241,   246,   249,   422,    39,    40,    41,   248,   425,   451,
      31,    32,   247,   137,   423,   471,   477,   225,   250,   429,
     475,    37,    38,   433,     0,     0,     0,    39,    40,    41,
       0,     0,     0,     0,     0,     0,   446,     0,     5,     6,
       7,     0,     8,     0,     0,     9,   322,   144,    10,     0,
      11,    12,     0,     0,   145,   146,   147,    13,     0,   148,
      14,   149,    15,    16,    17,   150,   151,     0,    18,    19,
       0,   152,   153,    20,    21,     0,     0,   469,    22,    23,
     331,    24,    25,     0,    26,   474,    27,     0,     0,    28,
      29,     0,    30,     0,     0,   479,     0,     0,     0,    31,
      32,    33,     0,    34,    35,    36,     0,     0,     0,     0,
      37,    38,     0,     0,     0,     0,    39,    40,    41,     5,
       6,     7,     0,     8,     0,     0,     9,     0,     0,    10,
     407,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,    15,    16,    17,     0,     0,     0,    18,
      19,     0,     0,     0,    20,    21,     0,     0,     0,    22,
      23,     0,     0,    25,     0,    26,     0,    27,     0,     0,
      28,    29,     0,    30,     0,     0,     0,     0,     0,     0,
      31,    32,    33,     0,    34,    35,    36,     0,     0,     0,
       0,    37,    38,     0,     0,     0,     0,    39,    40,    41,
       5,     6,     7,     0,     8,     0,     0,     9,     0,     0,
      10,     0,    11,    12,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,    15,    16,    17,     0,     0,     0,
      18,    19,     0,     0,     0,    20,    21,     0,     0,     0,
      22,    23,     0,     0,    25,     0,    26,     0,    27,     0,
       0,    28,    29,     0,    30,     0,     0,     0,     0,     0,
       0,    31,    32,    33,     0,    34,    35,    36,     0,     0,
       0,     0,    37,    38,     0,     0,     0,     0,    39,    40,
      41,     5,     0,     7,     0,     8,     0,     0,     0,     0,
       0,    10,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,    16,    17,     0,     0,
       0,     0,    19,     0,     0,     0,    20,    21,     0,     0,
       0,    22,    23,     0,   231,    25,     0,    26,     0,    27,
       0,     0,    28,    29,     0,    30,     0,     0,     0,     0,
       0,     0,    31,    32,     0,     5,     0,     7,    36,     8,
       0,     0,     0,    37,    38,    10,     0,     0,    12,    39,
      40,    41,     0,     0,     0,     0,     0,    14,     0,     0,
      16,    17,     0,     0,     0,     0,    19,     0,     0,     0,
      20,    21,     0,     0,     0,    22,    23,     0,   315,    25,
       0,    26,     0,    27,     0,     0,    28,    29,     7,    30,
       0,     0,     0,     0,     0,     0,    31,    32,     0,     0,
     321,     7,    36,     0,     0,     0,     0,    37,    38,     0,
       0,     0,     0,    39,    40,    41,     0,     0,     0,     0,
       0,    20,    21,     0,     0,     0,    22,    23,     0,     0,
      25,     0,    26,     0,    20,    21,     0,     0,     0,    22,
      23,     0,     7,    25,     0,    26,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     7,     0,     0,    37,    38,
      31,    32,     0,     0,    39,    40,    41,     0,   470,     0,
       0,    37,    38,     0,     0,    20,    21,    39,    40,    41,
      22,    23,     0,     0,    25,     0,    26,     0,   401,    21,
       0,     0,     0,    22,    23,     0,     0,    25,     0,    26,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,    38,    31,    32,     0,   172,    39,    40,
      41,     0,     0,     0,     0,    37,    38,   173,     0,     0,
       0,    39,    40,    41,     0,     0,   174,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     0,     0,   177,     0,     0,     0,     0,     0,     0,
     178,   179,     0,     0,     0,     0,   180,     0,     0,     0,
     181,   182,     0,     0,     0,   183,     0,     0,     0,   184
};

static const yytype_int16 yycheck[] =
{
       5,     3,     7,   140,    22,    15,   208,   194,    30,   113,
     192,    84,   116,    18,    36,     6,    21,    22,    23,    25,
      21,   203,     9,    28,    29,    21,    15,    31,   306,    34,
      35,    21,    47,    12,    47,    14,    15,   220,     6,    47,
      10,   224,    37,    15,     0,   228,    15,    25,    77,    78,
      50,    47,   234,    21,    50,    42,    43,    47,    48,    54,
      47,    48,    31,    76,    51,    65,    53,    15,    81,    39,
      85,    75,    85,    81,    63,    47,    54,    85,     6,    15,
       9,    68,    69,     9,    85,   363,    76,    16,    16,    76,
      31,   273,    79,    80,    81,   168,    37,   434,    85,    86,
      87,   438,    85,   440,    28,   110,    30,   444,    31,    31,
     293,    85,     8,   104,    37,    37,    42,    43,    14,   302,
     125,    47,    48,    19,    85,    51,   463,    53,    85,   466,
     312,    54,    25,   113,     5,    28,   116,   143,    15,    16,
       9,   121,    68,    69,    79,    80,    10,   127,    74,    12,
     333,    24,    25,    79,    80,     4,    68,    16,   340,    85,
      86,    87,   184,   185,    47,    39,   184,   185,    38,    15,
     353,   193,    16,    15,    43,   154,   198,    31,    47,    48,
      60,   186,   255,   365,    53,    63,   191,   369,    31,    64,
     294,    16,   197,    15,   396,    81,    82,    83,    84,    68,
      69,     6,   207,    16,    51,   215,   388,    39,    63,   214,
      79,    80,    63,   223,   401,    15,    85,    86,    87,   356,
     357,    16,    38,    85,   229,    21,    16,   331,    85,    85,
      75,    16,   414,    85,   239,   417,   215,   419,    16,    40,
       9,    75,    63,    63,   223,    85,    15,    15,   430,   254,
      16,    63,    21,     6,    85,    85,    63,   236,    16,    16,
      39,   266,   445,    39,    16,    15,   448,    15,    15,    25,
      63,    15,    21,    42,    43,   457,   458,    64,    47,    48,
      50,    16,    51,    15,    53,    16,    63,   292,    85,    16,
      76,   296,    16,    15,    30,   274,   301,   434,     9,    68,
      69,   438,   307,   440,   306,   327,    15,   444,   313,   327,
      79,    80,    15,   318,    21,    16,    85,    86,    87,    25,
      63,     9,    15,    85,   329,   330,   463,    16,    15,   466,
      15,    42,    43,   338,    54,    15,    47,    48,    16,    15,
      51,    15,    53,    15,    15,    44,    16,   253,    44,   238,
     185,   327,   305,   393,   359,    43,   204,    68,    69,    47,
      48,   363,   277,    51,   313,    53,   309,    78,    79,    80,
     141,   155,   160,   378,    85,    86,    87,   157,   383,   421,
      68,    69,   156,    44,   378,   455,   464,   121,   163,   394,
     461,    79,    80,   398,    -1,    -1,    -1,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,   411,    -1,     7,     8,
       9,    -1,    11,    -1,    -1,    14,   421,    27,    17,    -1,
      19,    20,    -1,    -1,    34,    35,    36,    26,    -1,    39,
      29,    41,    31,    32,    33,    45,    46,    -1,    37,    38,
      -1,    51,    52,    42,    43,    -1,    -1,   452,    47,    48,
     455,    50,    51,    -1,    53,   460,    55,    -1,    -1,    58,
      59,    -1,    61,    -1,    -1,   470,    -1,    -1,    -1,    68,
      69,    70,    -1,    72,    73,    74,    -1,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    -1,    85,    86,    87,     7,
       8,     9,    -1,    11,    -1,    -1,    14,    -1,    -1,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    31,    32,    33,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    47,
      48,    -1,    -1,    51,    -1,    53,    -1,    55,    -1,    -1,
      58,    59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    -1,    72,    73,    74,    -1,    -1,    -1,
      -1,    79,    80,    -1,    -1,    -1,    -1,    85,    86,    87,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    -1,
      17,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    31,    32,    33,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      47,    48,    -1,    -1,    51,    -1,    53,    -1,    55,    -1,
      -1,    58,    59,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    -1,    72,    73,    74,    -1,    -1,
      -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    85,    86,
      87,     7,    -1,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    47,    48,    -1,    50,    51,    -1,    53,    -1,    55,
      -1,    -1,    58,    59,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    -1,     7,    -1,     9,    74,    11,
      -1,    -1,    -1,    79,    80,    17,    -1,    -1,    20,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    47,    48,    -1,    50,    51,
      -1,    53,    -1,    55,    -1,    -1,    58,    59,     9,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    -1,
      21,     9,    74,    -1,    -1,    -1,    -1,    79,    80,    -1,
      -1,    -1,    -1,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    47,    48,    -1,    -1,
      51,    -1,    53,    -1,    42,    43,    -1,    -1,    -1,    47,
      48,    -1,     9,    51,    -1,    53,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    79,    80,
      68,    69,    -1,    -1,    85,    86,    87,    -1,    76,    -1,
      -1,    79,    80,    -1,    -1,    42,    43,    85,    86,    87,
      47,    48,    -1,    -1,    51,    -1,    53,    -1,    42,    43,
      -1,    -1,    -1,    47,    48,    -1,    -1,    51,    -1,    53,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    80,    68,    69,    -1,     3,    85,    86,
      87,    -1,    -1,    -1,    -1,    79,    80,    13,    -1,    -1,
      -1,    85,    86,    87,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    71,    -1,    -1,    -1,    75
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    89,    90,    92,     0,     7,     8,     9,    11,    14,
      17,    19,    20,    26,    29,    31,    32,    33,    37,    38,
      42,    43,    47,    48,    50,    51,    53,    55,    58,    59,
      61,    68,    69,    70,    72,    73,    74,    79,    80,    85,
      86,    87,    91,    93,    95,    96,    97,   108,   109,   111,
     112,   116,   121,   122,   123,   124,   125,   126,   127,   128,
     131,   132,   133,   142,   144,   145,   146,   147,   149,   150,
     151,   155,   167,   169,   170,   171,   172,   174,   175,   176,
     177,   179,   181,   183,   184,   185,   187,   192,   195,   205,
     210,   226,   167,    85,   141,   167,   225,    85,    85,   174,
     203,   174,   203,   134,   227,    85,   167,   137,   140,   141,
      15,    99,   101,   167,   191,   206,   167,   188,   189,   194,
     226,   167,   190,   193,   171,    78,   118,   167,   167,   205,
      15,   167,   157,   167,   205,    93,    97,   210,   110,   117,
      37,    54,   168,     5,    27,    34,    35,    36,    39,    41,
      45,    46,    51,    52,   173,    10,    12,     4,    77,    78,
     178,    79,    80,   180,    81,    82,    83,    84,   182,   183,
     186,    68,     3,    13,    22,    23,    44,    49,    56,    57,
      62,    66,    67,    71,    75,   115,    16,    21,    47,    50,
       9,    16,    15,    47,    47,    98,   204,    39,    39,    38,
      21,   141,   143,    15,    16,     6,   167,    15,    47,    76,
      81,    85,   103,   105,    15,    31,   117,   209,   223,    60,
     117,   223,    63,    31,   117,   220,    64,   167,   117,    16,
     130,    50,   109,   161,    15,   156,     6,    50,    65,    16,
     169,   170,   171,    51,    39,   174,   175,   176,   177,   179,
     181,   183,    21,    47,    48,    76,   196,   113,   114,   205,
     226,   113,   167,    85,    94,   212,   213,   167,   161,   205,
     211,    63,    99,    15,    16,   167,   205,    47,    81,    85,
     135,   136,   138,    16,   161,   137,    85,   167,   105,   106,
      85,    85,    75,   100,   167,   203,    16,   104,   104,   203,
     104,    16,   119,   120,   104,   167,    40,    28,    30,   152,
     158,   161,    15,    16,   174,    50,   111,   167,    25,    85,
      94,    21,   167,   197,   199,   200,   183,    75,    63,    76,
      81,   167,   216,   217,    63,    63,   161,   174,    16,   129,
      15,   138,     6,   139,    85,   148,   107,    63,    16,   102,
     167,    16,   104,   207,   208,   223,    39,    39,   167,    16,
     104,   129,   108,   162,   167,    15,    25,   153,   158,    15,
      25,   161,   157,   167,    63,    21,    64,   198,    15,   114,
      50,   167,   167,    75,   218,   223,    16,   104,    15,   167,
     161,    63,    85,    16,    24,    25,    16,    76,    16,   104,
     169,    42,   163,   165,   166,   169,   167,    18,   108,     6,
      16,   159,   160,   161,    15,    30,   154,    15,   161,    15,
      21,    16,   167,   200,   214,   167,   161,    25,   136,   167,
      15,   105,    85,   167,    37,   222,   223,   224,    15,    99,
      37,   219,   220,   221,    16,   164,   167,   161,    15,   161,
     161,   199,    15,   201,   202,    16,   215,    15,    15,   161,
      15,   165,   165,    15,   165,   165,    16,   104,   161,   167,
      76,   217,   161,   161,   167,   222,   165,   219,   165,   167
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   112,   113,   113,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   122,   123,   123,   123,   123,   123,   124,   125,
     126,   126,   127,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   133,   134,   134,   135,   135,   135,   136,   136,
     137,   137,   138,   138,   139,   139,   140,   140,   141,   141,
     142,   143,   143,   144,   144,   145,   145,   146,   146,   146,
     146,   146,   146,   146,   146,   147,   147,   148,   148,   149,
     149,   150,   150,   151,   151,   152,   152,   153,   153,   154,
     154,   155,   156,   156,   157,   157,   158,   158,   159,   159,
     160,   160,   161,   161,   162,   162,   163,   163,   164,   164,
     165,   165,   166,   166,   167,   167,   168,   168,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   174,   174,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     180,   181,   181,   182,   182,   182,   182,   183,   183,   184,
     184,   184,   185,   185,   186,   186,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   188,   188,   189,   189,   190,
     190,   191,   191,   192,   192,   193,   193,   194,   194,   195,
     195,   196,   196,   196,   197,   197,   198,   198,   199,   199,
     199,   200,   200,   201,   201,   202,   202,   203,   203,   204,
     204,   205,   205,   206,   206,   207,   207,   208,   208,   209,
     209,   210,   210,   211,   211,   212,   213,   213,   214,   214,
     215,   215,   216,   216,   216,   217,   217,   218,   218,   219,
     219,   220,   220,   221,   221,   222,   222,   223,   223,   224,
     224,   225,   225,   226,   226,   227,   227
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     0,     6,     3,
       1,     0,     2,     1,     2,     2,     5,     3,     2,     2,
       4,     2,     0,     4,     0,     3,     0,     3,     2,     1,
       0,     1,     3,     3,     2,     3,     0,     1,     1,     4,
       3,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     3,     0,     3,     0,     3,     2,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     1,     2,     0,     3,     0,     1,
       1,     2,     4,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     3,     0,     1,     3,     1,     3,
       3,     3,     0,     5,     2,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     8,     5,     5,     0,     7,
       4,     9,     6,     6,     6,     4,     3,     3,     0,     3,
       0,     5,     3,     0,     3,     1,     3,     1,     1,     1,
       2,     0,     1,     4,     2,     1,     3,     1,     3,     2,
       1,     1,     4,     3,     2,     1,     4,     0,     1,     3,
       1,     3,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     4,     2,     2,     0,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       0,     1,     0,     2,     1,     2,     3,     2,     3,     4,
       3,     3,     3,     2,     3,     2,     3,     0,     3,     1,
       4,     1,     0,     1,     0,     2,     1,     3,     2,     3,
       0,     3,     2,     4,     2,     5,     0,     1,     2,     1,
       2,     7,     4,     1,     0,     2,     3,     0,     3,     0,
       3,     0,     2,     4,     2,     2,     3,     1,     0,     1,
       1,     5,     4,     3,     2,     1,     1,     5,     4,     3,
       2,     1,     3,     2,     1,     2,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 69 "includes/parse.y" /* yacc.c:1646  */
    {	(yyvsp[0].node)->eval("global");	  	}
#line 1916 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 83 "includes/parse.y" /* yacc.c:1646  */
    {	(yyval.vec) = (yyvsp[0].vec);				}
#line 1922 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 85 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.vec) = NULL; 			}
#line 1928 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 96 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new FuncNode( (yyvsp[-3].id), (yyvsp[-2].node), (yyvsp[0].node) );
			pool.add((yyval.node));
			delete [] (yyvsp[-3].id);
	}
#line 1938 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 104 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new FmlParaNode((yyvsp[-1].vec));
			delete (yyvsp[-1].vec);
			pool.add((yyval.node));
		}
#line 1948 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 110 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;	}
#line 1954 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 114 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.vec) = (yyvsp[-1].vec);
		}
#line 1962 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 118 "includes/parse.y" /* yacc.c:1646  */
    {
			if( (yyvsp[-1].node) != NULL ){
				Node* temp = new AsgBinaryNode((yyvsp[-2].node), (yyvsp[-1].node));
				(yyvsp[-3].vec)->push_back(temp);
				pool.add(temp);
			}
			else {
				(yyvsp[-3].vec)->push_back((yyvsp[-2].node));
			}
			(yyval.vec) = (yyvsp[-3].vec);
		}
#line 1978 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 132 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);			}
#line 1984 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 134 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;		}
#line 1990 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 138 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyvsp[-3].vec)->push_back((yyvsp[-2].node));
			(yyval.vec) = (yyvsp[-3].vec);
		}
#line 1999 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 143 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.vec) = new std::vector<Node*>(); }
#line 2005 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 155 "includes/parse.y" /* yacc.c:1646  */
    {	(yyval.node) = NULL;   	}
#line 2011 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 157 "includes/parse.y" /* yacc.c:1646  */
    {	(yyval.node) = NULL;   	}
#line 2017 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 161 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new IdentNode((yyvsp[0].id));
			delete [] (yyvsp[0].id);
			pool.add((yyval.node));
		}
#line 2027 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 167 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;							}
#line 2033 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 179 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);			}
#line 2039 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 181 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);			}
#line 2045 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 185 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-3].node);			}
#line 2051 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 187 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node);			}
#line 2057 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 197 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); 			}
#line 2063 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 199 "includes/parse.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[0].node);			}
#line 2069 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 201 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   	}
#line 2075 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 203 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2081 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 205 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); 			}
#line 2087 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 207 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2093 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 209 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2099 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 211 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2105 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 213 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2111 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 217 "includes/parse.y" /* yacc.c:1646  */
    {
			Node* temp = NULL;
			switch ((yyvsp[-1].intNumber)) {
        case PLUSEQUAL:
					temp = new AddBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
					(yyval.node) = new AsgBinaryNode((yyvsp[-2].node), temp);
					pool.add(temp);
					pool.add((yyval.node));
          break;
        case MINEQUAL:
					// $$ = new MinusAsgBinaryNode($1, $3);
					// pool.add($$);
					temp = new SubBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
					(yyval.node) = new AsgBinaryNode((yyvsp[-2].node), temp);
					pool.add(temp);
					pool.add((yyval.node));
          break;
        case STAREQUAL:
					// $$ = new MulBinaryNode($1, $3);
					// pool.add($$);
					temp = new MulBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
					(yyval.node) = new AsgBinaryNode((yyvsp[-2].node), temp);
					pool.add(temp);
					pool.add((yyval.node));
          break;
        case SLASHEQUAL:
					// $$ = new DivAsgBinaryNode($1, $3);
					// pool.add($$);
					temp = new DivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
					(yyval.node) = new AsgBinaryNode((yyvsp[-2].node), temp);
					pool.add(temp);
					pool.add((yyval.node));
          break;
        case PERCENTEQUAL:
					// $$ = new ModAsgBinaryNode($1, $3);
					// pool.add($$);
					temp = new ModBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
					(yyval.node) = new AsgBinaryNode((yyvsp[-2].node), temp);
					pool.add(temp);
					pool.add((yyval.node));
          break;
        case DOUBLESTAREQUAL:
					// $$ = new PowAsgBinaryNode($1, $3);
					// pool.add($$);
					temp = new PowBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
					(yyval.node) = new AsgBinaryNode((yyvsp[-2].node), temp);
					pool.add(temp);
					pool.add((yyval.node));
          break;
        case DOUBLESLASHEQUAL:
					// $$ = new IdivAsgBinaryNode($1, $3);
					// pool.add($$);
					temp = new IdivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
					(yyval.node) = new AsgBinaryNode((yyvsp[-2].node), temp);
					pool.add(temp);
					pool.add((yyval.node));
          break;
				// /* Add shift operations */
				// case LEFTSHIFTEQUAL:
				// 	temp = new LShiftBinaryNode($1, $3);
				// 	$$ = new AsgBinaryNode($1, temp);
				// 	pool.add(temp);
				// 	pool.add($$);
				// 	break;
				// case RIGHTSHIFTEQUAL:
				// 	temp = new RShiftBinaryNode($1, $3);
				// 	$$ = new AsgBinaryNode($1, temp);
				// 	pool.add(temp);
				// 	pool.add($$);
				// 	break;
        default:
					(yyval.node) = NULL;
          break;
      }
		}
#line 2191 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 293 "includes/parse.y" /* yacc.c:1646  */
    {
			// ```
			//if ($2 != nullptr) {
			(yyval.node) = new AsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
			pool.add((yyval.node));
		}
#line 2202 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 300 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);		}
#line 2208 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 304 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);		}
#line 2214 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 306 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);		}
#line 2220 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 310 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new AsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
			pool.add((yyval.node));
		}
#line 2229 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 315 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2235 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 319 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = PLUSEQUAL;				 }
#line 2241 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 321 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = MINEQUAL; 				 }
#line 2247 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 323 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = STAREQUAL; 			 }
#line 2253 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 325 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = SLASHEQUAL; 			 }
#line 2259 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 327 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = PERCENTEQUAL; 		 }
#line 2265 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 329 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = AMPEREQUAL;			 }
#line 2271 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 331 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = VBAREQUAL;				 }
#line 2277 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 333 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = CIRCUMFLEXEQUAL;	 }
#line 2283 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 335 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = LEFTSHIFTEQUAL;	 }
#line 2289 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 337 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = RIGHTSHIFTEQUAL;	 }
#line 2295 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 339 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = DOUBLESTAREQUAL;	 }
#line 2301 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 341 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = DOUBLESLASHEQUAL; }
#line 2307 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 345 "includes/parse.y" /* yacc.c:1646  */
    {
			/*if( $2 )	$2->eval()->print();*/
			(yyval.node) = new PrintNode( (yyvsp[0].node) );
			pool.add( (yyval.node) );
		}
#line 2317 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 351 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2323 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 359 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2329 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 361 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2335 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 365 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); 			}
#line 2341 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 367 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2347 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 385 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   			}
#line 2353 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 387 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   			}
#line 2359 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 389 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);					}
#line 2365 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 391 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   			}
#line 2371 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 393 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   			}
#line 2377 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 403 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new ReturnNode((yyvsp[0].node));
			pool.add((yyval.node));
		}
#line 2386 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 408 "includes/parse.y" /* yacc.c:1646  */
    {
			/* const Node* node = new IntLiteral(0); */
			(yyval.node) = new ReturnNode(nullptr);
			pool.add((yyval.node));
			/* pool.add(Node); */
		}
#line 2397 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 490 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);			}
#line 2403 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 492 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   	}
#line 2409 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 494 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   	}
#line 2415 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 496 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   	}
#line 2421 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 498 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   	}
#line 2427 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 500 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);			}
#line 2433 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 502 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   	}
#line 2439 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 504 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   	}
#line 2445 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 508 "includes/parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-6].node)) {
				(yyval.node) = new IfNode((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[0].node));
				pool.add((yyval.node));
			}
			else {
				std::cout << "SyntaxError: invalid syntax" << std::endl;
			}
		}
#line 2459 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 518 "includes/parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-3].node)) {
        (yyval.node) = new IfNode((yyvsp[-3].node), (yyvsp[-1].node), NULL);
        pool.add((yyval.node));
      }
      else {
        std::cout << "SyntaxError: invalid syntax" << std::endl;
      }
		}
#line 2473 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 582 "includes/parse.y" /* yacc.c:1646  */
    {

			(yyval.node) = new SuiteNode( *(yyvsp[-1].vec) );
			pool.add((yyval.node));
			delete (yyvsp[-1].vec);
		}
#line 2484 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 591 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.vec) = (yyvsp[-1].vec);
			(yyval.vec)->push_back((yyvsp[0].node));
		}
#line 2493 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 596 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.vec) = new std::vector<Node*>();
			// $$->reserve(8);
			(yyval.vec)->push_back((yyvsp[0].node));
		}
#line 2503 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 620 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);	 		}
#line 2509 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 622 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2515 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 626 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2521 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 628 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2527 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 632 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);	 		}
#line 2533 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 634 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2539 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 638 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);	 		}
#line 2545 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 640 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2551 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 644 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 2557 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 646 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);	 		}
#line 2563 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 650 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);	 		}
#line 2569 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 652 "includes/parse.y" /* yacc.c:1646  */
    {
			switch((yyvsp[-1].intNumber)) {
				case LESS:
					(yyval.node) = new LessThanBianryNode((yyvsp[-2].node), (yyvsp[0].node));
					pool.add((yyval.node));
					break;
				case LESSEQUAL:
					(yyval.node) = new LessEqualBianryNode((yyvsp[-2].node), (yyvsp[0].node));
					pool.add((yyval.node));
					break;
				case NOTEQUAL:
					(yyval.node) = new NotEqualBianryNode((yyvsp[-2].node), (yyvsp[0].node));
					pool.add((yyval.node));
					break;
	      case EQEQUAL:
	        (yyval.node) = new EqualBianryNode((yyvsp[-2].node), (yyvsp[0].node));
	        pool.add((yyval.node));
	        break;
	      case GREATER:
	        (yyval.node) = new GreatThanBianryNode((yyvsp[-2].node), (yyvsp[0].node));
	        pool.add((yyval.node));
	        break;
	      case GREATEREQUAL:
	        (yyval.node) = new GreatEqualBianryNode((yyvsp[-2].node), (yyvsp[0].node));
	        pool.add((yyval.node));
	        break;
	      case GRLT:
	        (yyval.node) = new NotEqualBianryNode((yyvsp[-2].node), (yyvsp[0].node));
	        pool.add((yyval.node));
	        break;
	      default:
	        break;
			}
		}
#line 2608 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 689 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = LESS; 					}
#line 2614 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 691 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = GREATER; 			}
#line 2620 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 693 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = EQEQUAL; 			}
#line 2626 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 695 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = GREATEREQUAL; 	}
#line 2632 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 697 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = LESSEQUAL; 		}
#line 2638 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 699 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = GRLT; 					}
#line 2644 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 701 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = NOTEQUAL; 			}
#line 2650 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 703 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = IN; 						}
#line 2656 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 705 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = 0; 						}
#line 2662 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 707 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = IS; 						}
#line 2668 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 709 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = 0; 						}
#line 2674 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 713 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);						}
#line 2680 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 718 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);						}
#line 2686 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 723 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);						}
#line 2692 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 728 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);						}
#line 2698 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 730 "includes/parse.y" /* yacc.c:1646  */
    {
			// if ($2 == LEFTSHIFT) {
			// 	$$ = new LShiftBinaryNode($1, $3);
			// 	pool.add($$);
			// }
			// if ($2 == RIGHTSHIFT) {
			// 	$$ = new RShiftBinaryNode($1, $3);
			// 	pool.add($$);
			// }
			(yyval.node) = NULL;
		}
#line 2714 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 744 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = LEFTSHIFT; 		}
#line 2720 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 746 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = RIGHTSHIFT; 		}
#line 2726 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 750 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); 						}
#line 2732 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 752 "includes/parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-1].intNumber) == PLUS) {
				(yyval.node) = new AddBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				// std::cout << "here" << std::endl;
				pool.add((yyval.node));
			}
			if ((yyvsp[-1].intNumber) == MINUS) {
				(yyval.node) = new SubBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				pool.add((yyval.node));
			}
		}
#line 2748 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 766 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = PLUS;					}
#line 2754 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 768 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = MINUS;					}
#line 2760 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 772 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); 						}
#line 2766 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 774 "includes/parse.y" /* yacc.c:1646  */
    {
			switch ((yyvsp[-1].intNumber)) {
				case STAR :
					(yyval.node) = new MulBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
          pool.add((yyval.node));
					break;
				case SLASH :
					(yyval.node) = new DivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
          pool.add((yyval.node));
					break;
				case PERCENT :
					(yyval.node) = new ModBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
          pool.add((yyval.node));
					break;
				case DOUBLESLASH :
					(yyval.node) = new IdivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
          pool.add((yyval.node));
					break;
			}
			//delete [] $2;
		}
#line 2792 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 798 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = STAR; 				}
#line 2798 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 800 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = SLASH; 			}
#line 2804 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 802 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = PERCENT;			}
#line 2810 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 804 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = DOUBLESLASH;	}
#line 2816 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 808 "includes/parse.y" /* yacc.c:1646  */
    {
			if( (yyvsp[-1].intNumber)==PLUS )
				(yyval.node) = new UnaryNode('+', (yyvsp[0].node));
			else
				(yyval.node) = new UnaryNode('-', (yyvsp[0].node));
      pool.add((yyval.node));
		}
#line 2828 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 816 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node);
		}
#line 2836 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 822 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = PLUS; 	}
#line 2842 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 824 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = MINUS; }
#line 2848 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 826 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = TILDE;	}
#line 2854 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 830 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new PowBinaryNode((yyvsp[-3].node), (yyvsp[0].node));
      pool.add((yyval.node));
		}
#line 2863 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 835 "includes/parse.y" /* yacc.c:1646  */
    {
			if((yyvsp[0].node) != NULL) {
				// int s = $1->getIdent();
				std::string n = reinterpret_cast<IdentNode*>((yyvsp[-1].node))->getIdent();
				(yyval.node) = new CallNode(n, (yyvsp[0].node));
				pool.add((yyval.node));
			}
			else {
				(yyval.node) = (yyvsp[-1].node);
			}
		}
#line 2879 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 849 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); 				}
#line 2885 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 851 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   		}
#line 2891 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 855 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); 				}
#line 2897 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 857 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    	}
#line 2903 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 859 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   		}
#line 2909 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 861 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    	}
#line 2915 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 863 "includes/parse.y" /* yacc.c:1646  */
    {
      (yyval.node) = new IdentNode((yyvsp[0].id));
      delete [] (yyvsp[0].id);
      pool.add((yyval.node));
    }
#line 2925 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 869 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new IntLiteral((yyvsp[0].intNumber));
      pool.add((yyval.node));
    }
#line 2934 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 874 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new FloatLiteral((yyvsp[0].fltNumber));
      pool.add((yyval.node));
    }
#line 2943 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 879 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2949 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 881 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   		}
#line 2955 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 885 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);				}
#line 2961 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 887 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);				}
#line 2967 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 891 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);				}
#line 2973 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 893 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   		}
#line 2979 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 913 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);				}
#line 2985 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 915 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node);				}
#line 2991 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 923 "includes/parse.y" /* yacc.c:1646  */
    {
			// $$ = new ArgNode($2);
			if( (yyvsp[-1].vec) != NULL ) {
				(yyval.node) = new ActParaNode(*(yyvsp[-1].vec));
				pool.add((yyval.node));
				delete (yyvsp[-1].vec);
			}
			// else {
			// 	$$ = NULL;
			// }
		}
#line 3007 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 935 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   		}
#line 3013 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 937 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   		}
#line 3019 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 974 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node);	}
#line 3025 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 976 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);	}
#line 3031 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1004 "includes/parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-1].vec) == NULL) {
				(yyval.vec) = new std::vector<Node*>();
			}
			else {
				(yyval.vec) = (yyvsp[-1].vec);
			}
			(yyval.vec)->push_back((yyvsp[0].node));
		}
#line 3045 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1016 "includes/parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-2].vec) == NULL) {
				(yyval.vec) = new std::vector<Node*>();
			}
			else {
				(yyval.vec) = (yyvsp[-2].vec);
			}
			(yyval.vec)->push_back((yyvsp[-1].node));
		}
#line 3059 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1026 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.vec) = NULL; }
#line 3065 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1038 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); 	 }
#line 3071 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1040 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 3077 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1042 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 3083 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1046 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);		}
#line 3089 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1048 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;	}
#line 3095 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1072 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 3101 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1074 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;    }
#line 3107 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1086 "includes/parse.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[0].node);			}
#line 3113 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1088 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;   	}
#line 3119 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 3123 "parse.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
  return yyresult;
}
#line 1095 "includes/parse.y" /* yacc.c:1906  */


#include <stdio.h>
void yyerror (const char *s)
{
    if(yylloc.first_line > 0)	{
        fprintf (stderr, "%d.%d-%d.%d:", yylloc.first_line, yylloc.first_column,
	                                     yylloc.last_line,  yylloc.last_column);
    }
    fprintf(stderr, " %s with [%s]\n", s, yytext);
}
