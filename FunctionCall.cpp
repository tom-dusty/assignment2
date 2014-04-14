//FunctionCall Node Source File
//Thomas Dusterwald
//13 April 2014

#include "FunctionCall.h"

//Clone function used to make a polymorphic copy of this Node type
Node * FunctionCall::clone(void) const
{
	return new FunctionCall(*this);
}

//Default Constructor - has 1 child, the name of the function
FunctionCall::FunctionCall(void) : Node(1)
{
}

//Constructor - takes in no of children as number of arguments and the name of the function
FunctionCall::FunctionCall(int noChildrenIn, std::string name) : Node(1+noChildrenIn)
{
	if(noChildrenIn<1)
	{
		numChildren = 1;
		noChildrenIn = 1;
	}
	children[0]->value = name;
}

//Overridden to_string
std::string FunctionCall::to_string(std::stringstream& strIn)
{
	for(int x = 0;x<numChildren;x++)
	{
		children[x]->to_string(strIn);
		strIn << " ";
	}
	strIn << "\n";
	return strIn.str();
}