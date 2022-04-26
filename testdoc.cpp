////////////////////////////////////////////////////////////////////////////////
//Resources used:
//https://www.geeksforgeeks.org/overloading-new-delete-operator-c/
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdlib.h>
#include <map>
#include "make.h"
using namespace std;

void bufferoverrun() {
    int *p = new int[10]; // 0,1,2,3,4,5,6,7,8,9 

    p[-1] = 10; //Buffer overrun to the negative side
    p[0] = 7;
    p[10] = 10; //Buffer overrun to the positive side
    
    delete [] p;
}

void memoryleak() {
    
    int *p = new int[100];
    
    //when delete data, in dictonary we put deleted, 
    //check dictonary at end and if no "delete" then we throw a error

    //No call to delete, so this pointer is a memory leak
}

void invaliddelete_1() {
    //cout << "Start test1\n";
    int *p;

    //In delete check if map has value at p, throw error if not 
    delete p;// no data to delete
}

void invaliddelete_2() {
    cout << "Invalid delete 2\n";
    int *p = new int;
    delete p;

    //In delete check if map has value at p, throw error if not 
    //invalid delete
    delete p;// already deleted once

    cout << endl;
}

void checkFree(){
    auto it = pointer_map.begin();
    while(it != pointer_map.end()){
        if(pointer_map[it->first] == 1111){ //if data has not been freed then it won't be equal to -9999!!!
            cout << "Some allocated memory has not been freed!\n ";
        }
        it++;
    }
}


int main() {
    pointer_map[0] = {NULL};
    dum = true;
    
    //bufferoverrun(); //incomplete

    //invaliddelete_1(); //works
    //invaliddelete_2(); //WORKS rn
    //memoryleak();  //WORKS rn

    cout << "End of the line\n";
    delMap = true; //map is ready to delete!!
    checkFree();
}