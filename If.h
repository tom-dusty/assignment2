// If Node header file
// Thomas Dusterwald
// 2 April 2014

#ifndef IF_H_
#define IF_H_

#include "Node.h"

class If : public Node
{
public:
	If(void);
	std::string to_String(std::stringstream & strIn);
	Node * clone(void) const;
};

#endif /* IF_H_ */