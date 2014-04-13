//7 April 2014
//Thomas Dusterwald
//Parse_tree source file

#include "parse_tree.h"

//begin function - returns tree_iterator that points to root of tree_iterator
tree_iterator parse_tree::begin(void) const
{
	tree_iterator start(root);
	return start;
}

//end function - returns a tree_iterator pointing to a nullptr
tree_iterator parse_tree::end(void) const
{
	tree_iterator nll(nullptr);
	return nll;
}

//deletes the entire tree from the root downwards
void parse_tree::clear(void)
{
	root->destroy();
}

//deletes the given node and all its children
void parse_tree::erase(tree_iterator i)
{
	Node temp(1);
	temp.children[0]=(*i);
	//(*i)->destroy();
}

//Returns the size of the tree
std::size_t parse_tree::size(void)
{
	tree_iterator beg(begin());
	tree_iterator finish(end());
	std::size_t count = 1;
	while(beg != finish)
	{
		++count;
		++beg;
	}
	return count;
}



//Inserts a new node as one of the children of the parent node. Returns an iterator pointing to the node inserted
tree_iterator parse_tree::insert(tree_iterator parent, const Node & child)
{
	tree_iterator ret(parent);
	if(root == nullptr && *(parent) == nullptr)
	{
		root = child.clone();
		ret = begin();
		return ret;
	}
	else
	{
		tree_iterator beg(begin());
		tree_iterator finish(end());
		while(beg != parent)
		{
			++beg;
			if(beg == finish)
			{
				//throw exception
				return parent;
				break;
			}
		}
		while((*beg)->numUsed<(*beg)->numChildren)
		{
			if(((*beg)->children[(*beg)->numUsed])->value != "")
				(*beg)->numUsed++;
			else
			{
				(*beg)->children[(*beg)->numUsed] = child.clone();
				((*beg)->numUsed)++;
				ret.nodeStack.push(*parent);
				ret.childNum.push((*parent)->numUsed);
				++ret;
				return ret;
			}
		}
		//throw exception
	}
}

//does a depth first traversal and passes an inorder representation of the tree to os

std::ostream& operator<<(std::ostream & os, const parse_tree & ptree)
{
	tree_iterator beg(ptree.begin());
	tree_iterator finish(ptree.end());
	std::stringstream ss;
	while(beg != finish)
	{
		if(beg==finish)
			break;
		(*beg)->to_String(ss);
		os << ss.str();
		ss.str("");
		++beg;
	}
	return os;
}



