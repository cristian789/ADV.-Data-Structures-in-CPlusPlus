/*********************************************************************
PROGRAM:    CSCI 340 Assignment 2
PROGRAMMER: Cristian Aguirre
LOGON ID:   Z1824863
DUE DATE:   2/6/18

FUNCTION: For this program we are to implement two search algorithms (linear search and
binary search) in C++ on randomly generated integers stored in vectors. In this
assignment, I will use routines from STL <algorithm> to implement these algorithms.
*********************************************************************/


#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>


//using std statemens intead of using namespace std for efficiency
using std::binary_search; using std::sort;
using std::vector; using std::cout; using std::fixed;
using std::setprecision; using std::endl;
using std::setw;

//intializing data
const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;


/* This routine generates random integers in the range[LOW = 1, HIGH = 200]
and puts them in vector v.Initializes the random number generator(RNG) by
calling the function srand() with the seed value seed, and generates random
integers by calling the function rand().*/
void genRndNums( vector<int>& v, int seed )
{
	int low = 1;
	int high = 100;
	srand(seed);

	for (unsigned int i = 0; i != v.size(); i++)
	{
		v.at(i) = rand () % (high - low + 1) + low;

	}
}



/*A linear search algorithm, where x is the searched item in vector
inputVec.It simply starts searching for x from the beginning of vector v to
the end, but it stops searching when there is a match.If the search is successful, it
returns true; otherwise, it returns false    */
bool linearSearch( const vector<int>& inputVec, int x) 
{
	vector<int>::const_iterator it = find(inputVec.begin(), inputVec.end(), x);
	if (it == inputVec.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}



/*A binary search algorithm, where x is the searched item in vector
inputVec.If the search is successful, it returns true; otherwise, it returns
false.To implement this routine, simply call the binary_search()
function from the STL*/
bool binarySearch( const vector<int>& inputVec, int x) 
{
	if (binary_search(inputVec.begin(), inputVec.end(), x))
	{
		return false;
	}
	else
	{
		return true;
	}
}



/*A generic search algorithm – takes a pointer to the
search routine p( ), and then it calls p( ) for each element of vector
searchVec in vector inputVec. It computes the total number of successful
searches and returns that value to the main() routine as an input argument to
the print routine printStat()
*/
int search( const vector<int>& inputVec, const vector<int>& searchVec,
            bool (*p)( const vector<int>&, int) )
{
	int search = 0;

	for (unsigned int i = 0; i < searchVec.size(); i++)
	{
		if ( p(inputVec, searchVec[i]) != true)
			{
			search++;
			}
	}

	return search;
}


/*A sort algorithm to sort the elements of vector 
inputVec in ascending order*/
void sortVector (vector<int>& inputVec) 
{
	sort(inputVec.begin(), inputVec.end());
}



/*Prints the percent of successful searches as 
floating-point numbers on stdout, where totalSucCnt 
is the total number of successful comparisons and vec_size
is the size of the test vector.*/
void printStat (int totalSucCnt, int vec_size) 
{
	float result = 0;
	result = ((float)totalSucCnt / vec_size);
	cout << "Successful searches: " << fixed << setprecision(2)
		<< (result * 100) << '%' << endl;
}



/*This routine displays the contents of vector vec
on standard output, printing exactly
NO_ITEMS = 10 numbers on a single line, except perhaps the last line.*/
void print_vec( const vector<int>& vec )
{
	int NO_ITEMS = 10, ITEM_W = 6;

	int count = 0;
	cout << "The vector elements are " << endl;

	for (unsigned int i = 0; i < vec.size();i++)
	{
		if (count == NO_ITEMS){
		count = 0;
		cout<<endl;
		}
		count++;
		cout<< setw(ITEM_W);
		cout << vec.at(i)<< " ";
	}
	cout<<endl;
}



int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "\n\n----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}

