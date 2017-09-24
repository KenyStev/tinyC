#ifndef _JUMP_STATEMENT_H_
#define _JUMP_STATEMENT_H_
#include "../ast.h"

class ReturnStatement : public Statement
{
public:
	ReturnStatement(Expr *expr)
	{
		this->expr = expr;
	}
	
	void genCode(string &);
    StatementKind getKind() { return RETURN_STATEMENT; }
	Expr *expr;
};

#endif