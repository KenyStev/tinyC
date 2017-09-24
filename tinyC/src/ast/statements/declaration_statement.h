#ifndef _DECLARATION_STATEMENT_H_
#define _DECLARATION_STATEMENT_H_
#include "../ast.h"

class Declarator
{
public:
	Declarator(string id, ParamList params, int size, DeclaratorKind dec)
	{
		this->id = id;
		this->params = params;
		this->size = size;
		this->decType = dec;
	}
	
	string id;
	int size;
	ParamList params;
	DeclaratorKind decType;
};

class VariableDeclaration : public Statement
{
public:
	VariableDeclaration(string id, ExprList exprList, SemanticValidType type)
	{
		this->id = id;
		this->initializer=exprList;
		this->type=type;
	}

	StatementKind getKind() { return VAR_DEC_STATEMENT; }
    void genCode(codeData &);

    string id;
    ExprList initializer;
    SemanticValidType type;
};

class FuncPrototypeDeclaration : public Statement
{
public:
	FuncPrototypeDeclaration(string id, ParamList parameters, SemanticValidType type)
	{
		this->id=id;
		this->parameters=parameters;
		this->returnType=type;
	}
	
	StatementKind getKind() { return FUNC_DEC_STATEMENT; }
    void genCode(codeData &);

    string id;
    ParamList parameters;
    SemanticValidType returnType;
};

class FunctionDeclaration : public Statement
{
public:
	FunctionDeclaration(string id, ParamList parameters, SemanticValidType type, BlockStatement *body)
	{
		this->id=id;
		this->parameters=parameters;
		this->returnType=type;
		this->body=body;
	}
	
	StatementKind getKind() { return FUNC_DEC_STATEMENT; }
    void genCode(codeData &);

    string id;
    ParamList parameters;
    SemanticValidType returnType;
    BlockStatement *body;
};

#endif