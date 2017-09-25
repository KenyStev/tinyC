#ifndef _ASSIGNMENT_EXPRESSION_H_
#define _ASSIGNMENT_EXPRESSION_H_
#include "ast.h"


class AssignmentExpr : public Expr
{
public:
	AssignmentExpr(Expr *expr1, Expr *expr2)
	{
		this->expr1 = expr1;
		this->expr2 = expr2;
	}
	int getKind() { return ASSIGN_EXPR; }
	void genCode(codeData &);
	Expr *expr1,*expr2;
};

class MultAssignmentExpr : public AssignmentExpr
{
public:
	MultAssignmentExpr(Expr *expr1, Expr *expr2) : AssignmentExpr(expr1,expr2) {}
	int getKind() { return MULT_ASSIGN_EXPR; }
	void genCode(codeData &);
};

class DivAssignmentExpr : public AssignmentExpr
{
public:
	DivAssignmentExpr(Expr *expr1, Expr *expr2) : AssignmentExpr(expr1,expr2) {}
	int getKind() { return DIV_ASSIGN_EXPR; }
	void genCode(codeData &);
};

class ModAssignmentExpr : public AssignmentExpr
{
public:
	ModAssignmentExpr(Expr *expr1, Expr *expr2) : AssignmentExpr(expr1,expr2) {}
	int getKind() { return MOD_ASSIGN_EXPR; }
	void genCode(codeData &);
};

class AddAssignmentExpr : public AssignmentExpr
{
public:
	AddAssignmentExpr(Expr *expr1, Expr *expr2) : AssignmentExpr(expr1,expr2) {}
	int getKind() { return ADD_ASSIGN_EXPR; }
	void genCode(codeData &);
};

class SubAssignmentExpr : public AssignmentExpr
{
public:
	SubAssignmentExpr(Expr *expr1, Expr *expr2) : AssignmentExpr(expr1,expr2) {}
	int getKind() { return SUB_ASSIGN_EXPR; }
	void genCode(codeData &);
};

class LeftAssignmentExpr : public AssignmentExpr
{
public:
	LeftAssignmentExpr(Expr *expr1, Expr *expr2) : AssignmentExpr(expr1,expr2) {}
	int getKind() { return LEFT_ASSIGN_EXPR; }
	void genCode(codeData &);
};

class RightAssignmentExpr : public AssignmentExpr
{
public:
	RightAssignmentExpr(Expr *expr1, Expr *expr2) : AssignmentExpr(expr1,expr2) {}
	int getKind() { return RIGHT_ASSIGN_EXPR; }
	void genCode(codeData &);
};

class AndAssignmentExpr : public AssignmentExpr
{
public:
	AndAssignmentExpr(Expr *expr1, Expr *expr2) : AssignmentExpr(expr1,expr2) {}
	int getKind() { return AND_ASSIGN_EXPR; }
	void genCode(codeData &);
};

class XorAssignmentExpr : public AssignmentExpr
{
public:
	XorAssignmentExpr(Expr *expr1, Expr *expr2) : AssignmentExpr(expr1,expr2) {}
	int getKind() { return XOR_ASSIGN_EXPR; }
	void genCode(codeData &);
};

class OrAssignmentExpr : public AssignmentExpr
{
public:
	OrAssignmentExpr(Expr *expr1, Expr *expr2) : AssignmentExpr(expr1,expr2) {}
	int getKind() { return OR_ASSIGN_EXPR; }
	void genCode(codeData &);
};

#endif