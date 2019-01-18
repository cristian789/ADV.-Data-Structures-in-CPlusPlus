/*********************************************************************
 PROGRAM:    CSCI 340 Assignment 6
 PROGRAMMER: Cristian Aguirre
 LOGON ID:   Z1824863
 DUE DATE:   3/23/18
 
FUNCTION:   For this computer assignment, we are to write a C++ program to implement classes to
represent a binary tree (of integers). it will display the height
the size the bianry tree in inorder preoder and postoder.
*********************************************************************/
#ifndef ASSIGNMENT5  //if def
#define ASSIGNMENT5


class Node {
    friend class BST;           //making BST class a friend to use its private functions
    
    friend class binTree;      //making bintree class a friend to use its private functions
    
    int data;   //data
    Node*left;    //left of the tree
    Node*right;   //right of the tree
public:
    Node (int d) {      //passing in the data to node
        data = d;
        left = NULL;         //initiallizing left to null
        right = NULL;        //initiallizing right to null
        
    }
};


class binTree {
    
    Node* r;
    
    friend class BST;
    
public:
    binTree(); // default constructor
    
    //        ~binTree();    //destructor
    
    virtual void insert(int); // inserts a node in tree
    int height() const; // returns height of tree
    unsigned size() const; // return size of tree
    void inorder(void(*)(int)); // inorder traversal of tree
    void preorder(void(*)(int)); // preorder traversal
    void postorder(void(*)(int)); // postorder traversal
    
    
private:
    void insert(Node*&, int); //private version of insert()
    int height(Node*) const; //private version of height()
    unsigned size(Node*) const; //private version of size()
    void inorder(Node*, void(*)(int)); //private version ofinorder()
    void preorder(Node*, void(*)(int)); //private version of preorder()
    void postorder(Node*, void(*)(int));//private version of postorder()
    
    void freeNode(Node* leaf);    //to free the nodes
};
#endif

