all : tut

#INCLUDE_DIRS = -I gtest-1.7.0/include
INCLUDE_DIRS =
CPPFLAGS = $(INCLUDE_DIRS) -std=c++0x

LIB_DIRS =
LIBS = 
#LIB_DIRS = -Lgtest-1.7.0/lib
#LIBS = -lgtest -lgtest_main -lpthread 
LDFLAGS = $(LIBS) $(LIB_DIRS) -fPIC
OBJECTS = minitut.o
PROGRAM = tut

$(PROGRAM) : $(OBJECTS)
	g++  $(OBJECTS) -o $(PROGRAM) $(LDFLAGS)

minitut.o : minitut.cpp
	g++ -c minitut.cpp $(CPPFLAGS)
run :
	./$(PROGRAM)

clean :
	rm *.o