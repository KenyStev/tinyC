#include "bits_expression.h"

void ShiftLeftExpr::genCode(codeData &data)
{
	codeData le, re;
	expr1->genCode(le);
	expr2->genCode(re);
	releaseTemp(le.place);
	releaseTemp(re.place);
	data.place = nextTemp();

	data.code = "sll " + data.place + ", " + le.place + ", " + re.place + "\n";
}

void ShiftRightExpr::genCode(codeData &data)
{
	codeData le, re;
	expr1->genCode(le);
	expr2->genCode(re);
	releaseTemp(le.place);
	releaseTemp(re.place);
	data.place = nextTemp();

	data.code = "srl " + data.place + ", " + le.place + ", " + re.place + "\n";
}

void BitAndExpr::genCode(codeData &data)
{
	codeData le, re;
	expr1->genCode(le);
	expr2->genCode(re);
	releaseTemp(le.place);
	releaseTemp(re.place);
	data.place = nextTemp();

	data.code = "and " + data.place + ", " + le.place + ", " + re.place + "\n";
}

void XorExpr::genCode(codeData &data)
{
	codeData le, re;
	expr1->genCode(le);
	expr2->genCode(re);
	releaseTemp(le.place);
	releaseTemp(re.place);
	data.place = nextTemp();

	data.code = "xor " + data.place + ", " + le.place + ", " + re.place + "\n";
}

void BitOrExpr::genCode(codeData &data)
{
	codeData le, re;
	expr1->genCode(le);
	expr2->genCode(re);
	releaseTemp(le.place);
	releaseTemp(re.place);
	data.place = nextTemp();

	data.code = "or " + data.place + ", " + le.place + ", " + re.place + "\n";
}

void AndExpr::genCode(codeData &data)
{
	
}

void OrExpr::genCode(codeData &data)
{
	
}