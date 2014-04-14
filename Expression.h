// Node header file
// Thomas Dusterwald
// 13 April 2014

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "Node.h"

class Expression : public Node
{
public:
	//Constructors
	Expression(int noChildrenIn);
	Expression(void);
	//Overloaded to_string method
	std::string to_string(std::stringstream & strIn);
	//Clone function used to make a polymorphic copy of this Node type
	Node * clone(void) const;
};

#endif /* EXPRESSION_H_ */