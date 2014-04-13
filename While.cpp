#include "While.h"
#include "Expression.h"
#include "Compound.h"

Node * While::clone(void) const
{
	return new While(*this);
}

While::While(void) : Node(2)
{
	children[0] = new Expression;
	children[1] = new Compound;
}

std::string While::to_String(std::stringstream& strIn)
{
	strIn << "while ";
	children[0]->to_String(strIn);
	children[1]->to_String(strIn);
	return strIn.str();
}