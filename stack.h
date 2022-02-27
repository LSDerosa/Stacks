/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

#ifndef STACK_H
#define STACK_H
using namespace std;

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#include <iostream>

class Stack {

public:
    bool pop(Data*);

    bool peek(int, string *);

    bool push(int, string *);

    bool isEmpty();

    Stack(int size) {
        Data* myDataArray2[size];
        this->stack=myDataArray2;
    }

    ~Stack() {
        for (int i = top; i >= 0; i--) {
            delete stack[top];}
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

#endif //STACK_H



