//Expression Node source File
//Thomas Dusterwald
//13 April 2014

#include "Expression.h"

//Clone function used to make a polymorphic copy of this Node type
Node * Expression::clone(void) const
{
	return new Expression(*this);
}

//Constructor
Expression::Expression(int noChildrenIn) : Node(noChildrenIn)
{
}

//Default constructor
Expression::Expression() : Node()
{
}

//Overloaded to_string method
std::string Expression::to_string(std::stringstream& strIn)
{
	for(int x = 0;x<numChildren && x<3;x++)
	{
		children[x]->to_string(strIn);
	}
	return strIn.str();
}