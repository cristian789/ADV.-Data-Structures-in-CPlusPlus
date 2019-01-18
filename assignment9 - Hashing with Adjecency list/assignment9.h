/*********************************************************************
 PROGRAM:    CSCI 340 Assignment 9
 PROGRAMMER: Cristian Aguirre
 LOGON ID:   Z1824863
 DUE DATE:   4/27/18
 
 FUNCTION:  For this computer assignment, you are to write a C++ program
 to implement several graph algorithms on simple graphs. These graphs are
 implemented with adjacency list representation.
 *********************************************************************/
#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H
#include <vector>
#include <list>

class graph {
    private:
        int size;
        std::vector< std::list<int> > adj_list;
        std::vector< char > labels;
        void depth_first( int ) const;
    public:
        graph( const char* filename );
        ~graph();
        int get_size() const;
        void traverse( ) const;
        void print ( ) const;
};

#endif 
