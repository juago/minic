
/*  A Bison parser, made from c:\dev\minic\minic\grammar/parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	IDENTIFIER	258
#define	INTEGER_NUM	259
#define	DOUBLE_NUM	260
#define	FLOAT_NUM	261
#define	BOOL_LITERAL	262
#define	MAIN	263
#define	INT	264
#define	FLOAT	265
#define	DOUBLE	266
#define	VOID	267
#define	BOOL	268
#define	CHAR	269
#define	CEQ	270
#define	CNE	271
#define	CLT	272
#define	CLE	273
#define	CGT	274
#define	CGE	275
#define	EQUAL	276
#define	LPAREN	277
#define	RPAREN	278
#define	LBRACE	279
#define	RBRACE	280
#define	COMMA	281
#define	DOT	282
#define	SEMICOLON	283
#define	PLUS	284
#define	MINUS	285
#define	MUL	286
#define	DIV	287
#define	MOD	288
#define	LSHIFT	289
#define	RSHIFT	290
#define	NOT	291
#define	TILDA	292
#define	IF	293
#define	ELSE	294
#define	WHILE	295
#define	RETURN	296
#define	OR	297
#define	AND	298
#define	LE	299
#define	LT	300
#define	GT	301
#define	GE	302
#define	EQ	303
#define	NE	304
#define	UNARY_OP	305


    #include <cstdio>
    #include <cstdlib>

    #include "node.h"

    using namespace std;

    Block*    pProgramBlock; /* the top level root node of our final AST */
    MainDefn* pMain;

    extern int yylex();
    extern unsigned int lineNo;
    extern char *yytext;
    extern char linebuf[50];

    void yyerror(char *s)
    {
         printf("Line %d: %s at %s in this line:\n%s\n",
                lineNo, s, yytext, linebuf);
    }

typedef union
{
    Node                                      *node;
    Block                                     *block;
    Expr                                      *expr;
    Stmt                                      *stmt;
    Identifier                                *ident;
    Variable                                  *var_decl;
    DataType                                  *data_type;
    std::vector<Variable*>                    *varvec;
    std::vector<Expr*>                        *exprvec;
    std::string                               *string;
    int                                        token;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		98
#define	YYFLAG		-32768
#define	YYNTBASE	51

#define YYTRANSLATE(x) ((unsigned)(x) <= 305 ? yytranslate[x] : 69)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     6,     8,    10,    12,    14,    16,    19,
    21,    23,    25,    27,    29,    31,    35,    38,    42,    48,
    51,    58,    65,    72,    79,    80,    82,    86,    88,    90,
    92,    94,    98,   102,   106,   110,   114,   118,   122,   126,
   130,   134,   138,   142,   146,   149,   152,   155,   160,   165,
   167,   169,   171,   173,   175,   179,   180,   182,   184
};

static const short yyrhs[] = {     9,
     0,    10,     0,    11,     0,    13,     0,    14,     0,    12,
     0,    53,     0,    54,     0,    53,    54,     0,    56,     0,
    57,     0,    59,     0,    60,     0,    58,     0,    67,     0,
    24,    53,    25,     0,    24,    25,     0,    51,    62,    28,
     0,    51,    62,    21,    67,    28,     0,    51,    62,     0,
    51,     8,    22,    61,    23,    28,     0,    51,     8,    22,
    61,    23,    55,     0,    51,    62,    22,    61,    23,    28,
     0,    51,    62,    22,    61,    23,    55,     0,     0,    56,
     0,    61,    26,    56,     0,     3,     0,     4,     0,     5,
     0,     6,     0,    67,    29,    67,     0,    67,    30,    67,
     0,    67,    31,    67,     0,    67,    32,    67,     0,    67,
    33,    67,     0,    67,    42,    67,     0,    67,    43,    67,
     0,    67,    48,    67,     0,    67,    49,    67,     0,    67,
    44,    67,     0,    67,    45,    67,     0,    67,    47,    67,
     0,    67,    46,    67,     0,    36,    67,     0,    29,    67,
     0,    30,    67,     0,    62,    21,    67,    28,     0,    62,
    22,    68,    23,     0,    62,     0,    64,     0,    65,     0,
    66,     0,    63,     0,    22,    67,    23,     0,     0,    12,
     0,    67,     0,    68,    26,    67,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   134,   135,   136,   137,   138,   139,   142,   145,   146,   149,
   150,   151,   152,   153,   154,   157,   158,   161,   162,   163,
   166,   173,   180,   186,   192,   193,   194,   197,   200,   201,
   202,   206,   207,   208,   209,   210,   212,   213,   214,   215,
   216,   217,   218,   219,   222,   223,   224,   226,   227,   228,
   229,   230,   231,   232,   233,   236,   237,   238,   239
};

static const char * const yytname[] = {   "$","error","$undefined.","IDENTIFIER",
"INTEGER_NUM","DOUBLE_NUM","FLOAT_NUM","BOOL_LITERAL","MAIN","INT","FLOAT","DOUBLE",
"VOID","BOOL","CHAR","CEQ","CNE","CLT","CLE","CGT","CGE","EQUAL","LPAREN","RPAREN",
"LBRACE","RBRACE","COMMA","DOT","SEMICOLON","PLUS","MINUS","MUL","DIV","MOD",
"LSHIFT","RSHIFT","NOT","TILDA","IF","ELSE","WHILE","RETURN","OR","AND","LE",
"LT","GT","GE","EQ","NE","UNARY_OP","data_type","program","stmts","stmt","block",
"var_decl","main_decl","main_defn","func_decl","func_defn","func_args","ident",
"numeric","ops_expr","comparison_expr","unary_expr","expr","call_args",""
};
#endif

static const short yyr1[] = {     0,
    51,    51,    51,    51,    51,    51,    52,    53,    53,    54,
    54,    54,    54,    54,    54,    55,    55,    56,    56,    56,
    57,    58,    59,    60,    61,    61,    61,    62,    63,    63,
    63,    64,    64,    64,    64,    64,    65,    65,    65,    65,
    65,    65,    65,    65,    66,    66,    66,    67,    67,    67,
    67,    67,    67,    67,    67,    68,    68,    68,    68
};

static const short yyr2[] = {     0,
     1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
     1,     1,     1,     1,     1,     3,     2,     3,     5,     2,
     6,     6,     6,     6,     0,     1,     3,     1,     1,     1,
     1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     2,     2,     2,     4,     4,     1,
     1,     1,     1,     1,     3,     0,     1,     1,     3
};

static const short yydefact[] = {     0,
    28,    29,    30,    31,     1,     2,     3,     6,     4,     5,
     0,     0,     0,     0,     0,     7,     8,    10,    11,    14,
    12,    13,    50,    54,    51,    52,    53,    15,     0,    46,
    47,    45,     0,    20,     9,     0,    56,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    55,    25,     0,    25,    18,     0,    57,    58,     0,    32,
    33,    34,    35,    36,    37,    38,    41,    42,    44,    43,
    39,    40,     0,    26,     0,     0,     0,    48,    49,     0,
    20,     0,     0,    19,     0,    59,     0,    21,    22,    27,
    23,    24,    17,     0,    16,     0,     0,     0
};

static const short yydefgoto[] = {    15,
    96,    16,    17,    89,    18,    19,    20,    21,    22,    75,
    23,    24,    25,    26,    27,    28,    59
};

static const short yypact[] = {    99,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   121,   121,   121,   121,    42,    99,-32768,-32768,-32768,-32768,
-32768,-32768,    39,-32768,-32768,-32768,-32768,   161,   123,-32768,
-32768,-32768,   -17,   -14,-32768,   121,   111,   121,   121,   121,
   121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
-32768,     8,   121,     8,-32768,   131,-32768,   161,    63,    -8,
    -8,-32768,-32768,-32768,   182,   188,   209,   209,   209,   209,
   209,   209,    12,-32768,    64,   153,    65,-32768,-32768,   121,
   -12,    34,     8,-32768,    35,   161,    43,-32768,-32768,-32768,
-32768,-32768,-32768,    71,-32768,    44,    51,-32768
};

static const short yypgoto[] = {   -42,
-32768,   -21,   -16,   -18,   -41,-32768,-32768,-32768,-32768,    15,
    -9,-32768,-32768,-32768,-32768,   -10,-32768
};


#define	YYLAST		258


static const short yytable[] = {    35,
    29,    30,    31,    32,    52,    34,    53,    54,    53,    73,
    74,    73,    74,    55,     1,    55,     5,     6,     7,     8,
     9,    10,    40,    41,    42,    56,    58,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    90,    76,    97,     1,     1,     2,     3,     4,    33,
    98,     5,     6,     7,     8,     9,    10,    87,    87,    36,
    37,    88,    91,    81,    11,    94,    92,    93,    77,    86,
     0,    12,    13,     1,     2,     3,     4,    35,    14,     5,
     6,     7,     8,     9,    10,    79,    82,    85,    80,    83,
    83,     0,    11,     0,     0,    95,     0,     0,     0,    12,
    13,     1,     2,     3,     4,     0,    14,     5,     6,     7,
     8,     9,    10,     1,     2,     3,     4,     0,     0,     0,
    11,     0,    57,     1,     2,     3,     4,    12,    13,     0,
     0,     0,    11,     0,    14,     0,     0,     0,     0,    12,
    13,     0,    11,     0,     0,    51,    14,     0,     0,    12,
    13,    38,    39,    40,    41,    42,    14,     0,    78,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    43,    44,    45,    46,    47,    48,    49,    50,
    84,    38,    39,    40,    41,    42,     0,     0,     0,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    43,    44,    45,    46,    47,    48,    49,    50,
    38,    39,    40,    41,    42,     0,    38,    39,    40,    41,
    42,     0,     0,     0,    44,    45,    46,    47,    48,    49,
    50,    45,    46,    47,    48,    49,    50,    38,    39,    40,
    41,    42,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,-32768,-32768,-32768,-32768,-32768,-32768
};

static const short yycheck[] = {    16,
    11,    12,    13,    14,    22,    15,    21,    22,    21,    52,
    52,    54,    54,    28,     3,    28,     9,    10,    11,    12,
    13,    14,    31,    32,    33,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    83,    83,    53,     0,     3,     3,     4,     5,     6,     8,
     0,     9,    10,    11,    12,    13,    14,    24,    24,    21,
    22,    28,    28,    73,    22,    87,    85,    25,    54,    80,
    -1,    29,    30,     3,     4,     5,     6,    94,    36,     9,
    10,    11,    12,    13,    14,    23,    23,    23,    26,    26,
    26,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    29,
    30,     3,     4,     5,     6,    -1,    36,     9,    10,    11,
    12,    13,    14,     3,     4,     5,     6,    -1,    -1,    -1,
    22,    -1,    12,     3,     4,     5,     6,    29,    30,    -1,
    -1,    -1,    22,    -1,    36,    -1,    -1,    -1,    -1,    29,
    30,    -1,    22,    -1,    -1,    23,    36,    -1,    -1,    29,
    30,    29,    30,    31,    32,    33,    36,    -1,    28,    29,
    30,    31,    32,    33,    42,    43,    44,    45,    46,    47,
    48,    49,    42,    43,    44,    45,    46,    47,    48,    49,
    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    29,
    30,    31,    32,    33,    42,    43,    44,    45,    46,    47,
    48,    49,    42,    43,    44,    45,    46,    47,    48,    49,
    29,    30,    31,    32,    33,    -1,    29,    30,    31,    32,
    33,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
    49,    44,    45,    46,    47,    48,    49,    29,    30,    31,
    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    44,    45,    46,    47,    48,    49
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */


/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
{ yyval.data_type = new DataType(C_INT, lineNo); delete yyvsp[0].string; ;
    break;}
case 2:
{ yyval.data_type = new DataType(C_FLOAT, lineNo); delete yyvsp[0].string; ;
    break;}
case 3:
{ yyval.data_type = new DataType(C_DOUBLE, lineNo); delete yyvsp[0].string; ;
    break;}
case 4:
{ yyval.data_type = new DataType(C_BOOL, lineNo); delete yyvsp[0].string; ;
    break;}
case 5:
{ yyval.data_type = new DataType(C_CHAR, lineNo); delete yyvsp[0].string; ;
    break;}
case 6:
{ yyval.data_type = new DataType(C_VOID, lineNo); delete yyvsp[0].string; ;
    break;}
case 7:
{ pProgramBlock = yyvsp[0].block; ;
    break;}
case 8:
{ yyval.block = new Block(lineNo); yyval.block->AddStmt(yyvsp[0].stmt); ;
    break;}
case 9:
{ yyvsp[-1].block->AddStmt(yyvsp[0].stmt); ;
    break;}
case 15:
{ yyval.stmt = new ExprStmt(yyvsp[0].expr, lineNo); ;
    break;}
case 16:
{ yyval.block = yyvsp[-1].block; ;
    break;}
case 17:
{ yyval.block = new Block(lineNo); ;
    break;}
case 18:
{ yyval.stmt = new Variable(yyvsp[-2].data_type, yyvsp[-1].ident, lineNo); ;
    break;}
case 19:
{ yyval.stmt = new Variable(yyvsp[-4].data_type, yyvsp[-3].ident, yyvsp[-1].expr, lineNo); ;
    break;}
case 20:
{ yyval.stmt = new Variable(yyvsp[-1].data_type, yyvsp[0].ident, lineNo); ;
    break;}
case 21:
{
                std::cout << "Errorrrrrrrrrrrrrrrrrrrrrr" << std::endl;
                yyerror("WARNING: Main Declaration not allowed\n");
            ;
    break;}
case 22:
{ 
                pMain = new MainDefn(yyvsp[-5].data_type, *yyvsp[-2].varvec, yyvsp[0].block, lineNo); 
                yyval.stmt = pMain; 
            ;
    break;}
case 23:
{ 
                yyval.stmt = new FuncDecl(yyvsp[-5].data_type, yyvsp[-4].ident, *yyvsp[-2].varvec, lineNo);
            ;
    break;}
case 24:
{ 
                yyval.stmt = new FuncDefn(yyvsp[-5].data_type, yyvsp[-4].ident, *yyvsp[-2].varvec, yyvsp[0].block, lineNo);
            ;
    break;}
case 25:
{ yyval.varvec = new VariableList(lineNo); ;
    break;}
case 26:
{ yyval.varvec = new VariableList(); yyval.varvec->push_back(yyvsp[0].var_decl); ;
    break;}
case 27:
{ yyvsp[-2].varvec->push_back(yyvsp[0].var_decl); ;
    break;}
case 28:
{ yyval.ident = new Identifier(*yyvsp[0].string, lineNo); ;
    break;}
case 29:
{ yyval.expr = new Integer(atol(yyvsp[0].string->c_str()), lineNo); ;
    break;}
case 30:
{ yyval.expr = new Double(atof(yyvsp[0].string->c_str()), lineNo); ;
    break;}
case 31:
{ yyval.expr = new Float(atof(yyvsp[0].string->c_str()), lineNo); ;
    break;}
case 32:
{ yyval.expr = new AdditionBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 33:
{ yyval.expr = new SubtractionBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 34:
{ yyval.expr = new MultiplicationBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 35:
{ yyval.expr = new DivisionBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 36:
{ yyval.expr = new ModulusBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 37:
{ yyval.expr = new OrBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 38:
{ yyval.expr = new AndBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 39:
{ yyval.expr = new EQCompareBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 40:
{ yyval.expr = new NECompareBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 41:
{ yyval.expr = new LECompareBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 42:
{ yyval.expr = new LTCompareBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 43:
{ yyval.expr = new GECompareBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 44:
{ yyval.expr = new GTCompareBinaryExpr(yyvsp[-2].expr, yyvsp[0].expr, lineNo); ;
    break;}
case 45:
{ yyval.expr = new NegateUnaryExpr(yyvsp[0].expr, lineNo); ;
    break;}
case 46:
{ yyval.expr = new AdditionUnaryExpr(yyvsp[0].expr, lineNo); ;
    break;}
case 47:
{ yyval.expr = new SubtractUnaryExpr(yyvsp[0].expr, lineNo); ;
    break;}
case 48:
{ yyval.expr = new Assignment(yyvsp[-3].ident, yyvsp[-1].expr, lineNo); ;
    break;}
case 49:
{ yyval.expr = new FunctionCall(yyvsp[-3].ident, *yyvsp[-1].exprvec, lineNo); ;
    break;}
case 50:
{ yyval.ident = yyvsp[0].ident; ;
    break;}
case 55:
{ yyval.expr = yyvsp[-1].expr; ;
    break;}
case 56:
{ yyval.exprvec = new ExprList(lineNo); ;
    break;}
case 57:
{ yyval.exprvec = new ExprList(lineNo); ;
    break;}
case 58:
{ yyval.exprvec = new ExprList(lineNo); yyval.exprvec->push_back(yyvsp[0].expr); ;
    break;}
case 59:
{ yyvsp[-2].exprvec->push_back(yyvsp[0].expr); ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */


  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
