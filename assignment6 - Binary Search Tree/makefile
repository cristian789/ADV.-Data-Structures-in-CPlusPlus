#
# PROGRAM:    assign4
# PROGRAMMER: Cristia Aguirre
# LOGON ID:   z-1824863
# DATE DUE:   10/19/2017
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment6main: assignment6main.o assignment6.o assignment5.o
	g++ $(CCFLAGS) -o assignment6main assignment6main.o assignment6.o assignment5.o

# Rules to compile source code file to object code
assignment6main.o: assignment6main.cc assignment6.h assignment5.h
	g++ $(CCFLAGS) -c assignment6main.cc

assignment6.o: assignment6.cc assignment6.h
	g++ $(CCFLAGS) -c assignment6.cc

assignment5.o: assignment5.cc assignment5.h
	g++ $(CCFLAGS) -c assignment5.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment6main
