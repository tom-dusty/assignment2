//testing
//Thomas Dusterwald
//5 April 2014

#include <iostream>		// I/O streams Header
#include <string>		// Strings Header
#include <random>		// For random number generation
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

#define UNIT_TESTING     // So that we know whether to include our counter class
#include "counter.h"   

TEST_CASE("Node")
{
	SECTION("Test constructor")
	{
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


/*
	SECTION("Test destructor")
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
		n1.destroy();
		n2.destroy();
		n3.destroy();
		n4.destroy();
		n5.destroy();
		n6.destroy();
		n7.destroy();
		n8.destroy();
		n9.destroy();
		n10.destroy();

		//REQUIRE(Node::alive == 0);
	}
	*/

	SECTION("Test to_String")
	{
		Node n1(7);
		std::stringstream ss;
		n1.to_String(ss);
		std::cout << ss.str();
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

	*(n4.children[0]) = n9;
	*(n4.children[1]) = n10;
	*(n2.children[0]) = n4;
	*(n2.children[1]) = n5;
	*(n2.children[2]) = n6;
	*(n3.children[0]) = n7;
	*(n3.children[1]) = n8;
	*(n1.children[0]) = n2;
	*(n1.children[1]) = n3;
	
	SECTION("Test increment and decrement operations")
	{
		parse_tree tree;
		tree_iterator t(tree.begin());
		tree.insert(t,n1);
		t = tree.begin();
		REQUIRE((*t)->value==n1.value);++t;
		REQUIRE((*t)->value==n2.value);++t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n9.value);++t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n10.value);++t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n2.value);--t;
		REQUIRE((*t)->value==n4.value);--t;
		REQUIRE((*t)->value==n10.value);--t;
		REQUIRE((*t)->value==n4.value);++t;
		REQUIRE((*t)->value==n10.value);++t;
		t+=100;
		REQUIRE((*t)==0);
	}

	SECTION("Test += and -= operations")
	{
		tree_iterator t(&n1);
		t+=5;
		REQUIRE((*t)->value == n10.value);
		t-=3;
		REQUIRE((*t)->value == n4.value);
	}

	SECTION("Test distance operation")
	{
		tree_iterator t1(&n1);
		t1+=5;
		tree_iterator t2(&n1);
		REQUIRE((t1-t2) == 5);
	}	

	SECTION("Test copy constructor")
	{
		tree_iterator t1(&n1);
		++t1;
		++t1;
		tree_iterator t2(t1);
		++t2;
		++t1;
		REQUIRE(t2==t1);
	}
	SECTION("Test destructor")
	{
		//n2.~Node();
	}
}

TEST_CASE("Parse Tree")
{
	/*		n1
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
		std::cout << ptree << std::endl;
	}


/*
	SECTION("Check erase")
	{
		{
			int x = Node::alive;
			t = ptree.begin();
			++t;
			ptree.erase(t);
			std::cout << ptree << std::endl;
			REQUIRE((x-Node::alive) == 5);
		}

		std::cout << "winning?" << std::endl;
	}

	SECTION("check clear")
	{
		ptree.clear();
		std::cout << ptree << std::endl;
		REQUIRE(Node::alive == 12);
	}

	SECTION("Last check")
	{
		REQUIRE(Node::alive == 0);
	}
	*/
}


TEST_CASE("Polymorphism")
{

	Compound c1 (2);
	
	Statement s1;
	Node a;a.value = "a";
	Expression exp1(1);


	While wh;
	Expression exp2(3);
	Node br1; br1.value = "(";
	Node br2; br2.value = ")";
	Expression exp3(3);
	Node lt;lt.value = "<";
	Node exp10;exp10.value = "10";

	Compound c2(2);
	If if1;
	Expression exp4(3);
	Expression exp5(3);
	Node eq;eq.value = "==";
	Node eq1;eq1.value = "=";
	Node zero;zero.value = "0";
	Expression exp6(3);
	Node mod;mod.value = "%";
	Node two;two.value = "2";


	Compound c3(1);
	FunctionCall f1(1,"print");
	Node even;even.value = "\"even\"";


	Compound c4(1);
	FunctionCall f2(1, "print");
	Node odd;odd.value = "\"odd\"";

	Statement s2;
	Node peq;peq.value = "+=";
	Expression exp7(1);
	Node one;one.value = "1";




	Node * pointer = new Node;
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


	
	
	std::stringstream ss;
	(*ptree.begin())->to_String(ss); 
	std::cout<<ss.str()<<std::endl;
	
}



