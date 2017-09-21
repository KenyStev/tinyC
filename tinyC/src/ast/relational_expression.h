#ifndef _RELATIONAL_EXPRESSION_H_
#define _RELATIONAL_EXPRESSION_H_

#include "ast.h"

extern void releaseTemp(string tmp);
extern string nextTemp();
extern string nextLstringFor(string str);
extern string nextInternalLaber(string str);

class LTExpr: public BinaryExpr {
public:
    LTExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}

    int getKind() { return LT_EXPR; }
    void genCode(codeData &);
};

class GTExpr: public BinaryExpr {
public:
    GTExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}

    int getKind() { return GT_EXPR; }
    void genCode(codeData &);
};

class LTEExpr: public BinaryExpr {
public:
    LTEExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}

    int getKind() { return LTE_EXPR; }
    void genCode(codeData &);
};

class GTEExpr: public BinaryExpr {
public:
    GTEExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}

    int getKind() { return GTE_EXPR; }
    void genCode(codeData &);
};

class NEExpr: public BinaryExpr {
public:
    NEExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}

    int getKind() { return NE_EXPR; }
    void genCode(codeData &);
};

class EQExpr: public BinaryExpr {
public:
    EQExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}

    int getKind() { return NE_EXPR; }
    void genCode(codeData &);
};

#endif