/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "uccompiler.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "functions.h"

int yylex(void);
void yyerror(char* s);

extern int lines;
extern int columns;
extern char* yytext;
extern int yyleng;
extern struct program* myprog;
int syntax_error_counter = 0;

#line 84 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CHAR = 258,
    ELSE = 259,
    WHILE = 260,
    IF = 261,
    INT = 262,
    SHORT = 263,
    DOUBLE = 264,
    RETURN = 265,
    VOID = 266,
    BITWISEAND = 267,
    BITWISEOR = 268,
    BITWISEXOR = 269,
    AND = 270,
    ASSIGN = 271,
    MUL = 272,
    COMMA = 273,
    DIV = 274,
    EQ = 275,
    GE = 276,
    GT = 277,
    LBRACE = 278,
    LE = 279,
    LPAR = 280,
    LT = 281,
    MINUS = 282,
    MOD = 283,
    NE = 284,
    NOT = 285,
    OR = 286,
    PLUS = 287,
    RBRACE = 288,
    RPAR = 289,
    SEMI = 290,
    RESERVED = 291,
    SIMPLECOMMENT = 292,
    MLCOMMENTS = 293,
    MLCOMMENTE = 294,
    THEN = 295,
    CHRLIT = 296,
    ID = 297,
    REALLIT = 298,
    INTLIT = 299,
    OP1 = 300,
    error_aux = 301
  };
#endif
/* Tokens.  */
#define CHAR 258
#define ELSE 259
#define WHILE 260
#define IF 261
#define INT 262
#define SHORT 263
#define DOUBLE 264
#define RETURN 265
#define VOID 266
#define BITWISEAND 267
#define BITWISEOR 268
#define BITWISEXOR 269
#define AND 270
#define ASSIGN 271
#define MUL 272
#define COMMA 273
#define DIV 274
#define EQ 275
#define GE 276
#define GT 277
#define LBRACE 278
#define LE 279
#define LPAR 280
#define LT 281
#define MINUS 282
#define MOD 283
#define NE 284
#define NOT 285
#define OR 286
#define PLUS 287
#define RBRACE 288
#define RPAR 289
#define SEMI 290
#define RESERVED 291
#define SIMPLECOMMENT 292
#define MLCOMMENTS 293
#define MLCOMMENTE 294
#define THEN 295
#define CHRLIT 296
#define ID 297
#define REALLIT 298
#define INTLIT 299
#define OP1 300
#define error_aux 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "uccompiler.y" /* yacc.c:355  */

    int integer;
    char* string;
    struct program* prog;
    struct function_definition* i_f_def;
    struct function_declaration* i_f_dec;
    struct declaration* i_dec;
    struct parameter_list* i_param_list;
    struct function_body* i_f_body;
    struct parameter_declaration* i_param_dec;
    struct statement* i_stt;
    struct expression* i_expr;
    struct declarator* i_decl;
    struct call* i_call;

#line 232 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 249 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   556

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    91,    91,    92,    93,    96,    97,    98,    99,   102,
     105,   106,   109,   110,   112,   113,   116,   119,   121,   122,
     125,   126,   130,   131,   133,   134,   137,   138,   139,   140,
     141,   144,   145,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   159,   160,   162,   163,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   185,   186,   187,   189,   190,
     192,   193,   194,   195,   197,   198,   199,   202,   203
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "ELSE", "WHILE", "IF", "INT",
  "SHORT", "DOUBLE", "RETURN", "VOID", "BITWISEAND", "BITWISEOR",
  "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ", "GE", "GT",
  "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS",
  "RBRACE", "RPAR", "SEMI", "RESERVED", "SIMPLECOMMENT", "MLCOMMENTS",
  "MLCOMMENTE", "THEN", "CHRLIT", "ID", "REALLIT", "INTLIT", "OP1",
  "error_aux", "$accept", "FunctionsAndDeclarations",
  "kleenClosureFDefFDecDec", "FunctionDefinition", "FunctionBody",
  "DeclarationsAndStatements", "DeclarationsOrStatements",
  "FunctionDeclaration", "ParameterList",
  "kleenClosureCommaParameterDeclaration", "ParameterDeclaration",
  "Declaration", "kleenClosureCommaDeclarator", "TypeSpec", "Declarator",
  "Statement", "kleenClosureStatement", "ErrorOrStat", "Expression",
  "kleenClosureCommaExpr", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -117

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-117)))

#define YYTABLE_NINF -5

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     545,   -26,  -117,  -117,  -117,  -117,  -117,    13,  -117,  -117,
    -117,   -23,  -117,  -117,    56,   524,   536,    46,  -117,  -117,
    -117,  -117,   452,   108,    25,   164,   452,   452,   452,  -117,
      20,  -117,  -117,   381,    21,  -117,     5,    16,  -117,    27,
     312,  -117,  -117,  -117,   120,   452,   452,   452,   452,   452,
     452,   452,   452,   452,   452,   452,   452,   452,   452,   452,
     452,   452,   452,   -13,    59,  -117,    58,  -117,  -117,  -117,
      48,  -117,   381,   480,   442,   223,   423,   381,  -117,   381,
    -117,   494,   206,   206,   206,   206,    95,  -117,   494,   402,
      95,    43,  -117,  -117,   108,  -117,   -14,    55,    63,   448,
     143,  -117,  -117,    99,  -117,  -117,    16,  -117,   264,  -117,
     452,  -117,   452,   452,  -117,   288,   -21,  -117,  -117,   187,
    -117,  -117,  -117,  -117,   381,   335,   358,  -117,  -117,  -117,
      54,  -117,  -117,   231,   231,  -117,    79,   231,  -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    26,    27,    29,    30,    28,     0,     5,     5,
       5,     0,    23,     1,     0,     0,     0,    31,    24,     6,
       7,     8,     0,     0,     0,     0,     0,     0,     0,    70,
      71,    73,    72,    32,     0,    18,    21,     0,    22,     0,
       0,    66,    65,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    20,    31,    25,    76,    74,
       0,    69,    77,    61,    63,    62,    48,    59,    56,    60,
      57,    49,    53,    52,    64,    51,    55,    58,    50,    47,
      54,     0,    16,     9,     0,    75,     0,     0,     0,     0,
       0,    10,    34,     0,    12,    15,     0,    14,     0,    19,
       0,    68,     0,     0,    39,     0,     0,    42,    46,     0,
      43,    11,    13,    33,    78,     0,     0,    40,    41,    45,
       0,    35,    44,     0,     0,    38,    36,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -117,  -117,     6,    94,  -117,  -117,    -8,    96,  -117,  -117,
       3,     0,  -117,   -22,    61,   -80,  -117,  -116,   -20,  -117
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,    14,    19,    93,   103,   104,    20,    34,    64,
      35,    21,    24,    11,    18,   118,   119,   120,   108,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    36,    33,   132,   110,    40,    41,    42,    43,    12,
      91,   107,   128,    13,   129,    15,    16,   135,   136,    17,
     111,   138,    92,   107,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    37,     1,    44,     2,    65,    97,    98,
       3,     4,     5,    99,     6,    63,    -2,     1,    66,     2,
      38,    68,    22,     3,     4,     5,   100,     6,    25,   106,
      26,    23,    36,    27,    22,    28,   101,    94,   102,   115,
     112,   106,    95,   137,    29,    30,    31,    32,   113,   129,
     124,   105,   125,   126,     8,   122,     9,   109,    67,     0,
       1,     0,     2,   105,    97,    98,     3,     4,     5,    99,
       6,     2,    50,     0,    52,     3,     4,     5,     0,     6,
       0,    70,   100,    59,    25,     0,    26,     0,     0,    27,
       0,    28,   121,     0,   102,     0,     0,     0,     0,     0,
      29,    30,    31,    32,   116,    25,     0,    26,    97,    98,
      27,     0,    28,    99,    71,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    39,   100,     0,    25,     0,
      26,     0,     0,    27,     0,    28,   117,     0,   102,     0,
       0,     0,     0,     0,    29,    30,    31,    32,   130,    25,
       0,    26,    97,    98,    27,     0,    28,    99,     0,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,     0,
     100,     0,    25,     0,    26,     0,     0,    27,     0,    28,
     131,     0,   102,    50,     0,    52,     0,     0,    29,    30,
      31,    32,   130,    58,    59,    45,    97,    98,    62,     0,
      50,    99,    52,    53,    54,    55,     0,    56,     0,    57,
      58,    59,    60,     0,   100,    62,    25,     0,    26,     0,
       0,    27,     0,    28,     0,     0,   102,     0,     0,     0,
       0,     0,    29,    30,    31,    32,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     0,    56,     0,
      57,    58,    59,    60,     0,    61,    62,     0,     0,   123,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     0,    56,     0,    57,    58,    59,    60,     0,    61,
      62,     0,     0,   127,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     0,    56,     0,    57,    58,
      59,    60,     0,    61,    62,     0,    69,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     0,    56,
       0,    57,    58,    59,    60,     0,    61,    62,     0,   133,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     0,    56,     0,    57,    58,    59,    60,     0,    61,
      62,     0,   134,    45,    46,    47,    48,    49,    50,     0,
      52,    53,    54,    55,     0,    56,     0,    57,    58,    59,
      60,     0,    61,    62,    45,    46,    47,    48,     0,    50,
       0,    52,    53,    54,    55,     0,    56,     0,    57,    58,
      59,    60,     0,     0,    62,    45,    46,    47,     0,     0,
      50,     0,    52,    53,    54,    55,     0,    56,     0,    57,
      58,    59,    60,     0,    45,    62,    47,     0,     0,    50,
       0,    52,    53,    54,    55,     0,    56,     0,    57,    58,
      59,    60,     0,    25,    62,    26,     0,    25,    27,    26,
      28,     0,    27,   114,    28,     0,     0,     0,     0,    29,
      30,    31,    32,    29,    30,    31,    32,    50,     0,    52,
      53,    54,    55,     0,    56,     0,    57,    58,    59,    60,
       0,    50,    62,    52,     0,    54,    55,     0,    56,     0,
      57,    58,    59,     0,    -3,     1,    62,     2,     0,     0,
       0,     3,     4,     5,     0,     6,    -4,     1,     0,     2,
       0,     0,     0,     3,     4,     5,     1,     6,     2,     0,
       0,     0,     3,     4,     5,     0,     6
};

static const yytype_int16 yycheck[] =
{
       0,    23,    22,   119,    18,    25,    26,    27,    28,    35,
      23,    91,    33,     0,    35,     9,    10,   133,   134,    42,
      34,   137,    35,   103,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    18,     1,    25,     3,    42,     5,     6,
       7,     8,     9,    10,    11,    34,     0,     1,    42,     3,
      35,    34,    16,     7,     8,     9,    23,    11,    25,    91,
      27,    25,    94,    30,    16,    32,    33,    18,    35,    99,
      25,   103,    34,     4,    41,    42,    43,    44,    25,    35,
     110,    91,   112,   113,     0,   103,     0,    94,    37,    -1,
       1,    -1,     3,   103,     5,     6,     7,     8,     9,    10,
      11,     3,    17,    -1,    19,     7,     8,     9,    -1,    11,
      -1,     1,    23,    28,    25,    -1,    27,    -1,    -1,    30,
      -1,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,     1,    25,    -1,    27,     5,     6,
      30,    -1,    32,    10,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,     1,    23,    -1,    25,    -1,
      27,    -1,    -1,    30,    -1,    32,    33,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,     1,    25,
      -1,    27,     5,     6,    30,    -1,    32,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    -1,
      23,    -1,    25,    -1,    27,    -1,    -1,    30,    -1,    32,
      33,    -1,    35,    17,    -1,    19,    -1,    -1,    41,    42,
      43,    44,     1,    27,    28,    12,     5,     6,    32,    -1,
      17,    10,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    23,    32,    25,    -1,    27,    -1,
      -1,    30,    -1,    32,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    31,    32,    -1,    -1,    35,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    -1,    31,
      32,    -1,    -1,    35,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    -1,    31,    32,    -1,    34,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    29,    -1,    31,    32,    -1,    34,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    -1,    31,
      32,    -1,    34,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    -1,    31,    32,    12,    13,    14,    15,    -1,    17,
      -1,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    12,    13,    14,    -1,    -1,
      17,    -1,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    12,    32,    14,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    -1,    25,    32,    27,    -1,    25,    30,    27,
      32,    -1,    30,    35,    32,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    41,    42,    43,    44,    17,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    17,    32,    19,    -1,    21,    22,    -1,    24,    -1,
      26,    27,    28,    -1,     0,     1,    32,     3,    -1,    -1,
      -1,     7,     8,     9,    -1,    11,     0,     1,    -1,     3,
      -1,    -1,    -1,     7,     8,     9,     1,    11,     3,    -1,
      -1,    -1,     7,     8,     9,    -1,    11
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    11,    48,    50,    54,
      58,    60,    35,     0,    49,    49,    49,    42,    61,    50,
      54,    58,    16,    25,    59,    25,    27,    30,    32,    41,
      42,    43,    44,    65,    55,    57,    60,    18,    35,     1,
      65,    65,    65,    65,    25,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    24,    26,    27,    28,
      29,    31,    32,    34,    56,    42,    42,    61,    34,    34,
       1,    34,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    23,    35,    51,    18,    34,    66,     5,     6,    10,
      23,    33,    35,    52,    53,    58,    60,    62,    65,    57,
      18,    34,    25,    25,    35,    65,     1,    33,    62,    63,
      64,    33,    53,    35,    65,    65,    65,    35,    33,    35,
       1,    33,    64,    34,    34,    64,    64,     4,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    49,    49,    49,    49,    50,
      51,    51,    52,    52,    53,    53,    54,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    60,    60,    60,    60,
      60,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     2,     2,     2,     6,
       2,     3,     1,     2,     1,     1,     6,     2,     0,     3,
       2,     1,     4,     2,     0,     3,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     3,     5,     7,     5,     2,
       3,     3,     2,     1,     2,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     5,     3,
       1,     1,     1,     1,     3,     4,     3,     0,     3
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 91 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.prog)=myprog=insert_program_func_def((yyvsp[-1].i_f_def),(yyvsp[0].prog));}}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 92 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.prog)=myprog=insert_program_func_dec((yyvsp[-1].i_f_dec),(yyvsp[0].prog));}}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 93 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.prog)=myprog=insert_program_dec((yyvsp[-1].i_dec),(yyvsp[0].prog));}}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 96 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.prog)= NULL;}}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 97 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.prog)=insert_program_func_def_rem((yyvsp[-1].prog),(yyvsp[0].i_f_def));}}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 98 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.prog)=insert_program_func_dec_rem((yyvsp[-1].prog),(yyvsp[0].i_f_dec));}}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 99 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.prog)=insert_program_dec_rem((yyvsp[-1].prog),(yyvsp[0].i_dec));}}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 102 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_f_def)=insert_function_definition((yyvsp[-5].integer),(yyvsp[-4].string),(yyvsp[-2].i_param_list),(yyvsp[0].i_f_body));}}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 105 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_f_body)=NULL;}}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 106 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_f_body)=(yyvsp[-1].i_f_body);}}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 109 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_f_body)=(yyvsp[0].i_f_body);}}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 110 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_f_body)=insert_f_body_multiple((yyvsp[-1].i_f_body),(yyvsp[0].i_f_body));}}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 112 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_f_body)=insert_f_body_statement((yyvsp[0].i_stt));} }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 113 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_f_body)=insert_f_body_declaration((yyvsp[0].i_dec));} }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 116 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_f_dec)=insert_function_declaration((yyvsp[-5].integer),(yyvsp[-4].string),(yyvsp[-2].i_param_list));}}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 119 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_param_list)=insert_param_list((yyvsp[-1].i_param_dec), (yyvsp[0].i_param_list));}}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 121 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_param_list)=NULL;}}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 122 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_param_list)=insert_param_list_rem((yyvsp[-2].i_param_list),(yyvsp[0].i_param_dec));}}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 125 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_param_dec)=insert_param_dec((yyvsp[-1].integer),(yyvsp[0].string));}}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 126 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_param_dec)=insert_param_dec((yyvsp[0].integer), NULL);}}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 130 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_dec)=insert_dec((yyvsp[-3].integer),(yyvsp[-2].i_decl),(yyvsp[-1].i_dec));}}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 131 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_dec)=NULL;}}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 133 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_dec)=NULL;}}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 134 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_dec)=insert_dec_rem((yyvsp[-2].i_dec),(yyvsp[0].i_decl));}}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 137 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.integer)=0;}}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 138 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.integer)=1;}}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 139 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.integer)=2;}}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 140 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.integer)=3;}}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 141 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.integer)=4;}}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 144 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_decl)=insert_decl((yyvsp[0].string), NULL);}}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 145 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_decl)=insert_decl((yyvsp[-2].string),(yyvsp[0].i_expr));}}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 148 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=insert_expr_statement((yyvsp[-1].i_expr));}}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 149 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=NULL;}}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 150 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=insert_statlist((yyvsp[-1].i_stt));}}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 151 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=insert_if_statement((yyvsp[-2].i_expr),(yyvsp[0].i_stt),NULL);}}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 152 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=insert_if_statement((yyvsp[-4].i_expr),(yyvsp[-2].i_stt),(yyvsp[0].i_stt));}}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 153 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=insert_while_statement((yyvsp[-2].i_expr),(yyvsp[0].i_stt));}}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 154 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=insert_return(NULL);}}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 155 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=insert_return((yyvsp[-1].i_expr));}}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 156 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=NULL;}}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 157 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=NULL;}}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 159 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=(yyvsp[0].i_stt);}}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 160 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=insert_statement((yyvsp[-1].i_stt),(yyvsp[0].i_stt));}}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 162 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=NULL;}}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 163 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_stt)=(yyvsp[0].i_stt);}}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 166 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),0,(yyvsp[0].i_expr));}}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 167 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),1,(yyvsp[0].i_expr));}}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 168 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),2,(yyvsp[0].i_expr));}}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 169 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),3,(yyvsp[0].i_expr));}}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 170 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),4,(yyvsp[0].i_expr));}}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 171 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),5,(yyvsp[0].i_expr));}}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 172 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),6,(yyvsp[0].i_expr));}}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 173 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),7,(yyvsp[0].i_expr));}}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 174 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),8,(yyvsp[0].i_expr));}}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 175 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),9,(yyvsp[0].i_expr));}}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 176 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),10,(yyvsp[0].i_expr));}}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 177 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),11,(yyvsp[0].i_expr));}}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 178 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),12,(yyvsp[0].i_expr));}}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 179 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),13,(yyvsp[0].i_expr));}}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 180 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),14,(yyvsp[0].i_expr));}}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 181 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),15,(yyvsp[0].i_expr));}}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 182 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),16,(yyvsp[0].i_expr));}}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 183 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op2((yyvsp[-2].i_expr),17,(yyvsp[0].i_expr));}}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 185 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op1(0,(yyvsp[0].i_expr));}}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 186 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op1(1,(yyvsp[0].i_expr));}}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 187 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_op1(2,(yyvsp[0].i_expr));}}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 189 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_call((yyvsp[-4].string),(yyvsp[-2].i_expr),(yyvsp[-1].i_call));}}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 190 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_call((yyvsp[-2].string),NULL,NULL);}}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 192 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_terminal((yyvsp[0].string),1);};}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 193 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_terminal((yyvsp[0].string),2);}}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 194 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_terminal((yyvsp[0].string),5);}}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 195 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=insert_expression_terminal((yyvsp[0].string),7);}}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 197 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=(yyvsp[-1].i_expr);}}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 198 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=NULL;}}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 199 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_expr)=NULL;}}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 202 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_call)=NULL;}}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 203 "uccompiler.y" /* yacc.c:1646  */
    {if(syntax_error_counter == 0){(yyval.i_call)=insert_expression_kleen((yyvsp[-2].i_call),(yyvsp[0].i_expr));}}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1967 "y.tab.c" /* yacc.c:1646  */
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 207 "uccompiler.y" /* yacc.c:1906  */


void yyerror(char *msg) {
        //printf("columns = %d; yyleng = %d\n",columns,yyleng);
        printf ("Line %d, col %d: %s: %s\n" , lines, columns - yyleng, msg , yytext);
        ++syntax_error_counter;
}
