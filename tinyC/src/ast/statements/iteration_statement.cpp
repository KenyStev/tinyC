#include "iteration_statement.h"

// genS(While);
void WhileStatement::genCode(string &code)
{
    codeData cd;
    cond->genCode(cd);

    string block_code;
    block->genCode(block_code);

    string lwhile = nextInternalLaber("while");
    string lendwhile = nextInternalLaber("end_while");

    code = "# WhileStatement\n";
    code += lwhile + ": \n" + cd.code + "\n";
    code += "\tbeqz " + cd.place + ", " + lendwhile + "\n";
    releaseTemp(cd.place);
    code += block_code + "\n\tj " + lwhile + "\n";
    code += lendwhile + ": \n";
}

// genS(For);
void ForStatement::genCode(string &code)
{
    codeData se, ce, fe;
    startExpr->genCode(se);
    cond->genCode(ce);
    endExpr->genCode(fe);
    string block_code;
    block->genCode(block_code);

    string lfor = nextInternalLaber("for");
    string lendfor = nextInternalLaber("end_for");

    code = "# ForStatement\n";
    code += se.code + "\n";
    code += lfor + ":\n";
    code += ce.code + "\n";
    code += "\tbeqz " + ce.place + ", " + lendfor + "\n";
    code += block_code + "\n";
    code += fe.code + "\n";
    code += "\tj " + lfor + "\n";
    code += lendfor + ": \n";
    releaseTemp(se.place);
    releaseTemp(fe.place);
    releaseTemp(ce.place);
}