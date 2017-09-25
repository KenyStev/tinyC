#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "ast.h"

using namespace std;

int lstringCount=0, labelsCount=0;

string temps[] = {"$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$t8","$t9"};
map<string, int> tempRegs;
map<string, int> vars;
map<string, string> lstrings;

void releaseTemp(string tmp)
{
    if(tempRegs[tmp]!=0)
    {
        tempRegs[tmp]=0;
    }
}

string nextTemp()
{
    for (int i = 0; i < 10; ++i)
        if (tempRegs.find(temps[i]) == tempRegs.end() || tempRegs[temps[i]] == 0)
        {
            tempRegs[temps[i]] = 1;
            return temps[i];
        }
    return "";
}

string nextLstringFor(string str)
{
    if(lstrings.find(str) == lstrings.end())
    {
        lstrings[str] = "lstring" + to_string(lstringCount++);
    }
    return lstrings[str];
}

string nextInternalLaber(string str)
{
    return string(".l") + str + to_string(labelsCount++);
}

/* Generating Code */

#define gen(name) void name##Expr::genCode(codeData &data){}
#define genS(name) void name##Statement::genCode(string &code){}

void NumExpr::genCode(codeData &data)
{
    data.place = nextTemp();
    data.code = "\tli " + data.place + ", " + to_string(value);
}

void StringExpr::genCode(codeData &data)
{
    data.place = nextTemp();
    data.code = "\tla " + data.place + ", "+nextLstringFor(str);
}

void IdExpr::genCode(codeData &data)
{
    data.place = nextTemp();
    data.code = "\tlw " + data.place + ", " + id;
}

// gen(Input);
void InputExpr::genCode(codeData &data)
{
    data.place = "$v0";
    data.code = "\tla $a0, "+nextLstringFor(prompt)+"\n";
    data.code += "\tjal puts\n\n";
    data.code += ".get_key_loop:\n\tjal keypad_getkey\n\tbeqz $v0, .get_key_loop";
    data.code += "\n\n\tli $a0, '\\n' \n\tjal put_char";
}

// gen(Call);
void CallExpr::genCode(codeData &data)
{
    switch (fnId) {
        case FN_TIMECLOCK: {
            data.place = "$v0";
            data.code = "\tlw $v0, MS_COUNTER_REG_ADDR\n";
            return;
        }
        case FN_RANDINT: {
            data.code += "\tjal rand\n";
            data.place = "$v0";
        }
    }
}

// Statements
void PrintStatement::genCode(string &code)
{
    list<Expr *>::iterator it = lexpr.begin();
    list<Expr *>::iterator str_f = lexpr.begin();
    code = "# PrintStatement\n";

    if (!(*str_f)->isA(STRING_EXPR))
    {
        throw "First Parameter must be string!";
    }

    it++;
    string format = ((StringExpr*)*str_f)->str;
    string buff;
    for (int i = 0; i < format.size(); ++i)
    {
        if (format[i]=='%')
        {
            string ls = nextLstringFor(buff);
            code += "\tla $a0, " + ls + "\n";
            code += "\tjal puts\n\n";
            buff = "";

            i++;
            Expr *expr = *it;
            codeData cd;
            expr->genCode(cd);
            code += cd.code+"\n";
            releaseTemp(cd.place);
            code += "\tmove $a0, " + cd.place+"\n";

            switch(format[i])
            {
                case 's': {
                    code += "\tjal puts\n";
                    break;
                }
                case 'c': {
                    code += "\tjal put_char\n";
                    break;
                }
                default: {
                    code += "\tjal put_udecimal\n";
                    break;
                }
            }
            it++;
        }else{
            buff.push_back(format[i]);
        }
    }
    code += "\n\n\tli $a0, '\\n' \n\tjal put_char";
}

void CallStatement::genCode(string &code)
{
    code = "# CallStatement\n";
    switch (fnId) {
        case FN_RANDSEED: {
            codeData cd;
            arg0->genCode(cd);
            code += cd.code + "\n";
            code += "\tmove $a0, "+cd.place+"\n";
            code += "\tjal rand_seed";
            releaseTemp(cd.place);
        }
        default: {
            
        }
    }
}

void AssignStatement::genCode(string &code)
{
    vars[id] = 0;
    codeData cd;
    expr->genCode(cd);

    code = "# AssignStatement\n";
    code += cd.code+"\n";
    releaseTemp(cd.place);
    code += "\tsw " + cd.place + ", " + id;
}

void CompilationUnit::genCode(string &code)
{
    code = "";
    for (StatementList::iterator it = declarations.begin();
        it != declarations.end(); it++)
    {
        string s = "";
        (*it)->genCode(s);
        code += s;
    }
}

void CharExpr::genCode(codeData &data)
{
    data.place = nextTemp();
    data.code = string("\tli ") + data.place + ", '" + value + "'";
    printf("%s\n", data.code.c_str());
}