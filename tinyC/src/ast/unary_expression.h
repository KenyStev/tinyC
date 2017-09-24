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
	int getKind() { return PRE_INC_EXPR; }
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
	int getKind() { return PRE_DEC_EXPR; }
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
	int getKind() { return POSITIVE_NUM_EXPR; }
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
	int getKind() { return NEGATIVE_NUM_EXPR; }
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
	int getKind() { return BIT_NOT_EXPR; }
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
	int getKind() { return LOGIC_NOT_EXPR; }
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
	int getKind() { return SIZEOF_EXPR; }
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
	int getKind() { return SIZEOF_TYPE_EXPR; }
	void genCode(codeData &);

	SemanticValidType targetType;
};

#endif