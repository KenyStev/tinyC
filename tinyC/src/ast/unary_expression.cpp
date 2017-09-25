#include "unary_expression.h"

void PreIncExpr::genCode(codeData &cd)
{
	string id = ((IdExpr*)expr)->id;
	data.place = nextTemp();
	string place = nextTemp();

	data.code = "\tlw " + place + ", " + id + "\n";
	data.code += "\taddi " + data.place + ", " + data.place + ", 1\n";
	data.code += "\tsw " + data.place + ", " + id + "\n";
	releaseTemp(place);
}

void PreDecExpr::genCode(codeData &cd)
{
	string id = ((IdExpr*)expr)->id;
	data.place = nextTemp();
	string place = nextTemp();

	data.code = "\tlw " + place + ", " + id + "\n";
	data.code += "\taddi " + data.place + ", " + data.place + ", -1\n";
	data.code += "\tsw " + data.place + ", " + id + "\n";
	releaseTemp(place);
}

void PositiveNumberExpr::genCode(codeData &cd)
{

}

void NegativeNumberExpr::genCode(codeData &cd)
{

}

void BitNotExpr::genCode(codeData &cd)
{
	string id = ((IdExpr*)expr)->id;
	data.place = nextTemp();

	data.code += "\txori " + data.place + ", 0xffff\n";
	releaseTemp(place);
}

void LogicNotExpr::genCode(codeData &cd)
{

}

void SizeOfExpr::genCode(codeData &cd)
{

}

void SizeOfTypeExpr::genCode(codeData &cd)
{

}