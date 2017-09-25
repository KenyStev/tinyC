#include "unary_expression.h"

void PreIncExpr::genCode(codeData &data)
{
	string id = ((IdExpr*)expr)->id;
	data.place = nextTemp();
	string place = nextTemp();

	data.code = "\tlw " + place + ", " + id + "\n";
	data.code += "\taddi " + data.place + ", " + data.place + ", 1\n";
	data.code += "\tsw " + data.place + ", " + id + "\n";
	releaseTemp(place);
}

void PreDecExpr::genCode(codeData &data)
{
	string id = ((IdExpr*)expr)->id;
	data.place = nextTemp();
	string place = nextTemp();

	data.code = "\tlw " + place + ", " + id + "\n";
	data.code += "\taddi " + data.place + ", " + data.place + ", -1\n";
	data.code += "\tsw " + data.place + ", " + id + "\n";
	releaseTemp(place);
}

void PositiveNumberExpr::genCode(codeData &data)
{

}

void NegativeNumberExpr::genCode(codeData &data)
{

}

void BitNotExpr::genCode(codeData &data)
{
	string id = ((IdExpr*)expr)->id;
	data.place = nextTemp();

	data.code += "\txori " + data.place + ", 0xffff\n";
}

void LogicNotExpr::genCode(codeData &data)
{

}

void SizeOfExpr::genCode(codeData &data)
{

}

void SizeOfTypeExpr::genCode(codeData &data)
{

}