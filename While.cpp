// While Source File
//Thomas Dusterwald
//13 April 2014

#include "While.h"
#include "Expression.h" //Uses Expression and Compound type nodes
#include "Compound.h"

//Clone function used to make a polymorphic copy of this Node type
Node * While::clone(void) const
{
	return new While(*this);
}

//Default Constructor - always has 2 children
While::While(void) : Node(2)
{
	children[0] = new Expression;
	children[1] = new Compound;
}

//Overridden to_string
std::string While::to_string(std::stringstream& strIn)
{
	strIn << "while ";
	children[0]->to_string(strIn);
	children[1]->to_string(strIn);
	return strIn.str();
}