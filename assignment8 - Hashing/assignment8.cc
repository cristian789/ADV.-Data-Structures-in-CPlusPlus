/*********************************************************************
PROGRAM:    CSCI 340 Assignment 8
PROGRAMMER: Cristian Aguirre
LOGON ID:   Z1824863
DUE DATE:   4/16/18

FUNCTION:   For this computer assignment, you are to write a C++ program to create, search, print, and manage an item inventory
*********************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include "assignment8.h"

using namespace std;


Entry* get_entry(const string& line)
{
    Entry* parsed_line = new Entry;
    
    parsed_line -> key = line.substr(2,3);
    parsed_line -> description = line.substr(6, line.length() - 6);
    return parsed_line;
}

string get_key (const string& line)
{
    string gKey = line.substr(2,3);
    return gKey;
}



HT :: HT ( int s )
{
    hTable = new vector<Entry>(s);
    table_size = s;
    item_count = 0;
    
}

HT :: ~HT ()
{
    delete hTable;
}


int HT :: search (const string& key)
{
    int keyIndex = hashing(key);
    
    for (int i = 0; i < table_size;  i++)
    {
        if ((*hTable)[keyIndex].key == key)
            
            return keyIndex;
        
        keyIndex = (keyIndex + 1) % table_size;
    }
    
    return -1;
}


bool HT::insert(const Entry& e)
{
    int keyIndex = hashing(e.key);
    string sKey = e.key;
    
    if (search(sKey) != -1)
    {
        cerr<< "Unable to insert - the table is full."<<endl;
        return false;
    }
    else {
    
        for (int i = 0; i< table_size; i++)
        {
            if((*hTable)[keyIndex].key == "---" || (*hTable)[keyIndex].key == "+++")
            {
                (*hTable)[keyIndex] = e;
                item_count++;
                
                return true;
            }
            
            keyIndex = keyIndex + 1 % table_size;
        }
    }
    
    return false;
}


bool HT::remove(const string& s)
{
    if (search(s) == -1)
    {
        return false;
    }
    
    else {
        int keyIndex = search(s);
        
        (*hTable)[keyIndex].key = "+++";
        item_count--;
        return true;
    }
}


void HT::print()
{
    cout << endl<< "----Hash Table-----"<< endl;
    
    for (int i = 0; i< table_size; i++)
    {
        if ((*hTable)[i].key != "---" && (*hTable)[i].key != "+++")
        {
            cout << right << setw(2) << i << ":";
            cout << (*hTable)[i].key <<" ";
            cout << (*hTable)[i].description<< endl;
            
        }
    }
    cout << "-------------------"<<endl<<endl;
}


// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key) {
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht;
    ifstream infile("assignment8input.txt", ios::in);
    string line;
    infile >> line;    
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) { 
            Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 ) 
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
        }
        infile >> line;
 
    }

    infile.close();
    return 0;
}
