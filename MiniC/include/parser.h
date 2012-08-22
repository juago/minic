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


extern YYSTYPE yylval;
