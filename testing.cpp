//testing
//Thomas Dusterwald
//5 April 2014

#include <iostream>		// I/O streams Header
#include <string>		// Strings Header
#include <random>		// For random number generation
#include "Node.h"		

#define CATCH_CONFIG_MAIN /
#include "catch.hpp"     

#define UNIT_TESTING     // So that we know whether to include our counter class
#include "counter.h"   

TEST_CASE("Node")
{
	Node n1(7);
	n1.value = "hello";
	SECTION("Test constructor")
	{
		REQUIRE(n1.value == "hello");
		REQUIRE(n1.numChildren == 7);
	}
	SECTION("Test copy constructor")
	{

	}
	SECTION("Test copy assignment operator")
	{

	}
	SECTION("Test move constructor")
	{

	}
	SECTION("Test move assignment operator")
	{

	}
	SECTION("Test destructor")
	{

	}
	SECTION("Test to_string")
	{

	}
}