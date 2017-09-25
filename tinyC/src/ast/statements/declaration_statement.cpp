#include "declaration_statement.h"

void Declaration::genCode(string &code)
{
    code = "";
    for(
    DeclaratorList::iterator it = declarators.begin();
    it != declarators.end(); it++)
    {
        string s;
        (*it)->genCode(s);
        code += s;
    }
}

void VariableDeclaration::genCode(string &code)
{
    vars[id] = 0;
    printf("Entro a VariableDeclaration\n");
}

void ArrayDeclaration::genCode(string &code)
{

}

void Parameter::genCode(string &code)
{

}

void FunctionDeclaration::genCode(string &code)
{
    code = "# FunctionDeclaration \n";

    string sb;
    body->genCode(sb);

    code += id + ":\n";

    if (id == "main")
    {
        code += "\tli $a0, BRIGHT_WHITE\n";
        code += "\tli $a1, BLACK\n";
        code += "\tjal set_color\n";
        code += "\tjal clear_screen\n\n";
    }

    code += sb;
    code += "\tjr $ra\n";
}

void ExpressionStatement::genCode(string &code)
{
	code = "# ExpressionStatement\n";
    codeData s;
    expr->genCode(s);
    code += s.code + "\n";
    code += "\tmove $v0, " + s.place;
    place = "$v0";
}

void BlockStatement::genCode(string &code)
{
    code = "";
    list<Statement *>::iterator itd = decList.begin();
    while (itd != decList.end()) {
        Statement *st = *itd;

        string c;
        st->genCode(c);
        code += "\n"+c+"\n";
        itd++;
    }

    list<Statement *>::iterator it = stList.begin();
    // code = "";
    while (it != stList.end()) {
        Statement *st = *it;

        string c;
        st->genCode(c);
        code += "\n"+c+"\n";
        it++;
    }
}