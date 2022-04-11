#
# PROGRAM:    assign8
# PROGRAMMER: Tyler Trotter
# LOGON ID:   z1802019
# DATE DUE:   11/3
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11 -w

# Rule to link object code files to create executable file
binarytree: bst.o
	g++ $(CCFLAGS) -o bst bst.o
# Rules to compile source code file to object code

bst.o: bst.cc
	g++ $(CCFLAGS) -c bst.cc

	
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o bst

