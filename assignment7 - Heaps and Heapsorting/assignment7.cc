/*********************************************************************
 PROGRAM:    CSCI 340 Assignment 7
 PROGRAMMER: Cristian Aguirre
 LOGON ID:   Z1824863
 DUE DATE:   4/4/18
 
 FUNCTION:   For this computer assignment, you are to write a C++
 program to sort numbers using the heapsort technique. Your program
 first builds a heap structure for the numbers. Then, it retrieves
 these numbers from the heap in a certain order and prints them
 out on stdout.
 *********************************************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

const int HEAP_SIZE = 50;


/*   This function “heapifies” a tree at the root position r,
 assuming r’s two sub-trees are already heaps. heap_size  */

void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) )
{
    int left  = 2 * r;
    int right = 2 * r + 1;
    
    int largest;
    int temp;
    
    /*****************if left*************/
    if (left <= heap_size && compar(v[left], v [r]))
        largest = left;
    else
        largest = r;
    
    /*****************if right*************/
    if (right <= heap_size && compar(v[right], v[largest]))
        largest = right;
    
    /*****************if none *************/
    if (largest != r)
    {
        temp = v[r];
        
        v[r] = v[largest];
        
        v[largest] = temp;
        
        heapify(v, heap_size, largest, compar);
    }
}



/* This function constructs a heap with heap_size elements in the vector v.
 Pay attention that elements start at position 1
 (position 0 is wasted and ignored) in the vector. */
void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) )
{
    for (int i = heap_size/2; i >= 1; i--)
    {
        heapify(v, heap_size, i, compar);
    }
}


/* This function compares two integers and returns
 true if e1 is less than e2. Otherwise it returns false.
 When this function is used as predicate in build_heap,
 a min heap will be constructed.    */
bool less_than ( int e1, int e2 )
{
    if (e1 < e2)
        return true;
    else
        return false;
}



//This function compares two integers and returns
//true if e1 is greater than e2. Otherwise it returns
//false. When this function is used as predicate in
//build_heap, a max heap will be constructed.
bool greater_than ( int e1, int e2 )
{
    if (e1 > e2)
        return true;
    else
        return false;
}


// This function extracts the root of the heap
//recorded in v, fills the root with the last
//element of the current heap, updates heap_size,
//“heapifies” at the root, and returns the old
//root value. This function will invoke heapify
//specified above.
int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) )
{
    int extract;
    
    if (heap_size < 1)
        cout<< "Error"<<endl;
    
    extract = v[1];
    
    v[1] = v[heap_size];
    
    heap_size = heap_size - 1;
    
    heapify(v, heap_size, 1, compar);
    
    return extract;
}


/*This function implement the heap sort algorithm.
At beginning the vector v contains a heap. At
the end of this function, vector v contains
sorted elements. Similar to build_heap, there
is a predicate in the parameter list to specify
how to compare two elements. If less_than is
passed in as argument here, the results are in
ascending order. If greater_than is used, the
results are in descending order. heap_sort will
invoke extract_heap specified below.
*/
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) )
{
    int i;
    
    for (i = heap_size; i >= 2; i --)
    {
        v[i] = extract_heap(v, heap_size, compar);
    }
    
    reverse(v.begin() + 1, v.end());
}




/*This function displays size number of elements
contained in vector v starting at position pos.
It shows 8 elements per line. Each item occupies 5 spaces.
*/
void print_vector ( vector < int >& v, int pos, int size )
{
    
    for(; pos <= size; pos++)
    {
        cout <<setw(5)<< v[pos] <<" ";
        
        if ((pos % 8) == 0)
        {
            cout<<endl;
            
        }

    }
}


int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\n\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "\n\nHeap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\n\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "\n\nHeap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}
