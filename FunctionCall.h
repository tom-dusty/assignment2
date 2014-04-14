// FunctionCall Node header file
// Thomas Dusterwald
// 13 April 2014

#ifndef FUNCTIONCALL_H_
#define FUNCTIONCALL_H_

#include "Node.h"

class FunctionCall : public Node
{
public:
	//Constructors
	FunctionCall(void);
	FunctionCall(int noChildrenIn, std::string name);
	//Overwritten to_string method
	std::string to_string(std::stringstream & strIn);
	//Clone function used to make a polymorphic copy of this Node type
	Node * clone(void) const;
};

#endif /* FUNCTIONCALL_H_ */