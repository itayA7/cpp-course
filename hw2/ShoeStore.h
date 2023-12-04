#ifndef SHOE_STORE_H
#define SHOE_STORE_H
#include "ShoeStorage.h"
#include <iostream>
using namespace std;

class ShoeStore
{
private:
    ShoeStorage shoeStorage;
    double currentDiscountPrecent;

public:
    ShoeStore(double precent = 0)
    {
        currentDiscountPrecent = precent;
    }

    void SetDiscountPrecent(double precent)
    {
        currentDiscountPrecent = precent;
    }
    double getDiscountPrecent()
    {
        return this->currentDiscountPrecent;
    }
    void AddShoes(char *shoeName, int shoePrice, int numberOfShoes = 1)
    {
        PairOfShoes shoeToAdd(shoeName, shoePrice);
        for (int i = 0; i < numberOfShoes; i++)
        {
            this->shoeStorage.AddPairOfShoes(shoeToAdd);
        }
    }
    double AverageShoePrice()
    {
        double price = this->shoeStorage.AverageShoePrice();
        double discountedPrice = price * (1 - (currentDiscountPrecent / 100));
        return discountedPrice;
    }
    double GetShoePrice(char *shoeName)
    {
        double price = this->shoeStorage.GetPrice(shoeName);
        double discountedPrice = price * (1 - (currentDiscountPrecent / 100));
        return discountedPrice;
    }
    void RemoveOnePair(char *shoeName)
    {
        this->shoeStorage.RemovePairOfShoes(shoeName);
    }
};

#endif
