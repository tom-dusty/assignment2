// Node header file
// Thomas Dusterwald
// 13 April 2014

#ifndef STATEMENT_H_
#define STATEMENT_H_

#include "Node.h"

class Statement : public Node
{
public:
	//Constructor
	Statement(void);
	//Overloaded to_string method
	std::string to_string(std::stringstream & strIn);
	//Clone function used to make a polymorphic copy of this Node type
	Node * clone(void) const;
};

#endif /* STATEMENT_H_ */