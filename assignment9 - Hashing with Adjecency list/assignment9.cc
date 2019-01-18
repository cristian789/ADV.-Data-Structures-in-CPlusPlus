/*********************************************************************
 PROGRAM:    CSCI 340 Assignment 9
 PROGRAMMER: Cristian Aguirre
 LOGON ID:   Z1824863
 DUE DATE:   4/27/18
 
 FUNCTION:  For this computer assignment, you are to write a C++ program
 to implement several graph algorithms on simple graphs. These graphs are
 implemented with adjacency list representation.
 *********************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include "assignment9.h"
using namespace std;

#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST


graph::~graph()
{}

int graph::get_size() const
{
    return size;
}


/*************************************************************/
/*This is the constructor. It reads from the input file of the graph with
 adjacency matrix representation and builds the graph with adjacency list
 representation. This method sets the value of size, builds the vectors
 labels and adj_list. For example, for the following line of input:
 D0100100
 Add edges to adj_list[3], which records edges starting from vertex D,
 by adding values 1 and 4, which are indexes for vertices B and E.*/
/*************************************************************/
graph::graph(const char * filename)
{
    ifstream input;
    input.open(filename);
    
    input >> size;
    char temp[100];
    input.getline(temp,1);
    input.getline(temp,100);
    {
        string line(temp);
        string::iterator end = remove_if(line.begin(), line.end(), static_cast<int(*)(int)> (isspace));
        line.erase(end, line.end());
        for (int i = 0; i< line.size();i++)
            labels.push_back('A'+ i );
    }
    
    while(input)
    {
        list<int>values;
        input.getline(temp,100);
        string line(temp);
        if(line.size()== 0) break;
        
        line.erase(remove_if(line.begin(),line.end(), static_cast<int(*)(int)>(isspace)), line.end());
        
        for(int i = 1; i < line.size(); i++)
        {
            if(line[i] == '1')
                values.push_back(i-1);
        }
        adj_list.push_back(values);
    }
}


/*************************************************************/
/*This function prints the adjacency list for the graph. The
 following line is an example from an output.
 D: B, E,
 It indicates there are edges from vertex D to vertices B and E.*/
/*************************************************************/
void graph::print()const
{
    int i = 0;
    cout << "Number of vertices in graph: "<< size << endl;
    cout << "\n--------START GRAPH------------" << endl;
    for (list<int> l: adj_list)
    {
        cout << (char) ('A' + i++) << ": ";
    for(int c : l)
    
        cout << labels[c] << ", ";
    cout << endl;
}
cout << "-----------END GRAPH----------" << endl;
}

int * num;
string s;




/*************************************************************/
/* This private function is used to traverse a graph in the
 depth-first traversal/search algorithm starting at the vertex
 with the index value of v. To implement this method (and
 together with the traverse method below), you may need several
 global variable and objects. E.g. container objects to record
 the visiting order of all vertices, the container object to
 record the paths of traversing edges, and an integer indicating
 the current order in traversing.
 */
/*************************************************************/
void graph::depth_first(int x) const
{
    num[x]++;
    cout << labels[x] << " ";
    for(int i : adj_list[x])
        if(num[i] == 0){
            s = s + '(' + labels[x] + ',' + labels[i] + ')';
            depth_first(i);
        }
}


/*************************************************************/
/*This public function is used to traverse a graph and invokes
 the above depth_first method. You will also need to display
 traverse result: the list of vertices in the order of their
 visit and the list of edges showing the path(s) of the traversal.
 At beginning of this method, you need to initialize the global
 variable(s) and object(s) used in depth_first.*/
/*************************************************************/
void graph::traverse()const
{
    s = "";
    cout << "\n--------traverse of graph--------" << endl;
    num = new int[size];
    for(int i = 0 ; i< size; i++)
        num[i] = 0;
    
    for(int i = 0; i < size; i++)
        if(num[i] == 0)
            depth_first(i);
    cout << endl << s << endl;
    
    delete num;
    cout << "----------end traverse-----------" << endl;
}




int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }
    
    graph g(argv[1]);

    g.print();
    
    g.traverse();

    return 0;
}

#endif
