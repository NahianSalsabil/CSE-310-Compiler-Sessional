/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "1705091.y"

#include<bits/stdc++.h>
#include"SymbolTable.cpp"

using namespace std;

int yyparse(void);
int yylex(void);

extern FILE *yyin;
ofstream errorout;
ofstream logout;
int line_count = 1;
int error_count = 0;

SymbolTable symboltable(logout, 30); 
string type;

void yyerror(char *s){
	logout << "Error at line " << line_count << ": Syntax Error\n";
	errorout << "Error at line " << line_count << ": Syntax Error\n";
	error_count++;
}


#line 96 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    DO = 262,
    INT = 263,
    CHAR = 264,
    FLOAT = 265,
    VOID = 266,
    RETURN = 267,
    CONTINUE = 268,
    NOT = 269,
    LPAREN = 270,
    RPAREN = 271,
    LCURL = 272,
    RCURL = 273,
    LTHIRD = 274,
    RTHIRD = 275,
    PRINTLN = 276,
    COMMA = 277,
    SEMICOLON = 278,
    ADDOP = 279,
    MULOP = 280,
    INCOP = 281,
    DECOP = 282,
    LOGICOP = 283,
    RELOP = 284,
    ASSIGNOP = 285,
    ID = 286,
    CONST_INT = 287,
    CONST_FLOAT = 288,
    LOWER_THAN_ELSE = 289
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define INT 263
#define CHAR 264
#define FLOAT 265
#define VOID 266
#define RETURN 267
#define CONTINUE 268
#define NOT 269
#define LPAREN 270
#define RPAREN 271
#define LCURL 272
#define RCURL 273
#define LTHIRD 274
#define RTHIRD 275
#define PRINTLN 276
#define COMMA 277
#define SEMICOLON 278
#define ADDOP 279
#define MULOP 280
#define INCOP 281
#define DECOP 282
#define LOGICOP 283
#define RELOP 284
#define ASSIGNOP 285
#define ID 286
#define CONST_INT 287
#define CONST_FLOAT 288
#define LOWER_THAN_ELSE 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "1705091.y"

	vector<SymbolInfo*>* vectorsymbol;
	SymbolInfo *symbol;

#line 221 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

#define YYUNDEFTOK  2
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    45,    45,    50,    71,    87,    99,   111,   127,   181,
     206,   291,   206,   320,   348,   320,   373,   388,   400,   408,
     418,   435,   445,   469,   477,   484,   493,   516,   542,   560,
     583,   597,   620,   632,   642,   642,   642,   656,   685,   706,
     737,   758,   774,   789,   796,   809,   838,   872,   883,   931,
     941,   959,   969,   986,   996,  1014,  1024,  1059,  1071,  1084,
    1096,  1106,  1196,  1209,  1216,  1223,  1234,  1246,  1257,  1264,
    1280
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "INT", "CHAR", "FLOAT", "VOID", "RETURN", "CONTINUE", "NOT", "LPAREN",
  "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "PRINTLN", "COMMA",
  "SEMICOLON", "ADDOP", "MULOP", "INCOP", "DECOP", "LOGICOP", "RELOP",
  "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT", "LOWER_THAN_ELSE",
  "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "$@1", "$@2", "$@3", "$@4", "parameter_list",
  "compound_statement", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "$@5", "$@6",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,   -76,   -76,   -76,    16,    58,   -76,   -76,   -76,   -76,
       6,   -76,   -76,     3,    77,    82,     2,    12,   -76,    22,
      -9,    30,    47,    54,   -76,    63,    48,    58,   -76,   -76,
      57,     9,   -76,   -76,    63,    51,    66,    80,    86,    87,
     118,   118,   118,   -76,    88,   -76,   118,    39,   -76,   -76,
     -76,    89,    73,   -76,    63,   -76,    33,    85,   -76,    83,
      27,    92,   -76,   -76,   -76,   -76,   -76,   -76,   118,   107,
     118,    90,    -1,   -76,   108,    95,   -76,   118,   118,   110,
     -76,   -76,   -76,   -76,   -76,   118,   -76,   118,   118,   118,
     118,   -76,   125,   107,   127,   -76,   -76,   128,   -76,   129,
     101,   114,   -76,   -76,   -76,    92,   122,   -76,   104,   118,
     104,   124,   -76,   118,   -76,   144,   136,   -76,   -76,   -76,
     104,   104,   -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,     0,     0,     0,    22,    13,
       0,    19,     0,    26,     9,     0,    10,     0,    18,    29,
       0,    34,    14,     8,     0,    17,     0,     0,     0,     0,
       0,     0,     0,    21,     0,    43,     0,    45,    63,    64,
      32,     0,    34,    30,     0,    33,    60,     0,    47,    49,
      51,    53,    55,    59,    15,    11,    16,    27,     0,     0,
       0,     0,    60,    58,     0,     0,    57,    68,     0,    28,
      20,    31,    35,    65,    66,     0,    44,     0,     0,     0,
       0,    12,     0,     0,     0,    42,    62,     0,    70,     0,
      67,     0,    36,    48,    50,    54,    52,    56,    34,     0,
      34,     0,    61,     0,    46,    38,     0,    40,    41,    69,
      34,    34,    39,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   148,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -26,    52,    50,   -76,   -76,   -46,   -76,   -76,   -58,
     -41,   -39,   -75,    67,    68,    70,   -37,   -76,   -76,   -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    34,    91,    25,    64,
      20,    32,    50,    51,    14,    52,    53,    54,   102,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    99,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      72,    71,    98,    74,    73,    72,    81,    26,    65,    76,
     103,    93,    37,    27,    38,    39,    11,     1,    15,     2,
       3,    40,    16,    41,    42,    83,    84,    43,    82,    92,
      44,    94,    45,    46,    22,   109,    72,    13,   119,   101,
      47,    48,    49,    23,    72,    24,    72,    72,    72,    72,
      10,    88,     9,   107,    77,    10,    89,     9,    78,    83,
      84,    28,   115,    85,   117,    21,     1,    29,     2,     3,
     116,    33,    72,    30,   122,   123,    37,    35,    38,    39,
      31,     1,    66,     2,     3,    40,    67,    41,    42,    36,
       1,    80,     2,     3,    44,    68,    45,    46,    19,    17,
      18,    69,    70,    75,    47,    48,    49,    37,    86,    38,
      39,    87,     1,    95,     2,     3,    40,    90,    41,    42,
      79,    41,    42,   113,    96,    44,    97,    45,    46,    16,
      45,    46,    41,    42,   114,    47,    48,    49,    47,    48,
      49,   108,    46,   110,   111,   112,    88,   118,   120,    47,
      48,    49,   121,    12,   104,     0,     0,   106,   105
};

static const yytype_int8 yycheck[] =
{
      41,    40,    77,    42,    41,    46,    52,    16,    34,    46,
      85,    69,     3,    22,     5,     6,     0,     8,    15,    10,
      11,    12,    19,    14,    15,    26,    27,    18,    54,    68,
      21,    70,    23,    24,    32,    93,    77,    31,   113,    78,
      31,    32,    33,    31,    85,    23,    87,    88,    89,    90,
       0,    24,     0,    90,    15,     5,    29,     5,    19,    26,
      27,    31,   108,    30,   110,    15,     8,    20,    10,    11,
     109,    23,   113,    19,   120,   121,     3,    27,     5,     6,
      17,     8,    31,    10,    11,    12,    20,    14,    15,    32,
       8,    18,    10,    11,    21,    15,    23,    24,    16,    22,
      23,    15,    15,    15,    31,    32,    33,     3,    23,     5,
       6,    28,     8,    23,    10,    11,    12,    25,    14,    15,
      31,    14,    15,    22,    16,    21,    31,    23,    24,    19,
      23,    24,    14,    15,    20,    31,    32,    33,    31,    32,
      33,    16,    24,    16,    16,    16,    24,    23,     4,    31,
      32,    33,    16,     5,    87,    -1,    -1,    89,    88
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    11,    36,    37,    38,    39,    40,    47,
      48,     0,    38,    31,    49,    15,    19,    22,    23,    16,
      45,    48,    32,    31,    23,    43,    16,    22,    31,    20,
      19,    17,    46,    23,    41,    48,    32,     3,     5,     6,
      12,    14,    15,    18,    21,    23,    24,    31,    32,    33,
      47,    48,    50,    51,    52,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    44,    46,    31,    20,    15,    15,
      15,    56,    55,    61,    56,    15,    61,    15,    19,    31,
      18,    51,    46,    26,    27,    30,    23,    28,    24,    29,
      25,    42,    56,    54,    56,    23,    16,    31,    57,    63,
      64,    56,    53,    57,    58,    60,    59,    61,    16,    54,
      16,    16,    16,    22,    20,    51,    56,    51,    23,    57,
       4,    16,    51,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    39,    39,
      41,    42,    40,    43,    44,    40,    45,    45,    45,    45,
      46,    46,    47,    48,    48,    48,    49,    49,    49,    49,
      50,    50,    51,    51,    52,    53,    51,    51,    51,    51,
      51,    51,    51,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    64,
      64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     0,     8,     0,     0,     7,     4,     3,     2,     1,
       3,     2,     3,     1,     1,     1,     3,     6,     1,     4,
       1,     2,     1,     1,     0,     0,     3,     7,     5,     7,
       5,     5,     3,     1,     2,     1,     4,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     2,     2,     1,
       1,     4,     3,     1,     1,     2,     2,     1,     0,     3,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 45 "1705091.y"
               {
			logout << "Line " << line_count-1 << ": start : program\n\n";
		}
#line 1492 "y.tab.c"
    break;

  case 3:
#line 51 "1705091.y"
        {	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no " << line_count <<  ": program : program unit\n\n";
		for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
			logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
			if((yyvsp[-1].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[-1].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
	}
#line 1517 "y.tab.c"
    break;

  case 4:
#line 72 "1705091.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no " << line_count <<  ": program : unit \n\n";
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
	}
#line 1535 "y.tab.c"
    break;

  case 5:
#line 88 "1705091.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no " << line_count <<  ": unit : var_declaration\n\n";
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void")
				logout << " ";
		}
		logout << "\n\n";
	}
#line 1551 "y.tab.c"
    break;

  case 6:
#line 100 "1705091.y"
     {
     		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
     		logout << "line no " << line_count <<  ": unit : func_declaration\n\n";
     		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
				if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void")
					logout << " ";
			}
		logout << "\n\n"; 
     }
#line 1567 "y.tab.c"
    break;

  case 7:
#line 112 "1705091.y"
     {
     		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
     		logout << "line no " << line_count <<  ": unit : func_definition\n\n";
     		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
				if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
					logout << " ";
				if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
			}
		logout << "\n\n"; 
     }
#line 1585 "y.tab.c"
    break;

  case 8:
#line 128 "1705091.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n";
			
			// semantic error----------//
			if(symboltable.LookUp(logout, (yyvsp[-4].symbol)->getName()) != nullptr){   // Multiple declaration of function
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-4].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-4].symbol)->getName() << "\n\n";
				error_count++;
			}
			vector<string> param_name;       // Multiple declaration of parameter
			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){  
				if((yyvsp[-2].vectorsymbol)->at(i)->getType() == "ID"){
					param_name.push_back((yyvsp[-2].vectorsymbol)->at(i)->getName());
					for(int j = 0; j < param_name.size()-1; j++){
						if((yyvsp[-2].vectorsymbol)->at(i)->getName() == param_name.at(j)){
							param_name.pop_back();
							logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-2].vectorsymbol)->at(i)->getName() << " in parameter\n\n";
							errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-2].vectorsymbol)->at(i)->getName() << " in parameter\n\n";
							error_count++;
						}
					}
				}
			}
			//Insert func declaration Into SymbolTable------------------//
			bool inserted = symboltable.Insert(logout, (yyvsp[-4].symbol)->getName(),"ID",(yyvsp[-5].symbol)->getType(), "func");
			//---------------//

			// store parameter type sequentially
			if(inserted){   
				SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-4].symbol)->getName());
				for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
					if((yyvsp[-2].vectorsymbol)->at(i)->getType() == "INT" || (yyvsp[-2].vectorsymbol)->at(i)->getType() == "FLOAT" || (yyvsp[-2].vectorsymbol)->at(i)->getType() == "VOID")
						temp->setParamType((yyvsp[-2].vectorsymbol)->at(i)->getType());
				}
			}
			//----------//

			logout << (yyvsp[-5].symbol)->getName() << " " << (yyvsp[-4].symbol)->getName() << (yyvsp[-3].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-5].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));

			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
				if((yyvsp[-2].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "void")
					logout << " ";
			}
			logout << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		}
#line 1643 "y.tab.c"
    break;

  case 9:
#line 181 "1705091.y"
                                                           {
			logout << "line no " << line_count <<  ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n";
			
			// semantic error----------//
			if(symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()) != nullptr){   // Multiple declaration of function
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
				error_count++;
			}
			//----------//

			logout << (yyvsp[-4].symbol)->getName() << " " << (yyvsp[-3].symbol)->getName() << (yyvsp[-2].symbol)->getName() << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			(yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));

			//Insert func declaration Into SymbolTable------------------//
			bool inserted = symboltable.Insert(logout, (yyvsp[-3].symbol)->getName(),"ID",(yyvsp[-4].symbol)->getType(), "func");
			//---------------//
		}
#line 1671 "y.tab.c"
    break;

  case 10:
#line 206 "1705091.y"
                                                                 {
				if(symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()) == nullptr)
					bool inserted = symboltable.Insert(logout, (yyvsp[-3].symbol)->getName(),"ID",(yyvsp[-4].symbol)->getType(), "func");
				
				//semantic error-----------//
				else if((symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->getWhichVariable() != "func"){
					logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
					errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
					error_count++;
				}
				else if((symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->getDefined()){     // Function Already Defined
					logout << "Error at line " << line_count << ": Multiple Definition of " << (yyvsp[-3].symbol)->getName() <<"\n\n";
					errorout << "Error at line " << line_count << ": Multiple Definition of " << (yyvsp[-3].symbol)->getName() <<"\n\n";
					error_count++;
				}
				else if(!(symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->getDefined()){        // Return type doesn't match with declaration
					(symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->setDefined(true);
					if((symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()))->getVariableType() != (yyvsp[-4].symbol)->getType()){
						logout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << (yyvsp[-3].symbol)->getName() << "\n\n";
						errorout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << (yyvsp[-3].symbol)->getName() << "\n\n";
						error_count++;
					}
				}

				SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName());
				temp->setDefined(true);
				
				
				vector<string> param_name;       // Multiple declaration of parameter
				for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){  
					if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "ID"){
						param_name.push_back((yyvsp[-1].vectorsymbol)->at(i)->getName());
						for(int j = 0; j < param_name.size()-1; j++){
							if((yyvsp[-1].vectorsymbol)->at(i)->getName() == param_name.at(j)){
								param_name.pop_back();
								logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-1].vectorsymbol)->at(i)->getName() << " in parameter\n\n";
								errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-1].vectorsymbol)->at(i)->getName() << " in parameter\n\n";
								error_count++;
							}
						}
					}
				}
				//------------//

				symboltable.EnterScope(logout);
				
				for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){      // Insert parameter into symboltable
					if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "ID"){
						if((yyvsp[-1].vectorsymbol)->at(i-1)->getType() == "INT")
							bool inserted = symboltable.Insert(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName(),"ID", "INT","var");
						else if((yyvsp[-1].vectorsymbol)->at(i-1)->getType() == "FLOAT")
							bool inserted = symboltable.Insert(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName(),"ID", "FLOAT", "var");
						else if((yyvsp[-1].vectorsymbol)->at(i-1)->getType() == "VOID")
							bool inserted = symboltable.Insert(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName(),"ID", "VOID", "var");
					}
				}
				
				if(temp->getParamSize() == 0){       // store parameter type sequentially
					for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
					if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "INT" || (yyvsp[-1].vectorsymbol)->at(i)->getType() == "FLOAT" || (yyvsp[-1].vectorsymbol)->at(i)->getType() == "VOID")
						temp->setParamType((yyvsp[-1].vectorsymbol)->at(i)->getType());
					}
				}
				else{          // function argument check with declaration
					vector<string> parameter_type;
					for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
						if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "INT" || (yyvsp[-1].vectorsymbol)->at(i)->getType() == "FLOAT" || (yyvsp[-1].vectorsymbol)->at(i)->getType() == "VOID"){
							parameter_type.push_back((yyvsp[-1].vectorsymbol)->at(i)->getType());
						}
					}
					if(parameter_type.size() != temp->getParamSize()){
						logout << "Error at line " << line_count << ": Total number of arguments mismatch with declaration in function " << (yyvsp[-3].symbol)->getName() << "\n\n";
						errorout << "Error at line " << line_count << ": Total number of arguments mismatch with declaration in function " << (yyvsp[-3].symbol)->getName() << "\n\n";
						error_count++;
					} 
					else{
						for(int i = 0; i < temp->getParamSize(); i++){
							if(parameter_type.at(i) != temp->getParamType(i)){
								logout << "Error at line " << line_count << ": " << i+1 << "th argument mismatch in function " << (yyvsp[-3].symbol)->getName() <<"\n\n";
								errorout << "Error at line " << line_count << ": " << i+1 << "th argument mismatch in function " << (yyvsp[-3].symbol)->getName() <<"\n\n";
								error_count++;
							}
						}
					}
				}
			}
#line 1762 "y.tab.c"
    break;

  case 11:
#line 291 "1705091.y"
                                             { 
				symboltable.printAllScopeTable(logout);
				symboltable.ExitScope(logout);
			}
#line 1771 "y.tab.c"
    break;

  case 12:
#line 295 "1705091.y"
                {
 			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n";
			logout << (yyvsp[-7].symbol)->getName() << " " << (yyvsp[-6].symbol)->getName() << (yyvsp[-5].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-7].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-6].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-5].symbol));
			for (int i = 0; i < (yyvsp[-4].vectorsymbol)->size(); i++){
				logout << (yyvsp[-4].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-4].vectorsymbol)->at(i));
				if((yyvsp[-4].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-4].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-4].vectorsymbol)->at(i)->getName() == "void")
					logout << " ";
			}
			logout << (yyvsp[-3].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
			for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
				logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
				if((yyvsp[-1].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "return")
					logout << " ";
				if((yyvsp[-1].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
			}
			logout << "\n\n";
 		}
#line 1801 "y.tab.c"
    break;

  case 13:
#line 320 "1705091.y"
                                                  {
				if(symboltable.LookUp(logout, (yyvsp[-2].symbol)->getName()) == nullptr)
					bool inserted = symboltable.Insert(logout, (yyvsp[-2].symbol)->getName(),"ID", (yyvsp[-3].symbol)->getType(), "func");
				
				//semantic error-----------//
				else{        // Return type doesn't match with declaration
					SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-2].symbol)->getName());
					if(temp->getVariableType() != (yyvsp[-3].symbol)->getType()){
						logout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << (yyvsp[-2].symbol)->getName() << "\n\n";
						errorout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << (yyvsp[-2].symbol)->getName() << "\n\n";
						error_count++;
					}
				}
				SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-2].symbol)->getName());  // Function Already Defined
				if(temp->getDefined()){
					logout << "Error at line " << line_count << ": Multiple Definition of " << (yyvsp[-2].symbol)->getName() <<"\n\n";
					errorout << "Error at line " << line_count << ": Multiple Definition of " << (yyvsp[-2].symbol)->getName() <<"\n\n";
					error_count++;
				}

				else
					temp->setDefined(true);
				
					
				//------------//

				symboltable.EnterScope(logout);
			}
#line 1834 "y.tab.c"
    break;

  case 14:
#line 348 "1705091.y"
                                           {
				symboltable.printAllScopeTable(logout);
				symboltable.ExitScope(logout);
			}
#line 1843 "y.tab.c"
    break;

  case 15:
#line 352 "1705091.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n";
			logout << (yyvsp[-6].symbol)->getName() << " " << (yyvsp[-5].symbol)->getName() << (yyvsp[-4].symbol)->getName() << (yyvsp[-3].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-6].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-5].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
			for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
				logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
				if((yyvsp[-1].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "return")
					logout << " ";
				if((yyvsp[-1].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
			}
			logout << "\n\n";
		}
#line 1866 "y.tab.c"
    break;

  case 16:
#line 374 "1705091.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": parameter_list : parameter_list COMMA type_specifier ID\n\n";
			for(int i = 0; i < (yyvsp[-3].vectorsymbol)->size(); i++){
				logout << (yyvsp[-3].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-3].vectorsymbol)->at(i));
				if((yyvsp[-3].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-3].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-3].vectorsymbol)->at(i)->getName() == "void")
					logout << " ";
			}
			logout << (yyvsp[-2].symbol)->getName() << (yyvsp[-1].symbol)->getName() << " " << (yyvsp[0].symbol)->getName() << "\n\n"; 
			(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		}
#line 1885 "y.tab.c"
    break;

  case 17:
#line 389 "1705091.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no " << line_count <<  ": parameter_list : parameter_list COMMA type_specifier\n\n";
			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			}
			logout << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		}
#line 1901 "y.tab.c"
    break;

  case 18:
#line 401 "1705091.y"
                {
 			logout << "line no " << line_count <<  ": parameter_list : type_specifier ID\n\n";
 			logout << (yyvsp[-1].symbol)->getName() << " " << (yyvsp[0].symbol)->getName() << "\n\n";
 			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
 			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
 			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
 		}
#line 1913 "y.tab.c"
    break;

  case 19:
#line 409 "1705091.y"
                {
			logout << "line no " << line_count <<  ": parameter_list : type_specifier\n\n";
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		}
#line 1924 "y.tab.c"
    break;

  case 20:
#line 418 "1705091.y"
                                           {
		    (yyval.vectorsymbol) = new vector<SymbolInfo*>();
		 	logout << "line no " << line_count <<  ": compound_statement : LCURL statements RCURL\n\n";
		 	logout << (yyvsp[-2].symbol)->getName() << "\n";
		 	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		  	for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
		  		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
		  		logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
				if((yyvsp[-1].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "return")
					logout << " ";
				if((yyvsp[-1].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
		  	}
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		
		    }
#line 1946 "y.tab.c"
    break;

  case 21:
#line 436 "1705091.y"
                    {
 		    	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
 		    	logout << "line no " << line_count <<  ": compound_statement : LCURL RCURL\n\n";
				logout << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
				(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
				(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
 		    }
#line 1958 "y.tab.c"
    break;

  case 22:
#line 446 "1705091.y"
                 {
		 	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		 	logout << "line no " << line_count <<  ": var_declaration : type_specifier declaration_list SEMICOLON\n\n";
			
			// semantic error-----------//
			if((yyvsp[-2].symbol)->getType() == "VOID"){
				logout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
				errorout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
				error_count++;
			}
			//---------------//
		 	logout << (yyvsp[-2].symbol)->getName() << " ";
		 	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		  	for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
		  		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
		  		logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
		  	}
			
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		 }
#line 1984 "y.tab.c"
    break;

  case 23:
#line 470 "1705091.y"
                {
			logout << "line no " << line_count <<  ": type_specifier :  INT\n\n";
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.symbol) = (yyvsp[0].symbol);
			type = "INT";
		}
#line 1995 "y.tab.c"
    break;

  case 24:
#line 478 "1705091.y"
                {
 			logout << "line no " << line_count <<  ": type_specifier :  FLOAT\n\n";
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.symbol) = (yyvsp[0].symbol);
			type = "FLOAT";
 		}
#line 2006 "y.tab.c"
    break;

  case 25:
#line 485 "1705091.y"
                {
 			logout << "line no " << line_count <<  ": type_specifier :  VOID\n\n";
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.symbol) = (yyvsp[0].symbol);
			type = "VOID";
 		}
#line 2017 "y.tab.c"
    break;

  case 26:
#line 494 "1705091.y"
                  { 
			//semantic error------//
			bool inserted;
			if(type != "VOID")      // don't insert void variable in symboltable
				inserted = symboltable.Insert(logout, (yyvsp[0].symbol)->getName(),"ID",type,"var");
			if(!inserted){
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[0].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[0].symbol)->getName() << "\n\n";
				error_count++;
			}
			//--------//

		  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		  	logout << "line no " << line_count <<  ": declaration_list : declaration_list COMMA ID\n\n";
		  	for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
		  		(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
		  		logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
		  	}
			logout << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		  }
#line 2044 "y.tab.c"
    break;

  case 27:
#line 517 "1705091.y"
                  {
			//semantic error------//
			bool inserted;
			if(type != "VOID")      // don't insert void variable in symboltable
				inserted = symboltable.Insert(logout, (yyvsp[-3].symbol)->getName(),"ID",type,"array");
			if(!inserted){
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
				error_count++;
			}
			//--------//

		  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		  	logout << "line no " << line_count <<  ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n";
		  	for(int i = 0; i < (yyvsp[-5].vectorsymbol)->size(); i++){
		  		(yyval.vectorsymbol)->push_back((yyvsp[-5].vectorsymbol)->at(i));
		  		logout << (yyvsp[-5].vectorsymbol)->at(i)->getName();
		  	}
			logout << (yyvsp[-4].symbol)->getName() << (yyvsp[-3].symbol)->getName() <<  (yyvsp[-2].symbol)->getName() << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		  }
#line 2074 "y.tab.c"
    break;

  case 28:
#line 543 "1705091.y"
                  {
			//semantic error------//
			bool inserted;
			if(type != "VOID")     // don't insert void variable in symboltable
				inserted = symboltable.Insert(logout, (yyvsp[0].symbol)->getName(),"ID",type, "var");
			if(!inserted){
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[0].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[0].symbol)->getName() << "\n\n";
				error_count++;
			}
			//--------//

			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
 		  	logout << "line no " << line_count <<  ": declaration_list : ID\n\n";
			logout << (yyvsp[0].symbol)->getName() << "\n\n";
			(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
 		  }
#line 2096 "y.tab.c"
    break;

  case 29:
#line 561 "1705091.y"
                  {
			//semantic error------//
			bool inserted;
			if(type != "VOID")      // don't insert void variable in symboltable
				inserted = symboltable.Insert(logout, (yyvsp[-3].symbol)->getName(),"ID",type, "array");
			if(!inserted){
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].symbol)->getName() << "\n\n";
				error_count++;
			}
			//--------//

 		  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
 		  	logout << "line no " << line_count <<  ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n";
 		  	logout << (yyvsp[-3].symbol)->getName() << (yyvsp[-2].symbol)->getName() << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
 		  	(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
 		  	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
 		  	(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
 		  	(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
 		  }
#line 2121 "y.tab.c"
    break;

  case 30:
#line 584 "1705091.y"
           {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statements : statement\n\n";
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
		}
		logout << "\n\n";
	   }
#line 2139 "y.tab.c"
    break;

  case 31:
#line 598 "1705091.y"
           {
	   	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statements : statements statement\n\n";
		for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
			logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
			if((yyvsp[-1].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[-1].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
		}
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
		}
		logout << "\n\n";
	   }
#line 2165 "y.tab.c"
    break;

  case 32:
#line 621 "1705091.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : var_declaration\n\n";
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void")
				logout << " ";
		}
		logout << "\n\n";
	  }
#line 2181 "y.tab.c"
    break;

  case 33:
#line 633 "1705091.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : expression_statement\n\n";
	  	for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
		}
		logout << "\n\n";
	  }
#line 2195 "y.tab.c"
    break;

  case 34:
#line 642 "1705091.y"
             {symboltable.EnterScope(logout);}
#line 2201 "y.tab.c"
    break;

  case 35:
#line 642 "1705091.y"
                                                                  {symboltable.printAllScopeTable(logout); symboltable.ExitScope(logout);}
#line 2207 "y.tab.c"
    break;

  case 36:
#line 643 "1705091.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : compound_statement\n\n";
	  	for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
			logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
			if((yyvsp[-1].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[-1].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-1].vectorsymbol)->at(i)->getName() == "}")
					logout << "\n";
		}
		logout << "\n\n";
	  }
#line 2225 "y.tab.c"
    break;

  case 37:
#line 657 "1705091.y"
          {
  	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ":statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n";
	  	logout << (yyvsp[-6].symbol)->getName() << (yyvsp[-5].symbol)->getName();
	  	for(int i = 0; i < (yyvsp[-4].vectorsymbol)->size(); i++){
			logout << (yyvsp[-4].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-4].vectorsymbol)->at(i));
		}
		for(int i = 0; i < (yyvsp[-3].vectorsymbol)->size(); i++){
			logout << (yyvsp[-3].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-3].vectorsymbol)->at(i));
		}
		for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
			logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
		}
		logout << (yyvsp[-1].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
  	  }
#line 2258 "y.tab.c"
    break;

  case 38:
#line 686 "1705091.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : IF LPAREN expression RPAREN statement\n\n";
	  	logout << (yyvsp[-4].symbol)->getName() << (yyvsp[-3].symbol)->getName();
	  	for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
			logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
		}
		logout << (yyvsp[-1].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
	  }
#line 2283 "y.tab.c"
    break;

  case 39:
#line 707 "1705091.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n";
	  	logout << (yyvsp[-6].symbol)->getName() << (yyvsp[-5].symbol)->getName();
	  	for(int i = 0; i < (yyvsp[-4].vectorsymbol)->size(); i++){
			logout << (yyvsp[-4].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-4].vectorsymbol)->at(i));
		}
		logout << (yyvsp[-3].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
		for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
			logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			if((yyvsp[-2].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[-2].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[-2].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << (yyvsp[-1].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
	  }
#line 2318 "y.tab.c"
    break;

  case 40:
#line 738 "1705091.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : WHILE LPAREN expression RPAREN statement\n\n";
	  	logout << (yyvsp[-4].symbol)->getName() << (yyvsp[-3].symbol)->getName();
	  	for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
			logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
		}
		logout << (yyvsp[-1].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
			logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == "int" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "float" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "void" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "return")
				logout << " ";
			if((yyvsp[0].vectorsymbol)->at(i)->getName() == ";" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "{" || (yyvsp[0].vectorsymbol)->at(i)->getName() == "}")
				logout << "\n";
		}
		logout << "\n\n";
	  }
#line 2343 "y.tab.c"
    break;

  case 41:
#line 759 "1705091.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n";
		if(symboltable.LookUp(logout, (yyvsp[-2].symbol)->getName()) == nullptr){  // Undeclared error
			logout << "Error at line " << line_count << ": Undeclared variable " << (yyvsp[-2].symbol)->getName() << "\n\n";
			errorout << "Error at line " << line_count << ": Undeclared variable " << (yyvsp[-2].symbol)->getName() << "\n\n";
			error_count++;
		}
	  	logout << (yyvsp[-4].symbol)->getName() << (yyvsp[-3].symbol)->getName() << (yyvsp[-2].symbol)->getName() << (yyvsp[-1].symbol)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
	  	(yyval.vectorsymbol)->push_back((yyvsp[-4].symbol));
	  	(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
	  	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
	  	(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
	  	(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
	  }
#line 2363 "y.tab.c"
    break;

  case 42:
#line 775 "1705091.y"
          {
	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	  	logout << "line no " << line_count <<  ": statement : RETURN expression SEMICOLON\n\n";
	  	logout << (yyvsp[-2].symbol)->getName() << " ";
	  	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
	  	for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
			logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
		}
		logout << (yyvsp[0].symbol)->getName() << "\n\n";
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
	  }
#line 2380 "y.tab.c"
    break;

  case 43:
#line 790 "1705091.y"
                        {
				logout << "line no: " << line_count <<  " expression_statement 	: SEMICOLON\n\n";
				logout << (yyvsp[0].symbol)->getName() << "\n\n";
				(yyval.vectorsymbol) = new vector<SymbolInfo*>();
				(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
			}
#line 2391 "y.tab.c"
    break;

  case 44:
#line 797 "1705091.y"
                        {
				(yyval.vectorsymbol) = new vector<SymbolInfo*>();
				logout << "line no: " << line_count <<  " expression_statement : expression SEMICOLON \n\n";
				for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
					logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
					(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
				}
				logout << (yyvsp[0].symbol)->getName() << "\n\n";
				(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
			}
#line 2406 "y.tab.c"
    break;

  case 45:
#line 810 "1705091.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " variable : ID\n\n";

		// semantic error-------//
		if(symboltable.LookUp(logout, (yyvsp[0].symbol)->getName()) == nullptr){  // Undeclared error
			logout << "Error at line " << line_count << ": Undeclared variable " << (yyvsp[0].symbol)->getName() << "\n\n";
			errorout << "Error at line " << line_count << ": Undeclared variable " << (yyvsp[0].symbol)->getName() << "\n\n";
			error_count++;
		}
		else{    // type mismatch error
			SymbolInfo *temp = symboltable.LookUp(logout, (yyvsp[0].symbol)->getName());
			if(temp->getWhichVariable() == "array"){
				logout << "Error at line " << line_count << ": Type mismatch, " << (yyvsp[0].symbol)->getName() << " is an array\n\n";
				errorout << "Error at line " << line_count << ": Type mismatch, " << (yyvsp[0].symbol)->getName() << " is an array\n\n";
				error_count++;
			}
			else if(temp->getWhichVariable() == "func"){
				logout << "Error at line " << line_count << ": Type mismatch, " << (yyvsp[0].symbol)->getName() << " is a function\n\n";
				errorout << "Error at line " << line_count << ": Type mismatch, " << (yyvsp[0].symbol)->getName() << " is a function\n\n";
				error_count++;
			}
		}
		//-----------//
		logout << (yyvsp[0].symbol)->getName() << "\n\n";
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
		
	}
#line 2439 "y.tab.c"
    break;

  case 46:
#line 839 "1705091.y"
         { 
	 	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	 	logout << "line no: " << line_count <<  " variable : ID LTHIRD expression RTHIRD\n\n";
		// semantic error-------//
		if(symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName()) == nullptr){    // Undeclared error
			logout << "Error at line " << line_count << ": Undeclared variable " << (yyvsp[-3].symbol)->getName() << "\n\n";
			errorout << "Error at line " << line_count << ": Undeclared variable " << (yyvsp[-3].symbol)->getName() << "\n\n";
			error_count++;
		}
		else{               // not an array
			SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName());
			if(temp->getWhichVariable() != "array"){      
				logout << "Error at line " << line_count << ": " << (yyvsp[-3].symbol)->getName() << " not an array\n\n";
				errorout << "Error at line " << line_count << ": " << (yyvsp[-3].symbol)->getName() << " not an array\n\n";
				error_count++;
			}
		}
		if((yyvsp[-1].vectorsymbol)->at(0)->getType() != "CONST_INT"){  // array index not integer
			logout << "Error at line " << line_count << ": Expression inside third brackets not an integer\n\n";
			errorout << "Error at line " << line_count << ": Expression inside third brackets not an integer\n\n";
			error_count++;
		}
		
		//-----------//
	 	logout << (yyvsp[-3].symbol)->getName() << (yyvsp[-2].symbol)->getName() << (yyvsp[-1].vectorsymbol)->at(0)->getName() << (yyvsp[0].symbol)->getName() << "\n\n";
	 	(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
	 	(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(0));
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
	 }
#line 2474 "y.tab.c"
    break;

  case 47:
#line 873 "1705091.y"
          {
 	  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " expression : logic_expression\n\n";

			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";
 	  }
#line 2489 "y.tab.c"
    break;

  case 48:
#line 884 "1705091.y"
           {
	   	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " expression : variable ASSIGNOP logic_expression\n\n";
			
			//semantic error----------//
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){     //  void function in expression
				if((yyvsp[0].vectorsymbol)->at(i)->getType() == "ID" && symboltable.LookUp(logout, (yyvsp[0].vectorsymbol)->at(i)->getName()) != nullptr){
					SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[0].vectorsymbol)->at(i)->getName());
					if(temp->getWhichVariable() == "func" && temp->getVariableType() == "VOID"){
						logout << "Error at line " << line_count << ": Void function used in expression\n\n";
						errorout << "Error at line " << line_count << ": Void function used in expression\n\n";
						error_count++;
					}
				}
			}
			      
			if(symboltable.LookUp(logout, (yyvsp[-2].vectorsymbol)->at(0)->getName()) != nullptr){     // float assignment in integer error
				SymbolInfo *temp = symboltable.LookUp(logout, (yyvsp[-2].vectorsymbol)->at(0)->getName());
				if(temp->getVariableType() == "INT"){
					
					for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
						if((yyvsp[0].vectorsymbol)->at(i)->getType() == "CONST_FLOAT"){
							logout << "Error at line " << line_count << ": Type Mismatch\n\n";
							errorout << "Error at line " << line_count << ": Type Mismatch\n\n";
							error_count++;
							break;
						}
						
					}
				}
			}
			//------------//

			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			}
			logout << (yyvsp[-1].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";
	   }
#line 2539 "y.tab.c"
    break;

  case 49:
#line 932 "1705091.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " logic_expression : rel_expression\n\n";
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";
		}
#line 2553 "y.tab.c"
    break;

  case 50:
#line 942 "1705091.y"
                 {
		 	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " logic_expression : rel_expression LOGICOP rel_expression\n\n";
			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			}
			logout << (yyvsp[-1].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";
		 }
#line 2573 "y.tab.c"
    break;

  case 51:
#line 960 "1705091.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " rel_expression : simple_expression\n\n";
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";
		}
#line 2587 "y.tab.c"
    break;

  case 52:
#line 970 "1705091.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " rel_expression : simple_expression RELOP simple_expression\n\n";
			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			}
			logout << (yyvsp[-1].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";
		}
#line 2607 "y.tab.c"
    break;

  case 53:
#line 987 "1705091.y"
                {	
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " simple_expression : term\n\n";
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";
		}
#line 2621 "y.tab.c"
    break;

  case 54:
#line 997 "1705091.y"
                  {
		  	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " simple_expression : simple_expression ADDOP term\n\n";
			for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
				logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
			}
			logout << (yyvsp[-1].symbol)->getName();
			(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
			for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
				logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
				(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
			}
			logout << "\n\n";
		  }
#line 2641 "y.tab.c"
    break;

  case 55:
#line 1015 "1705091.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " term :	unary_expression\n\n";
		for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
	 	}
	 	logout << "\n\n";
	}
#line 2655 "y.tab.c"
    break;

  case 56:
#line 1025 "1705091.y"
        {
     		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
     		logout << "line no: " << line_count <<  " term :  term MULOP unary_expression\n\n";

		// semantic error-----------//
		if((yyvsp[-1].symbol)->getName() == "%"){    // mod operand not integer
			if((yyvsp[-2].vectorsymbol)->size() == 1 && (yyvsp[0].vectorsymbol)->size() == 1){
				if((yyvsp[-2].vectorsymbol)->at(0)->getType() != "CONST_INT" || (yyvsp[0].vectorsymbol)->at(0)->getType() != "CONST_INT"){
					logout << "Error at line " << line_count << ": Non-Integer operand on modulus operator\n\n";
					errorout << "Error at line " << line_count << ": Non-Integer operand on modulus operator\n\n";
					error_count++;
				}
				else if((yyvsp[0].vectorsymbol)->at(0)->getName() == "0"){
					logout << "Error at line " << line_count << ": Modulus by Zero\n\n";
					errorout << "Error at line " << line_count << ": Modulus by Zero\n\n";
					error_count++;
				}
			}
		}
			
		for(int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
	 	}
	 	logout << (yyvsp[-1].symbol)->getName();
	 	(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
	 	for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
	 	}
	 	logout << "\n\n";
        }
#line 2692 "y.tab.c"
    break;

  case 57:
#line 1060 "1705091.y"
                 {
		 	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		 	logout << "line no: " << line_count <<  " unary_expression : ADDOP unary_expression \n\n";
		 	logout << (yyvsp[-1].symbol)->getName();
		 	(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		 	for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
		 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
		 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
		 	}
		 	logout << "\n\n";
		 }
#line 2708 "y.tab.c"
    break;

  case 58:
#line 1072 "1705091.y"
                 {
		 	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		 	logout << "line no: " << line_count <<  " unary_expression : NOT unary_expression \n\n";
		 	logout << (yyvsp[-1].symbol)->getName();
		 	(yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
		 	for(int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
		 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
		 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
		 	}
		 	logout << "\n\n";
		 	
		 }
#line 2725 "y.tab.c"
    break;

  case 59:
#line 1085 "1705091.y"
                 {
  		 	(yyval.vectorsymbol) = new vector<SymbolInfo*>();
  		 	logout << "line no: " << line_count <<  " unary_expression : factor \n\n";
  		 	for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
  		 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
  		 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
  		 	}
		 	logout << "\n\n";
  		 }
#line 2739 "y.tab.c"
    break;

  case 60:
#line 1097 "1705091.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : variable \n\n";
		for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
  		 }
  		 logout << "\n\n";
	}
#line 2753 "y.tab.c"
    break;

  case 61:
#line 1107 "1705091.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : ID LPAREN argument_list RPAREN\n\n";

		//semantic error--------//
		if(symboltable.LookUp(logout,(yyvsp[-3].symbol)->getName()) == nullptr){
			logout << "Error at line " << line_count << ": Undeclared function " << (yyvsp[-3].symbol)->getName() << "\n\n";
			errorout << "Error at line " << line_count << ": Undeclared function " << (yyvsp[-3].symbol)->getName() << "\n\n";
			error_count++;
		}
		else{          // function argument check with declaration
			SymbolInfo* temp = symboltable.LookUp(logout, (yyvsp[-3].symbol)->getName());
			if(temp->getWhichVariable() != "func"){
				logout << "Error at line " << line_count << ": " << (yyvsp[-3].symbol)->getName() << " not a function" << "\n\n";
				errorout << "Error at line " << line_count << ": " << (yyvsp[-3].symbol)->getName() << " not a function"<< "\n\n";
				error_count++;
			}
			vector<string> parameter_type;
			for(int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
				if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "ID"){
					if(i != (yyvsp[-1].vectorsymbol)->size()-1){
						if((yyvsp[-1].vectorsymbol)->at(i+1)->getName() != "["){      // variable
							SymbolInfo* temp1 = symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName());
							if(temp1 != nullptr)
								parameter_type.push_back(temp1->getVariableType());
						}
						else if((yyvsp[-1].vectorsymbol)->at(i+2)->getType() == "CONST_INT" && (yyvsp[-1].vectorsymbol)->at(i+3)->getName() == "]"){   //array
							SymbolInfo* temp1 = symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName());
							if(temp1 != nullptr)
								parameter_type.push_back(temp1->getVariableType());
						}
					}
					else{       // variable
						SymbolInfo* temp1 = symboltable.LookUp(logout, (yyvsp[-1].vectorsymbol)->at(i)->getName());
						if(temp1 != nullptr)
							parameter_type.push_back(temp1->getVariableType());
					}
				}
				
				else if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "CONST_INT"){
					if(i != 0){
						if((yyvsp[-1].vectorsymbol)->at(i-1)->getName() != "["){
							if((yyvsp[-1].vectorsymbol)->at(i-1)->getName() == ",")
								parameter_type.push_back("INT");
						}
					}
					else{
						parameter_type.push_back("INT");
					}
				}
				else if((yyvsp[-1].vectorsymbol)->at(i)->getType() == "CONST_FLOAT"){
					if(i != 0){
						if((yyvsp[-1].vectorsymbol)->at(i-1)->getName() != "["){
							if((yyvsp[-1].vectorsymbol)->at(i-1)->getName() == ",")
								parameter_type.push_back("FLOAT");
						}
					}
					else{
						parameter_type.push_back("FLOAT");
					}
				}
			}
			if(parameter_type.size() != temp->getParamSize()){
				logout << "Error at line " << line_count << ": Total number of arguments mismatch in function " << (yyvsp[-3].symbol)->getName() << "\n\n";
				errorout << "Error at line " << line_count << ": Total number of arguments mismatch in function " << (yyvsp[-3].symbol)->getName() << "\n\n";
				error_count++;
			} 
			else{
				for(int i = 0; i < temp->getParamSize(); i++){
					if(parameter_type.at(i) != temp->getParamType(i)){
						logout << "Error at line " << line_count << ": " << i+1 << "th argument mismatch in function " << (yyvsp[-3].symbol)->getName() <<"\n\n";
						errorout << "Error at line " << line_count << ": " << i+1 << "th argument mismatch in function " << (yyvsp[-3].symbol)->getName() <<"\n\n";
						error_count++;
						break;
					}
				}
			}
		}
		//---------------//
		logout << (yyvsp[-3].symbol)->getName() << (yyvsp[-2].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-3].symbol));
		(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
  		 }
  		 logout << (yyvsp[0].symbol)->getName() << "\n\n";
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
	}
#line 2847 "y.tab.c"
    break;

  case 62:
#line 1197 "1705091.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : LPAREN expression RPAREN\n\n";
		logout << (yyvsp[-2].symbol)->getName();
		(yyval.vectorsymbol)->push_back((yyvsp[-2].symbol));
		for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
  		 }
  		 logout << (yyvsp[0].symbol)->getName() << "\n\n";
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
	}
#line 2864 "y.tab.c"
    break;

  case 63:
#line 1210 "1705091.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor : CONST_INT\n\n";
		logout << (yyvsp[0].symbol)->getName() << "\n\n";
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
	}
#line 2875 "y.tab.c"
    break;

  case 64:
#line 1217 "1705091.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor : CONST_FLOAT\n\n";
		logout << (yyvsp[0].symbol)->getName() << "\n\n";
		(yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
	}
#line 2886 "y.tab.c"
    break;

  case 65:
#line 1224 "1705091.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : variable INCOP\n\n";
		for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
  		 }
  		 logout << (yyvsp[0].symbol)->getName() << "\n\n";
  		 (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
	}
#line 2901 "y.tab.c"
    break;

  case 66:
#line 1235 "1705091.y"
        {
		(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		logout << "line no: " << line_count <<  " factor  : variable DECOP\n\n";
		for (int i = 0; i < (yyvsp[-1].vectorsymbol)->size(); i++){
	 		logout << (yyvsp[-1].vectorsymbol)->at(i)->getName();
	 		(yyval.vectorsymbol)->push_back((yyvsp[-1].vectorsymbol)->at(i));
  		 }
  		 logout << (yyvsp[0].symbol)->getName() << "\n\n";
  		 (yyval.vectorsymbol)->push_back((yyvsp[0].symbol));
	}
#line 2916 "y.tab.c"
    break;

  case 67:
#line 1247 "1705091.y"
                  {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		  	logout << "line no: " << line_count <<  " argument_list : arguments\n\n";
			for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
		 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
		 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
	  		 }
	  		 logout << "\n\n";
		  }
#line 2930 "y.tab.c"
    break;

  case 68:
#line 1257 "1705091.y"
                  {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
		  	logout << "line no: " << line_count <<  " argument_list : \n\n";
	  		logout << "\n\n";
		  }
#line 2940 "y.tab.c"
    break;

  case 69:
#line 1265 "1705091.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
			logout << "line no: " << line_count <<  " arguments : arguments COMMA logic_expressionn\n";
			for (int i = 0; i < (yyvsp[-2].vectorsymbol)->size(); i++){
		 		logout << (yyvsp[-2].vectorsymbol)->at(i)->getName();
		 		(yyval.vectorsymbol)->push_back((yyvsp[-2].vectorsymbol)->at(i));
	  		 }
	  		 logout << (yyvsp[-1].symbol)->getName();
	  		 (yyval.vectorsymbol)->push_back((yyvsp[-1].symbol));
	  		 for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
		 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
		 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
	  		 }
	  		 logout << "\n\n";
		}
#line 2960 "y.tab.c"
    break;

  case 70:
#line 1281 "1705091.y"
                {
			(yyval.vectorsymbol) = new vector<SymbolInfo*>();
	      		logout << "line no: " << line_count <<  " arguments  : logic_expression\n\n";
			for (int i = 0; i < (yyvsp[0].vectorsymbol)->size(); i++){
		 		logout << (yyvsp[0].vectorsymbol)->at(i)->getName();
		 		(yyval.vectorsymbol)->push_back((yyvsp[0].vectorsymbol)->at(i));
	  		}
	  		logout << "\n\n";
		}
#line 2974 "y.tab.c"
    break;


#line 2978 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 1292 "1705091.y"


int main(int argc,char *argv[])
{

	if(argc!=2){
		cout << "Please provide input file name and try again\n";
		return 0;
	}
	
	FILE *infile=fopen(argv[1],"r");
	if(infile==NULL){
		cout << "Cannot open specified file\n";
		return 0;
	}
	
	logout.open("log.txt");
	errorout.open("error.txt");
	
	yyin=infile;
	yyparse();

	symboltable.printAllScopeTable(logout);
	logout << "Total lines: " << line_count-1 << endl;
    logout << "Total errors: " << error_count << endl;
	fclose(yyin);
	logout.close();
	errorout.close();
	
	
	return 0;
}
