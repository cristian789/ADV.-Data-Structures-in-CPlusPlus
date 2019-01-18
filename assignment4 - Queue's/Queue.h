/*********************************************************************
PROGRAM:    CSCI 340 Assignment 4/ Queue.h
PROGRAMMER: Cristian Aguirre
LOGON ID:   Z1824863
DUE DATE:   2/22/18

FUNCTION:   For this computer assignment, we are to write and implement a C++ program to find
and push and pop numbers as they are typed in as well as to store them on a stack.
*********************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

//h file is the header file for assignment 4

class Queue {
    private:
        std::stack<int> s1, s2;
    public:

        bool empty() const;
        int size() const;
        int front();
        int back();
        void push(const int& val);
        void pop();
};


#endif
