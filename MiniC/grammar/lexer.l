%option noyywrap
%option stack
%option outfile="lexer.cpp"

L                       [a-zA-Z_]

%{
/* unused options:
   %option debug
*/

#include <iostream>
#include <string>
#include <io.h>

#include "node.h"
#include "parser.h"

#define SAVE_TOKEN (yylval.string = new std::string(yytext, yyleng))
#define TOKEN(t) (yylval.token = t)

#define YY_NEVER_INTERACTIVE 1 
#define isatty _isatty

char linebuf[50];
unsigned int lineNo = 1;

extern void yyerror(char *s);

void ignore_c_comments()
{
    register int c;

    while(1)
    {
        /* eat up text of comment */
        while ( (c = getchar()) != '*' && c != EOF );

        if ( c == '*' )
        {
            while ( (c = getchar()) == '*' );

            /* found the end */
            if ( c == '/' ) break;
        }

        if ( c == EOF )
        {
            yyerror( "EOF in comment" );
            break;
        }
    }
}

%}

%%
\n.*                    { 
                            strncpy(linebuf, yytext+1, sizeof(linebuf)); /* save the next line */
                            yyless(1);      /* give back all but the \n to rescan */                            
                            ++lineNo;
                        }
[ \t]					;

"main"                  { SAVE_TOKEN; return MAIN; }

"int"                   { SAVE_TOKEN; return INT; }
"double"                { SAVE_TOKEN; return DOUBLE; }
"float"                 { SAVE_TOKEN; return FLOAT; }
"void"                  { SAVE_TOKEN; return VOID; }
"bool"                  { SAVE_TOKEN; return BOOL; }
"char"                  { SAVE_TOKEN; return CHAR; }

"if"                    { SAVE_TOKEN; return IF; }
"else"                  { SAVE_TOKEN; return ELSE; }
"while"                 { SAVE_TOKEN; return WHILE; }
"return"                { SAVE_TOKEN; return RETURN; }

"true"                  { SAVE_TOKEN; return BOOL_LITERAL; }
"false"                 { SAVE_TOKEN; return BOOL_LITERAL; }

"!"                     { return TOKEN(NOT); }
"~"                     { return TOKEN(TILDA); }

"="						{ return TOKEN(EQUAL); }
"=="					{ return TOKEN(CEQ); }
"!="					{ return TOKEN(CNE); }
"<"						{ return TOKEN(CLT); }
"<="					{ return TOKEN(CLE); }
">"						{ return TOKEN(CGT); }
">="					{ return TOKEN(CGE); }

"("						{ return TOKEN(LPAREN); }
")"						{ return TOKEN(RPAREN); }
"{"						{ return TOKEN(LBRACE); }
"}"						{ return TOKEN(RBRACE); }

"+"						{ return TOKEN(PLUS); }
"-"						{ return TOKEN(MINUS); }
"*"						{ return TOKEN(MUL); }
"/"						{ return TOKEN(DIV); }
"%"                     { return TOKEN(MOD); }
"<<"                    { return TOKEN(LSHIFT); }
">>"                    { return TOKEN(RSHIFT); }

"."						{ return TOKEN(DOT); }
","						{ return TOKEN(COMMA); }
";"                     { return TOKEN(SEMICOLON); }

[0-9]+\.[0-9]* 			{ SAVE_TOKEN; return DOUBLE_NUM; }
[0-9]+\.[0-9]*f         { SAVE_TOKEN; return FLOAT_NUM; }
[0-9]+					{ SAVE_TOKEN; return INTEGER_NUM; }

[a-zA-Z_][a-zA-Z0-9_]* 	{ SAVE_TOKEN; return IDENTIFIER; }


"/*"                    { ignore_c_comments(); } /* slash star style comments  */
\/\/.*                  {;}                      /* slash slash style comments */

.						{ 
                          std::cout << "Unknown token " << 
                          yytext << " on line: " << lineNo << std::endl; yyterminate(); 
                        }

%%