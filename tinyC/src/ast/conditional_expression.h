#ifndef _CONDITIONAL_EXPRESSION_H_
#define _CONDITIONAL_EXPRESSION_H_
#include "ast.h"

class TernaryExpr : public Expr
{
public:
    TernaryExpr(Expr *cond, Expr *trueExpr, Expr *falseExpr)
    {
        this->cond = cond;
        this->trueExpr = trueExpr;
        this->falseExpr = falseExpr;
    }
    int getKind() { return TERNARY_EXPR; }
    void genCode(codeData &);

    Expr *cond, *trueExpr, *falseExpr;
};

class LogicOrExpr : public Expr
{
public:
    LogicOrExpr(Expr *leftExpr, Expr *rightExpr)
    {
        this->leftExpr = leftExpr;
        this->rightExpr = rightExpr;
    }
    int getKind() { return LOGIC_OR_EXPR; }
    void genCode(codeData &);

    Expr *leftExpr, *rightExpr;
};

class LogicAndExpr : public Expr
{
public:
    LogicAndExpr(Expr *leftExpr, Expr *rightExpr)
    {
        this->leftExpr = leftExpr;
        this->rightExpr = rightExpr;
    }
    int getKind() { return LOGIC_AND_EXPR; }
    void genCode(codeData &);

    Expr *leftExpr, *rightExpr;
};

#endif