//testing
//Thomas Dusterwald
//5 April 2014
/*
Some general notes:
The tests are divided into five Test cases:
	Node - tests the Node class, including the 6 special member functions
	Iterator - tests the tree_iterator methods for correctness
	Parse Tree - tests parse_tree methods and 6 special member functions
	Polymorphism - Makes sure the polymorphic calls are functioning correctly
	Randomized Tree Testing - Creates 500 random trees and checks them for correctness
*/

//Neccessary includes
#include <iostream>		
#include <string>		
#include <random>	
#include <chrono>	
#include "Node.h"		
#include "tree_iterator.h"
#include "parse_tree.h"
#include "Expression.h"
#include "If.h"
#include "While.h"
#include "FunctionCall.h"
#include "Compound.h"
#include "Statement.h"

#define CATCH_CONFIG_MAIN /
#include "catch.hpp"     

#define UNIT_TESTING     
#include "counter.h"   

TEST_CASE("Node")
{
	SECTION("Test constructor")
	{
		std::cout << "__TESTS__" << std::endl;
		Node n1(7);
		Node n2(9);
		n1.value = "hello";
		REQUIRE(n1.value == "hello");
		REQUIRE(n1.numChildren == 7);
		REQUIRE(n1.maxChildren == 9);
		REQUIRE(n1.children[0]->value == "");
		REQUIRE(n1.noChildren == 16);
	}
	
	SECTION("Test copy constructor")
	{
		Node n2(9);
		Node n3(n2);
		REQUIRE(n3.value == n2.value);
		REQUIRE(n3.numChildren == n2.numChildren);
		for(int x = 0;x<n3.numChildren;x++)
		{
			REQUIRE(n3.children[x]->value == n2.children[x]->value);
		}
	}
	

	SECTION("Test copy assignment operator")
	{
		Node n1(7);
		Node n3 = n1;
		REQUIRE(n3.value == n1.value);
		REQUIRE(n3.numChildren == n1.numChildren);
		for(int x = 0;x<n3.numChildren;x++)
		{
			REQUIRE(n3.children[x]->value == n1.children[x]->value);
		}
	}

	
	SECTION("Test move constructor")
	{
		Node n4(Node(10));
		REQUIRE(n4.value == "");
		REQUIRE(n4.numChildren == 10);
		for(int x = 0;x<n4.numChildren;x++)
		{
			REQUIRE(n4.children[x]->value == "");
		}
	}


	SECTION("Test move assignment operator")
	{
		Node n4 = Node(4);
		REQUIRE(n4.value == "");
		REQUIRE(n4.numChildren == 4);
		for(int x = 0;x<n4.numChildren;x++)
		{
			REQUIRE(n4.children[x]->value == "");
		}
	}



	SECTION("Test destructor")
	{
		{
			Node n1(2);n1.value = "1";
			Node n2(3);n2.value = "2";
			Node n3(2);n3.value = "3";
			Node n4(2);n4.value = "4";
			Node n5(0);n5.value = "5";
			Node n6(0);n6.value = "6";
			Node n7(0);n7.value = "7";
			Node n8(0);n8.value = "8";
			Node n9(0);n9.value = "9";
			Node n10(0);n10.value = "10";

			*(n4.children[0]) = n9;
			*(n4.children[1]) = n10;
			*(n2.children[0]) = n4;
			*(n2.children[1]) = n5;
			*(n2.children[2]) = n6;
			*(n3.children[0]) = n7;
			*(n3.children[1]) = n8;
			*(n1.children[0]) = n2;
			*(n1.children[1]) = n3;
		}
		REQUIRE(Node::alive == 0);
	}

	SECTION("Test to_string")
	{
		Node n3(0);n3.value = "3";
		Node n1(7);
		*(n1.children[1]) = n3;
		std::stringstream ss;
		n1.to_string(ss);
		REQUIRE(ss.str()=="");
		n1.children[1]->to_string(ss);
		REQUIRE(ss.str()=="3");
	}
}


TEST_CASE("Iterator")
{
	/*		n1
		   /  \
		  n2  n3
		 /|\   |\
		n4n5n6 n7n8
	   / |
	  n9 n10
	*/
	Node n1(2);n1.value = "1";
	Node n2(3);n2.value = "2";
	Node n3(2);n3.value = "3";
	Node n4(2);n4.value = "4";
	Node n5(0);n5.value = "5";
	Node n6(0);n6.value = "6";
	Node n7(0);n7.value = "7";
	Node n8(0);n8.value = "8";
	Node n9(0);n9.value = "9";
	Node n10(0);n10.value = "10";

	parse_tree tree;
	tree_iterator t = tree.begin();
	t = tree.insert(t,n1);
	tree.insert(t,n2);
	tree.insert(t,n3);
	t++;
	tree.insert(t,n4);
	tree.insert(t,n5);
	tree.insert(t,n6);
	t++;
	tree.insert(t,n9);
	tree.insert(t,n10);
	t+=11;
	tree.insert(t,n7);
	tree.insert(t,n8);
	
	SECTION("Test increment and decrement operations")
	{
		t = tree.begin();
		REQUIRE((*t)->value==n1.value);++t;
		REQUIRE((*t)->value==n2.value);t++;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n9.value);++t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n10.value);++t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n2.value);--t;
		REQUIRE((*t)->value==n4.value);t--;
		REQUIRE((*t)->value==n10.value);--t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n10.value);++t;
		t+=100;
		REQUIRE((*t)==0);
	}

	SECTION("Test += and -= operations")
	{
		t=tree.begin();
		t+=5;
		REQUIRE((*t)->value == n10.value);
		t-=3;
		REQUIRE((*t)->value == n4.value);
	}

	SECTION("Test distance operation")
	{
		t=tree.begin();
		t+=5;
		tree_iterator t2 = tree.begin();
		REQUIRE((t-t2) == 5);
	}	

	SECTION("Test copy constructor")
	{
		t=tree.begin();
		++t;
		++t;
		tree_iterator t2(t);
		++t2;
		++t;
		REQUIRE(t2==t);
	}
}

TEST_CASE("Parse Tree")
{
	/* The tree shown below is built and then tests run on it		
			n1
		   / 
		  n2  
		 /|\   
		n4n5n6 
	   / |
	  n9 n10
	*/
	Node n1(2);n1.value = "1";
	Node n2(3);n2.value = "2";
	Node n4(2);n4.value = "4";
	Node n5(0);n5.value = "5";
	Node n6(0);n6.value = "6";
	Node n9(0);n9.value = "9";
	Node n10(0);n10.value = "10";

	parse_tree ptree;
	tree_iterator t(ptree.begin());
	ptree.insert(t,n1);
	t = ptree.begin();
	t = ptree.insert(t,n2);


	ptree.insert(t,n4);
	ptree.insert(t,n5);
	ptree.insert(t,n6);
	++t;
	ptree.insert(t,n9);
	ptree.insert(t,n10);


	SECTION("Test tree")
	{
		t = ptree.begin();
		tree_iterator z = ptree.end();
		REQUIRE((*t)->value==n1.value);++t;
		REQUIRE((*t)->value==n2.value);++t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n9.value);++t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n10.value);
		t+=10;
		REQUIRE(t==z);
	}

	SECTION("Test begin() and end() functions")
	{
		tree_iterator beg = ptree.begin();
		tree_iterator end = ptree.end();
		int count = 0;
		while(beg!=end)
		{
			count++;
			++beg;
		}
		REQUIRE(count == 15);
	}

	SECTION("Check erase")
	{
		{
			int x = Node::alive;
			t = ptree.begin();
			++t;
			ptree.erase(t);
			REQUIRE((x-Node::alive) == 6);
		}
	}

	SECTION("check clear")
	{
		int x = Node::alive;
		ptree.clear();
		REQUIRE((x-Node::alive) == 8);
	}

	SECTION("Test copy constructor")
	{
		parse_tree ptree2(ptree);
		t = ptree2.begin();
		REQUIRE((*t)->value==n1.value);++t;
		REQUIRE((*t)->value==n2.value);++t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n9.value);++t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n10.value);
	}
	

	SECTION("Test copy assignment operator")
	{
		parse_tree ptree2=ptree;
		t = ptree2.begin();
		REQUIRE((*t)->value==n1.value);++t;
		REQUIRE((*t)->value==n2.value);++t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n9.value);++t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n10.value);
	}
}


TEST_CASE("Polymorphism")
{
/*
Builds the tree that was shown in the assignment that should produce the code:
{
	a = 0
	while (a < 10){
		if (a % 2 == 0){
			print "even"
		}
		else {
			print "odd"
		}
		a += 1
	}
}
*/

	//Building tree
	Compound c1 (2);
	Statement s1;
	Node a;a.value = "a";
	Expression exp1(1);
	While wh;
	Expression exp2(3);
	Node br1; br1.value = "(";
	Node br2; br2.value = ")";
	Node lt;lt.value = "<";
	Node exp10;exp10.value = "10";
	If if1;
	Node eq;eq.value = "==";
	Node eq1;eq1.value = "=";
	Node zero;zero.value = "0";
	Node mod;mod.value = "%";
	Node two;two.value = "2";
	Compound c3(1);
	FunctionCall f1(1,"print");
	Node even;even.value = "\"even\"";
	Node odd;odd.value = "\"odd\"";
	Node peq;peq.value = "+=";
	Node one;one.value = "1";


	parse_tree ptree;
	tree_iterator t(ptree.begin());
	ptree.insert(t,c1);
	t = ptree.begin();
	ptree.insert(t,s1);
	ptree.insert(t,wh);

	t+=3;

	ptree.insert(t,a);
	ptree.insert(t,eq1);
	ptree.insert(t,exp1);
	t+=5;
	ptree.insert(t,zero);
	t+=5;
	ptree.insert(t,exp2);
	ptree.insert(t,c1);
	++t;
	
	ptree.insert(t,br1);
	ptree.insert(t,exp2);
	ptree.insert(t,br2);
	t+=3;
	ptree.insert(t,a);
	ptree.insert(t,lt);
	ptree.insert(t,exp10);
	t+=11;
	ptree.insert(t,if1);
	ptree.insert(t,s1);
	t+=3;
	ptree.insert(t,exp2);
	ptree.insert(t,c3);
	ptree.insert(t,c3);
	++t;
	ptree.insert(t,br1);
	ptree.insert(t,exp2);
	ptree.insert(t,br2);
	t+=3;
	
	ptree.insert(t,exp2);
	ptree.insert(t,eq);
	ptree.insert(t,zero);
	++t;
	ptree.insert(t,a);
	ptree.insert(t,mod);
	ptree.insert(t,two);
	t+=16;
	ptree.insert(t,f1);
	t+=3;
	ptree.insert(t,even);
	t+=11;
	ptree.insert(t,f1);
	t+=3;
	ptree.insert(t,odd);
	t+=10;
	ptree.insert(t,a);
	ptree.insert(t,peq);
	ptree.insert(t,exp1);
	t+=5;
	ptree.insert(t,one);

	std::cout << "Actual code" << std::endl;
	std::cout << "{\n  a = 0\n  while (a<10){\n  if (a%2==0){\n  print \"even\" \n}\nelse{\n  print \"odd\" \n}\n  a += 1\n}\n}\n" << std::endl;
	std::string test = "{\n  a = 0\n  while (a<10){\n  if (a%2==0){\n  print \"even\" \n}\nelse{\n  print \"odd\" \n}\n  a += 1\n}\n}\n";
	//Testing tree
	std::stringstream ss;
	(*ptree.begin())->to_string(ss); 
	std::cout<<"Version produced by tree" << std::endl;
	std::cout<<ss.str()<<std::endl;
	REQUIRE(ss.str()==test);
	std::stringstream ss1;
	parse_tree ptree1(ptree);
	(*ptree1.begin())->to_string(ss1);
	//std::cout <<ss1.str()<<std::endl;
}

TEST_CASE("Randomized Tree Testing")
{
	SECTION("Randomized Tree Testing")
	{
		for(int x = 0;x < 500;x++) //Repeat tests 500 times
		{
			{
			parse_tree ptree;
			tree_iterator t = ptree.begin();
			//Creating random integers between 3 and 10 for the height of the tree
			std::size_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    		std::default_random_engine e(seed);
    		std::uniform_int_distribution<int> rangeh(3, 10);
    		//Each child has anywhere between 0 and 5 children
    		std::uniform_int_distribution<int> rangec(1, 5);

    		int height = rangeh(e);

    		//Construct tree
    		int numchild = rangec(e);
    		Node temp(numchild);
    		ptree.insert(t,temp);
    		t = ptree.begin();
    		int heighti = 1;
    		
    		while(heighti < height)
    		{
    			for(int x = 0;x<(*t)->numChildren;x++)
    			{
    				numchild = rangec(e);
    				Node temp(numchild);
    				ptree.insert(t,temp);
    			}
    			++t;
    			heighti++;
    		}
    		
    		//Test copy constructor
    		parse_tree p2(ptree);
    		tree_iterator beg = ptree.begin();
    		tree_iterator end = ptree.end();
    		tree_iterator z = p2.begin();
    		while(beg!=end)
    		{
    			REQUIRE((*z)->numChildren==(*beg)->numChildren);
    			z++;
    			beg++;
    		}

    		//Test copy assignment
    		parse_tree p3 = ptree;
    		beg = ptree.begin();
    		end = ptree.end();
    		z = p3.begin();
    		while(beg!=end)
    		{
    			REQUIRE((*z)->numChildren==(*beg)->numChildren);
    			z++;
    			beg++;
    		}



    		//Check erase
    		int N = 1;
    		t = ptree.begin();
    		t+=N;
    		ptree.erase(t);
    		beg = p3.begin();
    		end = p3.end();
    		int count = 0;
    		int count2 = 0;
    		while(beg!=end)
    		{
    			if(count2<N)
    				count2++;
    			else
    				count++;
    			beg++;
    		}
    		REQUIRE(ptree.size()==count+2);

    		//Check clear
    		ptree.clear();
    		REQUIRE(*(ptree.begin())==0);
    	}	
		}
	}
}



