#include <iostream>		// I/O streams Header
#include <string>		// Strings Header
#include <random>		// For random number generation
#include <chrono>		// For accessing the system clock

#define CATCH_CONFIG_MAIN // So that Catch will define a main method
#include "catch.hpp"     // Catch unit testing framework

#define UNIT_TESTING     // So that we know whether to include our counter class
#include "counter.h"     // Object counter header

// (1) This tutorial uses the Catch unit testing framework
//     Its exists in the directory as the header only catch.hpp file
//     In your tut directory run the following to get a brief idea of
//     the testing framework output:
//     # ~/basedir$ make
//     # ~/basedir$ ./tut --help
//     # ~/basedir$ ./tut
//     # ~/basedir$ ./tut -s
//     # ~/basedir$ ./tut -s Basics
//     
//     The first run prints some command line help.
//     The second prints the output of failed runs
//     The thid prints the output of successful runs too
//     The fourth prints all output for a specific test cases, "Basics"
//
// NOW, proceed to each TEST_CASE and follow the instructions there.

// Pull in things from std namespace
using namespace std;

// A unit test
// TEST_CASE(<test case name>, <tags>)
TEST_CASE("Basics","[pointers]")
{
	// (1) Run # ./tut -s Basics
	//     to see all output from just this test case
	// (2) Compare the program output to the code below

	// Obtain a seed from the system clock and seed the random engine
    // Create random ints between 1 and 100
    std::size_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::uniform_int_distribution<int> intgen(1, 100);

    // Get a random integer between 1 and 100
    const int N = intgen(e);

	// Construct integer a with random value
	int a = N;
	// Assign the address of integer a to integer pointer, aptr.
	int * aptr = &a;

	// A testing section
	SECTION("Dereferencing aptr is equal to the value of a")
	{
		// Log the values of variable a and *aptr
		CAPTURE(a);
		CAPTURE(*aptr);

		// Contrast with the first pointer diagram in the slides
		INFO("a's address is " << static_cast<void *>(&a));
		INFO("aptr's address is " << static_cast<void *>(&aptr)
			<< " and points at " << static_cast<void *>(aptr));
		// INFO and CAPTURE messages only get printed after an assertion.

		// A testing assertion. These must be true
		// for the test to succeed.
		REQUIRE(*aptr == N);	
		REQUIRE(*aptr == a);	
		REQUIRE(aptr == &a);	

		// Can create warning and failures
		//if(isprime(a)) { WARN("I dislike primes"); }
		if(a % 2 == 1) { FAIL("OH NO. AN ODD NUMBER!"); }
	}

	// Some more tests
	SECTION("Assigning to dereferenced aptr, changes a's value")
	{
		// Get another random integer
		const int M = intgen(e);

		// Assign M to dereferenced value of aptr. This should change a
		*aptr = M;
		REQUIRE(a == M);
	}
}

// A very dumb class
class dumb
#ifdef UNIT_TESTING
: public sjp::counter<dumb>
#endif
{};

// TEST_CASE(<test case name>, <tags>)
TEST_CASE("SingleAllocate","[pointers][allocation]")
{
	//------------------------------------------------------------------------
	// (1) Run ./tut -s SingleAllocate
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// (2) Dynamically allocate a single dumb and
	//     assign the address of this array to an dumb pointer.
	//------------------------------------------------------------------------



	REQUIRE(dumb::alive == 1);

	//------------------------------------------------------------------------
	// (3) Release the memory
	//------------------------------------------------------------------------



	REQUIRE(dumb::alive == 0);
}

TEST_CASE("ArrayAllocate","[pointers][allocation]")
{
	//------------------------------------------------------------------------
	// (1) Run ./tut -s ArrayAllocate
	//------------------------------------------------------------------------

	// Obtain a seed from the system clock and seed the random engine
    // Create random ints between 4 and 10
    std::size_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::uniform_int_distribution<int> intgen(4, 10);

	const int N = intgen(e);

	//------------------------------------------------------------------------
	// (2) Dynamically allocate an array of N dumb's and
	//     assign the address of this array to a dumb pointer.
	//------------------------------------------------------------------------



	REQUIRE(dumb::alive == N);

	//------------------------------------------------------------------------
	// (3) Release the memory
	//------------------------------------------------------------------------




	REQUIRE(dumb::alive == 0);
}

TEST_CASE("Arithmetic", "[pointers][arithmetic]")
{
	// Obtain a seed from the system clock and seed the random engine
    // Create random ints between 4 and 10
    std::size_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::uniform_int_distribution<int> intgen(4, 10);

    const int N = intgen(e);

	//------------------------------------------------------------------------
	// (1) Dynamically allocate an array of N floats
	//------------------------------------------------------------------------



	//------------------------------------------------------------------------
	// (2) Initialise this array using pointer arithmetic
	//     *(...) = i;
	//------------------------------------------------------------------------



	//------------------------------------------------------------------------
	// (3) Then iterate through this array using array indexing
	//     to confirm that the contents of the array matches the loop counter
	//------------------------------------------------------------------------



	//------------------------------------------------------------------------
	// (4) Be sure to deallocate the float array
	//------------------------------------------------------------------------
}

// A class describing a node in a singly linked list
class slist_node
#ifdef UNIT_TESTING
: public sjp::counter<slist_node>
#endif
{
public:
	slist_node * next; // Pointer to next node in the list
	int value;         // Value stored in the node
};

TEST_CASE("LinkedList","[pointers][linkedlist]")
{
	//------------------------------------------------------------------------
	// (1) Run ./tut -s LinkedList
	//------------------------------------------------------------------------

	// Obtain a seed from the system clock and seed the random engine
    // Create random ints between 4 and 10
    std::size_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::uniform_int_distribution<int> intgen(4, 10);

	// Make a singly linked list of N node's connected together
	const int N = intgen(e);

	//------------------------------------------------------------------------
	// (2) Dynamically allocate the first node and assign it
	//     to a pointer named 'head'. Set the int value contained in this
	//     node to '0', by using the -> operator.
	//------------------------------------------------------------------------




	// We'd now expect there to be one node alive
	REQUIRE(slist_node::alive == 1);

	//------------------------------------------------------------------------
	// (3) Now, write a loop to create a list of N-1 nodes, with each
	//     node pointing to the next. Remember to terminate
	//     the last node with nullptr so that you know
	//     where the linked list stops.
	//     Assign the values in these nodes incrementally (1..N-1)
	//     You may find it useful to use an extra
	//     pointer variable here, to avoid
	//     losing the head pointer. 
	//------------------------------------------------------------------------	




	// There should now be N nodes in existence
	REQUIRE(slist_node::alive == N);

	//------------------------------------------------------------------------
	// (4) Iterate through the list, checking that each value
	//     has been assigned incrementally using pointer arithmetic
	//------------------------------------------------------------------------

	//for( ... )
	//{
	//	REQUIRE(node->value) == i;
	//}






	//------------------------------------------------------------------------
	// (5) Now, destroy your linked list. Delete the
	//     head node, then the next node and so on.
	//     BUT, once the head node is destroyed, how does one find
	//     the next node?
	//------------------------------------------------------------------------





	// There should now be zero nodes in existence
	REQUIRE(slist_node::alive == 0);
}

// A class describing a node in a binary tree
class binary_tree_node
#ifdef UNIT_TESTING
: public sjp::counter<binary_tree_node>
#endif
{
public:
	binary_tree_node * left;    // Pointer to the left child node
	binary_tree_node * right;   // Pointer to the right child node
	int value;                  // Value stored by the node
};

// First argument is a reference to a pointer
void allocate_tree(binary_tree_node * & root, std::size_t depth)
{
}

// First argument is a reference to a pointer
void delete_tree(binary_tree_node * & root)
{
}

TEST_CASE("BinaryTree","[pointers][binarytree]")
{
	//------------------------------------------------------------------------
	// (1) Run ./tut -s BinaryTree
	//------------------------------------------------------------------------

	// Obtain a seed from the system clock and seed the random engine
    // Create random ints between 4 and 10
    std::size_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::uniform_int_distribution<int> intgen(4, 10);

	// Make a binary tree of depth N.
	const std::size_t N = intgen(e);
	REQUIRE(binary_tree_node::alive == 0);

	//------------------------------------------------------------------------
	// (2) Recursively create a binary tree of depth N
	//------------------------------------------------------------------------
	binary_tree_node * root;
	allocate_tree(root, N);
	REQUIRE(binary_tree_node::alive == std::pow(2,N)-1);

	//------------------------------------------------------------------------
	// (3) Recursively delete the binary tree
	//------------------------------------------------------------------------
	delete_tree(root);
	REQUIRE(binary_tree_node::alive == 0);
}