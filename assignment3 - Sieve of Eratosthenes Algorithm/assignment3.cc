/*********************************************************************
PROGRAM:    CSCI 340 Assignment 3
PROGRAMMER: Cristian Aguirre
LOGON ID:   Z1824863
DUE DATE:   2/14/18

FUNCTION:   For this computer assignment, we are to write and implement a C++ program to find
and print all prime numbers within a range [lower upper] using the algorithm
known as the Sieve of Eratosthenes. The program will have basic interactive user
interface to take input values of lower and upper and allow the user to continue or
quit the game.
*********************************************************************/


#include <iostream>
#include <set>
#include <string>
#include <cctype>
#include <iomanip>
#include <algorithm>

//initialized data
const int NO_ITEMS = 6;
const int ITEM_W = 4;


//using namespace std;
using std::cout; using std::setw;
using std::endl; using std::set; using std::for_each;
using std::cin;  using std::string;

//made a class print to make print primes a bit easier to see and more effiient
//with less likelyness for it to fail.
class print 
{
private:
	int column;

public:
	print() { column = 1; }
	void operator()(const int& element)
	{
		cout << setw(ITEM_W) << element;
		if (column % NO_ITEMS == 0)
			cout << endl;
		column++;
	}
};

/*: This routine can be used to apply the Sieve of Eratosthenes
algorithm to remove all nonprime numbers from the integer set s = {
	lower, …, upper }. */
void sieve(set<int>& s, const int lower, const int upper)
{
	s.clear();

	for (int i = 1 + lower; i <= upper; i++)
		s.insert(i);
	
	for (int outer = 2; (outer)*(outer) < upper; outer++)
		for (int inner = (outer) * 2; inner <= upper; inner += outer)
			s.erase(inner);

	return; 
}


//This function calls on the class print to print the primes with a set of width and 
//number of items.
void print_primes( const set<int>& s, const int lower, const int upper) 
{	
	cout << endl;
	cout << "There are " << s.size() << " prime numbers between " << lower << " and " << upper << ":" << endl;

	for_each(s.begin(), s.end(), print());

	cout << endl << endl;
	return;
}


/* This routine maintains a loop to take
inputs from a user. The user will be asked for the range of the prime numbers.
If the range is not valid, e.g. lower is greater than upper, the user will be
asked to input again. The routine will invoke sieve() and
print_primes(). Once the results are displayed, the user will be asked
whether to continue or quit the game. In case of continuing the game, the
user will be asked for values of the range again. The game continues until the
user requests to stop. */
void run_game(set<int>& s) 
{
	int lower, upper;
	string answer;
	
	do {
		do
		{
			lower = upper = 0;
			cout << "Please input lower bound and upper bound and hit enter (e.g. 10 100): " << endl;
			cin >> lower;
			cin >> upper;
			cin.clear();
			cin.ignore(256,'\n');
		} while (lower >= upper);

	
		sieve(s, lower, upper);
	
		print_primes(s, lower,upper);
	
		do
		{
			cout << "Do you want to continue or not? Please answear yes or no and hit enter: " << endl;
			cin >> answer;
			for (unsigned int i = 0; i < answer.length(); i++)
				answer[i] = tolower(answer[i]);
		} while (answer != "no" && answer != "yes");

	} while (answer == "yes");

	return;
}

int main() {
    set<int> s;
    run_game(s);
    return 0;
}
