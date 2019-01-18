/*********************************************************************
 PROGRAM:    CSCI 340 Assignment 6
 PROGRAMMER: Cristian Aguirre
 LOGON ID:   Z1824863
 DUE DATE:   3/23/18
 
 FUNCTION:   For this computer assignment, we are to write a C++ program to implement classes to
 represent a binary search tree (of integers). it will display the height
 the size the bianry tree in inorder preoder and postoder.
 *********************************************************************/
#include <iostream>
#include "assignment5.h"
#include "assignment6.h"
using namespace std;



//inserting node with value x
void BST:: insert( int x )
{
    insert(this -> r, x);
}


//removes leaf with value x
bool BST::search ( int x)
{
    return search (this -> r, x);
}


// removes leaf with value x
bool BST::remove (int x)
{
    return remove(r, x);
}

//public sum of left leaves
int BST::sumLeftLeaves()
{
    return sumLeftLeaves(r);
}

// private version of insert(int)
void BST::insert (  Node*& obj, int x )
{
    if (obj == NULL)
        obj = new Node(x);
    if (x < obj->data)
    {
        if (obj->left == NULL)
        {
            obj->left = new Node(x);

        }

        else
            insert(obj->left, x);
    }
    else if (x > obj->data)
    {
        if (obj->right == NULL)
        {
            obj->right = new Node(x);
        }

        else
            insert(obj->right, x);
    }
}


bool BST:: search ( Node*& r, int x )  //*******search************//
{
    
    
    // Base Cases: root is null or key is present at root
    if (r == NULL || r->data == x)
        return r;
    
    // Key (data) is greater than root's key
    if (r->data < x)
        return search(r->right, x);
    
    // Key is smaller than root's key
    
    return search(r->left, x);

}




bool BST::remove ( Node*& r, int x )
{
    if ( r == NULL)
        return r;
    
    if (r->data > x )
    { return remove (r->left, x);
//        return true;
    }
    
    if (r->data < x)
    {
       return remove(r->right, x);
//        return true;
    }
    
    if (r ->left != NULL && r ->right != NULL)
    {
        Node* pred = r -> left;
        while (pred->right != NULL)
            pred = pred->right;
        
        r->data = pred->data;
        
        return remove(r->left, pred->data);
    }
    
    else if (r->left == NULL && r->right == NULL)
    {
        delete r;
        r = NULL;
        return true;
    }
    else
    {
        Node* temp = r;
        if (r->left == NULL)
            r = r->right;
        else
            r = r->left;
        
        delete temp;
//        free(r);
        return true;
    }
}

//looking for empty leafs
bool BST::leaf(Node *node)
{
    if (node == NULL)
        return false;
    if (node ->left == NULL && node->right == NULL)
        return true;
    else
    return false;
}

//sum of left leaves
int BST::sumLeftLeaves(Node*& r)
{
    if (!r)
        return 0;
    int res = 0;
    // add root data to sum if
    // root is a leaf node
    if (!r->left && !r->right)
    {  res += r->data;
    }
 
//
    //update result if root is not null
    if (r != NULL)
    {
        //if left root is null, then add key of left child
        if (leaf (r ->left))
            res += r ->left->data;
        else
        {
            // Else recur for left child of root
            res += sumLeftLeaves(r -> right);

            // Recur for right child of root and update res
            res += sumLeftLeaves(r->right);
        }
    }

    return res;    //returning result
//
}












