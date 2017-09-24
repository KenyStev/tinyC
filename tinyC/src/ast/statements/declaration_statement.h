#ifndef _DECLARATION_STATEMENT_H_
#define _DECLARATION_STATEMENT_H_
#include "../ast.h"

class ExternalDeclaration : public Statement
{
public:
	ExternalDeclaration()
	{

	}

	StatementKind getKind() { return EXTERNAL_STATEMENT; }
	
	SemanticValidType type;
};

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

class VariableDeclaration : public ExternalDeclaration
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
};

class ArrayDeclaration : public ExternalDeclaration
{
public:
	ArrayDeclaration(string id, int size, SemanticValidType type)
	{
		this->id = id;
		this->size=size;
		this->type=type;
	}

	StatementKind getKind() { return ARRAY_DEC_STATEMENT; }
    void genCode(codeData &);

    string id;
    int size;
};

class Parameter
{
public:
	Parameter(string id, SemanticValidType type)
	{
		this->id = id;
		this->type=type;
	}

    void genCode(codeData &);

	string id;
    SemanticValidType type;
};

class BlockStatement: public Statement {
public:
    BlockStatement() {}
    void genCode(string &);
    StatementKind getKind() { return BLOCK_STATEMENT; }
	void add(Statement *st) { stList.push_back(st); }

    list<Statement *> stList;
};

class FunctionDeclaration : public ExternalDeclaration
{
public:
	FunctionDeclaration(string id, ParamList parameters, SemanticValidType type, BlockStatement *body)
	{
		this->id=id;
		this->parameters=parameters;
		this->type=type;
		this->body=body;
	}
	
	StatementKind getKind() { return FUNC_DEC_STATEMENT; }
    void genCode(codeData &);

    string id;
    ParamList parameters;
    BlockStatement *body;
};

#endif