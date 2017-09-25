#include "postfix_expression.h"

void ArrayAccessExpr::genCode(codeData &data)
{

}

void CallFunctionExpr::genCode(codeData &data)
{

}

void PostIncExpr::genCode(codeData &data)
{
	string id = ((IdExpr*)expr)->id;
	data.place = nextTemp();
	string place = nextTemp();

	data.code = "\tlw " + data.place + ", " + id + "\n";
	data.code += "\taddi " + place + ", " + data.place + ", 1\n";
	data.code += "\tsw " + place + ", " + id + "\n";
	releaseTemp(place);
}

void PostDecExpr::genCode(codeData &data)
{
	string id = ((IdExpr*)expr)->id;
	data.place = nextTemp();
	string place = nextTemp();

	data.code = "\tlw " + data.place + ", " + id + "\n";
	data.code = "\taddi " + place + ", " + data.place + ", -1\n";
	data.code = "\tsw " + place + ", " + id + "\n";
	releaseTemp(place);
}
