#include "assignment_expression.h"

void AssignmentExpr::genCode(codeData &data)
{
	data.place = nextTemp();
	if (expr1->isA(ID_EXPR))
	{
		codeData cd;
		expr2->genCode(cd);
		releaseTemp(cd.place);
		data.code = "# AssignmentExpr\n";
		data.code += cd.code + "\n";
		data.code += "\tsw "+cd.place + ", "+ ((IdExpr*)expr1)->id ;
	}
}

void MultAssignmentExpr::genCode(codeData &data)
{
	
}

void DivAssignmentExpr::genCode(codeData &data)
{
	
}

void ModAssignmentExpr::genCode(codeData &data)
{
	
}

void AddAssignmentExpr::genCode(codeData &data)
{
	
}

void SubAssignmentExpr::genCode(codeData &data)
{
	
}

void LeftAssignmentExpr::genCode(codeData &data)
{
	
}

void RightAssignmentExpr::genCode(codeData &data)
{
	
}

void AndAssignmentExpr::genCode(codeData &data)
{
	
}

void XorAssignmentExpr::genCode(codeData &data)
{
	
}

void OrAssignmentExpr::genCode(codeData &data)
{
	
}