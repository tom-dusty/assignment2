// Node header file
// Thomas Dusterwald
// 2 April 2014

#ifndef STATEMENT_H_
#define STATEMENT_H_

#include "Node.h"

class Statement : public Node
{
public:
	Statement(void);
	std::string to_String(std::stringstream & strIn);
	Node * clone(void) const;
};

#endif /* STATEMENT_H_ */