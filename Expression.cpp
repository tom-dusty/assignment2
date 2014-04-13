#include "Expression.h"


Node * Expression::clone(void) const
{
	return new Expression(*this);
}

Expression::Expression(int noChildrenIn) : Node(noChildrenIn)
{
}

Expression::Expression() : Node()
{
}

std::string Expression::to_String(std::stringstream& strIn)
{
	for(int x = 0;x<numChildren && x<3;x++)
	{
		children[x]->to_String(strIn);
	}
	return strIn.str();
}