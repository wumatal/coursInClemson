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
#define YYLAST   888

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  140
/* YYNRULES -- Number of rules.  */
#define YYNRULES  315
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  479

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
       0,    60,    60,    63,    66,    67,    71,    73,    77,    78,
      81,    82,    86,    87,    90,    91,    94,   101,   102,   105,
     106,   109,   110,   113,   114,   117,   118,   121,   122,   125,
     127,   131,   132,   135,   136,   139,   140,   143,   145,   149,
     151,   155,   157,   161,   163,   165,   167,   169,   171,   173,
     175,   177,   181,   257,   264,   268,   270,   274,   279,   283,
     285,   287,   289,   291,   293,   295,   297,   299,   301,   303,
     305,   309,   315,   323,   325,   329,   331,   335,   336,   339,
     340,   343,   346,   349,   351,   353,   355,   357,   361,   364,
     367,   372,   381,   384,   385,   388,   389,   392,   393,   396,
     397,   400,   403,   406,   407,   410,   411,   412,   415,   416,
     419,   420,   423,   424,   427,   428,   431,   432,   435,   436,
     439,   442,   443,   446,   447,   450,   451,   454,   456,   458,
     460,   462,   464,   466,   468,   472,   482,   494,   495,   498,
     499,   502,   503,   506,   507,   510,   511,   514,   515,   518,
     519,   522,   525,   526,   529,   530,   533,   534,   537,   538,
     541,   542,   545,   546,   555,   560,   568,   569,   572,   573,
     576,   577,   580,   581,   584,   586,   590,   592,   596,   598,
     602,   604,   608,   610,   614,   616,   653,   655,   657,   659,
     661,   663,   665,   667,   669,   671,   673,   677,   679,   682,
     684,   687,   689,   692,   694,   708,   710,   714,   716,   729,
     731,   735,   737,   761,   763,   765,   767,   771,   779,   785,
     787,   789,   793,   798,   811,   813,   817,   819,   821,   823,
     825,   831,   836,   841,   845,   847,   851,   853,   857,   858,
     861,   862,   865,   866,   869,   870,   873,   875,   879,   880,
     883,   885,   887,   891,   892,   895,   896,   899,   900,   901,
     904,   905,   908,   909,   912,   913,   916,   917,   920,   921,
     924,   926,   930,   931,   934,   935,   938,   939,   942,   943,
     946,   947,   950,   951,   954,   958,   959,   962,   963,   966,
     967,   970,   971,   972,   975,   976,   979,   980,   983,   984,
     987,   988,   991,   992,   995,   996,   999,  1001,  1005,  1006,
    1009,  1010,  1013,  1015,  1019,  1020
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

#define YYPACT_NINF -280

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-280)))

#define YYTABLE_NINF -262

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -280,    41,  -280,    23,  -280,   710,   -35,   710,  -280,   -26,
    -280,   -13,   801,  -280,   801,   801,  -280,    29,   710,   -35,
      53,   710,   630,   710,  -280,   760,  -280,   645,   710,   710,
    -280,  -280,   103,   710,   710,   710,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,   156,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,     9,   125,  -280,   489,   116,   133,   152,   111,
     120,   113,  -280,   801,  -280,  -280,    69,  -280,    76,  -280,
    -280,   144,  -280,    17,  -280,   118,    47,   126,   116,  -280,
      48,   129,   140,    26,  -280,   175,  -280,   188,   107,   710,
     191,    68,    38,   147,  -280,   179,  -280,   146,  -280,  -280,
     181,   150,  -280,  -280,   710,  -280,  -280,   199,  -280,   500,
     201,  -280,   211,  -280,  -280,  -280,  -280,    74,   203,   760,
     760,  -280,   760,  -280,  -280,  -280,  -280,  -280,   171,  -280,
    -280,   185,  -280,   801,   801,   801,   801,  -280,  -280,   801,
    -280,  -280,   801,  -280,  -280,  -280,  -280,   801,  -280,    59,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,   630,   630,   710,   142,   162,  -280,  -280,
     710,   500,   710,   166,   217,   221,   710,   710,    65,   200,
     218,   224,   500,   -35,   157,  -280,   710,    -8,   161,   167,
    -280,  -280,   176,   710,   801,   225,  -280,  -280,  -280,   225,
    -280,  -280,   801,   225,  -280,  -280,   238,   225,   710,  -280,
     215,  -280,   151,   500,    85,   801,  -280,   564,   710,    32,
     125,  -280,  -280,  -280,   116,   133,   152,   111,   120,   113,
    -280,   172,   162,   697,   801,  -280,   184,  -280,  -280,  -280,
    -280,  -280,  -280,   198,  -280,   202,  -280,  -280,  -280,   204,
    -280,   205,   500,   801,   246,   248,   187,  -280,   258,  -280,
    -280,  -280,   192,  -280,  -280,  -280,  -280,  -280,   206,  -280,
     250,   710,   257,   179,   237,   710,  -280,  -280,   240,  -280,
     710,   264,  -280,  -280,   246,   419,   710,   269,    20,   270,
     268,   500,   710,   116,  -280,  -280,  -280,   710,  -280,   236,
     285,   295,   247,  -280,   298,  -280,   630,   265,   710,   710,
      13,  -280,   300,   299,  -280,  -280,   116,   710,  -280,   500,
     256,   235,   305,  -280,   178,   306,  -280,   255,  -280,  -280,
      12,  -280,   310,  -280,  -280,   760,   751,  -280,   710,  -280,
    -280,  -280,   338,   115,   500,   318,   307,   323,   500,   324,
    -280,  -280,  -280,  -280,   319,  -280,   325,   710,  -280,  -280,
    -280,  -280,   710,  -280,  -280,   279,  -280,   500,  -280,   326,
    -280,  -280,   187,   710,   328,    -8,   259,   710,  -280,    86,
     333,   117,   334,  -280,   308,  -280,  -280,  -280,  -280,  -280,
     710,  -280,  -280,   500,   339,  -280,   500,  -280,   500,  -280,
     615,  -280,   344,   345,  -280,  -280,   348,  -280,   349,   500,
    -280,  -280,   350,   751,  -280,  -280,  -280,   751,   351,   751,
    -280,  -280,  -280,   751,   352,  -280,  -280,   500,  -280,  -280,
    -280,   710,  -280,  -280,   249,  -280,   500,   500,  -280,   710,
     121,  -280,   751,   117,  -280,   751,  -280,  -280,  -280,   710,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       7,     0,     2,     0,     1,     0,     0,     0,    88,     0,
      89,     0,     0,     3,     0,     0,   315,     0,     0,     0,
      24,   241,   237,   239,     4,     0,    82,    76,    94,    91,
     243,   221,     0,     0,     0,   313,   219,   220,   230,   231,
     232,     6,    13,     0,   134,   132,     5,    37,    42,    43,
      44,    45,    46,    47,    83,    84,    85,    87,    86,    48,
      99,   100,    49,    50,    51,    38,   127,   128,   129,   130,
     131,    74,   177,   178,   180,   183,   184,   197,   199,   201,
     203,   207,   211,     0,   218,   225,   233,   175,    54,   133,
      92,   126,   118,     0,   310,     0,     0,     0,   269,    81,
     124,     0,     0,     0,   122,     0,   116,   101,   111,     0,
       0,     0,    74,     0,   240,    74,   236,     0,   235,   234,
      74,     0,   238,   182,     0,    71,    74,    98,    90,     0,
       0,   153,   155,   312,    12,    15,    14,     0,   271,     0,
       0,   174,     0,   188,   187,   189,   191,   193,   195,   186,
     190,     0,   192,     0,     0,     0,     0,   205,   206,     0,
     209,   210,     0,   213,   214,   215,   216,     0,   217,   223,
     242,    64,    66,    70,    69,    67,    60,    63,    59,    68,
      62,    61,    65,     0,     0,     0,     0,   286,     9,   229,
       0,     0,   283,    24,     0,   267,     0,     0,     0,   314,
     103,   120,     0,     0,     0,   249,     0,     0,     0,     0,
      31,    19,    22,     0,     0,    30,   273,   278,   228,    30,
     246,   226,     0,    30,   244,   227,    80,    30,     0,    93,
       0,   162,     0,     0,     0,     0,    40,     0,   270,     0,
     179,   181,   196,   194,   185,   198,   200,   202,   204,   208,
     212,     0,   286,   261,     0,   224,    58,    53,    56,    55,
      52,   125,   119,     0,    10,     0,   311,   281,   282,     0,
      18,     0,     0,   266,    96,     0,     0,   105,   109,   102,
     115,   107,     0,   138,   117,   110,   248,    36,     0,    28,
      26,     0,    30,   275,     0,    29,   279,   247,     0,   245,
       0,    30,    72,    75,    96,     0,   157,     0,   148,     0,
     140,     0,     0,   154,    39,    41,    73,     0,   252,     0,
       0,   258,     0,   256,     0,   222,     0,     0,     0,     0,
     297,   284,    30,     0,    17,    16,   268,     0,   123,     0,
       0,     0,   113,   121,   136,    34,    32,     0,    27,    21,
      23,    20,    30,   272,   276,     0,     0,    78,    29,    79,
      97,   165,     0,   161,     0,     0,   150,     0,     0,     0,
     151,   152,   176,   250,     0,   251,   254,   261,    57,     8,
     293,   288,     0,   294,   296,   285,   291,     0,    95,   142,
     106,   108,   112,     0,     0,    33,     0,    29,   277,   307,
      24,   301,   167,   171,   170,    77,   163,   164,   158,   159,
       0,   156,   144,     0,     0,   143,     0,   146,     0,   257,
     253,   260,   263,   290,   295,   280,     0,   114,     0,     0,
      35,    25,     0,     0,   306,   304,   305,     0,     0,     0,
     300,   298,   299,     0,    30,   160,   147,     0,   145,   139,
     255,   265,   259,   262,     0,   292,     0,     0,   135,     0,
     309,   173,     0,   303,   169,    29,   166,   149,   264,     0,
     287,   141,   137,   274,   308,   172,   302,   168,   289
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -280,  -280,  -280,  -280,  -280,   330,   122,  -280,  -280,   335,
    -280,  -187,  -280,  -280,  -280,  -280,  -216,  -197,  -280,  -280,
    -279,    -2,  -280,   145,  -280,   195,    58,  -280,  -280,    57,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,    79,  -280,  -280,  -280,  -280,  -280,  -280,     2,   197,
     114,  -280,  -280,    19,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,    75,
      83,  -280,  -280,  -182,  -280,  -280,  -280,  -278,  -280,    -5,
    -280,  -135,   261,    -1,  -280,  -280,    21,   241,   243,   253,
    -280,   244,  -280,   242,  -280,   -62,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,   -18,    36,  -280,  -280,     4,  -280,   -21,  -280,  -280,
    -280,  -280,   371,  -280,  -280,  -280,  -280,  -280,  -280,   -38,
    -280,   -44,   301,  -280,   -40,  -100,  -280,  -280,   -17,  -280
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    41,     3,    42,   263,    43,    44,    45,
     194,   110,   292,   111,   348,   211,   296,   212,   288,   345,
      46,   231,   137,    48,    49,   256,   257,   184,    50,   138,
     125,   301,   302,    51,    52,    53,    54,    55,    56,    57,
      58,   338,   229,    59,    60,    61,   102,   279,   280,   106,
     281,   342,   107,   108,    62,   201,    63,    64,    65,    66,
     344,    67,    68,    69,   308,   366,   415,    70,   234,   131,
     309,   410,   411,   232,   362,   401,   444,   402,   403,    71,
     141,    72,    73,    74,    75,   153,    76,    77,    78,    79,
     159,    80,   162,    81,   167,    82,    83,    84,   169,    85,
     116,   117,   121,   113,    86,   122,   118,    87,   255,   322,
     376,   323,   324,   452,   453,    99,   195,    88,   114,   352,
     353,   216,    89,   269,   264,   265,   423,   455,   331,   332,
     383,   440,   441,   442,   434,   435,   436,    95,    90,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    47,    94,   297,   239,   119,   271,   299,   128,   267,
     287,   303,   217,   105,   133,   220,   112,   115,   120,   101,
     283,   168,   126,   127,   123,    93,   361,   -29,   130,   132,
       5,     6,     7,    98,     8,   100,    98,     9,   186,   207,
      10,     4,    11,    12,   214,   365,   139,   199,   306,    13,
      92,   310,    14,   213,    15,    16,    17,   317,   154,    96,
      18,    19,   191,   140,   187,    20,    21,   188,   109,   214,
      22,    23,    97,    24,    25,   -29,   351,   210,    26,   171,
     251,    27,    28,   407,    29,   359,   140,   196,   382,   172,
     335,    30,    31,    32,   192,    33,    34,    35,   173,   174,
     311,   312,    36,    37,   205,   250,   252,   253,    38,    39,
      40,    92,   276,   204,   104,   207,   386,   214,   129,   226,
     175,   408,   200,   433,   236,   176,   154,   189,   186,   370,
     142,   409,   177,   178,   190,   254,   398,   170,   179,   237,
     140,   241,   180,   181,   208,   155,   277,   182,   222,   209,
     278,   183,   214,   210,   439,   460,   156,   389,   433,   461,
     185,   463,   258,   258,     6,   464,   259,   259,   197,   215,
       9,   268,   219,   193,   244,    11,   275,   223,   198,   306,
     261,   307,   412,   227,   475,   266,   417,   477,   157,   158,
     202,   274,   325,   354,   163,   164,   165,   166,   430,   160,
     161,   286,   393,   394,   203,   425,   206,   218,   293,   221,
     214,     7,   222,   438,   225,   228,   233,   235,   294,   238,
     399,   404,   242,   304,   243,   -11,   298,   262,   466,   270,
     384,   446,   272,   316,   448,    98,   449,   273,  -104,   186,
     282,   295,   285,    98,    20,    21,   289,   458,   321,    22,
      23,   291,   290,    25,   300,   305,   313,   318,     7,   326,
     330,   327,   337,   339,   341,   467,   347,   333,   334,   346,
      30,    31,   278,   350,   471,   472,   355,   343,   328,   356,
     358,    36,    37,   329,   364,   368,   349,    38,    39,    40,
     316,    20,    21,   369,   336,   357,    22,    23,   404,   373,
      25,   363,   404,    47,   404,   258,   374,   132,   404,   259,
    -260,   375,   372,   377,   387,   379,   385,    30,    31,   390,
     391,   392,   395,   380,   381,   469,   397,   404,    36,    37,
     404,   396,   388,   413,    38,    39,    40,   414,   416,   418,
     419,   420,   -29,   429,   431,     5,     6,     7,   437,     8,
     443,   426,     9,   405,   447,    10,   406,    11,    12,   451,
      47,   454,   140,   456,   457,   459,   462,    14,   465,    15,
      16,    17,   421,   134,   319,    18,    19,   424,   135,   260,
      20,    21,   315,   360,   378,    22,    23,   371,   428,    25,
     340,   367,   432,    26,   427,   245,    27,    28,   246,    29,
     284,   240,   450,   248,   249,   445,    30,    31,    32,   247,
      33,    34,    35,   422,   136,   321,   470,    36,    37,   476,
     474,   224,     0,    38,    39,    40,     5,     6,     7,     0,
       8,     0,     0,     9,     0,     0,    10,     0,    11,    12,
       0,     0,     0,     0,     0,     0,   468,     0,    14,   330,
      15,    16,    17,     0,   473,     0,    18,    19,     0,     0,
       0,    20,    21,     0,   478,     0,    22,    23,     0,     0,
      25,     0,     0,     0,    26,     0,     0,    27,    28,     0,
      29,     0,     0,     0,     0,     0,     0,    30,    31,    32,
       0,    33,    34,    35,     0,     0,     0,     0,    36,    37,
       0,     0,     0,     0,    38,    39,    40,     5,     0,     7,
       0,     8,     0,     0,     0,     0,   143,    10,     0,     0,
      12,     0,     0,   144,   145,   146,     0,     0,   147,    14,
     148,     0,    16,    17,   149,   150,     0,     0,    19,     0,
     151,   152,    20,    21,     0,     0,     0,    22,    23,     0,
     230,    25,     0,     0,     0,    26,     0,     0,    27,    28,
       0,    29,     0,     0,     0,     0,     0,     0,    30,    31,
       0,     5,     0,     7,    35,     8,     0,     0,     0,    36,
      37,    10,     0,     0,    12,    38,    39,    40,     0,     0,
       0,     0,     0,    14,     0,     0,    16,    17,     0,     0,
       0,     0,    19,     0,     0,     0,    20,    21,     0,     0,
       0,    22,    23,     0,   314,    25,     0,     0,     0,    26,
       0,     0,    27,    28,     7,    29,     0,     0,     0,     0,
    -261,     0,    30,    31,     0,     0,   320,     0,    35,     7,
       0,     0,     0,    36,    37,     0,     0,     0,     0,    38,
      39,    40,     0,     0,     7,     0,     0,    20,    21,     0,
       0,     0,    22,    23,     0,     0,    25,     0,     0,     0,
       0,     0,    20,    21,     0,     0,     0,    22,    23,     0,
       0,    25,     0,    30,    31,     0,     0,    20,    21,     0,
       0,     0,    22,    23,    36,    37,    25,     0,    30,    31,
      38,    39,    40,     0,    35,     0,     7,     0,     0,    36,
      37,     0,     0,    30,    31,    38,    39,    40,   320,     7,
       0,     0,     0,   124,    36,    37,     0,     0,     0,     0,
      38,    39,    40,     0,     0,     0,     0,     0,     0,    20,
      21,     0,     0,     0,    22,    23,     0,     0,    25,     0,
       0,     0,    20,    21,     0,     0,     0,    22,    23,     0,
       7,    25,     0,     0,     0,    30,    31,     0,     0,     7,
       0,     0,     0,     0,     0,     0,    36,    37,    30,    31,
       0,     0,    38,    39,    40,     0,     0,     0,     0,    36,
      37,     0,     0,   400,    21,    38,    39,    40,    22,    23,
       0,     0,    25,    21,     0,     0,     0,    22,    23,     0,
       7,    25,     0,     0,     0,     0,     0,     0,     0,    30,
      31,     0,     0,     0,     0,     0,     0,     0,    30,    31,
      36,    37,     0,     0,     0,     0,    38,    39,    40,    36,
      37,     0,     0,     0,    21,    38,    39,    40,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,     0,     0,     0,     0,    38,    39,    40
};

static const yytype_int16 yycheck[] =
{
       5,     3,     7,   219,   139,    22,   193,   223,    29,   191,
     207,   227,   112,    18,    35,   115,    21,    22,    23,    15,
     202,    83,    27,    28,    25,     6,   305,    15,    33,    34,
       7,     8,     9,    12,    11,    14,    15,    14,    21,    47,
      17,     0,    19,    20,    31,    25,    37,    21,    28,    26,
      85,   233,    29,    15,    31,    32,    33,    25,    10,    85,
      37,    38,    15,    54,    47,    42,    43,    50,    15,    31,
      47,    48,    85,    50,    51,    63,   292,    85,    55,     3,
      21,    58,    59,   362,    61,   301,    54,    39,    75,    13,
     272,    68,    69,    70,    47,    72,    73,    74,    22,    23,
      15,    16,    79,    80,   109,   167,    47,    48,    85,    86,
      87,    85,    47,     6,    85,    47,   332,    31,    15,   124,
      44,     6,   103,    37,    50,    49,    10,     9,    21,   311,
       5,    16,    56,    57,    16,    76,   352,    68,    62,    65,
      54,   142,    66,    67,    76,    12,    81,    71,    31,    81,
      85,    75,    31,    85,    37,   433,     4,   339,    37,   437,
      16,   439,   183,   184,     8,   443,   183,   184,    39,   112,
      14,   192,   115,    47,   153,    19,   197,   120,    38,    28,
     185,    30,   364,   126,   462,   190,   368,   465,    77,    78,
      15,   196,   254,   293,    81,    82,    83,    84,   395,    79,
      80,   206,    24,    25,    16,   387,    15,    60,   213,    63,
      31,     9,    31,   400,    64,    16,    15,     6,   214,    16,
     355,   356,    51,   228,    39,    63,   222,    85,   444,    63,
     330,   413,    15,   238,   416,   214,   418,    16,    38,    21,
      16,    16,    85,   222,    42,    43,    85,   429,   253,    47,
      48,    75,    85,    51,    16,    40,   235,    85,     9,    75,
     265,    63,    16,    15,     6,   447,    16,    63,    63,    63,
      68,    69,    85,    16,   456,   457,    39,    85,    76,    39,
      16,    79,    80,    81,    15,    15,   291,    85,    86,    87,
     295,    42,    43,    25,   273,   300,    47,    48,   433,    63,
      51,   306,   437,   305,   439,   326,    21,   312,   443,   326,
      15,    64,   317,    15,    15,    50,    16,    68,    69,    63,
      85,    16,    16,   328,   329,    76,    16,   462,    79,    80,
     465,    76,   337,    15,    85,    86,    87,    30,    15,    15,
      21,    16,    63,    15,    85,     7,     8,     9,    15,    11,
      16,    25,    14,   358,    15,    17,    18,    19,    20,    15,
     362,    16,    54,    15,    15,    15,    15,    29,    16,    31,
      32,    33,   377,    43,   252,    37,    38,   382,    43,   184,
      42,    43,   237,   304,   326,    47,    48,   312,   393,    51,
     276,   308,   397,    55,   392,   154,    58,    59,   155,    61,
     203,   140,   420,   159,   162,   410,    68,    69,    70,   156,
      72,    73,    74,   377,    43,   420,   454,    79,    80,   463,
     460,   120,    -1,    85,    86,    87,     7,     8,     9,    -1,
      11,    -1,    -1,    14,    -1,    -1,    17,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,    29,   454,
      31,    32,    33,    -1,   459,    -1,    37,    38,    -1,    -1,
      -1,    42,    43,    -1,   469,    -1,    47,    48,    -1,    -1,
      51,    -1,    -1,    -1,    55,    -1,    -1,    58,    59,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      -1,    72,    73,    74,    -1,    -1,    -1,    -1,    79,    80,
      -1,    -1,    -1,    -1,    85,    86,    87,     7,    -1,     9,
      -1,    11,    -1,    -1,    -1,    -1,    27,    17,    -1,    -1,
      20,    -1,    -1,    34,    35,    36,    -1,    -1,    39,    29,
      41,    -1,    32,    33,    45,    46,    -1,    -1,    38,    -1,
      51,    52,    42,    43,    -1,    -1,    -1,    47,    48,    -1,
      50,    51,    -1,    -1,    -1,    55,    -1,    -1,    58,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      -1,     7,    -1,     9,    74,    11,    -1,    -1,    -1,    79,
      80,    17,    -1,    -1,    20,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    47,    48,    -1,    50,    51,    -1,    -1,    -1,    55,
      -1,    -1,    58,    59,     9,    61,    -1,    -1,    -1,    -1,
      15,    -1,    68,    69,    -1,    -1,    21,    -1,    74,     9,
      -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    85,
      86,    87,    -1,    -1,     9,    -1,    -1,    42,    43,    -1,
      -1,    -1,    47,    48,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    47,    48,    -1,
      -1,    51,    -1,    68,    69,    -1,    -1,    42,    43,    -1,
      -1,    -1,    47,    48,    79,    80,    51,    -1,    68,    69,
      85,    86,    87,    -1,    74,    -1,     9,    -1,    -1,    79,
      80,    -1,    -1,    68,    69,    85,    86,    87,    21,     9,
      -1,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    47,    48,    -1,    -1,    51,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    47,    48,    -1,
       9,    51,    -1,    -1,    -1,    68,    69,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    68,    69,
      -1,    -1,    85,    86,    87,    -1,    -1,    -1,    -1,    79,
      80,    -1,    -1,    42,    43,    85,    86,    87,    47,    48,
      -1,    -1,    51,    43,    -1,    -1,    -1,    47,    48,    -1,
       9,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      79,    80,    -1,    -1,    -1,    -1,    85,    86,    87,    79,
      80,    -1,    -1,    -1,    43,    85,    86,    87,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    -1,    85,    86,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    89,    90,    92,     0,     7,     8,     9,    11,    14,
      17,    19,    20,    26,    29,    31,    32,    33,    37,    38,
      42,    43,    47,    48,    50,    51,    55,    58,    59,    61,
      68,    69,    70,    72,    73,    74,    79,    80,    85,    86,
      87,    91,    93,    95,    96,    97,   108,   109,   111,   112,
     116,   121,   122,   123,   124,   125,   126,   127,   128,   131,
     132,   133,   142,   144,   145,   146,   147,   149,   150,   151,
     155,   167,   169,   170,   171,   172,   174,   175,   176,   177,
     179,   181,   183,   184,   185,   187,   192,   195,   205,   210,
     226,   167,    85,   141,   167,   225,    85,    85,   174,   203,
     174,   203,   134,   227,    85,   167,   137,   140,   141,    15,
      99,   101,   167,   191,   206,   167,   188,   189,   194,   226,
     167,   190,   193,   171,    78,   118,   167,   167,   205,    15,
     167,   157,   167,   205,    93,    97,   210,   110,   117,    37,
      54,   168,     5,    27,    34,    35,    36,    39,    41,    45,
      46,    51,    52,   173,    10,    12,     4,    77,    78,   178,
      79,    80,   180,    81,    82,    83,    84,   182,   183,   186,
      68,     3,    13,    22,    23,    44,    49,    56,    57,    62,
      66,    67,    71,    75,   115,    16,    21,    47,    50,     9,
      16,    15,    47,    47,    98,   204,    39,    39,    38,    21,
     141,   143,    15,    16,     6,   167,    15,    47,    76,    81,
      85,   103,   105,    15,    31,   117,   209,   223,    60,   117,
     223,    63,    31,   117,   220,    64,   167,   117,    16,   130,
      50,   109,   161,    15,   156,     6,    50,    65,    16,   169,
     170,   171,    51,    39,   174,   175,   176,   177,   179,   181,
     183,    21,    47,    48,    76,   196,   113,   114,   205,   226,
     113,   167,    85,    94,   212,   213,   167,   161,   205,   211,
      63,    99,    15,    16,   167,   205,    47,    81,    85,   135,
     136,   138,    16,   161,   137,    85,   167,   105,   106,    85,
      85,    75,   100,   167,   203,    16,   104,   104,   203,   104,
      16,   119,   120,   104,   167,    40,    28,    30,   152,   158,
     161,    15,    16,   174,    50,   111,   167,    25,    85,    94,
      21,   167,   197,   199,   200,   183,    75,    63,    76,    81,
     167,   216,   217,    63,    63,   161,   174,    16,   129,    15,
     138,     6,   139,    85,   148,   107,    63,    16,   102,   167,
      16,   104,   207,   208,   223,    39,    39,   167,    16,   104,
     129,   108,   162,   167,    15,    25,   153,   158,    15,    25,
     161,   157,   167,    63,    21,    64,   198,    15,   114,    50,
     167,   167,    75,   218,   223,    16,   104,    15,   167,   161,
      63,    85,    16,    24,    25,    16,    76,    16,   104,   169,
      42,   163,   165,   166,   169,   167,    18,   108,     6,    16,
     159,   160,   161,    15,    30,   154,    15,   161,    15,    21,
      16,   167,   200,   214,   167,   161,    25,   136,   167,    15,
     105,    85,   167,    37,   222,   223,   224,    15,    99,    37,
     219,   220,   221,    16,   164,   167,   161,    15,   161,   161,
     199,    15,   201,   202,    16,   215,    15,    15,   161,    15,
     165,   165,    15,   165,   165,    16,   104,   161,   167,    76,
     217,   161,   161,   167,   222,   165,   219,   165,   167
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
     187,   187,   187,   187,   188,   188,   189,   189,   190,   190,
     191,   191,   192,   192,   193,   193,   194,   194,   195,   195,
     196,   196,   196,   197,   197,   198,   198,   199,   199,   199,
     200,   200,   201,   201,   202,   202,   203,   203,   204,   204,
     205,   205,   206,   206,   207,   207,   208,   208,   209,   209,
     210,   210,   211,   211,   212,   213,   213,   214,   214,   215,
     215,   216,   216,   216,   217,   217,   218,   218,   219,   219,
     220,   220,   221,   221,   222,   222,   223,   223,   224,   224,
     225,   225,   226,   226,   227,   227
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
       1,     1,     1,     1,     1,     1,     1,     0,     1,     0,
       1,     0,     2,     1,     2,     3,     2,     3,     4,     3,
       3,     3,     2,     3,     2,     3,     0,     3,     1,     4,
       1,     0,     1,     0,     2,     1,     3,     2,     3,     0,
       3,     2,     4,     2,     5,     0,     1,     2,     1,     2,
       7,     4,     1,     0,     2,     3,     0,     3,     0,     3,
       0,     2,     4,     2,     2,     3,     1,     0,     1,     1,
       5,     4,     3,     2,     1,     1,     5,     4,     3,     2,
       1,     3,     2,     1,     2,     0
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
#line 68 "includes/parse.y" /* yacc.c:1646  */
    { (yyvsp[0].node)->eval();		}
#line 1900 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 83 "includes/parse.y" /* yacc.c:1646  */
    {	(yyval.node) = nullptr;	}
#line 1906 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 94 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new FuncNode( (yyvsp[-3].id), (yyvsp[0].node) );
			pool.add((yyval.node));
			delete [] (yyvsp[-3].id);
	}
#line 1916 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 126 "includes/parse.y" /* yacc.c:1646  */
    {	(yyval.node) = nullptr;	}
#line 1922 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 128 "includes/parse.y" /* yacc.c:1646  */
    {	(yyval.node) = nullptr;	}
#line 1928 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 144 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);			}
#line 1934 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 146 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);			}
#line 1940 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 162 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); 			}
#line 1946 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 164 "includes/parse.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[0].node);			}
#line 1952 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 166 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;	}
#line 1958 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 168 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 1964 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 170 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); 			}
#line 1970 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 172 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 1976 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 174 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 1982 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 176 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 1988 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 178 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 1994 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 182 "includes/parse.y" /* yacc.c:1646  */
    {
			Node* temp = nullptr;
			switch ((yyvsp[-1].intNumber)) {
        case PLUSEQUAL:
					(yyval.node) = new AddBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
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
					(yyval.node) = nullptr;
          break;
      }
		}
#line 2074 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 258 "includes/parse.y" /* yacc.c:1646  */
    {
			// ```
			//if ($2 != nullptr) {
			(yyval.node) = new AsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
			pool.add((yyval.node));
		}
#line 2085 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 265 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);		}
#line 2091 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 269 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);		}
#line 2097 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 271 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);		}
#line 2103 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 275 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new AsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
			pool.add((yyval.node));
		}
#line 2112 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 280 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2118 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 284 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = PLUSEQUAL;				 }
#line 2124 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 286 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = MINEQUAL; 				 }
#line 2130 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 288 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = STAREQUAL; 			 }
#line 2136 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 290 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = SLASHEQUAL; 			 }
#line 2142 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 292 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = PERCENTEQUAL; 		 }
#line 2148 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 294 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = AMPEREQUAL;			 }
#line 2154 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 296 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = VBAREQUAL;				 }
#line 2160 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 298 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = CIRCUMFLEXEQUAL;	 }
#line 2166 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 300 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = LEFTSHIFTEQUAL;	 }
#line 2172 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 302 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = RIGHTSHIFTEQUAL;	 }
#line 2178 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 304 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = DOUBLESTAREQUAL;	 }
#line 2184 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 306 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = DOUBLESLASHEQUAL; }
#line 2190 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 310 "includes/parse.y" /* yacc.c:1646  */
    {
			/*if( $2 )	$2->eval()->print();*/
			(yyval.node) = new PrintNode( (yyvsp[0].node) );
			pool.add( (yyval.node) );
		}
#line 2200 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 316 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2206 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 324 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2212 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 326 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2218 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 330 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); 			}
#line 2224 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 332 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2230 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 350 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;			}
#line 2236 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 352 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;			}
#line 2242 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 354 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);					}
#line 2248 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 356 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;			}
#line 2254 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 358 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;			}
#line 2260 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 368 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new ReturnNode((yyvsp[0].node));
			pool.add((yyval.node));
		}
#line 2269 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 373 "includes/parse.y" /* yacc.c:1646  */
    {
			/* const Node* node = new IntLiteral(0); */
			(yyval.node) = new ReturnNode(nullptr);
			pool.add((yyval.node));
			/* pool.add(Node); */
		}
#line 2280 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 455 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);			}
#line 2286 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 457 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;	}
#line 2292 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 459 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;	}
#line 2298 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 461 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;	}
#line 2304 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 463 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;	}
#line 2310 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 465 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);			}
#line 2316 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 467 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;	}
#line 2322 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 469 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;	}
#line 2328 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 473 "includes/parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-6].node)) {
				(yyval.node) = new IfNode((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[0].node));
				pool.add((yyval.node));
			}
			else {
				std::cout << "SyntaxError: invalid syntax" << std::endl;
			}
		}
#line 2342 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 483 "includes/parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-3].node)) {
        (yyval.node) = new IfNode((yyvsp[-3].node), (yyvsp[-1].node), nullptr);
        pool.add((yyval.node));
      }
      else {
        std::cout << "SyntaxError: invalid syntax" << std::endl;
      }
		}
#line 2356 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 547 "includes/parse.y" /* yacc.c:1646  */
    {
			/*$$ = new SuiteNode( $3->rbegin(), $3->rend() );*/
			(yyval.node) = new SuiteNode( *(yyvsp[-1].vec) );
			pool.add((yyval.node));
			delete (yyvsp[-1].vec);
		}
#line 2367 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 556 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.vec) = (yyvsp[-1].vec);
			(yyval.vec)->push_back((yyvsp[0].node));
		}
#line 2376 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 561 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.vec) = new std::vector<Node*>();
			(yyval.vec)->reserve(8);
			(yyval.vec)->push_back((yyvsp[0].node));
		}
#line 2386 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 585 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);	 		}
#line 2392 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 587 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2398 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 591 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2404 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 593 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2410 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 597 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);	 		}
#line 2416 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 599 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2422 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 603 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);	 		}
#line 2428 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 605 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2434 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 609 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2440 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 611 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);	 		}
#line 2446 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 615 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);	 		}
#line 2452 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 617 "includes/parse.y" /* yacc.c:1646  */
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
#line 2491 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 654 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = LESS; 					}
#line 2497 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 656 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = GREATER; 			}
#line 2503 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 658 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = EQEQUAL; 			}
#line 2509 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 660 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = GREATEREQUAL; 	}
#line 2515 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 662 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = LESSEQUAL; 		}
#line 2521 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 664 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = GRLT; 					}
#line 2527 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 666 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = NOTEQUAL; 			}
#line 2533 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 668 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = IN; 						}
#line 2539 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 670 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = 0; 						}
#line 2545 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 672 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = IS; 						}
#line 2551 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 674 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = 0; 						}
#line 2557 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 678 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);						}
#line 2563 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 683 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);						}
#line 2569 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 688 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);						}
#line 2575 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 693 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);						}
#line 2581 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 695 "includes/parse.y" /* yacc.c:1646  */
    {
			// if ($2 == LEFTSHIFT) {
			// 	$$ = new LShiftBinaryNode($1, $3);
			// 	pool.add($$);
			// }
			// if ($2 == RIGHTSHIFT) {
			// 	$$ = new RShiftBinaryNode($1, $3);
			// 	pool.add($$);
			// }
			(yyval.node) = nullptr;
		}
#line 2597 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 709 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = LEFTSHIFT; 		}
#line 2603 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 711 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = RIGHTSHIFT; 		}
#line 2609 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 715 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); 						}
#line 2615 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 717 "includes/parse.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-1].intNumber) == PLUS) {
				(yyval.node) = new AddBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				pool.add((yyval.node));
			}
			if ((yyvsp[-1].intNumber) == MINUS) {
				(yyval.node) = new SubBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
				pool.add((yyval.node));
			}
		}
#line 2630 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 730 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = PLUS;					}
#line 2636 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 732 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = MINUS;					}
#line 2642 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 736 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); 						}
#line 2648 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 738 "includes/parse.y" /* yacc.c:1646  */
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
#line 2674 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 762 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = STAR; 				}
#line 2680 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 764 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = SLASH; 			}
#line 2686 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 766 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = PERCENT;			}
#line 2692 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 768 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = DOUBLESLASH;	}
#line 2698 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 772 "includes/parse.y" /* yacc.c:1646  */
    {
			if( (yyvsp[-1].intNumber)==PLUS )
				(yyval.node) = new UnaryNode('+', (yyvsp[0].node));
			else
				(yyval.node) = new UnaryNode('-', (yyvsp[0].node));
      pool.add((yyval.node));
		}
#line 2710 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 780 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node);
		}
#line 2718 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 786 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = PLUS; 	}
#line 2724 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 788 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = MINUS; }
#line 2730 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 790 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.intNumber) = TILDE;	}
#line 2736 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 794 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new PowBinaryNode((yyvsp[-3].node), (yyvsp[0].node));
      pool.add((yyval.node));
		}
#line 2745 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 799 "includes/parse.y" /* yacc.c:1646  */
    {
			if(!(yyvsp[0].node)) {
				std::string n = reinterpret_cast<IdentNode*>((yyvsp[-1].node))->getIdent();
				(yyval.node) = new CallNode(n);
				pool.add((yyval.node));
			}
			else {
				(yyval.node) = (yyvsp[-1].node);
			}
		}
#line 2760 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 812 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); 				}
#line 2766 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 814 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;		}
#line 2772 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 818 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); 				}
#line 2778 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 820 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; 	}
#line 2784 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 822 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;		}
#line 2790 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 824 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; 	}
#line 2796 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 826 "includes/parse.y" /* yacc.c:1646  */
    {
      (yyval.node) = new IdentNode((yyvsp[0].id));
      delete [] (yyvsp[0].id);
      pool.add((yyval.node));
    }
#line 2806 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 832 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new IntLiteral((yyvsp[0].intNumber));
      pool.add((yyval.node));
    }
#line 2815 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 837 "includes/parse.y" /* yacc.c:1646  */
    {
			(yyval.node) = new FloatLiteral((yyvsp[0].fltNumber));
      pool.add((yyval.node));
    }
#line 2824 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 842 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;			}
#line 2830 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 846 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);				}
#line 2836 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 848 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);				}
#line 2842 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 852 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node);				}
#line 2848 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 854 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;		}
#line 2854 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 874 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);				}
#line 2860 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 876 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node);				}
#line 2866 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 884 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;		}
#line 2872 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 886 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;		}
#line 2878 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 888 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;		}
#line 2884 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 925 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node);	}
#line 2890 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 927 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node);	}
#line 2896 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 955 "includes/parse.y" /* yacc.c:1646  */
    {	(yyval.node) = nullptr;		}
#line 2902 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1000 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2908 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1002 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2914 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1014 "includes/parse.y" /* yacc.c:1646  */
    {	(yyval.node) = (yyvsp[0].node);			}
#line 2920 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1016 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr;	}
#line 2926 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 2930 "parse.tab.c" /* yacc.c:1646  */
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
#line 1023 "includes/parse.y" /* yacc.c:1906  */


#include <stdio.h>
void yyerror (const char *s)
{
    if(yylloc.first_line > 0)	{
        fprintf (stderr, "%d.%d-%d.%d:", yylloc.first_line, yylloc.first_column,
	                                     yylloc.last_line,  yylloc.last_column);
    }
    fprintf(stderr, " %s with [%s]\n", s, yytext);
}
