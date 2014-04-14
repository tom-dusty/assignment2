//Expression Source File
//Thomas Dusterwald
//13 April 2014

#include "If.h"
#include "Expression.h" //Uses Expression and Compound Nodes
#include "Compound.h"

//Clone function used to make a polymorphic copy of this Node type
Node * If::clone(void) const
{
	return new If(*this);
}

//Default constructor - and if statement always has 4 children
If::If(void) : Node(4)
{
	children[0] = new Expression;
	children[1] = new Compound;
	children[2]->value = "else";
	children[3] = new Compound;
}

//Overridden to_string
std::string If::to_string(std::stringstream& strIn)
{
	strIn << "if ";
	children[0]->to_string(strIn);
	children[1]->to_string(strIn);
	children[2]->to_string(strIn);
	children[3]->to_string(strIn);
	return strIn.str();
}