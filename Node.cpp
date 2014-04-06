// Node class file
// Thomas Dusterwald
// 2 April 2014

#include "Node.h"

std::string Node::to_string(std::stringstream strIn)
{
	if(numChildren == 0)
	{
		strIn << value;
	}
	return "";
}

//Constructor - takes in number of children 
Node::Node(int noChildrenIn)
{
	if(noChildrenIn == 0){children = nullptr;}
	else
	{
		numChildren = noChildrenIn;
		if(numChildren > Node::maxChildren)
			maxChildren = numChildren;

		noChildren += numChildren;
		//Dynamically allocate memory for the children nodes
		children = new Node*[numChildren];
	}

}

//Default constructor
Node::Node(void) : numChildren(0), value("") {}

//Copy Constructor
Node::Node(const Node & rhs) : value(rhs.value) numChildren(rhs.numChildren)
{
	children = new Node[rhs.numChildren];
	noChildren += numChildren;
	for(int x = 0;x<rhs.numChildren;x++)
	{
		Node temp();
		*(children[x]) = **(rhs.children + x);
	}
}

//Copy Assignment operator
Node::Node & operator=(const Node & rhs)
{
	if(this!=&rhs)
	{
		numChildren = rhs.numChildren;
		value = rhs.value;
		if(children != nullptr){delete[] children;}
		children = new Node[rhs.numChildren];
		for(int x = 0;x<rhs.numChildren;x++)
		{	
			Node temp();
			*(children[x]) = **(rhs.children + x);
		}
	}
	return *this;
}

//Move constructor
Node::Node(Node && rhs) : value(rhs.value) numChildren(rhs.numChildren)
{
	children = rhs.children;
	rhs.children = nullptr;
}

//Move assignment operator
Node::Node & operator=(Node && rhs) 
{
	if(this != &rhs)
	{
		numChildren = rhs.numChildren;
		value = rhs.value;
		if(children != nullptr){delete[] children;}
		children = rhs.children;
		rhs.children = nullptr;
	}
	return *this;
}

//Destructor
Node::~Node(void)
{
	if(children != nullptr)
	{
		delete[] children;
		children = nullptr;
	}
}

