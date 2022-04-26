CS475W	Spring 2022
Lab06 – Memory Manager
Due time: 04/20/2022
Points: 100
For this lab, you can work in a group (two students) or on your own. Please submit your source code and a report in PDF format.

In this lab you will implement a memory manager library to help detect buffer overruns, memory leaks (pointers that are allocated without call to delete), and invalid delete calls (delete was called on a pointer that doesn’t refer to allocated memory). That is, your library should be able to catch these bugs at least:

#include <iostream>

void bufferoverrun() {
    int *p = new int[10];
    p[-1] = 10; //Buffer overrun to the negative side
    p[10] = 10; //Buffer overrun to the positive side
}

void memoryleak() {
    int *p = new int[100];

    //No call to delete, so this pointer is a memory leak
}

void invaliddelete_1() {
    int *p;
    delete p;
}

void invaliddelete_2() {
    int *p = new int;
    delete p;

    //invalid delete
    delete p;
}

int main() {
    bufferoverrun();
    memoryleak();
    invaliddelete_1();
    invaliddelete_2();
}

Your library will override the new and delete operators so that you can keep track of memory operations.  (Take a look at the -d flag for g++, and #ifdef and #ifndef. The preprocessor __FILE__ and __LINE__ directives might also be useful.) You may also implement other functions in your library in addition to overriding new and delete. For example, you may need a library function that initializes any data structures you’re using, and another to do any cleanup of resources when the program ends. Do research for these tasks and others, and as always document your sources.
