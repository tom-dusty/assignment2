// While Node header file
// Thomas Dusterwald
// 13 April 2014

#ifndef WHILE_H_
#define WHILE_H_

#include "Node.h"

class While : public Node
{
public:
	//Constructor
	While(void);
	//Overridden to_string
	std::string to_string(std::stringstream & strIn);
	//Clone function used to make a polymorphic copy of this Node type
	Node * clone(void) const;
};

#endif /* WHILE_H_ */