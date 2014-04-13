// Node header file
// Thomas Dusterwald
// 2 April 2014

#ifndef NODE_H_
#define NODE_H_

#include <cstdlib>
#include <string> 
#include <sstream>
#include "counter.h" // where is counter.cpp

class Node : public sjp::counter<Node>
{
public:
	Node ** children;
	std::string value;
	int numChildren;
	int numUsed;
	static int noChildren;
	static int maxChildren;
	//public variables

	void destroy(void);

	//public functions
	Node(int noChildren);
	virtual std::string to_String(std::stringstream & strIn);
	//six special member functions
	Node(void);
	Node(const Node & rhs);
	Node(Node && rhs);
	virtual Node* clone() const;
	Node & operator=(const Node & rhs);
	Node & operator=(Node && rhs);
	virtual ~Node(void);
	
};

#endif /* NODE_H_ */