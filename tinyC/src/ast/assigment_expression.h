#include "ast.h"

#ifndef _ARITHMETIC_EXPRESSION_H_
#define _ARITHMETIC_EXPRESSION_H_

class AssigmentExpr : public Expr
{
public:
	AssigmentExpr(Expr *expr1, Expr *expr2)
	{
		this->expr1 = expr1;
		this->expr2 = expr2;
	}
	
	Expr *expr1,*expr2;
};

class MultAssigmentExpr : public AssigmentExpr
{
public:
	MultAssigmentExpr(Expr *expr1, Expr *expr2) : AssigmentExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class DivAssigmentExpr : public AssigmentExpr
{
public:
	DivAssigmentExpr(Expr *expr1, Expr *expr2) : AssigmentExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class ModAssigmentExpr : public AssigmentExpr
{
public:
	ModAssigmentExpr(Expr *expr1, Expr *expr2) : AssigmentExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class AddAssigmentExpr : public AssigmentExpr
{
public:
	AddAssigmentExpr(Expr *expr1, Expr *expr2) : AssigmentExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class SubAssigmentExpr : public AssigmentExpr
{
public:
	SubAssigmentExpr(Expr *expr1, Expr *expr2) : AssigmentExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class LeftAssigmentExpr : public AssigmentExpr
{
public:
	LeftAssigmentExpr(Expr *expr1, Expr *expr2) : AssigmentExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class RightAssigmentExpr : public AssigmentExpr
{
public:
	RightAssigmentExpr(Expr *expr1, Expr *expr2) : AssigmentExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class AndAssigmentExpr : public AssigmentExpr
{
public:
	AndAssigmentExpr(Expr *expr1, Expr *expr2) : AssigmentExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class XorAssigmentExpr : public AssigmentExpr
{
public:
	XorAssigmentExpr(Expr *expr1, Expr *expr2) : AssigmentExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class OrAssigmentExpr : public AssigmentExpr
{
public:
	OrAssigmentExpr(Expr *expr1, Expr *expr2) : AssigmentExpr(expr1,expr2) {}
	void genCode(codeData &);
};

#endif