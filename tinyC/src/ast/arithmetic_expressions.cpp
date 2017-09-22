#include "arithmetic_expressions.h"

#define genAdditiveCode(name,func) void name##Expr::genCode(codeData &data) \
{   \
    codeData re, le;    \
    expr1->genCode(le); \
    expr2->genCode(re); \
    data.code = le.code + "\n" + re.code + "\n";    \
    releaseTemp(le.place);  \
    releaseTemp(re.place);  \
    data.place = nextTemp();    \
    data.code += "\t" #func " " + data.place + ", " + le.place + ", " + re.place;   \
}
#define genDivCode(name,reg) void name##Expr::genCode(codeData &data) \
{  \
    codeData re, le;  \
    expr1->genCode(le); \
    expr2->genCode(re); \
    data.code = le.code + "\n" + re.code + "\n";  \
    releaseTemp(le.place);  \
    releaseTemp(re.place);  \
    data.place = nextTemp();    \
    data.code += "\tmove $a0, " + le.place + "\n";    \
    data.code += "\tmove $a1, " + re.place + "\n";    \
    data.code += "\taddi $sp, -8\n";  \
    data.code += "\tmove $a2, $sp\n"; \
    data.code += "\taddi $a3, $sp, 4\n";  \
    data.code += "\tjal divide\n" ;   \
    data.code += "\tlw " + data.place + ", ($" #reg ")\n";  \
    data.code += "\taddi $sp, $sp, 8";    \
}

genAdditiveCode(Add,add);
genAdditiveCode(Sub,sub);

void MultExpr::genCode(codeData &data)
{  
    codeData re, le;  
    expr1->genCode(le);
    expr2->genCode(re);
    data.code = le.code + "\n" + re.code + "\n";  
    releaseTemp(le.place);
    releaseTemp(re.place); 
    data.place = nextTemp();

    data.code += "\tmove $a0, " + le.place + "\n";
    data.code += "\tmove $a1, " + re.place + "\n";
    data.code += "\tjal mult\n" ; 
    data.code += "\tmove " + data.place + ", $v0";
}

genDivCode(Div,a2);
genDivCode(Mod,a3);

void ExponentExpr::genCode(codeData &data)
{
    codeData re, le;  
    expr1->genCode(le);
    expr2->genCode(re);
    data.code = le.code + "\n" + re.code + "\n";  
    releaseTemp(le.place);
    releaseTemp(re.place); 
    data.place = nextTemp();

    data.code += "\tmove $a0, " + le.place + "\n";
    data.code += "\tmove $a1, " + re.place + "\n";
    data.code += "\tjal exponent\n"; 
    data.code += "\tmove " + data.place + ", $v0";
}