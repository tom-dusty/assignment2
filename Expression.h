// Node header file
// Thomas Dusterwald
// 2 April 2014

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "Node.h"

class Expression : public Node
{
public:
	Expression(int noChildrenIn);
	Expression(void);
	std::string to_String(std::stringstream & strIn);
	Node * clone(void) const;
};

#endif /* EXPRESSION_H_ */