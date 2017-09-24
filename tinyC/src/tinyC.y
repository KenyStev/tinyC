%code requires {
	#include "ast/ast.h"
	#include "ast/assignment_expression.h"
	#include "ast/arithmetic_expressions.h"
	#include "ast/bits_expression.h"
	#include "ast/relational_expression.h"
	#include "ast/unary_expression.h"
	#include "ast/postfix_expression.h"
	#include "ast/statements/declaration_statement.h"
	#include "ast/statements/iteration_statement.h"
}

%{
	/*
	* Some parts retrived from: https://www.lysator.liu.se/c/ANSI-C-grammar-y.html#storage-class-specifier
	**/

#include <cstdio>
#include <string>
//#include "ast.h"

using namespace std;

extern int yylineno;
extern int yycolumn;

int yylex();

void yyerror(const char *str)
{
    printf(" Line(%d,%d): %s\n", yylineno, yycolumn, str);
}

#define YYERROR_VERBOSE 1

//Statement *input;
%}

%token TK_ERROR NUMBER_TK

%token ID_TK STRING_LITERAL_TK CHAR_LITERAL_TK SIZEOF_KW
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN

%token CHAR_KW INT_KW VOID_KW

%token IF_KW ELSE_KW WHILE_KW FOR_KW CONTINUE_KW BREAK_KW RETURN_KW

%token KW_RANDSEED KW_RANDINT KW_TIMECLOCK

%expect 1

%start input

%%

input
	: external_declaration
	| input external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: type_specifier ID_TK '(' ')' compound_statement
	| type_specifier ID_TK '(' parameter_type_list ')' compound_statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

declaration
	: type_specifier init_declarator_list ';'
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

initializer
	: expression
	| '{' initializer_list '}'
	;

initializer_list
	: expression
	| initializer_list ',' expression
	;

statement_list
	: statement
	| statement_list statement
	;

statement
	: optional_expression ';'
	| selection_statement
	| iteration_statement
	| jump_statement
	| compound_statement
	;

iteration_statement
	: WHILE_KW '(' expression ')' statement
	| FOR_KW '(' optional_expression ';' optional_expression ';' optional_expression ')' statement
	;

jump_statement
	: RETURN_KW ';'
	| RETURN_KW expression ';'
	;

optional_expression
	: expression
	|
	;

selection_statement
	: IF_KW '(' expression ')' statement
	| IF_KW '(' expression ')' statement ELSE_KW statement
	;

declarator
	: direct_declarator
	;

direct_declarator
	: ID_TK
	| ID_TK '[' NUMBER_TK ']'
	| ID_TK '[' ']'
	| ID_TK '(' parameter_type_list ')'
	| ID_TK '(' ')'
	;

parameter_type_list
	: parameter_declaration
	| parameter_type_list ',' parameter_declaration
	;

parameter_declaration
	: type_specifier declarator
	| type_specifier
	;

type_specifier
	: VOID_KW
	| CHAR_KW
	| INT_KW
	;

type_name
	: type_specifier
	;

primary_expression
	: ID_TK
	| CHAR_LITERAL_TK
	| STRING_LITERAL_TK
	| NUMBER_TK
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| ID_TK '[' expression ']'
	| ID_TK '(' ')'
	| ID_TK '(' argument_expression_list ')'
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: expression
	| argument_expression_list ',' expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF_KW unary_expression
	| SIZEOF_KW '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: unary_expression assignment_operator expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| conditional_expression
	;

%%