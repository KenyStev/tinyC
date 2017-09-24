#include "selection_statement.h"

// genS(If);
void IfStatement::genCode(string &code)
{
    codeData cd;
    cond->genCode(cd);

    string tr, fl;
    trueBlock->genCode(tr);
    falseBlock->genCode(fl);

    string lelse = nextInternalLaber("else");
    string lendif = nextInternalLaber("end_if");

    code = "# IfStatement\n";
    code += cd.code + "\n";
    code += "\tbeqz " + cd.place + ", " + lelse;
    releaseTemp(cd.place);

    code += tr + "\n" + "\nj " + lendif + "\n";
    code += lelse + ":\n";
    code += fl + "\n" + lendif + ": \n";
}