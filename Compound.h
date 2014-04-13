// Compound Node header file
// Thomas Dusterwald
// 2 April 2014

#ifndef COMPOUND_H_
#define COMPOUND_H_

#include "Node.h"

class Compound : public Node
{
public:
	Compound(int noChildrenIn);
	Compound(void);
	Node * clone(void) const;
	std::string to_String(std::stringstream & strIn);
};

#endif /* COMPOUND_H_ */