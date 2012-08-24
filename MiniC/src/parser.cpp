
/*  A Bison parser, made from c:\dev\minic\minic\grammar/c.y with Bison version GNU Bison version 1.24
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
#define	MODULUS	288
#define	LSHIFT	289
#define	RSHIFT	290
#define	IF	291
#define	ELSE	292
#define	WHILE	293
#define	RETURN	294


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



#define	YYFINAL		71
#define	YYFLAG		-32768
#define	YYNTBASE	40

#define YYTRANSLATE(x) ((unsigned)(x) <= 294 ? yytranslate[x] : 56)

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
    36,    37,    38,    39
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     6,     8,    10,    13,    15,    17,    19,
    21,    23,    25,    29,    32,    36,    42,    45,    52,    59,
    66,    73,    74,    76,    80,    82,    84,    86,    88,    93,
    98,   100,   102,   106,   110,   111,   113,   117,   119,   121,
   123,   125,   127,   129,   131,   133,   135
};

static const short yyrhs[] = {     9,
     0,    10,     0,    11,     0,    42,     0,    43,     0,    42,
    43,     0,    45,     0,    46,     0,    48,     0,    49,     0,
    47,     0,    53,     0,    24,    42,    25,     0,    24,    25,
     0,    40,    51,    28,     0,    40,    51,    21,    53,    28,
     0,    40,    51,     0,    40,     8,    22,    50,    23,    28,
     0,    40,     8,    22,    50,    23,    44,     0,    40,    51,
    22,    50,    23,    28,     0,    40,    51,    22,    50,    23,
    44,     0,     0,    45,     0,    50,    26,    45,     0,     3,
     0,     4,     0,     5,     0,     6,     0,    51,    21,    53,
    28,     0,    51,    22,    54,    23,     0,    51,     0,    52,
     0,    53,    55,    53,     0,    22,    53,    23,     0,     0,
    53,     0,    54,    26,    53,     0,    15,     0,    16,     0,
    17,     0,    18,     0,    19,     0,    20,     0,    29,     0,
    30,     0,    31,     0,    32,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   125,   126,   127,   130,   133,   134,   137,   138,   139,   140,
   141,   142,   145,   146,   149,   150,   151,   154,   161,   168,
   174,   180,   181,   182,   185,   188,   189,   190,   193,   194,
   195,   196,   197,   198,   201,   202,   203,   206,   206,   206,
   206,   206,   206,   207,   207,   207,   207
};

static const char * const yytname[] = {   "$","error","$undefined.","IDENTIFIER",
"INTEGER_NUM","DOUBLE_NUM","FLOAT_NUM","BOOL_LITERAL","MAIN","INT","FLOAT","DOUBLE",
"VOID","BOOL","CHAR","CEQ","CNE","CLT","CLE","CGT","CGE","EQUAL","LPAREN","RPAREN",
"LBRACE","RBRACE","COMMA","DOT","SEMICOLON","PLUS","MINUS","MUL","DIV","MODULUS",
"LSHIFT","RSHIFT","IF","ELSE","WHILE","RETURN","data_type","program","stmts",
"stmt","block","var_decl","main_decl","main_defn","func_decl","func_defn","func_args",
"ident","numeric","expr","call_args","comparison",""
};
#endif

static const short yyr1[] = {     0,
    40,    40,    40,    41,    42,    42,    43,    43,    43,    43,
    43,    43,    44,    44,    45,    45,    45,    46,    47,    48,
    49,    50,    50,    50,    51,    52,    52,    52,    53,    53,
    53,    53,    53,    53,    54,    54,    54,    55,    55,    55,
    55,    55,    55,    55,    55,    55,    55
};

static const short yyr2[] = {     0,
     1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
     1,     1,     3,     2,     3,     5,     2,     6,     6,     6,
     6,     0,     1,     3,     1,     1,     1,     1,     4,     4,
     1,     1,     3,     3,     0,     1,     3,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1
};

static const short yydefact[] = {     0,
    25,    26,    27,    28,     1,     2,     3,     0,     0,     4,
     5,     7,     8,    11,     9,    10,    31,    32,    12,     0,
     0,    17,     6,     0,    35,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,     0,    34,    22,     0,    22,
    15,     0,    36,     0,    33,     0,    23,     0,     0,     0,
    29,    30,     0,    17,     0,     0,    16,     0,    37,     0,
    18,    19,    24,    20,    21,    14,     0,    13,     0,     0,
     0
};

static const short yydefgoto[] = {     9,
    69,    10,    11,    62,    12,    13,    14,    15,    16,    48,
    17,    18,    19,    44,    36
};

static const short yypact[] = {    56,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    46,    11,    56,
-32768,-32768,-32768,-32768,-32768,-32768,    97,-32768,    96,    54,
   -14,    -1,-32768,    46,    46,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    46,-32768,    71,    46,    71,
-32768,    72,    96,    30,    96,    13,-32768,    53,    78,    94,
-32768,-32768,    46,   -19,     0,    71,-32768,     6,    96,     1,
-32768,-32768,-32768,-32768,-32768,-32768,    33,-32768,    22,    25,
-32768
};

static const short yypgoto[] = {   -25,
-32768,   -27,   -10,   -23,     7,-32768,-32768,-32768,-32768,     8,
    -6,-32768,    -7,-32768,-32768
};


#define	YYLAST		128


static const short yytable[] = {    23,
    20,    39,    22,     1,     2,     3,     4,    38,    41,     5,
     6,     7,    46,     1,    46,     1,    42,    43,    21,    39,
    40,    70,     8,    60,    71,    66,    41,    61,    45,    60,
    46,    49,    67,    64,    65,     1,     2,     3,     4,    54,
     0,     5,     6,     7,    47,    59,    47,    50,     1,     2,
     3,     4,    52,     0,     8,    53,    23,    68,     1,     2,
     3,     4,    63,     0,     5,     6,     7,     8,    26,    27,
    28,    29,    30,    31,     0,    55,    37,     8,    56,     5,
     6,     7,    32,    33,    34,    35,    26,    27,    28,    29,
    30,    31,    26,    27,    28,    29,    30,    31,     0,    51,
    32,    33,    34,    35,     0,    57,    32,    33,    34,    35,
    26,    27,    28,    29,    30,    31,    58,    24,    25,    56,
     0,     0,     0,     0,    32,    33,    34,    35
};

static const short yycheck[] = {    10,
     8,    21,     9,     3,     4,     5,     6,    22,    28,     9,
    10,    11,    38,     3,    40,     3,    24,    25,     8,    21,
    22,     0,    22,    24,     0,    25,    28,    28,    36,    24,
    56,    39,    60,    28,    58,     3,     4,     5,     6,    46,
    -1,     9,    10,    11,    38,    53,    40,    40,     3,     4,
     5,     6,    23,    -1,    22,    26,    67,    25,     3,     4,
     5,     6,    56,    -1,     9,    10,    11,    22,    15,    16,
    17,    18,    19,    20,    -1,    23,    23,    22,    26,     9,
    10,    11,    29,    30,    31,    32,    15,    16,    17,    18,
    19,    20,    15,    16,    17,    18,    19,    20,    -1,    28,
    29,    30,    31,    32,    -1,    28,    29,    30,    31,    32,
    15,    16,    17,    18,    19,    20,    23,    21,    22,    26,
    -1,    -1,    -1,    -1,    29,    30,    31,    32
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
{ pProgramBlock = yyvsp[0].block; ;
    break;}
case 5:
{ yyval.block = new Block(lineNo); yyval.block->AddStmt(yyvsp[0].stmt); ;
    break;}
case 6:
{ yyvsp[-1].block->AddStmt(yyvsp[0].stmt); ;
    break;}
case 12:
{ yyval.stmt = new ExprStmt(yyvsp[0].expr, lineNo); ;
    break;}
case 13:
{ yyval.block = yyvsp[-1].block; ;
    break;}
case 14:
{ yyval.block = new Block(lineNo); ;
    break;}
case 15:
{ yyval.stmt = new Variable(yyvsp[-2].data_type, yyvsp[-1].ident, lineNo); ;
    break;}
case 16:
{ yyval.stmt = new Variable(yyvsp[-4].data_type, yyvsp[-3].ident, yyvsp[-1].expr, lineNo); ;
    break;}
case 18:
{
                std::cout << "Errorrrrrrrrrrrrrrrrrrrrrr" << std::endl;
                yyerror("WARNING: Main Declaration not allowed\n");
            ;
    break;}
case 19:
{ 
                pMain = new MainDefn(yyvsp[-5].data_type, *yyvsp[-2].varvec, yyvsp[0].block, lineNo); 
                yyval.stmt = pMain; 
            ;
    break;}
case 20:
{ 
                yyval.stmt = new FuncDecl(yyvsp[-5].data_type, yyvsp[-4].ident, *yyvsp[-2].varvec, lineNo);
            ;
    break;}
case 21:
{ 
                yyval.stmt = new FuncDefn(yyvsp[-5].data_type, yyvsp[-4].ident, *yyvsp[-2].varvec, yyvsp[0].block, lineNo);
            ;
    break;}
case 22:
{ yyval.varvec = new VariableList(lineNo); ;
    break;}
case 23:
{ yyval.varvec = new VariableList(); yyval.varvec->push_back(yyvsp[0].var_decl); ;
    break;}
case 24:
{ yyvsp[-2].varvec->push_back(yyvsp[0].var_decl); ;
    break;}
case 25:
{ yyval.ident = new Identifier(*yyvsp[0].string, lineNo); ;
    break;}
case 26:
{ yyval.expr = new Integer(atol(yyvsp[0].string->c_str()), lineNo); ;
    break;}
case 27:
{ yyval.expr = new Double(atof(yyvsp[0].string->c_str()), lineNo); ;
    break;}
case 28:
{ yyval.expr = new Float(atof(yyvsp[0].string->c_str()), lineNo); ;
    break;}
case 29:
{ yyval.expr = new Assignment(yyvsp[-3].ident, yyvsp[-1].expr, lineNo); ;
    break;}
case 30:
{ yyval.expr = new FunctionCall(yyvsp[-3].ident, *yyvsp[-1].exprvec, lineNo); ;
    break;}
case 31:
{ yyval.ident = yyvsp[0].ident; ;
    break;}
case 33:
{ yyval.expr = new BinaryOperator(yyvsp[-2].expr, yyvsp[-1].token, yyvsp[0].expr, lineNo); ;
    break;}
case 34:
{ yyval.expr = yyvsp[-1].expr; ;
    break;}
case 35:
{ yyval.exprvec = new ExprList(lineNo); ;
    break;}
case 36:
{ yyval.exprvec = new ExprList(lineNo); yyval.exprvec->push_back(yyvsp[0].expr); ;
    break;}
case 37:
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
