#
# PROGRAM:    assign1
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

# Rule to compile source code file to object code
assign1.o: assign1.cc
	g++ $(CCFLAGS) -c assign1.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign1
