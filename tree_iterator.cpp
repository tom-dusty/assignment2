// Iterator source file
// Thomas Dusterwald
// 2 April 2014

#include "tree_iterator.h"

//Comparison operators
//Two iterators are equal if they both have the same state
bool tree_iterator::operator==(const tree_iterator &other)
{
	if(currNode == other.currNode)
		return true;
	else
		return false;
}

bool tree_iterator::operator!=(const tree_iterator &other)
{
	return !operator==(other);
}
//Incrementing and decrementing operations
tree_iterator & tree_iterator::operator+=(std::size_t distance)
{
	for(std::size_t x = 0;x<distance;x++)
	{
		operator++();
	}
	return *this;
}

tree_iterator & tree_iterator::operator+(std::size_t distance)
{
	operator+=(distance);
	return *this;
}

tree_iterator & tree_iterator::operator-=(std::size_t distance)
{
	for(std::size_t x = 0;x<distance;x++)
	{
		operator--();
	}
	return *this;
}

tree_iterator & tree_iterator::operator-(std::size_t distance)
{
	operator-=(distance);
	return *this;
}

//Prefix increment operation
tree_iterator & tree_iterator::operator++()
{
	if(currNode != nullptr)
	{
		if(currNode->numChildren==currChildNum)
		{
			if(childNum.empty() == false)
			{
				currNode = nodeStack.top();
				nodeStack.pop();
				currChildNum = childNum.top()+1;
				childNum.pop();
			}
			else
			{
				currNode = nullptr;
			}
		}
		else
		{
			nodeStack.push(currNode);
			childNum.push(currChildNum);
			currNode = currNode->children[currChildNum];
			currChildNum = 0;
		}
	}
	return *this;
}

//postfix increment - implemented in terms of prefix increment
tree_iterator tree_iterator::operator++(int)
{
	tree_iterator temp(*this);
	operator++();
	return temp;
}

//prefix decrement operation
tree_iterator & tree_iterator::operator--()
{
	if(currNode != nullptr)
	{
		if(currChildNum==0)
		{
			if(childNum.empty() == false)
			{
				currNode = nodeStack.top();
				nodeStack.pop();
				currChildNum = childNum.top();
				childNum.pop();
			}
			else
			{
				currNode = nullptr;
			}
		}
		else
		{
			--currChildNum;
			nodeStack.push(currNode);
			childNum.push(currChildNum);
			currNode = currNode->children[currChildNum];
			currChildNum = currNode->numChildren;
		}
	}
	
	return *this;
}

//postfix decrement - implemented in terms of prefix decrement
tree_iterator tree_iterator::operator--(int)
{
	tree_iterator temp(*this);
	operator--();
	return temp;
}

//Overload * operator to return a reference to the current node
Node * tree_iterator::operator*()
{
	return currNode;
}
//distance operation
std::size_t tree_iterator::operator-(tree_iterator prev)
{
	tree_iterator curr(*this);
	std::size_t count = 0;
	while(curr != prev)
	{
		--curr;
		++count;
	}
	return count;
}

//Constructor
tree_iterator::tree_iterator(Node * start)
{
	currNode = start;
	currChildNum = 0;
}
