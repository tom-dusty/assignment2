// Node class file
// Thomas Dusterwald
// 2 April 2014

#include "Node.h"

int Node::maxChildren = 0;
int Node::noChildren = 0;
//To string method prints the value of the node if it has 0 children. (ie leaf node)
std::string Node::to_string(std::stringstream& strIn)
{
	if(numChildren == 0)
	{
		strIn << value;
		return value;
	}
	return "";
}

//Constructor - takes in number of children 
Node::Node(int noChildrenIn)
{
	if(noChildrenIn == 0){children = nullptr;numChildren = 0;value="";numUsed=0;}
	else
	{
		numChildren = noChildrenIn;
		if(numChildren > maxChildren)
			maxChildren = numChildren;

		noChildren += numChildren;
		numUsed = 0;
		//Dynamically allocate memory for the children nodes
		children = new Node*[numChildren];
		for(int x = 0;x<numChildren;x++)
		{
			Node temp(0);
			children[x] = new Node;
			*(children[x]) = temp;
		}
	}

}

//Default constructor
Node::Node(void) : numChildren(0), numUsed(0), value(""), children(nullptr) {}

//Copy Constructor
Node::Node(const Node & rhs) : value(rhs.value), numChildren(rhs.numChildren), numUsed(rhs.numUsed)
{
	children = new Node*[numChildren];
	noChildren+=numChildren;
	for(int x = 0;x<rhs.numChildren;x++)
	{
		children[x] = new Node;
		*(children[x]) = *(rhs.children[x]);
	}
}

//Copy Assignment operator
Node & Node::operator=(const Node & rhs)
{
	if(this!=&rhs)
	{
		noChildren+=numChildren;
		numUsed = rhs.numUsed;
		value = rhs.value;
		if(children != nullptr)
		{
			for(int x = 0;x<numChildren;x++)
			{
				delete children[x];
				children[x] = nullptr;
			}
			delete[] children;
		}
		numChildren = rhs.numChildren;
		children = new Node*[numChildren];
		for(int x = 0;x<numChildren;x++)
		{	
			children[x] = new Node;
			*(children[x]) = *(rhs.children[x]);
		}
	}
	return *this;
}

//Move constructor
Node::Node(Node && rhs) : value(std::move(rhs.value)), numChildren(std::move(rhs.numChildren)), numUsed(std::move(rhs.numUsed))
{
	noChildren+=numChildren;
	children = rhs.children;
}

//Clone function
Node *Node::clone(void) const
{
	return new Node(*this);
}

//Move assignment operator
Node & Node::operator=(Node && rhs) 
{
	if(this != &rhs)
	{
		numChildren = std::move(rhs.numChildren);
		noChildren+=numChildren;
		numUsed = std::move(rhs.numUsed);
		value = std::move(rhs.value);
		if(children != nullptr)
		{
			for(int x = 0;x<numChildren;x++)
			{
				children[x]->~Node();
			}
			delete[] children;
		}
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
		noChildren -= numChildren;
		for(int x = 0;x<numChildren;x++)
		{
			delete children[x];
			children[x] = nullptr;
		}
		if(numChildren != 0)
		{
			delete[] children;
			children = nullptr;
			numChildren = 0;
		}
	}

	
}