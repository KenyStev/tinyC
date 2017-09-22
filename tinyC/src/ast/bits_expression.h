#ifndef _BITS_EXPRESSION_H_
#define _BITS_EXPRESSION_H_

#include "ast.h"

class ShiftLeftExpr : public BinaryExpr
{
public:
	ShiftLeftExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class ShiftRightExpr : public BinaryExpr
{
public:
	ShiftRightExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class BitAndExpr : public BinaryExpr
{
public:
	BitAndExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class XorExpr : public BinaryExpr
{
public:
	XorExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class BitOrExpr : public BinaryExpr
{
public:
	BitOrExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class AndExpr : public BinaryExpr
{
public:
	AndExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1,expr2) {}
	void genCode(codeData &);
};

class OrExpr : public BinaryExpr
{
public:
	OrExpr(Expr *expr1, Expr *expr2) : BinaryExpr(expr1,expr2) {}
	void genCode(codeData &);
};

#endif