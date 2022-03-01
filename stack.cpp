/*********************
Name: Lucas De Rosa
Cosc 2436
Purpose: Coding 4, Dynamically Allocated Stack
File: main.cpp
**********************/


#include "stack.h"


bool Stack::push(int id, string* randStr){
    bool pushed = false;
    if (top < size)
    {
        Data *data = new Data;
        data->id = id;
        cout << "id " << id << endl;   // Just for debug
        data->information = randStr;
        stack[top++] = data;
        cout << "string " << *randStr << endl;   // Just for debug
        cout << "push, top is now " << top << endl; // Just for debug
        pushed =true;
    }
    return pushed;
}



//shallow vs deep copy??

bool Stack::pop(Data* popdata)
{
    bool popped = false;
    if (top > 0)
    {
        *popdata = *stack[--top];
        delete stack[top];
        popped = true;
    }

    return popped;
}


bool Stack::isEmpty() {
    return top == 0;
}

//Possibly overwriting unneccesarily?
bool Stack::peek(Data* peekdata){
    bool peeked = false;
    if (top > 0)
    {
        *peekdata = *stack[top-1];
        peeked = true;
    }
    return peeked;
}




