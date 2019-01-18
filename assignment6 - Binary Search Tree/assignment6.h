/*********************************************************************
 PROGRAM:    CSCI 340 Assignment 6
 PROGRAMMER: Cristian Aguirre
 LOGON ID:   Z1824863
 DUE DATE:   3/23/18
 
 FUNCTION:   For this computer assignment, we are to write a C++ program to implement classes to
 represent a binary search tree (of integers). it will display the height
 the size the bianry tree in inorder preoder and postoder.
 *********************************************************************/


#ifndef ASSIGNMENT6
#define ASSIGNMENT6
#include "assignment5.h"

class BST : public binTree {
    
    
    public:
    
        BST() : binTree() {}        // constructor
        void insert( int );         // insert an item in the tree
        bool search( int );         // search an item in the tree
        bool remove( int );         // removes an item in the tree & returns true when successful
    
       int sumLeftLeaves();        // returns the sum of values
                                    // of left leaves
    
    private:
    
        void insert( Node*&, int );     // private version of insert(int)
        bool search( Node*&, int );     // private version of search(int)
        bool remove( Node*&, int );     // private version of bool remove(int )
//        int FindMin(/*Node*&*/);
//    
        bool leaf ( Node*);             //checking if it s a leaf
        int sumLeftLeaves(Node*&);      // private version of sumLeftLeaves
};

#endif
