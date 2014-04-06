// Node class file
// Thomas Dusterwald
// 2 April 2014

#include "Node.h"

//Constructor - takes in number of children 
Node::Node(int noChildrenIn)
{
	numChildren = noChildrenIn;
	if(numChildren > Node::maxChildren)
		maxChildren = numChildren;

	noChildren += numChildren;
	//Dynamically allocate memory for the children nodes
	children = new Node[numChildren];
}

//Default constructor
Node::Node(void) : numChildren(0), value("") {}

//Copy Constructor
Node::Node(const Node & rhs) : value(rhs.value)
{
	rhs.children = new children[numChildren];
	for(int x = 0;x<numChildren;x++)
	{
		Node temp();
		*(rhs.children + x) = Node();
	}
}

