//Compound Node Source File
//Thomas Dusterwald
//13 April 2014

#include "Compound.h"

//Clone function used to make a polymorphic copy of this Node type
Node * Compound::clone(void) const
{
	return new Compound(*this);
}

//Constructor - has noChildrenIn + 2 children (for the brackets)
Compound::Compound(int noChildrenIn) : Node(noChildrenIn+2)
{
	children[0]->value = "{";
	children[numChildren-1]->value = "}";
	numUsed++;
}

//Default Constructor - min number of nodes is 2
Compound::Compound(void) : Node(2)
{
	children[0]->value = "{";
	children[numChildren-1]->value = "}";
	numUsed++;
}

//Overridden to_string
std::string Compound::to_string(std::stringstream& strIn)
{
	children[0]->to_string(strIn);
	strIn << "\n";
	for(int x = 1;x<numChildren-1;x++)
	{
		strIn << "  ";
		children[x]->to_string(strIn);
	}
	children[numChildren-1]->to_string(strIn);
	strIn << "\n";
	return strIn.str();
}
