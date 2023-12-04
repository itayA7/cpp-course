#ifndef SHOE_STORAGE_H
#define SHOE_STORAGE_H

#include "PairOfShoes.h"
#include <iostream>

using namespace std;

class ShoeStorage
{
private:
    PairOfShoes **storage;
    int storageSize;

public:
    ShoeStorage(int size = 4)
    {
        storage = new PairOfShoes *[size];
        for (int i = 0; i < size; i++)
        {
            storage[i] = nullptr;
        }
        storageSize = size;
    }

    // Copy constructor
    ShoeStorage(const ShoeStorage &other)
    {
        storageSize = other.storageSize;
        storage = new PairOfShoes *[storageSize];
        for (int i = 0; i < storageSize; i++)
        {
            if (other.storage[i] != nullptr)
            {
                storage[i] = new PairOfShoes(other.storage[i]->getName(), other.storage[i]->getPrice());
            }
            else
            {
                storage[i] = nullptr;
            }
        }
    }

    // Destructor
    ~ShoeStorage()
    {
        for (int i = 0; i < storageSize; i++)
        {
            delete storage[i];
        }
        delete[] storage;
    }

    // Assignment operator
    ShoeStorage &operator=(const ShoeStorage &other)
    {
        if (this == &other)
        {
            return *this;
        }
        for (int i = 0; i < storageSize; i++)
        {
            delete storage[i];
        }
        delete[] storage;
        storageSize = other.storageSize;
        storage = new PairOfShoes *[storageSize];
        for (int i = 0; i < storageSize; i++)
        {
            if (other.storage[i] != nullptr)
            {
                storage[i] = new PairOfShoes(other.storage[i]->getName(), other.storage[i]->getPrice());
            }
            else
            {
                storage[i] = nullptr;
            }
        }
        return *this;
    }

    int getSize()
    {
        return storageSize;
    }

    void AddPairOfShoes(const PairOfShoes &newShoe)
    {
        int index = 0;
        while (index < storageSize && storage[index] != nullptr)
        {
            ++index;
        }
        if (index == storageSize)
        {
            int newSize = storageSize * 2;
            PairOfShoes **newShoes = new PairOfShoes *[newSize];
            for (int i = 0; i < newSize; i++)
            {
                newShoes[i] = nullptr;
            }
            for (int i = 0; i < storageSize; i++)
            {
                newShoes[i] = storage[i];
            }
            delete[] storage;
            storage = newShoes;
            storageSize = newSize;
        }
        storage[index] = new PairOfShoes(newShoe);
    }

    void RemovePairOfShoes(const char *shoeName)
    {
        for (int i = 0; i < storageSize; i++)
        {
            if (storage[i] != nullptr && storage[i]->getName() == shoeName)
            {
                delete storage[i];
                storage[i] = nullptr;
                return;
            }
        }
    }

    double GetPrice(const char *shoeName)
    {
        for (int i = 0; i < storageSize; i++)
        {
            if (storage[i] != nullptr && storage[i]->getName() == shoeName)
            {
                return storage[i]->getPrice();
            }
        }
        return 0.0;
    }

    double AverageShoePrice()
    {
        double price = 0.0;
        int numberOfShoes = 0;
        for (int i = 0; i < storageSize; i++)
        {
            if (storage[i] != nullptr)
            {
                numberOfShoes++;
                price += storage[i]->getPrice();
            }
        }
        return numberOfShoes > 0 ? price / numberOfShoes : 0.0;
    }
};

#endif
