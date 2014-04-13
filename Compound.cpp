#include "Compound.h"

Node * Compound::clone(void) const
{
	std::cout << "working!" <<std::endl;
	return new Compound(*this);
}

Compound::Compound(int noChildrenIn) : Node(noChildrenIn+2)
{
	children[0]->value = "{";
	children[numChildren-1]->value = "}";
	numUsed++;
}

Compound::Compound(void) : Node(2)
{
	children[0]->value = "{";
	children[numChildren-1]->value = "}";
	numUsed++;
}

std::string Compound::to_String(std::stringstream& strIn)
{
	children[0]->to_String(strIn);
	strIn << "\n";
	for(int x = 1;x<numChildren-1;x++)
	{
		strIn << "  ";
		children[x]->to_String(strIn);
	}
	strIn <<  "\n";
	children[numChildren-1]->to_String(strIn);
	strIn << "\n";
	return strIn.str();
}
