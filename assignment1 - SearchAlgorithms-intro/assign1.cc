/*********************************************************************
PROGRAM:    CSCI 340 Assignment 1
PROGRAMMER: Cristian Aguirre
LOGON ID:   Z1824863
DUE DATE:   1/29/18

FUNCTION:   For this computer assignment, I am writing a C++ program to
implement two search algorithms (linear search and binary search) on randomly
generated integers stored in vectors.
*********************************************************************/


#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//initialized data
const int DATA_SIZE = 200;
const int DATA_RANGE = 200;
const int DATA_SEED = 9;
const int SEARCH_SEED = 17;

const int NO_ITEMS = 8;
const int ITEM_W = 4 ;



//A linear search algorithm, where x is the searched item in vector inputVec.
int linear_search(const vector<int>& inputVec, const int x, int& comparisons) {

comparisons = 0;
for (int i = 0; i < (int)inputVec.size(); i++)
	{
		if (inputVec[i] == x)
		{
			comparisons++;
			return i + 1;
		}
	       comparisons++;

	}
	return -1;
}


//A binary search algorithm, where x is the searched item in vector inputVec.
int binary_search(const vector<int>& inputVec, const int x, int& comparisons) {
comparisons = 0;

	int low = 0, high = inputVec.size() -1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (inputVec[mid] == x)
		{
			++comparisons;
			return mid + 1;
		}

		else if (inputVec[mid] > x)
		{
			++comparisons;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return -1;
}


//This routine displays the contents of vector vec on standard output,
void print_vec( const vector<int>& vec ){

int count = 0;
	cout << "The vector elements are " << endl;
	for (int i = 0; i < (int)vec.size(); i++)
	{
		if (count < NO_ITEMS)
		{cout << setw(ITEM_W) << vec[i];
                 count++;
		}
		else
                {count=0; cout<<"\n";}
		//cout << endl;
	}

	cout<<endl;
}


void average_comparisons(const vector<int>& inputVec, const vector<int>& searchVec, int (*search)(const vector<int>&, const int, int&) ) {
    int i, comparison = 0, sum = 0, found = 0;
    int res = 0;
    for (i = 0; i < (int)searchVec.size(); i++) {
        res = search( inputVec, searchVec[i], comparison );
        sum += comparison;
        if ( res >= 0 )
           found++;
    }
    cout << found << " numbers are found. The average number of comparisons in each search: " << (double)sum/(double)searchVec.size() << endl << endl;
}

int random_number() {
    return rand()%DATA_RANGE + 1;
}


int main () {

    // -------- create unique random numbers ------------------//
    vector<int> inputVec(DATA_SIZE);
    srand(DATA_SEED);
    generate(inputVec.begin(), inputVec.end(), random_number);
    sort(inputVec.begin(), inputVec.end());
    vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
    inputVec.resize( it - inputVec.begin() );
    random_shuffle( inputVec.begin(), inputVec.end() );

    cout << "------ Data source: " << inputVec.size() << " unique random numbers ------" << endl; 
    print_vec(inputVec);
    cout << endl;

    // -------- create random numbers to be searched ---------//
    vector<int> searchVec(DATA_SIZE/2);
    srand(SEARCH_SEED);
    generate(searchVec.begin(), searchVec.end(), random_number);

    cout << "------ " << searchVec.size() << " random numbers to be searched: ------" << endl;
    print_vec(searchVec);
    cout << endl;

    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    sort(inputVec.begin(), inputVec.end());
    cout << "------- numbers in data source are now sorted ---------" << endl << endl;
    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    return 0;

}


