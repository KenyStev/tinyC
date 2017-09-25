#ifndef _DECLARATION_STATEMENT_H_
#define _DECLARATION_STATEMENT_H_
#include "../ast.h"

class Parameter;
class Declarator;
class Declaration;

typedef list<Parameter*> ParamList;
typedef list<Declarator*> DeclaratorList;
typedef list<Declaration*> DeclarationList;

class ExternalDeclaration : public Statement
{
public:
	ExternalDeclaration()
	{

	}

	StatementKind getKind() { return EXTERNAL_STATEMENT; }
};

class Declarator : public ExternalDeclaration
{
public:
	Declarator(string id)
	{
		this->id = id;
	}

	void setType(SemanticValidType type)
	{
		this->type=type;
	}

	string id;
	SemanticValidType type;
};

class Declaration : public ExternalDeclaration
{
public:
	Declaration(SemanticValidType type, DeclaratorList declarators)
	{
		this->declarators = declarators;
		DeclaratorList::iterator it = this->declarators.begin();

  		while (it != this->declarators.end()) {
  			(*it)->setType(type);
  			it++;
  		}
	}
	void genCode(string &);
	DeclaratorList declarators;
};

class VariableDeclaration : public Declarator
{
public:
	VariableDeclaration(string id) : Declarator(id)
	{
		this->initializer=NULL;
	}

	StatementKind getKind() { return VAR_DEC_STATEMENT; }
    void genCode(string &);

    Expr *initializer;
};

class ArrayDeclaration : public Declarator
{
public:
	ArrayDeclaration(string id, int size) : Declarator(id)
	{
		this->size=size;
	}

	StatementKind getKind() { return ARRAY_DEC_STATEMENT; }
    void genCode(string &);

    int size;
};

class Parameter 
{
public:
	Parameter(SemanticValidType type, Declarator *dec)
	{
		this->declarator = dec;
		this->declarator->setType(type);
	}

	Parameter(SemanticValidType type) 
	{
		declarator=NULL;
	}

    void genCode(string &);
    Declarator *declarator;
};

class BlockStatement: public Statement {
public:
    BlockStatement() {}
    
    BlockStatement(StatementList d, StatementList s) {
    	stList = s;
    	decList = d;
    }
    void setStmtList(StatementList s) {
    	stList = s;
    }
    void setDecList(StatementList d) {
    	decList = d;
    }
    void genCode(string &);
    StatementKind getKind() { return BLOCK_STATEMENT; }
	void add(Statement *st) { stList.push_back(st); }

    list<Statement *> stList;
    list<Statement *> decList;
};

class FunctionDeclaration : public Declarator
{
public:
	FunctionDeclaration(string id, ParamList *parameters, BlockStatement *body) : Declarator(id)
	{
		this->parameters=parameters;
		this->body=body;
	}
	
	StatementKind getKind() { return FUNC_DEC_STATEMENT; }
    void genCode(string &);

    ParamList *parameters;
    BlockStatement *body;
};

class ExpressionStatement : public Statement
{
public:
	ExpressionStatement(Expr *expr)
	{
		this->expr=expr;
	}

	StatementKind getKind() { return EXPRESSION_STATEMENT; }
	void genCode(string &code);
	
	Expr *expr;
};

#endif