#ifndef _POSTFIX_EXPRESSION_H_
#define _POSTFIX_EXPRESSION_H_
#include "ast.h"

class ArrayAccessExpr
{
public:
	ArrayAccessExpr(string id, Expr *expr)
	{
		this->expr = expr;
	}

	int getKind() { return ACCESS_ARRAY_EXPR; }
	string id;
	Expr *expr;
};

class CallFunctionExpr 
{
public:
	CallFunctionExpr(string id, ExprList exprList)
	{
		expressions = exprList;
	}

	int getKind() { return CALL_FUNC_EXPR; }
	string id;
	ExprList expressions;
};

class PostIncExpr 
{
public:
	PostIncExpr(Expr *expr)
	{
		this->expr = expr;
	}

	int getKind() { return POST_INC_EXPR; }
	Expr *expr;
};

class PostDecExpr 
{
public:
	PostDecExpr(Expr *expr)
	{
		this->expr = expr;
	}

	int getKind() { return POST_DEC_EXPR; }
	Expr *expr;
};

#endif