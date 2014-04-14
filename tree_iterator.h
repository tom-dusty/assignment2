// Iterator header file
// Thomas Dusterwald
// 2 April 2014

#ifndef TREE_ITERATOR_H_
#define TREE_ITERATOR_H_

#include <cstdlib>
#include <string> 
#include <stack>
#include "Node.h"

class tree_iterator
{
	private:
		std::stack<Node *> nodeStack;
		std::stack<int> childNum;
		tree_iterator(void);
		tree_iterator(Node * start);
	public:
		Node * currNode;
		int currChildNum;


		//Comparison operators
		bool operator==(const tree_iterator &other);
		bool operator!=(const tree_iterator &other);
		//Incrementing and decrementing operations
		tree_iterator & operator+=(std::size_t distance);
		tree_iterator & operator+(std::size_t distance);
		tree_iterator & operator-=(std::size_t distance);
		tree_iterator & operator-(std::size_t distance);
		tree_iterator & operator++();
		tree_iterator operator++(int);
		tree_iterator & operator--();
		tree_iterator operator--(int);
		//Overrides * operator to return a pointer to the current node
		Node * operator*();
		//distance operation
		std::size_t operator-(tree_iterator prev);
		//special member functions
		tree_iterator & operator=(const tree_iterator & rhs) = default;
		tree_iterator & operator=(tree_iterator && rhs) = default;
		tree_iterator(const tree_iterator & rhs) = default;
		tree_iterator(tree_iterator && rhs) = default;
		~tree_iterator() = default;
		friend class parse_tree;
};

#endif /* TREE_ITERATOR_H_ */