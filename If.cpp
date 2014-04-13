#include "If.h"
#include "Expression.h"
#include "Compound.h"

Node * If::clone(void) const
{
	return new If(*this);
}

If::If(void) : Node(4)
{
	children[0] = new Expression;
	children[1] = new Compound;
	children[2]->value = "else";
	children[3] = new Compound;
}

std::string If::to_String(std::stringstream& strIn)
{
	strIn << "if ";
	children[0]->to_String(strIn);
	children[1]->to_String(strIn);
	children[2]->to_String(strIn);
	children[3]->to_String(strIn);
	return strIn.str();
}