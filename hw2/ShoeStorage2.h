#ifndef SHOE_STORAGE_H
#define SHOE_STORAGE_H
#include "PairOfShoes.h"
#include <iostream>
using namespace std;

class ShoeStorage
{
private:
    PairOfShoes *storage;
    int storageSize;

public:
    ShoeStorage(int size = 4)
    {
        storage = new PairOfShoes[size];
        for (int i = 0; i < size; i++)
        {
            this->storage[i] = nullptr;
        }
        this->storageSize = size;
    }

    // copy constructor
    ShoeStorage(const ShoeStorage &Cstorage)
    {
        this->storage = nullptr;
        *this = Cstorage;
    }

    // destructor
    ~ShoeStorage()
    {
        delete[] this->storage;
        this->storage = nullptr;
    }

    // assignment operator
    ShoeStorage &operator=(const ShoeStorage &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] storage;
        storageSize = other.storageSize;
        storage = new PairOfShoes[storageSize];
        for (int i = 0; i < storageSize; ++i)
        {
            storage[i] = other.storage[i];
        }
        return *this;
    }

    int getSize()
    {
        return storageSize;
    }

    void AddPairOfShoes(PairOfShoes newShoe)
    {
        int index = 0;
        while (index < storageSize && storage[index].getName() != nullptr)
        {
            ++index;
        }
        if (index == storageSize)
        {
            int newSize = storageSize * 2;
            PairOfShoes *newShoes = new PairOfShoes[newSize];
            for (int i = 0; i < newSize; ++i)
            {
                newShoes[i] = nullptr;
            }

            for (int i = 0; i < storageSize; ++i)
            {
                newShoes[i] = storage[i];
            }

            delete[] storage;
            storage = newShoes;
            storageSize = newSize;
        }

        storage[index] = newShoe;
    }

    void RemovePairOfShoes(char *shoeName)
    {
        for (int i = 0; i < storageSize; i++)
        {
            if (storage[i].getName() == shoeName)
            {
                storage[i] = nullptr;
                return;
            }
        }
    }

    double GetPrice(char *shoeName)
    {
        for (int i = 0; i < storageSize; i++)
        {
            if (storage[i].getName() == shoeName)
            {
                return storage[i].getPrice();
            }
        }
        return 0.0;
    }

    double AverageShoePrice()
    {
        double price = 0;
        int numberOfShoes = 0;
        for (int i = 0; i < storageSize; i++)
        {
            if (storage[i].getName() != nullptr)
            {
                numberOfShoes++;
                price += storage[i].getPrice();
            }
        }
        return price > 0 ? price / numberOfShoes : 0;
    }
};

#endif
