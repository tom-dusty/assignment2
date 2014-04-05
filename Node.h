// Node header file
// Thomas Dusterwald
// 2 April 2014

#ifndef NODE_H_
#define NODE_H_

#include <cstdlib>
#include <string> 
#include <iostream>
#include <sstream>
#include "counter.h" // where is counter.cpp

class Node : public sjp::counter<Node>
{
private:
	int numChildren;
	static int noChildren;
	static int maxChildren;

public:
	Node ** children;
	std::string value;
	//public variables


	//public functions
	Node(int noChildren);
	std::string to_String(sstream strIn);
	int getNoChildren(void);
	int getMaxChildren(void);
	bool setValue(std::string valueIn);
	//six special member fucntions
	Node(void);
	Node(const Node & rhs);
	Node(Node && rhs);
	Node & operator=(const Node & rhs);
	Node & operator=(Node && rhs);
	~Node(void);
};

#endif /* NODE_H_ */