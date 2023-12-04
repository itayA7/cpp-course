#include <iostream>
#include <cstring>
using namespace std;
#include "Trip.h"
int main()
{

    int *num; // pointer to int
    Trip *a;  // pointer to class Trip
    // to allocate memory to contain one single element of type type uninitialized
    a = new Trip;
    delete a;
    // to allocate and initialized memory to contain one single element of type type
    num = new int(10);
    // to allocate memory to contain a block (an array) of elements of type type
    a = new Trip[10];

    delete num; // delete memory allocated for a single element
    delete[] a; // delete memory allocated for an array
    cout << "hola";
}