/*********************
Name: Lucas De Rosa
Cosc 2436
Purpose: Introduction to the Stack
File: main.cpp
**********************/



#include "main.h"


int main(int argc, char **argv) {

    srand(time(NULL));
    int value;

    if(argc == 2){
        int size = atoi(argv[1]);

        if(size >= 2){
            try{
                Stack* newstack =  new Stack(size);
                std::string strtemp;
                Data *data = new Data;
                if (newstack->isEmpty())
                {
                    cout << "stack is empty" << endl;
                }
               else
                {
                    cout << "stack is NOT empty" << endl;
                }

                // testing peek() and pop() on empty stack
                if(newstack->peek(data))
                {
                    cout << "peeked: Value->" << data->id << " String->" <<  *data->information << endl;
                }
                else
                {
                    cerr << "peek underflow error: stack is empty" << endl;
                }

                if (newstack->pop(data))
                {
                    cout << "popped: Value->" << data->id << " String->" <<  *data->information << endl;
                }
                else
                {
                    cerr << "pop underflow error: stack is empty" << endl;
                }
                cout <<endl;

                //FILLING STACK AND PUSHING

                for(int i=0; i<size*MULTIPLIER; i++)
                {
                    rand_string(&strtemp);
                    data->id=i;
                    cout << "Random String " << *(&strtemp) << std::endl;

                    cout << "Pushing: ";
                    if(newstack->push(i, &strtemp))
                    {
                        cout << "Pushed!" << std::endl;
                    }
                    else
                    {
                        cerr << "Error, Overflow ERROR" << endl;
                    }
                    std::cout << std::endl;
                }


                // testing isEmpty() on full stack
                if (newstack->isEmpty())
                {
                    cout << "stack is empty" << endl;
                }
                else
                {
                    cout << "stack is NOT empty" << endl;
                }
                cout << endl;




                cout << "testing peek() and pop() on full stack" <<endl;
                if (newstack->pop(data))
                {
                    cout << "popped: " << "ID-> "<< data->id << " STRING->"<< *data->information << endl;
                } else
                {
                    cerr << "pop underflow error: stack is empty" << endl;
                }
                cout <<endl;

                if(newstack->peek(data))
                {
                    cout << "peeked: " << "ID-> "<< data->id << " STRING->"<< *data->information << endl;
                }
                else
                {
                    cerr << "peek underflow error: stack is empty" << endl;
                }



                // testing popping and peeking whole stack
                for (int i = 0; i < MULTIPLIER*size; i++)
                {
                    if(newstack->peek(data))
                    {
                        cout << "peeked: " << "Value-> "<< data->id << " STRING: "<< *data->information << endl;
                    }
                    else
                    {
                        cerr << "peek underflow error: stack is empty" << endl;
                    }
                    if(newstack->pop(data))
                    {
                        cout << "popped: Value->" << data->id << " String->" <<  *data->information << endl;
                    }
                    else
                    {
                        cerr << "pop underflow error: stack is empty" << endl;
                    }
                }




                // testing peek() and pop() on empty stack
                cout << endl;
                cout << endl;
                if(newstack->peek(data))
                {
                    cout << "peeked: " << "Value-> "<< data->id << " STRING: "<< *data->information << endl;
                }
                else
                {
                    cerr << "peek underflow error: stack is empty" << endl;
                }


                //testing pop on empty stack
                if (newstack->pop(data))
                {
                    cout << "popped: Value->" << data->id << " String->" <<  *data->information << endl;
                }
                else{
                    cerr << "pop underflow error: stack is empty" << endl;
                }
                cout <<endl;
                cout <<endl;




                /************************************************
                ******** MID-STACK TESTS ************************
                ************************************************/

                cout << "Filling stack halfway and testing the middle of the stack..." << endl;
                cout << "============================================================" << endl;


                // filling the stack half way to test the middle of the stack
                for (int i = 0; i< int(size / 2); i++)
                {
                    // using positive and negative "big" numbers
                    value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
                    rand_string(&strtemp);
                    if(newstack->push(value, &strtemp))
                    {
                        cout << "pushed!" << endl;
                    }
                    else {
                        cerr << "overflow error: " << i + 1 << " not pushed" << endl;
                    }
                }

                cout << "Testing middle, narrow band" << endl;


                // testing middle in a narrow band
                for (int i = 0; i<size*NARROW; i++)
                {
                    rand_string(&strtemp);
                    if (newstack->isEmpty())
                    {
                            cout << "stack is empty" << endl;
                    }
                    else
                    {
                            cout << "stack is NOT empty" << endl;
                    }
                    cout << endl;

                    if(newstack->peek(data))
                    {
                        cout << "peeked: " << "ID: "<< data->id << " STRING: "<< *data->information << endl;
                    }
                    else
                    {
                            cerr << "peek underflow error: stack is empty" << endl;
                    }
                    if (newstack->pop(data))
                    {
                        cout << "popped: Value->" << data->id << " String->" <<  *data->information << endl;
                    }
                    else{
                        cerr << "pop underflow error: stack is empty" << endl;
                    }
                    value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
                    if (newstack->push(value, &strtemp))
                    {
                        value = newstack->pop(data);
                        cout << "pushed: " << endl;
                    }
                    else
                    {
                            cerr << "overflow error: " << i + 1 << " not pushed" << endl;
                    }
                }
                cout << endl;


                /************************************************
                ******** RANDOM TESTS ***************************
                ************************************************/

                cout << "Random testing..." << endl;
                cout << "============================================================" << endl;
               //empty stack
                while(!newstack->isEmpty())
                {
                    newstack->pop(data);
                }

                // filling the stack half way with random numbers to begin random tests
                for (int i = 0; i< int(size / 2); i++) {
                    value = rand() % MAX_INT + 1;
                    rand_string(&strtemp);
                    if (newstack->push(value, &strtemp)) {
                        cout << "pushed: "<< endl;
                    }
                    else
                    {
                        cerr << "overflow error: " << i + 1 << " not pushed" << endl;
                    }
                }


                 //Random Operations. Push/Pop 2x

                int choice = rand() % CHOICES + 1;
                for (int i = 0; i < size*RANDOM_MULTIPLIER; i++) {
                    switch (choice) {
                        case 1:
                        case 2:
                            // push
                            value = (rand() % MAX_INT) + 1;
                            rand_string(&strtemp);
                            if (newstack->push(value, &strtemp)) {
                                cout << "pushed: " << endl;
                            } else {
                                cerr << "overflow error: " << data->id << *data->information<<" not pushed" << endl;
                            }
                            break;
                        case 3:
                        case 4:
                            cout <<"popping"<<endl;
                            if (newstack->pop(data))
                            {
                                cout << "popped: Value->" << data->id << " String->" <<  *data->information << endl;
                            }
                            else{
                                cerr << "pop underflow error: stack is empty" << endl;
                            }
                            break;
                        case 5:
                            // peek
                            if(newstack->peek(data)){
                                cout << "peeked: Value->" << data->id << " String->" <<  *data->information << endl;
                            } else {
                                cerr << "peek underflow error: stack is empty" << endl;
                            }
                            break;
                        case 6:
                            // isempty
                            if (newstack->isEmpty()) {
                                cout << "stack is empty" << endl;
                            } else {
                                cout << "stack is NOT empty" << endl;
                            }
                            break;
                    }
                    choice = rand() % CHOICES + 1;

                }
                cout << endl;




            }catch(...){
                cerr << "Invalid Length, Enter positive number greater than equal to 2" << endl;
            }
        }else{
            cerr << "Error: pass positive number greater than equal to 2" << endl;
        }
    }else{
        cerr << "Error: Must pass exactly one argument" << endl;
    }
    cout << "END OF TESTING" << endl;
    return 0;
}
