#ifndef _AST_H_
#define _AST_H_

#include <string>
#include <list>
#include <map>
#include "enums.h"

using namespace std;

extern map<string, int> vars;

extern int yylineno;
extern int yycolumn;
extern char* yylexeme;

struct codeData
{
    string code;
    string place;
};

class Token
{
public:
    Token(int r, int c, string l)
    {
        row=r;
        col=c;
        lexeme=l;
    }
    
    int row, col;
    string lexeme;
};

class Expr;
class Statement;

typedef list<Expr*> ExprList;
typedef list<Statement*> StatementList;

void releaseTemp(string tmp);
string nextTemp();
string nextLstringFor(string str);
string nextInternalLaber(string str);

class Expr {
public:
    virtual void genCode(codeData &) = 0;
    virtual int getKind() = 0;
    bool isA(int kind) { return (getKind() == kind); }

    Expr() {
        token = new Token(yylineno, yycolumn, yylexeme);
        // free(yylexeme);
    }

    Token *token;
};

class BinaryExpr: public Expr {
public:
    BinaryExpr(Expr *expr1, Expr *expr2) {
        this->expr1 = expr1;
        this->expr2 = expr2;
    }

    Expr *expr1;
    Expr *expr2;
};

class NumExpr: public Expr {
public:
    NumExpr(int value) { this->value = value; }
    int getKind() { return NUM_EXPR; }
    void genCode(codeData &);

    int value;
};

class IdExpr: public Expr {
public:
    IdExpr(string id) { this->id = id; }
    int getKind() { return ID_EXPR; }
    void genCode(codeData &);

    string id;
};

class StringExpr: public Expr {
public:
    StringExpr(string str) { this->str = str; }
    int getKind() { return STRING_EXPR; }
    void genCode(codeData &);

    string str;
};

class CharExpr: public Expr {
public:
    CharExpr(char str) { this->str = str; }
    int getKind() { return CHAR_EXPR; }
    void genCode(codeData &);

    char str;
};

class CastExpr : public Expr
{
public:
    CastExpr(SemanticValidType typeName, Expr *expr)
    {
        this->typeName = typeName;
        this->expr = expr;
    }
    
    SemanticValidType typeName;
    Expr *expr;
};

class InputExpr: public Expr {
public:
    InputExpr(string prompt) { this->prompt = prompt; }
    int getKind() { return INPUT_EXPR; }
    void genCode(codeData &);

    string prompt;
};

class CallExpr: public Expr {
public:
    CallExpr(BuiltInFunct fnId) { 
        this->fnId = fnId; 
    }
    CallExpr(BuiltInFunct fnId, Expr *arg0, Expr *arg1) { 
        this->fnId = fnId;
        this->arg0 = arg0;
        this->arg1 = arg1;
    }
    int getKind() { return CALL_EXPR; }
    void genCode(codeData &);

    BuiltInFunct fnId;
    Expr *arg0, *arg1;
};

class Statement {
public:
    virtual void genCode(string &) = 0;
    virtual StatementKind getKind() = 0;

    Statement() {
        token = new Token(yylineno, yycolumn, yylexeme);
        // free(yylexeme);
    }

    bool isA(StatementKind t){ return getKind()==t; }

    Token *token;
};

class AssignStatement: public Statement {
public:
    AssignStatement(string id, Expr *expr) {
        this->id = id;
        this->expr = expr;
    }
    void genCode(string &);
    StatementKind getKind() { return ASSIGN_STATEMENT; }

    string id;
    Expr *expr;
};

class PrintStatement: public Statement {
public:
    PrintStatement(ExprList lexpr) {
        this->lexpr = lexpr;
    }
    void genCode(string &);
    StatementKind getKind() { return PRINT_STATEMENT; }

    ExprList lexpr;
};

class CallStatement: public Statement {
public:
    CallStatement(BuiltInFunct fnId, Expr *arg0) {
        this->fnId = fnId;
        this->arg0 = arg0;
        this->arg1 = NULL;
    }
    CallStatement(BuiltInFunct fnId, Expr *arg0, Expr *arg1): CallStatement(fnId, arg0) {
        this->arg1 = arg1;
    }
    void genCode(string &);
    StatementKind getKind() { return CALL_STATEMENT; }

    BuiltInFunct fnId;
    Expr *arg0, *arg1;
};

class CompilationUnit
{
public:
    CompilationUnit()
    {

    }

    void add(Statement*s)
    {
        declarations.push_back(s);
    }
    void genCode(string &);

    StatementList declarations;
};

#endif