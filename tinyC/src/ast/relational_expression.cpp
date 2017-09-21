#include "relational_expression.h"

#define genRelCode(name,func) void name##Expr::genCode(codeData &data)  \
{   \
    codeData le, re;    \
    expr1->genCode(le); \
    expr2->genCode(re); \
    data.code = le.code + "\n" + re.code + "\n";    \
    releaseTemp(le.place);  \
    releaseTemp(re.place);  \
    data.place = nextTemp();    \
    data.code += "\t" #func " " + data.place + ", " + le.place + ", " + re.place;   \
}

genRelCode(LT,slt);
genRelCode(GT,sgt);
genRelCode(LTE,sle);
genRelCode(GTE,sge);
genRelCode(NE,sne);
genRelCode(EQ,seq);