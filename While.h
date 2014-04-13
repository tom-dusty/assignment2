// While Node header file
// Thomas Dusterwald
// 2 April 2014

#ifndef WHILE_H_
#define WHILE_H_

#include "Node.h"

class While : public Node
{
public:
	While(void);
	std::string to_String(std::stringstream & strIn);
	Node * clone(void) const;
};

#endif /* WHILE_H_ */