// FunctionCall Node header file
// Thomas Dusterwald
// 2 April 2014

#ifndef FUNCTIONCALL_H_
#define FUNCTIONCALL_H_

#include "Node.h"

class FunctionCall : public Node
{
public:
	FunctionCall(void);
	FunctionCall(int noChildrenIn, std::string name);
	std::string to_String(std::stringstream & strIn);
	Node * clone(void) const;
};

#endif /* FUNCTIONCALL_H_ */