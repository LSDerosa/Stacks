/*********************
Name: Lucas De Rosa
Cosc 2436
Purpose: Coding 4, Dynamically Allocated Stack
File: main.cpp
**********************/

#ifndef STACK_H
#define STACK_H


#include "data.h"
#include <iostream>

class Stack {

public:
    bool pop(Data*);

    bool peek(Data*);

    bool push(int, string *);

    bool isEmpty();

    Stack(int size) {

        stack = new Data* [size];
        this->size = size;
        top = 0;
    }

    ~Stack() {
        while (top>0) {
            delete stack[--top];
        }
        delete[] stack;
    }

        /*
         * write all your public method prototypes here
         * this includes you constructor and destructor
         */
    
private:

    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need.
    // do not modify them or add any other attributes
    int top;
    int size;
    Data **stack;
};


using std::cout;
using std::endl;

#endif //STACK_H



