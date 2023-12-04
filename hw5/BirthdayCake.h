#ifndef BirthdayCake_H
#define BirthdayCake_H

#include <iostream>
#include "Cake.h"
using namespace std;

class BirthdayCake : Cake
{
    char *text;

public:
    BirthdayCake(Date expiryDate, double height, double price, int storage, bool glutenFree, char *description);
    BirthdayCake(BirthdayCake &other);
    ~BirthdayCake();
    BirthdayCake &operator=(BirthdayCake &other);

    void setText(char *description);
    char *getText();

    void operator+=(int addCakePrice);

    bool operator==(BirthdayCake &other);

    friend ostream &operator<<(ostream &os, BirthdayCake &birthdayCake);
};

#endif