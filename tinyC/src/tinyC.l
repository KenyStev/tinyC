%option noyywrap
%option yylineno
%option nodefault

%x literal_string
%x block_comment

%{
	/*
	* Some parts retrived from: https://www.lysator.liu.se/c/ANSI-C-grammar-l.html
	**/

#include <cstdlib>
#include <cstring>
#include "ast/ast.h"
#include "tokens.h"

#define YYERROR_VERBOSE 1

int yycolumn = 0;

void count();
%}

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]

%%
[ \t\n]			{ /* Nothing */ }
"//".*\n		{ /* Line Comment */ }
"/*"			{ BEGIN(block_comment); }
"break"			{ count(); return BREAK_KW; }
"char"			{ count(); return CHAR_KW; }
"continue"		{ count(); return CONTINUE_KW; }
"else"			{ count(); return ELSE_KW; }
"for"			{ count(); return FOR_KW; }
"if"			{ count(); return IF_KW; }
"int"			{ count(); return INT_KW; }
"return"		{ count(); return RETURN_KW; }
"sizeof"		{ count(); return SIZEOF_KW; }
"void"			{ count(); return VOID_KW; }
"while"			{ count(); return WHILE_KW; }
"srand" 		{ count(); return KW_RANDSEED; }
"rand" 			{ count(); return KW_RANDINT; }
"time" 			{ count(); return KW_TIMECLOCK; }

{L}({L}|{D}|_)*		{ count(); return ID_TK; }

0[xX]{H}+			{ count(); return NUMBER_TK; }
{D}+				{ count(); return NUMBER_TK; }

'(\\.|[^\\'])+'		{ count(); return CHAR_LITERAL_TK; }
\"(\\.|[^\\"])*\"	{ count(); return STRING_LITERAL_TK; }

">>="			{ count(); return RIGHT_ASSIGN; }
"<<="			{ count(); return LEFT_ASSIGN; }
"+="			{ count(); return ADD_ASSIGN; }
"-="			{ count(); return SUB_ASSIGN; }
"*="			{ count(); return MUL_ASSIGN; }
"/="			{ count(); return DIV_ASSIGN; }
"%="			{ count(); return MOD_ASSIGN; }
"&="			{ count(); return AND_ASSIGN; }
"^="			{ count(); return XOR_ASSIGN; }
"|="			{ count(); return OR_ASSIGN; }
">>"			{ count(); return RIGHT_OP; }
"<<"			{ count(); return LEFT_OP; }
"++"			{ count(); return INC_OP; }
"--"			{ count(); return DEC_OP; }
"->"			{ count(); return PTR_OP; }
"&&"			{ count(); return AND_OP; }
"||"			{ count(); return OR_OP; }
"<="			{ count(); return LE_OP; }
">="			{ count(); return GE_OP; }
"=="			{ count(); return EQ_OP; }
"!="			{ count(); return NE_OP; }
";"			{ count(); return ';'; }
"{"			{ count(); return '{'; }
"}"			{ count(); return '}'; }
","			{ count(); return ','; }
":"			{ count(); return ':'; }
"="			{ count(); return '='; }
"("			{ count(); return '('; }
")"			{ count(); return ')'; }
"["			{ count(); return '['; }
"]"			{ count(); return ']'; }
"."			{ count(); return '.'; }
"&"			{ count(); return '&'; }
"!"			{ count(); return '!'; }
"~"			{ count(); return '~'; }
"-"			{ count(); return '-'; }
"+"			{ count(); return '+'; }
"*"			{ count(); return '*'; }
"/"			{ count(); return '/'; }
"%"			{ count(); return '%'; }
"<"			{ count(); return '<'; }
">"			{ count(); return '>'; }
"^"			{ count(); return '^'; }
"|"			{ count(); return '|'; }
"?"			{ count(); return '?'; }

.			{ printf("Unexpected Token! %s ",yytext); return TK_ERROR; }

<block_comment>"*/" { BEGIN(INITIAL); }
<block_comment>.|\n { /* comment body */ }
<block_comment><<EOF>> {printf("Line(%d,%d): Block comment without close.\n",yylineno,yycolumn); return 0;}

%%
void count() {
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			yycolumn = 0;
		else if (yytext[i] == '\t')
			yycolumn += 8 - (yycolumn % 8);
		else
			yycolumn++;

	ECHO;
}