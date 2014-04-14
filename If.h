// If Node header file
// Thomas Dusterwald
// 13 April 2014

#ifndef IF_H_
#define IF_H_

#include "Node.h"

class If : public Node
{
public:
	If(void);
	std::string to_string(std::stringstream & strIn);
	//Clone function used to make a polymorphic copy of this Node type
	Node * clone(void) const;
};

#endif /* IF_H_ */