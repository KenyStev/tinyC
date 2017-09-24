#ifndef _UNARY_EXPRESSION_H_
#define _UNARY_EXPRESSION_H_

#include "ast.h"

class PreIncExpr : public Expr
{
public:
	PreIncExpr(Expr *expr)
	{
		this->expr = expr;
	}
	void genCode(codeData &);

	Expr *expr;
};

class PreDecExpr : public Expr
{
public:
	PreDecExpr(Expr *expr)
	{
		this->expr = expr;
	}
	void genCode(codeData &);

	Expr *expr;
};

class PositiveNumberExpr : public Expr
{
public:
	PositiveNumberExpr(Expr *expr)
	{
		this->expr = expr;
	}
	void genCode(codeData &);

	Expr *expr;
};

class NegativeNumberExpr : public Expr
{
public:
	NegativeNumberExpr(Expr *expr)
	{
		this->expr = expr;
	}
	void genCode(codeData &);

	Expr *expr;
};

class BitNotExpr : public Expr
{
public:
	BitNotExpr(Expr *expr)
	{
		this->expr = expr;
	}
	void genCode(codeData &);

	Expr *expr;
};

class LogicNotExpr : public Expr
{
public:
	LogicNotExpr(Expr *expr)
	{
		this->expr = expr;
	}
	void genCode(codeData &);

	Expr *expr;
};

class SizeOfExpr : public Expr
{
public:
	SizeOfExpr(Expr *expr)
	{
		this->expr = expr;
	}
	void genCode(codeData &);

	Expr *expr;
};

class SizeOfTypeExpr : public Expr
{
public:
	SizeOfTypeExpr(SemanticValidType targetType)
	{
		this->targetType = targetType;
	}
	void genCode(codeData &);

	SemanticValidType targetType;
};

#endif