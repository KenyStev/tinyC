#ifndef _ARITHMETIC_EXPRESSION_H_
#define _ARITHMETIC_EXPRESSION_H_

#include "ast.h"

void releaseTemp(string tmp);
string nextTemp();
string nextLstringFor(string str);
string nextInternalLaber(string str);

class AddExpr: public BinaryExpr {
public:
    AddExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}

    int getKind() { return ADD_EXPR; }
    void genCode(codeData &);
};

class SubExpr: public BinaryExpr {
public:
    SubExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}

    int getKind() { return SUB_EXPR; }
    void genCode(codeData &);
};

class MultExpr: public BinaryExpr {
public:
    MultExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}

    int getKind() { return MULT_EXPR; }
    void genCode(codeData &);
};

class DivExpr: public BinaryExpr {
public:
    DivExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}

    int getKind() { return DIV_EXPR; }
    void genCode(codeData &);
};

class ModExpr: public BinaryExpr {
public:
    ModExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}

    int getKind() { return EXPT_EXPR; }
    void genCode(codeData &);
};

class ExponentExpr: public BinaryExpr {
public:
    ExponentExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}

    int getKind() { return MOD_EXPR; }
    void genCode(codeData &);
};

#endif