#ifndef _POSTFIX_EXPRESSION_H
#define _POSTFIX_EXPRESSION_H
#include "ast.h"

class ArrayAccessExpr
{
public:
	ArrayAccessExpr(string id, Expr *expr)
	{
		this->expr = expr;
	}

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

	Expr *expr;
};

class PostDecExpr 
{
public:
	PostDecExpr(Expr *expr)
	{
		this->expr = expr;
	}

	Expr *expr;
};

#endif