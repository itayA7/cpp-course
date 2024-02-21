#ifndef CAKE_H
#define CAKE_H
#include <cstring>

#include "Date.h"

class Cake
{
protected:
    Date expiryDate;
    const int diameter = 10;
    double height;
    double price;
    int storage; // 1 for Refrigerator and 2 for freezer
    bool glutenFree;

public:
    Cake();
    Cake(Date date, double height, double price, int storage, bool glutenFree);
    Cake(Cake &other);
    ~Cake();
    bool operator==(const Cake &other);
    Cake &operator=(Cake &other);
    void operator+=(int addCakePrice);
    friend ostream &operator<<(ostream &os, Cake &Cake);
    virtual string showRecip() = 0;
};

#endif