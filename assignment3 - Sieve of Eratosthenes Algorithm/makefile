#
# PROGRAM:    assignment3
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment3: assignment3.o
	g++ $(CCFLAGS) -o assignment3 assignment3.o

# Rule to compile source code file to object code
assignment3.o: assignment3.cc
	g++ $(CCFLAGS) -c assignment3.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment3
