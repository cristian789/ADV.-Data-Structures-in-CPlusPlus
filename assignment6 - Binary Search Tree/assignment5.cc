/*********************************************************************
 PROGRAM:    CSCI 340 Assignment 6
 PROGRAMMER: Cristian Aguirre
 LOGON ID:   Z1824863
 DUE DATE:   3/23/18
 
 FUNCTION:   For this computer assignment, we are to write a C++ program to implement classes to
 represent a binary tree (of integers). it will display the height
 the size the bianry tree in inorder preoder and postoder.
 *********************************************************************/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment5.h"


using namespace std;

//initialized data
//const int MAX_SIZE = 40; 
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}

binTree::binTree()    //constructor
{
    r = NULL;
}

//public version
void binTree::insert(int num)// inserts a node in tree
{ ///
    insert( r, num ); // call recursive
}  //



//private version
void binTree::insert(Node*& p, int data)// inserts a node in tree
{ ///
    if( p == NULL )
    {
        Node* newNode;
        newNode = new Node(data); // new node with new value
        p = newNode; // set ptr to new node
    }
    else
    {
        int lHeight = height( p->left );
        int rHeight = height( p->right );
        
        if( lHeight <= rHeight )
        {
            insert( p->left, data );
        }
        else
        {
            insert( p->right, data );
        }
    }
}



// returns height of tree
int binTree::height( ) const
{
    return height( r ); // call recursive
}


//private height
int binTree::height(Node* r)const  {
    
    if( r == NULL )
    {
        return 0; // empty tree
    }
    else
    {
        int lHeight = height( r->left ); // left side
        int rHeight = height( r->right ); // right side
        
        if( lHeight > rHeight ) // which is greater
            
        {
            return 1 + lHeight; // return left
        }
        else
        {
            return 1 + rHeight; // return right
        }
    }
}


// returns no of nodes
unsigned binTree::size( ) const
{
    return size( r ); // call recursive
}


// private version of size
unsigned binTree::size( Node *r ) const
{
    if( r != NULL ) // if not empty
    {
        return 1 + size( r->left ) + size( r->right );
    }
    else
    {
        return 0; // emtpy tree
    }
}



// inorder traversal of tree, public
void binTree::inorder(void (*p)(int))
{
    inorder( r, *p);  // call recursive
}


//inoder traversal of tree. public
void binTree::inorder(Node* r, void(*p)(int))
{
    if( r != NULL )
    {
        inorder( r->left, p);
        p( r->data);
        inorder( r->right, p );
    }
    
}

// preorder traversal of tree, public
void binTree::preorder(void (*p)(int))
{
    preorder( r, *p);  // call recursive
}

//preoder traversal of tree. public
void binTree::preorder(Node* r, void(*p)(int))
{
    if (r != NULL)
    {
        p( r->data );
        preorder( r->left, p );
        preorder( r->right, p );
    }
}



// postorder traversal of tree, public
void binTree::postorder(void (*p)(int))
{
    postorder( r, *p);  // call recursive
}


// private version of postorder
void binTree::postorder(Node* r, void(*p)(int))
{
    if( r != NULL )
    {
        postorder( r->left, p );
        postorder( r->right, p );
        p( r->data );
    }
}


//#define BINTREE_MAIN      //assignment6main is the new main
//#ifdef BINTREE_MAIN
//int main() {
//    vector<int> v(MAX_SIZE);
//    for (int i=1; i<MAX_SIZE; i++)
//        v[i] = i;
//    random_shuffle( v.begin(), v.end() );
//    
//    binTree bt;
//    vector<int>::iterator it;
//    for (it=v.begin(); it!=v.end(); it++)
//        bt.insert( *it );
//    
//    cout << "Height: " << bt.height() << endl;
//    cout << "Size: " << bt.size() << endl;
//    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
//    mcount = rcount = 0;
//    bt.inorder( display );
//    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
//    mcount = rcount = 0;
//    bt.preorder( display );
//    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
//    mcount = rcount = 0;
//    bt.postorder( display );
//    
//    cout << endl;
//    return 0;
//}

//#endif

