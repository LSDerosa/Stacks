#include "stack.h"






bool Stack::push(int id, string* randStr){
    bool pushed = false;
    if (top < size){
        Data *data = new Data;
        data->id = id;
        cout << "id " << id << endl;   // Just for debug
        data->information = randStr;
        stack[top++] = data;
        cout << "info " << randStr << endl;   // Just for debug
        cout << "inside push, top is now" << top << endl; // Just for debug
        pushed =true;
    }
    return pushed;
}


bool Stack::pop(Data* popdata){
    bool popped = false;
    if (top > 0) {
        *popdata = *stack[--top];
        delete stack[top];
        popped = true;
    }
    return popped;
}

bool Stack::isEmpty() {
    return top == 0;
}


bool Stack::peek(Data* peekdata){
    bool peeked = false;
    if (top > 0) {
        *peekdata = *stack[top-1];
        peeked = true;
    }
    return peeked;
}




