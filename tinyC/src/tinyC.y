%code requires {
	#include "ast/ast.h"
	#include "ast/assignment_expression.h"
	#include "ast/arithmetic_expressions.h"
	#include "ast/bits_expression.h"
	#include "ast/relational_expression.h"
	#include "ast/unary_expression.h"
	#include "ast/postfix_expression.h"
	#include "ast/conditional_expression.h"
	#include "ast/statements/declaration_statement.h"
	#include "ast/statements/iteration_statement.h"
	#include "ast/statements/jump_statement.h"
	#include "ast/statements/selection_statement.h"
}

%{
	/*
	* Some parts retrived from: https://www.lysator.liu.se/c/ANSI-C-grammar-y.html#storage-class-specifier
	**/

#include <cstdio>
#include <string>
#include "ast/ast.h"

using namespace std;

extern int yylineno;
extern int yycolumn;

int yylex();

void yyerror(const char *str)
{
    printf(" Line(%d,%d): %s\n", yylineno, yycolumn, str);
}

#define YYERROR_VERBOSE 1

CompilationUnit *input;
%}

%union {
	char char_t;
    char *id_t;
    int  num_t;
    SemanticValidType semtype_t;
    Statement *statement_t;
	BlockStatement *blkstatement_t;
	CompilationUnit *compunit_t;
    Expr *expr_t;
    StatementList *stmtlist_t;
    Parameter *parameter_t;
    Declarator *declarator_t;
    ExprList *exprlist_t;
    ParamList *paramlist_t;
    DeclaratorList *declist_t;
    DeclarationList *decionlist_t;
}

%token TK_ERROR 
%token<num_t> NUMBER_TK
%token<char_t> CHAR_LITERAL_TK 
%token<id_t> ID_TK STRING_LITERAL_TK

%token SIZEOF_KW PRINT_KW
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN

%token CHAR_KW INT_KW VOID_KW
%token IF_KW ELSE_KW WHILE_KW FOR_KW CONTINUE_KW BREAK_KW RETURN_KW
%token RANDSEED_KW RANDINT_KW TIMECLOCK_KW

//Statements
%type<compunit_t> input
%type<compunit_t> compilation_unit

%type<statement_t> statement
%type<statement_t> external_declaration
%type<statement_t> iteration_statement
%type<statement_t> jump_statement
%type<statement_t> selection_statement
%type<statement_t> function_definition
%type<statement_t> print_statement
%type<statement_t> call_statement
%type<statement_t> declaration 

%type<declarator_t> init_declarator
%type<declarator_t> declarator
%type<declarator_t> direct_declarator

%type<parameter_t> parameter_declaration

%type<declist_t> init_declarator_list
%type<exprlist_t> argument_expression_list
%type<stmtlist_t> declaration_list 
%type<paramlist_t> parameter_type_list
%type<stmtlist_t> statement_list
%type<blkstatement_t> compound_statement

//Expressions
%type<expr_t> expression
%type<expr_t> primary_expression
%type<expr_t> unary_expression
%type<expr_t> postfix_expression
%type<expr_t> assignment_expression
%type<expr_t> optional_expression

%type<expr_t> conditional_expression
%type<expr_t> additive_expression
%type<expr_t> logical_and_expression
%type<expr_t> logical_or_expression
%type<expr_t> inclusive_or_expression
%type<expr_t> exclusive_or_expression
%type<expr_t> and_expression
%type<expr_t> equality_expression
%type<expr_t> relational_expression
%type<expr_t> shift_expression
%type<expr_t> multiplicative_expression

%type<semtype_t> type_specifier
%type<semtype_t> type_name

%expect 1

%start input

%%

input
	: compilation_unit { $$ = $1; input = $$; }
	;

compilation_unit
	: external_declaration	{
		$$ = new CompilationUnit();
		$$->add($1);
	}
	| compilation_unit external_declaration	{
		$$ = $1;
		$$->add($2);
	}
	;

external_declaration
	: function_definition 	{ $$ = $1; }
	| declaration 			{ $$ = $1; }
	;

function_definition
	: type_specifier ID_TK '(' ')' compound_statement	{
		string id = $2;
		free($2);
		$$ = new FunctionDeclaration(id, NULL, $5);
	}
	| type_specifier ID_TK '(' parameter_type_list ')' compound_statement {
		string id = $2;
		free($2);
		$$ = new FunctionDeclaration(id, $4, $6);
	}
	;

compound_statement
	: '{' '}'									{ $$ = new BlockStatement(); }
	| '{' statement_list '}' 					{ $$ = new BlockStatement(); $$->setStmtList(*$2); }
	| '{' declaration_list '}' 					{ $$ = new BlockStatement(); $$->setDecList(*$2); }
	| '{' declaration_list statement_list '}' 	{ $$ = new BlockStatement(*$2,*$3); }
	;

declaration_list
	: declaration {
		$$ = new StatementList;
		$$->push_back($1);
	}
	| declaration_list declaration {
		$$ = $1;
		$$->push_back($2);
	}
	;

declaration
	: type_specifier init_declarator_list ';' { $$ = new Declaration($1,*$2); }
	;

init_declarator_list
	: init_declarator { $$ = new DeclaratorList; $$->push_back($1); }
	| init_declarator_list ',' init_declarator { $$ = $1; $$->push_back($3); }
	;

init_declarator
	: declarator 	{ $$ = $1; }
	| declarator '=' expression {
		if(!$1->isA(VAR_DEC_STATEMENT))
			throw "Just Variable declaration can be initialized!";

		$$ = $1;
		((VariableDeclaration*)$$)->initializer = $3;
	}
	;

declarator
	: direct_declarator { $$ = $1; }
	;

direct_declarator
	: ID_TK	{
		string id = $1;
        free($1);
        $$ = new VariableDeclaration(id);
	}
	| ID_TK '[' NUMBER_TK ']'	{
		string id = $1;
        free($1);
        $$ = new ArrayDeclaration(id,$3);
	}
	| ID_TK '(' parameter_type_list ')' {
		string id = $1;
        free($1);
        $$ = new FunctionDeclaration(id,$3,NULL);
	}
	| ID_TK '(' ')' {
		string id = $1;
        free($1);
        $$ = new FunctionDeclaration(id,NULL,NULL);
	}
	;

statement_list
	: statement { $$ = new StatementList; $$->push_back($1); }
	| statement_list statement { $$ = $1; $$->push_back($2); }
	;

statement
	: optional_expression ';' { $$ = new ExpressionStatement($1); }
	| selection_statement
	| iteration_statement
	| jump_statement
	| compound_statement	{ $$ = $1; }
	| print_statement ';'	{ $$ = $1; }
	| call_statement ';'	{ $$ = $1; }
	;

print_statement
	: PRINT_KW '(' argument_expression_list ')' {
		$$ = new PrintStatement(*$3);
	}
	;

iteration_statement
	: WHILE_KW '(' expression ')' statement 	{ $$ = new WhileStatement($3,$5); }
	| FOR_KW '(' optional_expression ';' optional_expression ';' optional_expression ')' statement {
		$$ = new ForStatement($3, $5, $7, $9);
	}
	;

jump_statement
	: RETURN_KW ';' 			{ $$ = new ReturnStatement(NULL); }
	| RETURN_KW expression ';'	{ $$ = new ReturnStatement($2); }
	;

optional_expression
	: expression 	{ $$ = $1; }
	|				{ $$ = NULL; }
	;

call_statement
	: RANDSEED_KW '(' expression ')' { $$ = new CallStatement(FN_RANDSEED, $3); }
	;

selection_statement
	: IF_KW '(' expression ')' statement 					{ $$ = new IfStatement($3,$5,NULL); }
	| IF_KW '(' expression ')' statement ELSE_KW statement 	{ $$ = new IfStatement($3,$5,$7); }
	;

parameter_type_list
	: parameter_declaration { $$ = new ParamList; $$->push_back($1); }
	| parameter_type_list ',' parameter_declaration { $$ = $1; $$->push_back($3); }
	;

parameter_declaration
	: type_specifier declarator { $$ = new Parameter($1,$2); }
	| type_specifier 			{ $$ = new Parameter($1); }
	;

type_specifier
	: VOID_KW	{ $$ = VOID_TYPE; }
	| CHAR_KW	{ $$ = CHAR_TYPE; }
	| INT_KW	{ $$ = INT_TYPE; }
	;

type_name
	: type_specifier
	;

primary_expression
	: ID_TK	{
		string id = $1;

        free($1);
        $$ = new IdExpr(id);
	}
	| CHAR_LITERAL_TK	{ $$ = new CharExpr($1); }
	| STRING_LITERAL_TK	{
		string str = $1;

	    free($1);
        $$ = new StringExpr(str);
	}
	| NUMBER_TK	{ $$ = new NumExpr($1); }
	| TIMECLOCK_KW '(' NUMBER_TK ')' { $$ = new CallExpr(FN_TIMECLOCK); }
    | RANDINT_KW '(' ')'  { $$ = new CallExpr(FN_RANDINT); }
	| '(' expression ')'	{ $$ = $2; }
	;

postfix_expression
	: primary_expression	{ $$ = $1; }
	| ID_TK '[' expression ']'	{
		string id = $1;

	    free($1);
		$$ = new ArrayAccessExpr(id,$3);
	}
	| ID_TK '(' ')'	{
		string id = $1;

	    free($1);
	    $$ = new CallFunctionExpr(id,NULL);
	}
	| ID_TK '(' argument_expression_list ')'	{
		string id = $1;

	    free($1);
	    $$ = new CallFunctionExpr(id,$3);
	}
	| postfix_expression INC_OP 	{ $$ = new PostIncExpr($1); }
	| postfix_expression DEC_OP		{ $$ = new PostDecExpr($1);	}
	;

argument_expression_list
	: expression {
		$$ = new ExprList;
	    $$->push_back($1);
	}
	| argument_expression_list ',' expression {
		$$ = $1;
	    $$->push_back($3);
	}
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression { $$ = new PreIncExpr($2); }
	| DEC_OP unary_expression { $$ = new PreDecExpr($2); }
	| '+' unary_expression 		{ $$ = new PositiveNumberExpr($2); }
	| '-' unary_expression		{ $$ = new NegativeNumberExpr($2); }
	| '~' unary_expression		{ $$ = new BitNotExpr($2); }
	| '!' unary_expression		{ $$ = new LogicNotExpr($2); }
	| SIZEOF_KW unary_expression { $$ = new SizeOfExpr($2); }
	| SIZEOF_KW '(' type_name ')' { $$ = new SizeOfTypeExpr($3); }
	;

multiplicative_expression
	: unary_expression
	| multiplicative_expression '*' unary_expression { $$ = new MultExpr($1,$3); }
	| multiplicative_expression '/' unary_expression { $$ = new DivExpr($1,$3); }
	| multiplicative_expression '%' unary_expression { $$ = new ModExpr($1,$3); }
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression { $$ = new AddExpr($1,$3); }
	| additive_expression '-' multiplicative_expression { $$ = new SubExpr($1,$3); }
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression   { $$ = new ShiftLeftExpr($1,$3); }
	| shift_expression RIGHT_OP additive_expression  { $$ = new ShiftRightExpr($1,$3); }
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression 	{ $$ = new LTExpr($1,$3); }
	| relational_expression '>' shift_expression	{ $$ = new GTExpr($1,$3); }
	| relational_expression LE_OP shift_expression	{ $$ = new LTEExpr($1,$3); }
	| relational_expression GE_OP shift_expression	{ $$ = new GTEExpr($1,$3); }
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression	{ $$ = new EQExpr($1,$3); }
	| equality_expression NE_OP relational_expression 	{ $$ = new NEExpr($1,$3); }
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression { $$ = new AndExpr($1,$3); }
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression { $$ = new XorExpr($1,$3); }
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression { $$ = new OrExpr($1,$3); }
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression { $$ = new LogicAndExpr($1,$3); }
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression { $$ = new LogicOrExpr($1,$3); }
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression {
		$$ = new TernaryExpr($1, $3, $5);
	}
	;

assignment_expression
	: unary_expression '=' expression 			{ $$ = new  AssignmentExpr($1,$3); }
	| unary_expression MUL_ASSIGN expression 	{ $$ = new  MultAssignmentExpr($1,$3); }
	| unary_expression DIV_ASSIGN expression 	{ $$ = new  DivAssignmentExpr($1,$3); }
	| unary_expression ADD_ASSIGN expression 	{ $$ = new  AddAssignmentExpr($1,$3); }
	| unary_expression MOD_ASSIGN expression 	{ $$ = new  ModAssignmentExpr($1,$3); }
	| unary_expression SUB_ASSIGN expression 	{ $$ = new  SubAssignmentExpr($1,$3); }
	| unary_expression LEFT_ASSIGN expression 	{ $$ = new  LeftAssignmentExpr($1,$3); }
	| unary_expression RIGHT_ASSIGN expression 	{ $$ = new  RightAssignmentExpr($1,$3); }
	| unary_expression AND_ASSIGN expression 	{ $$ = new  AndAssignmentExpr($1,$3); }
	| unary_expression XOR_ASSIGN expression 	{ $$ = new  XorAssignmentExpr($1,$3); }
	| unary_expression OR_ASSIGN expression 	{ $$ = new  OrAssignmentExpr($1,$3); }
	;

expression
	: assignment_expression
	| conditional_expression
	;

%%