#include "declaration_statement.h"

void Declaration::genCode(string &code)
{

}

void VariableDeclaration::genCode(string &code)
{

}

void ArrayDeclaration::genCode(string &code)
{

}

void Parameter::genCode(string &code)
{

}

void FunctionDeclaration::genCode(string &code)
{

}

void ExpressionStatement::genCode(string &code)
{
	
}

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