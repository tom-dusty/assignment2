all : tests

#INCLUDE_DIRS = -I gtest-1.7.0/include
INCLUDE_DIRS =
CPPFLAGS = $(INCLUDE_DIRS) -std=c++0x

#LIB_DIRS = -Lgtest-1.7.0/lib
#LIBS = -lgtest -lgtest_main -lpthread 
LDFLAGS = $(LIBS) $(LIB_DIRS) -fPIC
OBJECTS = FunctionCall.o While.o If.o Node.o testing.o tree_iterator.o parse_tree.o Compound.o Statement.o Expression.o
SOURCES = FunctionCall.cpp While.cpp If.cpp testing.cpp parse_tree.cpp Node.cpp tree_iterator.cpp parse_tree.o Compound.cpp Statement.cpp Expression.cpp
PROGRAM = tests

$(PROGRAM) : $(OBJECTS)
	g++  $(OBJECTS) -o $(PROGRAM) $(LDFLAGS)

testing.o : $(SOURCES)
	g++ -c testing.cpp $(CPPFLAGS)

parse_tree.o : parse_tree.cpp tree_iterator.cpp Node.cpp
	g++ -c parse_tree.cpp $(CPPFLAGS)

tree_iterator.o : tree_iterator.cpp
	g++ -c tree_iterator.cpp $(CPPFLAGS)

While.o : Node.cpp Compound.cpp Expression.cpp While.cpp
	g++ -c While.cpp $(CPPFLAGS)

If.o : Node.cpp Compound.cpp Expression.cpp If.cpp
	g++ -c If.cpp $(CPPFLAGS)

Compound.o : Node.cpp Compound.cpp Expression.cpp
	g++ -c Compound.cpp $(CPPFLAGS)

Statement.o : Node.cpp Statement.cpp
	g++ -c Statement.cpp $(CPPFLAGS)

Expression.o : Node.cpp Expression.cpp
	g++ -c Expression.cpp $(CPPFLAGS)

FunctionCall.o : Node.cpp FunctionCall.cpp
	g++ -c FunctionCall.cpp -c $(CPPFLAGS)

Node.o : Node.cpp
	g++ -c Node.cpp $(CPPFLAGS)

run :
	./$(PROGRAM)

clean :
	rm *.o