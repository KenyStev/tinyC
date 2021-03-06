#ifndef _ITERATION_STATEMENT_H_
#define _ITERATION_STATEMENT_H_
#include "../ast.h"

class WhileStatement: public Statement {
public:
    WhileStatement(Expr *cond, Statement *block) {
        this->cond = cond;
        this->block = block;
    }
    void genCode(string &);
    StatementKind getKind() { return WHILE_STATEMENT; }

    Expr *cond;
    Statement *block;
};

class ForStatement: public Statement {
public:
    ForStatement(Expr *startExpr,Expr *cond, Expr *endExpr, Statement *block) {
        this->cond = cond;
        this->startExpr = startExpr;
        this->endExpr = endExpr;
        this->block = block;
    }
    void genCode(string &);
    StatementKind getKind() { return FOR_STATEMENT; }

    Expr *cond;
    Expr *startExpr;
    Expr *endExpr;
    Statement *block;
};

#endif