// Compound Node header file
// Thomas Dusterwald
// 14 April 2014

#ifndef COMPOUND_H_
#define COMPOUND_H_

#include "Node.h"

class Compound : public Node
{
public:
	//Constructors
	Compound(int noChildrenIn);
	Compound(void);
	//Clone function used to make a polymorphic copy of this Node type
	Node * clone(void) const;
	//Overridden to_string
	std::string to_string(std::stringstream & strIn);
};

#endif /* COMPOUND_H_ */