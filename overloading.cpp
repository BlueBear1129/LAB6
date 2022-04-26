////////////////////////////////////////////////////////////////////////////////
//Resources used:
//https://www.geeksforgeeks.org/overloading-new-delete-operator-c/
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include "make.h"

 using namespace std;

map<void*, int> pointer_map;
//vector<>
 bool delMap = false;
 bool dum = false;
 int count;
 //int chek[];

//overloaded new
void* operator new(size_t size)
{   
    void *p = malloc(size+2);

    //implamentation for bufferover run
    // // *p[0] = "z";
    // // *p[size+1] = "z";
    // *(static_cast<char*>(p)) = 'z'; // only warnings
    // //cout << *(static_cast<char*>(p));
    // *(static_cast<char*>(p)+size) = 'z'; //only warnings

    if(dum == true){ //dum will be true when calling new
        cout << "New operator overloading " << endl;
        dum = false; //when pointer_map calls new, dum will not be true and so pointer_map new memory location will not also be added to pointer_map
        //adding p to map
        pointer_map[p] = 1111; // = int[size*2] [11 12 13]
    }
    dum = true;// p has already been added to pointer_map, so we can safely set dum to true again for next pointer.
    //return static_cast<void*>(static_cast<char*>(p));
    return p;
}

//overloaded delete 
void operator delete(void * p)
{
    dum = false;
    if(delMap == false){ //we arenot trying to delete the map
        if(pointer_map.find(p) != pointer_map.end() && pointer_map[p] != -9999){ // pointer exists in map
            cout << "Delete operator overloading " << endl;
            pointer_map[p] = -9999;
            free(p);
        }else if(pointer_map[p] == -9999){//pointer_map.find(p) == pointer_map.end()){ //if the p key does not exist in the map 
            cout << "Data already deleted \n";
        }
        else{
            cout << "ERROR: No data to delete\n";
        }
    }else {//time to delete the map
        //cout << "Time to delete map"<<endl;  
        free(p);
    }        

    dum = true;
}

void operator delete[](void * p)
{
    //trying to get buffer overrun to work
    //char * mypstart = static_cast<char*>(p);
    // char * mypend = static_cast<char*>(p) + sizeof(p);
    // cout << "mypend |" << *mypend << "|"<< endl;
    // cout << "mystart |" << *(static_cast<char*>(p)) << "|" << endl;

    dum = false;

    if(delMap == false){ //we arenot trying to delete the map
        if(pointer_map.find(p) != pointer_map.end() && pointer_map[p] != -9999){ // pointer exists in map
            cout << "Delete operator overloading " << endl;
            pointer_map[p] = -9999;
            free(p);
        }else if(pointer_map[p] == -9999){//pointer_map.find(p) == pointer_map.end()){ //if the p key does not exist in the map 
            cout << "Data already deleted \n";
        }
        else{
            cout << "ERROR: No data to delete\n";
        }
    }else {//time to delete the map
        //cout << "Time to delete map"<<endl;  
        free(p);
    }        

    dum = true;
}