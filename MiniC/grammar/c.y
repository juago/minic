%{
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
%}

/* Represents the many different ways we can access our data */
%union {
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
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */

/* constant types */
%token <string> IDENTIFIER INTEGER_NUM DOUBLE_NUM FLOAT_NUM

/* data types */
%token <string> MAIN INT FLOAT DOUBLE

%token <token> CEQ CNE CLT CLE CGT CGE EQUAL
%token <token> LPAREN RPAREN LBRACE RBRACE COMMA DOT SEMICOLON
%token <token> PLUS MINUS MUL DIV

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */

%type <stmt> main_decl main_defn func_decl func_defn
%type <ident> ident
%type <expr> numeric expr 
%type <varvec> func_args
%type <exprvec> call_args
%type <block> program stmts block
%type <stmt> stmt var_decl
%type <token> comparison
%type <data_type> data_type

/* Operator precedence for mathematical operators */
%left PLUS MINUS
%left MUL DIV

%start program

%%

data_type : INT    { $$ = new NDataType(C_INT, lineNo); delete $1; }
          | FLOAT  { $$ = new NDataType(C_FLOAT, lineNo); delete $1; }
          | DOUBLE { $$ = new NDataType(C_DOUBLE, lineNo); delete $1; }
          ;

program : stmts { pProgramBlock = $1; }
        ;
        
stmts : stmt { $$ = new NBlock(lineNo); $$->AddStatement($<stmt>1); }
      | stmts stmt { $1->AddStatement($<stmt>2); }
      ;

stmt : var_decl 
	 | main_decl
     | func_decl 
	 | func_defn 
	 | main_defn
     | expr { $$ = new NExpressionStatement($1, lineNo); }
     ;

block : LBRACE stmts RBRACE { $$ = $2; }
      | LBRACE RBRACE { $$ = new NBlock(lineNo); }
      ;

var_decl : data_type ident SEMICOLON { $$ = new NVariable($1, $2, lineNo); }
         | data_type ident EQUAL expr SEMICOLON { $$ = new NVariable($1, $2, $4, lineNo); }
         | data_type ident
         ;

main_decl : data_type MAIN LPAREN func_args RPAREN SEMICOLON 
			{
				std::cout << "Errorrrrrrrrrrrrrrrrrrrrrr" << std::endl;
				yyerror("WARNING: Main Declaration not allowed\n");
			}
		  ;

main_defn : data_type MAIN LPAREN func_args RPAREN block
            { 
                pMain = new NMainDefinition($1, *$4, $6, lineNo); 
                $$ = pMain; 
            }
          ;

func_decl : data_type ident LPAREN func_args RPAREN SEMICOLON 
            { 
                $$ = new NFunctionDeclaration($1, $2, *$4, lineNo);
            }
          ;

func_defn : data_type ident LPAREN func_args RPAREN block 
            { 
                $$ = new NFunctionDefinition($1, $2, *$4, $6, lineNo);
            }
          ;	
	              
func_args : /*blank*/  { $$ = new VariableList(lineNo); }
          | var_decl { $$ = new VariableList(); $$->push_back($<var_decl>1); }
          | func_args COMMA var_decl { $1->push_back($<var_decl>3); }
          ;

ident : IDENTIFIER { $$ = new NIdentifier(*$1, lineNo); }
      ;

numeric : INTEGER_NUM { $$ = new NInteger(atol($1->c_str()), lineNo); }
        | DOUBLE_NUM  { $$ = new NDouble(atof($1->c_str()), lineNo); }
        | FLOAT_NUM   { $$ = new NFloat(atof($1->c_str()), lineNo); }
        ;
    
expr : ident EQUAL expr SEMICOLON { $$ = new NAssignment($<ident>1, $3, lineNo); }
     | ident LPAREN call_args RPAREN { $$ = new NMethodCall($1, *$3, lineNo); }
     | ident { $<ident>$ = $1; }
     | numeric
     | expr comparison expr { $$ = new NBinaryOperator($1, $2, $3, lineNo); }
     | LPAREN expr RPAREN { $$ = $2; }
     ;
    
call_args : /*blank*/  { $$ = new ExpressionList(lineNo); }
          | expr { $$ = new ExpressionList(lineNo); $$->push_back($1); }
          | call_args COMMA expr  { $1->push_back($3); }
          ;

comparison : CEQ | CNE | CLT | CLE | CGT | CGE 
           | PLUS | MINUS | MUL | DIV
           ;

%%