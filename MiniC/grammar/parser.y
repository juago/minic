%{
    #include <cstdio>
    #include <cstdlib>

    #include "node.h"
    #include "symbol.h"

    using namespace std;

    Block*    pProgramBlock; /* the top level root node of our final AST */
    MainDefn* pMain;

    SymbolTableMgr* pSymbolTableMgr = new SymbolTableMgr();

    extern int yylex();
    extern unsigned int lineNo;
    extern char *yytext;
    extern char linebuf[50];

    string g_currentSymbolName = "";

    void yyerror(char *s)
    {
         printf("Line %d: %s at %s in this line:\n%s\n",
                lineNo, s, yytext, linebuf);
    }
%}

/* Represents the many different ways we can access our data */
%union
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
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */

/* constant types */
%token <string> IDENTIFIER 
%token <string> INTEGER_NUM 
%token <string> DOUBLE_NUM 
%token <string> FLOAT_NUM 
%token <string> BOOL_LITERAL

/* data types */
%token <string> MAIN 
%token <string> INT
%token <string> FLOAT
%token <string> DOUBLE
%token <string> VOID
%token <string> BOOL
%token <string> CHAR

/* Conditional Expression */
%token <token> CEQ 
%token <token> CNE 
%token <token> CLT 
%token <token> CLE 
%token <token> CGT 
%token <token> CGE 
%token <token> EQUAL

/* other indicators */
%token <token> LPAREN 
%token <token> RPAREN 
%token <token> LBRACE 
%token <token> RBRACE 
%token <token> COMMA 
%token <token> DOT 
%token <token> SEMICOLON

/* Operations */
%token <token> PLUS 
%token <token> MINUS 
%token <token> MUL 
%token <token> DIV
%token <token> MOD
%token <token> LSHIFT
%token <token> RSHIFT
%token <token> NOT
%token <token> TILDA

/* Conditions branches */
%token <token> IF 
%token <token> ELSE 
%token <token> WHILE 
%token <token> RETURN

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (Identifier*). It makes the compiler happy.
 */

%type <stmt> main_decl 
%type <stmt> main_defn 
%type <stmt> func_decl 
%type <stmt> func_defn
%type <stmt> stmt 
%type <stmt> var_decl
%type <stmt> if_stmt
%type <stmt> while_stmt
%type <stmt> return_stmt

%type <ident> ident

%type <expr> numeric 
%type <expr> expr
%type <expr> ops_expr
%type <expr> comparison_expr
%type <expr> unary_expr

%type <varvec> func_args
%type <exprvec> call_args

%type <block> program 
%type <block> stmts 
%type <block> block

%type <data_type> data_type

/* Operator precedence for mathematical operators */
%right EQUAL
%left OR
%left AND
%nonassoc LE LT GT GE EQ NE
%left PLUS MINUS
%left MUL DIV MOD
%right UNARY_OP

%start program

%%

data_type : INT                                     { $$ = new DataType(_INT_, lineNo); delete $1; }
          | FLOAT                                   { $$ = new DataType(_FLOAT_, lineNo); delete $1; }
          | DOUBLE                                  { $$ = new DataType(_DOUBLE_, lineNo); delete $1; }
          | BOOL                                    { $$ = new DataType(_BOOL_, lineNo); delete $1; }
          | CHAR                                    { $$ = new DataType(_CHAR_, lineNo); delete $1; }
          | VOID                                    { $$ = new DataType(_VOID_, lineNo); delete $1; }
          ;

program : stmts                                     { /* pProgramBlock = $1; */ }
        ;
        
stmts : stmt                                        { pSymbolTableMgr->insertStmtEntry($<stmt>1); }
      | stmts stmt                                  { pSymbolTableMgr->insertStmtEntry($<stmt>2); }
      ;

stmt : var_decl 
     | main_decl
     | func_decl 
     | func_defn 
     | main_defn
     | if_stmt                                      { $$ = $1; }
     | while_stmt                                   { $$ = $1; }
     | return_stmt                                  { $$ = $1; }
     | expr SEMICOLON                               { $$ = new ExprStmt($1, lineNo); }
     | SEMICOLON                                    { $$ = new NullStmt(lineNo); }
     ;

block : LBRACE                                      { $$ = new Block(lineNo); pSymbolTableMgr->enterScope($$); }
        stmts										{ $$ = $3 }
        RBRACE                                      { pSymbolTableMgr->leaveScope(); }
      ;

var_decl : data_type ident SEMICOLON                
		   {
				Stmt* pStmt = pSymbolTableMgr->isIdentifierPresent($2->getName());
				
				if (pStmt != NULL)
				{
					Log().Get(logERROR) << "Symbol \'" << $2->getName() << "\' on line:" << lineNo << " is not unique" << endl;
				}

			    $$ = new Variable($1, $2, lineNo);
				pSymbolTableMgr->insertVariableEntry((Variable*)$$); 
		   }
         | data_type ident EQUAL expr SEMICOLON     { $$ = new Variable($1, $2, $4, lineNo); pSymbolTableMgr->insertVariableEntry((Variable *)$$); }
         | data_type ident                          { $$ = new Variable($1, $2, lineNo); pSymbolTableMgr->insertVariableEntry((Variable *)$$); }
         ;

main_decl : data_type MAIN LPAREN func_args RPAREN SEMICOLON 
            {
                yyerror("WARNING: Main Declaration not allowed\n");
            }
          ;

main_defn : data_type MAIN LPAREN func_args RPAREN block
            { 
                pMain = new MainDefn($1, *$4, $6, lineNo); 
                $$ = pMain; 
            }
          ;

func_defn : data_type ident LPAREN func_args RPAREN block
            { 
                $$ = new FuncDefn($1, $2, *$4, $6, lineNo);
                pSymbolTableMgr->insertFuncDefnEntry((FuncDefn *)$$);
            }
          ;

func_decl : data_type ident LPAREN func_args RPAREN SEMICOLON 
            { 
                $$ = new FuncDecl($1, $2, *$4, lineNo);
                pSymbolTableMgr->insertFuncDeclEntry((FuncDecl *)$$);
            }
          ;
                  
func_args : /*blank*/                       { $$ = new VariableList(lineNo); }
          | var_decl                        { $$ = new VariableList(); $$->push_back($<var_decl>1); }
          | func_args COMMA var_decl        { $1->push_back($<var_decl>3); }
          ;

ident : IDENTIFIER                          { $$ = new Identifier(*$1, lineNo); g_currentSymbolName = *$1; }
      ;

numeric : INTEGER_NUM                       { $$ = new Integer(atol($1->c_str()), lineNo); }
        | DOUBLE_NUM                        { $$ = new Double(atof($1->c_str()), lineNo); }
        | FLOAT_NUM                         { $$ = new Float((float)(atof($1->c_str())), lineNo); }
        ;


ops_expr  : expr PLUS expr                  { $$ = new AdditionBinaryExpr($1, $3, lineNo); }
          | expr MINUS expr                 { $$ = new SubtractionBinaryExpr($1, $3, lineNo); }
          | expr MUL expr                   { $$ = new MultiplicationBinaryExpr($1, $3, lineNo); }
          | expr DIV expr                   { $$ = new DivisionBinaryExpr($1, $3, lineNo); }
          | expr MOD expr                   { $$ = new ModulusBinaryExpr($1, $3, lineNo); }

comparison_expr : expr OR expr              { $$ = new OrBinaryExpr($1, $3, lineNo); }
                | expr AND expr             { $$ = new AndBinaryExpr($1, $3, lineNo); }
                | expr EQ expr              { $$ = new EQCompareBinaryExpr($1, $3, lineNo); }
                | expr NE expr              { $$ = new NECompareBinaryExpr($1, $3, lineNo); }
                | expr LE expr              { $$ = new LECompareBinaryExpr($1, $3, lineNo); }
                | expr LT expr              { $$ = new LTCompareBinaryExpr($1, $3, lineNo); }
                | expr GE expr              { $$ = new GECompareBinaryExpr($1, $3, lineNo); }
                | expr GT expr              { $$ = new GTCompareBinaryExpr($1, $3, lineNo); }


unary_expr : NOT expr %prec UNARY_OP        { $$ = new NegateUnaryExpr($2, lineNo); }
           | PLUS expr %prec UNARY_OP       { $$ = new AdditionUnaryExpr($2, lineNo); }
           | MINUS expr %prec UNARY_OP      { $$ = new SubtractUnaryExpr($2, lineNo); }

expr : ident EQUAL expr SEMICOLON           { $$ = new Assignment($<ident>1, $3, lineNo); }
     | ident LPAREN call_args RPAREN        { $$ = new FunctionCall($1, *$3, lineNo); }
     | ident                                { $<ident>$ = $1; }
     | ops_expr
     | comparison_expr
     | unary_expr
     | numeric
     | LPAREN expr RPAREN                   { $$ = $2; }
     ;
    
call_args : /*blank*/                       { $$ = new ExprList(lineNo); }
          | VOID                            { $$ = new ExprList(lineNo); }
          | expr                            { $$ = new ExprList(lineNo); $$->push_back($1); }
          | call_args COMMA expr            { $1->push_back($3); }
          ;

if_stmt : IF LPAREN expr RPAREN stmt                { $$ = new IfStmt($3, $5, NULL, lineNo); }
        | IF LPAREN expr RPAREN stmt ELSE stmt      { $$ = new IfStmt($3, $5, $7, lineNo); }
        ;

while_stmt : WHILE LPAREN expr RPAREN stmt          { $$ = new WhileStmt($3, $5, lineNo); }
           ;

return_stmt : RETURN SEMICOLON                      { $$ = new ReturnStmt(NULL, lineNo); }
            | RETURN expr SEMICOLON                 { $$ = new ReturnStmt($2, lineNo); }
            ;

%%