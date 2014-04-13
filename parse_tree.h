// parse_tree header file
// Thomas Dusterwald
// 2 April 2014

#ifndef PARSETREE_H_
#define PARSETREE_H_

#include <cstdlib>
#include <string> 
#include <iostream>
#include <sstream>
#include "tree_iterator.h"
#include "Node.h"

class parse_tree
{
private:
	Node * root;
public:
	//six special member functions
	parse_tree(void): root(nullptr){};
	parse_tree(const parse_tree & rhs) = default;
	parse_tree(parse_tree && rhs) = default;
	parse_tree & operator=(const parse_tree & rhs) = default;
	parse_tree & operator=(parse_tree && rhs) = default;
	~parse_tree(void) = default;
	//constructor

	//end and begin functions
	tree_iterator end(void) const;
	tree_iterator begin(void) const;

	void clear(void);		//deletes the entire tree
	std::size_t size(void);	//Returns the size of the tree
	void erase(tree_iterator i);	//Recursively deletes every node from the current one
	tree_iterator insert(tree_iterator parent, const Node & child);	//insert node

	friend std::ostream& operator<<(std::ostream & os, const parse_tree & ptree);
};



#endif /* PARSETREE_H_ */