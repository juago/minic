
/*  A Bison parser, made from c:\dropbox\minic\minic\grammar/c.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	IDENTIFIER	258
#define	INTEGER_NUM	259
#define	DOUBLE_NUM	260
#define	FLOAT_NUM	261
#define	MAIN	262
#define	INT	263
#define	FLOAT	264
#define	DOUBLE	265
#define	CEQ	266
#define	CNE	267
#define	CLT	268
#define	CLE	269
#define	CGT	270
#define	CGE	271
#define	EQUAL	272
#define	LPAREN	273
#define	RPAREN	274
#define	LBRACE	275
#define	RBRACE	276
#define	COMMA	277
#define	DOT	278
#define	SEMICOLON	279
#define	PLUS	280
#define	MINUS	281
#define	MUL	282
#define	DIV	283

#line 1 "c:\dropbox\minic\minic\grammar/c.y"

    #include <cstdio>
    #include <cstdlib>

    #include "node.h"

    using namespace std;

    NBlock* pProgramBlock; /* the top level root node of our final AST */
    NMainDefinition* pMain;

    extern int yylex();
    extern unsigned int lineNo;
    extern char *yytext;
    extern char linebuf[50];

    void yyerror(char *s)
    {
         printf("Line %d: %s at %s in this line:\n%s\n",
               lineNo, s, yytext, linebuf);
    }

#line 25 "c:\dropbox\minic\minic\grammar/c.y"
typedef union {
    Node                                      *node;
    NBlock                                    *block;
    NExpression                               *expr;
    NStatement                                *stmt;
    NIdentifier                               *ident;
    NVariable                                 *var_decl;
    NDataType                                 *data_type;
    std::vector<NVariable*>                   *varvec;
    std::vector<NExpression*>                 *exprvec;
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
#define	YYNTBASE	29

#define YYTRANSLATE(x) ((unsigned)(x) <= 283 ? yytranslate[x] : 45)

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
    26,    27,    28
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     6,     8,    10,    13,    15,    17,    19,
    21,    23,    25,    29,    32,    36,    42,    45,    52,    59,
    66,    73,    74,    76,    80,    82,    84,    86,    88,    93,
    98,   100,   102,   106,   110,   111,   113,   117,   119,   121,
   123,   125,   127,   129,   131,   133,   135
};

static const short yyrhs[] = {     8,
     0,     9,     0,    10,     0,    31,     0,    32,     0,    31,
    32,     0,    34,     0,    35,     0,    37,     0,    38,     0,
    36,     0,    42,     0,    20,    31,    21,     0,    20,    21,
     0,    29,    40,    24,     0,    29,    40,    17,    42,    24,
     0,    29,    40,     0,    29,     7,    18,    39,    19,    24,
     0,    29,     7,    18,    39,    19,    33,     0,    29,    40,
    18,    39,    19,    24,     0,    29,    40,    18,    39,    19,
    33,     0,     0,    34,     0,    39,    22,    34,     0,     3,
     0,     4,     0,     5,     0,     6,     0,    40,    17,    42,
    24,     0,    40,    18,    43,    19,     0,    40,     0,    41,
     0,    42,    44,    42,     0,    18,    42,    19,     0,     0,
    42,     0,    43,    22,    42,     0,    11,     0,    12,     0,
    13,     0,    14,     0,    15,     0,    16,     0,    25,     0,
    26,     0,    27,     0,    28,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    78,    79,    80,    83,    86,    87,    90,    91,    92,    93,
    94,    95,    98,    99,   102,   103,   104,   107,   114,   121,
   127,   133,   134,   135,   138,   141,   142,   143,   146,   147,
   148,   149,   150,   151,   154,   155,   156,   159,   159,   159,
   159,   159,   159,   160,   160,   160,   160
};

static const char * const yytname[] = {   "$","error","$undefined.","IDENTIFIER",
"INTEGER_NUM","DOUBLE_NUM","FLOAT_NUM","MAIN","INT","FLOAT","DOUBLE","CEQ","CNE",
"CLT","CLE","CGT","CGE","EQUAL","LPAREN","RPAREN","LBRACE","RBRACE","COMMA",
"DOT","SEMICOLON","PLUS","MINUS","MUL","DIV","data_type","program","stmts","stmt",
"block","var_decl","main_decl","main_defn","func_decl","func_defn","func_args",
"ident","numeric","expr","call_args","comparison",""
};
#endif

static const short yyr1[] = {     0,
    29,    29,    29,    30,    31,    31,    32,    32,    32,    32,
    32,    32,    33,    33,    34,    34,    34,    35,    36,    37,
    38,    39,    39,    39,    40,    41,    41,    41,    42,    42,
    42,    42,    42,    42,    43,    43,    43,    44,    44,    44,
    44,    44,    44,    44,    44,    44,    44
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

static const short yypact[] = {   103,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   119,    21,   103,
-32768,-32768,-32768,-32768,-32768,-32768,     8,-32768,    89,    47,
   -16,     3,-32768,   119,   119,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   119,-32768,    60,   119,    60,
-32768,    65,    89,    28,    89,     5,-32768,    34,    71,    45,
-32768,-32768,   119,    -1,    24,    60,-32768,    25,    89,     1,
-32768,-32768,-32768,-32768,-32768,-32768,    33,-32768,    35,    52,
-32768
};

static const short yypgoto[] = {   -26,
-32768,   -27,   -10,   -24,   -25,-32768,-32768,-32768,-32768,    15,
    -6,-32768,    -7,-32768,-32768
};


#define	YYLAST		137


static const short yytable[] = {    23,
    20,    38,    22,     1,     2,     3,     4,     1,     5,     6,
     7,    46,    47,    46,    47,    39,    42,    43,     8,    39,
    40,    66,    41,     1,    24,    25,    41,    21,    45,    46,
    63,    49,    67,    65,    70,     1,     2,     3,     4,    54,
     5,     6,     7,    60,    60,    59,    52,    61,    64,    53,
     8,    71,    55,    68,    50,    56,    23,    26,    27,    28,
    29,    30,    31,    58,     0,    37,    56,     5,     6,     7,
     0,    32,    33,    34,    35,    26,    27,    28,    29,    30,
    31,    26,    27,    28,    29,    30,    31,     0,    51,    32,
    33,    34,    35,     0,    57,    32,    33,    34,    35,    26,
    27,    28,    29,    30,    31,     1,     2,     3,     4,     0,
     5,     6,     7,    32,    33,    34,    35,     0,     0,     0,
     8,     1,     2,     3,     4,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     8
};

static const short yycheck[] = {    10,
     8,    18,     9,     3,     4,     5,     6,     3,     8,     9,
    10,    38,    38,    40,    40,    17,    24,    25,    18,    17,
    18,    21,    24,     3,    17,    18,    24,     7,    36,    56,
    56,    39,    60,    58,     0,     3,     4,     5,     6,    46,
     8,     9,    10,    20,    20,    53,    19,    24,    24,    22,
    18,     0,    19,    21,    40,    22,    67,    11,    12,    13,
    14,    15,    16,    19,    -1,    19,    22,     8,     9,    10,
    -1,    25,    26,    27,    28,    11,    12,    13,    14,    15,
    16,    11,    12,    13,    14,    15,    16,    -1,    24,    25,
    26,    27,    28,    -1,    24,    25,    26,    27,    28,    11,
    12,    13,    14,    15,    16,     3,     4,     5,     6,    -1,
     8,     9,    10,    25,    26,    27,    28,    -1,    -1,    -1,
    18,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    18
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

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

#line 192 "bison.simple"

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
#line 78 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.data_type = new NDataType(C_INT, lineNo); delete yyvsp[0].string; ;
    break;}
case 2:
#line 79 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.data_type = new NDataType(C_FLOAT, lineNo); delete yyvsp[0].string; ;
    break;}
case 3:
#line 80 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.data_type = new NDataType(C_DOUBLE, lineNo); delete yyvsp[0].string; ;
    break;}
case 4:
#line 83 "c:\dropbox\minic\minic\grammar/c.y"
{ pProgramBlock = yyvsp[0].block; ;
    break;}
case 5:
#line 86 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.block = new NBlock(lineNo); yyval.block->AddStatement(yyvsp[0].stmt); ;
    break;}
case 6:
#line 87 "c:\dropbox\minic\minic\grammar/c.y"
{ yyvsp[-1].block->AddStatement(yyvsp[0].stmt); ;
    break;}
case 12:
#line 95 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.stmt = new NExpressionStatement(yyvsp[0].expr, lineNo); ;
    break;}
case 13:
#line 98 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.block = yyvsp[-1].block; ;
    break;}
case 14:
#line 99 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.block = new NBlock(lineNo); ;
    break;}
case 15:
#line 102 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.stmt = new NVariable(yyvsp[-2].data_type, yyvsp[-1].ident, lineNo); ;
    break;}
case 16:
#line 103 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.stmt = new NVariable(yyvsp[-4].data_type, yyvsp[-3].ident, yyvsp[-1].expr, lineNo); ;
    break;}
case 18:
#line 108 "c:\dropbox\minic\minic\grammar/c.y"
{
				std::cout << "Errorrrrrrrrrrrrrrrrrrrrrr" << std::endl;
				yyerror("WARNING: Main Declaration not allowed\n");
			;
    break;}
case 19:
#line 115 "c:\dropbox\minic\minic\grammar/c.y"
{ 
                pMain = new NMainDefinition(yyvsp[-5].data_type, *yyvsp[-2].varvec, yyvsp[0].block, lineNo); 
                yyval.stmt = pMain; 
            ;
    break;}
case 20:
#line 122 "c:\dropbox\minic\minic\grammar/c.y"
{ 
                yyval.stmt = new NFunctionDeclaration(yyvsp[-5].data_type, yyvsp[-4].ident, *yyvsp[-2].varvec, lineNo);
            ;
    break;}
case 21:
#line 128 "c:\dropbox\minic\minic\grammar/c.y"
{ 
                yyval.stmt = new NFunctionDefinition(yyvsp[-5].data_type, yyvsp[-4].ident, *yyvsp[-2].varvec, yyvsp[0].block, lineNo);
            ;
    break;}
case 22:
#line 133 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.varvec = new VariableList(lineNo); ;
    break;}
case 23:
#line 134 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.varvec = new VariableList(); yyval.varvec->push_back(yyvsp[0].var_decl); ;
    break;}
case 24:
#line 135 "c:\dropbox\minic\minic\grammar/c.y"
{ yyvsp[-2].varvec->push_back(yyvsp[0].var_decl); ;
    break;}
case 25:
#line 138 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.ident = new NIdentifier(*yyvsp[0].string, lineNo); ;
    break;}
case 26:
#line 141 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.expr = new NInteger(atol(yyvsp[0].string->c_str()), lineNo); ;
    break;}
case 27:
#line 142 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.expr = new NDouble(atof(yyvsp[0].string->c_str()), lineNo); ;
    break;}
case 28:
#line 143 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.expr = new NFloat(atof(yyvsp[0].string->c_str()), lineNo); ;
    break;}
case 29:
#line 146 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.expr = new NAssignment(yyvsp[-3].ident, yyvsp[-1].expr, lineNo); ;
    break;}
case 30:
#line 147 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.expr = new NMethodCall(yyvsp[-3].ident, *yyvsp[-1].exprvec, lineNo); ;
    break;}
case 31:
#line 148 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.ident = yyvsp[0].ident; ;
    break;}
case 33:
#line 150 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.expr = new NBinaryOperator(yyvsp[-2].expr, yyvsp[-1].token, yyvsp[0].expr, lineNo); ;
    break;}
case 34:
#line 151 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.expr = yyvsp[-1].expr; ;
    break;}
case 35:
#line 154 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.exprvec = new ExpressionList(lineNo); ;
    break;}
case 36:
#line 155 "c:\dropbox\minic\minic\grammar/c.y"
{ yyval.exprvec = new ExpressionList(lineNo); yyval.exprvec->push_back(yyvsp[0].expr); ;
    break;}
case 37:
#line 156 "c:\dropbox\minic\minic\grammar/c.y"
{ yyvsp[-2].exprvec->push_back(yyvsp[0].expr); ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

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
#line 163 "c:\dropbox\minic\minic\grammar/c.y"
