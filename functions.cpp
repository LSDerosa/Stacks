/*********************
Name: Lucas De Rosa
Cosc 2436
Purpose: Coding 4, Dynamically Allocated Stack
File: main.cpp
**********************/

#include "functions.h"
#include <iostream>
using std::cout;
void rand_string(std::string *str){
    // create size 0 to MAXSTRSIZE-1
    int rnum = rand() % MAXSTRSIZE;

    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;

    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }

    buffer[i] = '\0';

    // transfer buffer to passed in string
    *str = buffer;

    // clean up
    delete buffer;

    return;
}






