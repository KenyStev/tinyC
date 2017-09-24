#ifndef _POSTFIX_EXPRESSION_H
#define _POSTFIX_EXPRESSION_H
#include "ast.h"

class ArrayAccessExpr
{
public:
	ArrayAccessExpr(string id, ExprList exprList)
	{
		expressions = exprList;
	}

	string id;
	ExprList expressions;
};

#endif