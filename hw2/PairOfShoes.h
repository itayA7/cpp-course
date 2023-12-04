#ifndef PAIROFSHOES_H
#define PAIROFSHOES_H
#include <iostream>
using namespace std;

class PairOfShoes
{
private:
    char *shoeName;
    double price;

public:
    PairOfShoes(char *name = nullptr, double shoePrice = -1)
    {
        shoeName = name;
        price = shoePrice;
    }

    void setPrice(double new_price)
    {
        price = new_price;
    }
    char *getName() { return shoeName; }

    double getPrice() { return price; }
};

#endif
