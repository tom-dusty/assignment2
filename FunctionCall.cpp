#include "FunctionCall.h"

Node * FunctionCall::clone(void) const
{
	return new FunctionCall(*this);
}

FunctionCall::FunctionCall(void) : Node(1)
{
}

FunctionCall::FunctionCall(int noChildrenIn, std::string name) : Node(1+noChildrenIn)
{
	if(noChildrenIn<1)
	{
		numChildren = 1;
		noChildrenIn = 1;
	}
	children[0]->value = name;
}

std::string FunctionCall::to_String(std::stringstream& strIn)
{
	for(int x = 0;x<numChildren;x++)
	{
		children[x]->to_String(strIn);
		strIn << " ";
	}
	strIn << "\n";
	return strIn.str();
}