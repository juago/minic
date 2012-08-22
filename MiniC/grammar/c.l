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

#define isatty _isatty

char linebuf[50];

unsigned int lineNo = 1;

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
"."						{ return TOKEN(DOT); }
","						{ return TOKEN(COMMA); }
"+"						{ return TOKEN(PLUS); }
"-"						{ return TOKEN(MINUS); }
"*"						{ return TOKEN(MUL); }
"/"						{ return TOKEN(DIV); }
";"                     { return TOKEN(SEMICOLON); }

[0-9]+\.[0-9]* 			{ SAVE_TOKEN; return DOUBLE_NUM; }
[0-9]+\.[0-9]*f         { SAVE_TOKEN; return FLOAT_NUM; }
[0-9]+					{ SAVE_TOKEN; return INTEGER_NUM; }

[a-zA-Z_][a-zA-Z0-9_]* 	{ SAVE_TOKEN; return IDENTIFIER; }

.						{ std::cout << "Unknown token " << 
                          yytext << " on line: " << lineNo << std::endl; yyterminate(); }

%%