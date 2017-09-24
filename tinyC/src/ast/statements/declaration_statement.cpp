#include "declaration_statement.h"

// genS(Block);
void BlockStatement::genCode(string &code)
{
    list<Statement *>::iterator it = stList.begin();
    code = "";
    while (it != stList.end()) {
        Statement *st = *it;

        string c;
        st->genCode(c);
        code += "\n"+c+"\n";
        it++;
    }
}