#ifndef _POSTFIX_EXPRESSION_H_
#define _POSTFIX_EXPRESSION_H_
#include "ast.h"

class ArrayAccessExpr : public Expr
{
public:
	ArrayAccessExpr(string id, Expr *expr)
	{
		this->expr = expr;
	}

	int getKind() { return ACCESS_ARRAY_EXPR; }
	void genCode(codeData &);
	string id;
	Expr *expr;
};

class CallFunctionExpr : public Expr
{
public:
	CallFunctionExpr(string id, ExprList *exprList)
	{
		expressions = exprList;
	}

	int getKind() { return CALL_FUNC_EXPR; }
	void genCode(codeData &);
	string id;
	ExprList *expressions;
};

class PostIncExpr : public Expr
{
public:
	PostIncExpr(Expr *expr)
	{
		this->expr = expr;
	}

	int getKind() { return POST_INC_EXPR; }
	void genCode(codeData &);
	Expr *expr;
};

class PostDecExpr : public Expr
{
public:
	PostDecExpr(Expr *expr)
	{
		this->expr = expr;
	}

	int getKind() { return POST_DEC_EXPR; }
	void genCode(codeData &);
	Expr *expr;
};

#endif