#include "stack.h"






bool Stack::push(int id, string* randStr){
    bool pushed = false;
    if (top < size - 1){
        stack[++top];
        Data *data = new Data;
        data->id = id;
        cout << "id " << id << endl;   // Just for debug
        data->information = randStr;
        cout << "info " << randStr << endl;   // Just for debug
        cout << "inside push, top is now" << top << endl; // Just for debug
        pushed =true;
    }
    return pushed;
}


bool Stack::pop(Data* popdata){
    if (top < 0) {
        throw -1; // throw an int because we cannot return one
    }
    popdata->id = stack[top]->id;
    popdata->information = stack[top]->information;
    delete stack[top];
    top--;
    return true;
}

bool Stack::isEmpty() {
    return top < 0;
}


/*
bool Stack::peek(Data& popdata){
    if (top < 0) {
        throw -1; // throw an int because we cannot return one
    }
    peekdata.id = stack[top]->id; popdata.information = stack[top]->information;
    delete stack[top];
    top--;
    return true;
}
*/




