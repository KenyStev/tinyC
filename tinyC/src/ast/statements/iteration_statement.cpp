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
    vars[id] = 0;
    codeData se,fe;
    startExpr->genCode(se);
    endExpr->genCode(fe);

    string block_code;
    block->genCode(block_code);

    string lfor = nextInternalLaber("for");
    string lendfor = nextInternalLaber("end_for");
    string branch = nextTemp();

    code = "# ForStatement\n";
    code += se.code + "\n";
    code += "\tsw " + se.place + ", " + id + "\n";
    code += fe.code + "\n";
    
    code += "\taddi $sp, $sp, -4\n";
    code += "\tsw " + fe.place + ", ($sp)\n";
    code += lfor + ": \n";
    code += "\tlw " + fe.place + ", ($sp)\n";
    code += "\tsle " + branch + ", " + se.place + ", " + fe.place + "\n";
    code += "\tbeqz " + branch + ", " + lendfor + "\n";
    code += block_code + "\n";
    code += "\tlw " + se.place + ", " + id + "\n";
    code += "\taddi " + se.place + ", "+se.place + ", 1\n";
    code += "\tsw " + se.place + ", " + id+"\n";
    code += "\tj " + lfor + "\n";
    code += lendfor + ": \n";
    code += "\taddi $sp, $sp, 4";
    releaseTemp(se.place);
    releaseTemp(fe.place);
    releaseTemp(branch);
}