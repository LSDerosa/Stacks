/*********************
Name: Lucas De Rosa
Cosc 2436
Purpose: Coding 4, Dynamically Allocated Stack
File: main.cpp
**********************/

#ifndef STACKS_MAIN_H
#define STACKS_MAIN_H

// you probably need all these,
// but if you don't get rid of what you don't need
#include <stdlib.h>   /* srand, rand */
#include <time.h>     /* time */
#include <iostream>   /* cout, endl */
#include <string>     /* string */
#include "functions.h"
#include "stack.h"
#define MULTIPLIER 1.5 // used to test overflow and underflow
#define NARROW .30 // percent of the stack for a narrow band
#define RANDOM_MULTIPLIER 10
#define CHOICES 6 // used to pick random operations
#define MAX_INT 100000 // random ints to push, 1 - 100000

using std::cout;
using std::endl;
using std::cerr;

#endif /* STACKS_MAIN_H */
