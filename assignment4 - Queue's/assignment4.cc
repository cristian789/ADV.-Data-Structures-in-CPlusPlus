/*********************************************************************
PROGRAM:    CSCI 340 Assignment4.cc
PROGRAMMER: Cristian Aguirre
LOGON ID:   Z1824863
DUE DATE:   2/22/18

FUNCTION:   For this computer assignment, we are to write and implement a C++ program to find
and push and pop numbers as they are typed in as well as to store them on a stack.
*********************************************************************/


#include <iostream>
#include <queue>
#include <stack>  
#include <iomanip>
#include <algorithm>
#include "Queue.h"

//using namespace std;
using std::string; using std::cout; using std::endl;
using std::cin; using std::cerr; using std::setw;

//making sure both s1 and s2 are empty.
bool Queue::empty()const
{
	if (s1.empty() && s2.empty())
		return true;
	else
		return false;
}


//counting the number of elements in both s1 and s2.
int Queue::size()const
{
	return s1.size() + s2.size();
}


//This method returns the oldest element. First of all if s2 is empty, 
//move all elements from s1 to s2. Simply return the top element in s2.

int Queue::front()
{
    while (!s1.empty()) 
    {
        s2.push(s1.top());

        s1.pop();

    }
// pop and store the top element from s2

       int ret = s2.top();

// transfer all elements of s2 back to s1

    while (!s2.empty()) 
    {
        s1.push(s2.top());

        s2.pop();
    }

    return ret;
}


//This method returns the newest element. Simply return the top element in s1.
int Queue::back()
{
	return s1.top();
}

//Simply add the element to s1.
void Queue::push(const int &val)
{
	s1.push(val);
}

//This method removes the oldest element.
void Queue::pop()
{
	while (!s1.empty()) 
    {
        s2.push(s1.top());

        s1.pop();
    }

    //pop and store the top elemnt from s2
    s2.pop();


    //transfer all of the elements of s2 back to s1
    while (!s2.empty()) 
    {
        s1.push(s2.top());

        s2.pop();
    }
}


//main
int main() {
    Queue q;
    string op;
    int val = 0;
 
   cout << "operation -- size front end" << endl;
   cin >> op;
   while ( !cin.eof() ) {
        if ( op == "push" ) {
            cin >> val;
            q.push( val );
            cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" ) {
            q.pop();
            cout << op << "       -- ";
        }
        else {
            cerr << "Error input: " << op << endl;
            return 1;
        }
        cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back() << endl;
        cin >> op;
    }

    while ( !q.empty() )
        q.pop();

    return 0;
}
