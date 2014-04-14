//Statement Node Source File
//Thomas Dusterwald
//14 April 2014

#include "Statement.h"
#include "Expression.h"

//Clone function used to make a polymorphic copy of this Node type
Node * Statement::clone(void) const
{
	return new Statement(*this);
}

//Default constructor - must have 3 children
Statement::Statement(void) : Node(3)
{
}

//Overloaded to_string
std::string Statement::to_string(std::stringstream& strIn)
{
	children[0]->to_string(strIn);
	strIn << " ";
	children[1]->to_string(strIn);
	strIn << " ";
	children[2]->to_string(strIn);
	strIn << "\n";
	return strIn.str();
}