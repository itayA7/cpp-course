#include "Cake.h"
Cake::Cake(Date date, double height, double price, int storage, bool glutenFree)
{
    this->expiryDate = date;
    this->height = height;
    this->price = price;
    this->storage = storage;
    this->glutenFree = glutenFree;
}

Cake::Cake()
{
    this->expiryDate = Date();
    this->height = 10;
    this->price = 50;
    this->storage = 100;
    this->glutenFree = true;
}

bool Cake::operator==(const Cake &other)
{
    if ((!(this->expiryDate == other.expiryDate)) || this->height != other.height || this->diameter != other.diameter || this->price != other.price || this->storage != other.storage || this->glutenFree == other.glutenFree)
    {
        return true;
    }
    return false;
}

Cake &Cake::operator=(Cake &other)
{
    if (this != &other)
    {
        this->expiryDate = other.expiryDate;
        this->height = other.height;
        this->price = other.price;
        this->storage = other.storage;
        this->glutenFree = other.glutenFree;
    }
    return *this;
}

void Cake::operator+=(int addCakePrice)
{
    price += addCakePrice;
}

std::ostream &operator<<(ostream &os, Cake &cake)
{
    os << "Expiry Date: " << cake.expiryDate << endl;
    os << "Destination: " << cake.diameter << endl;
    os << "Height: " << cake.height << endl;
    os << "Price: " << cake.price << endl;
    os << "Storage: " << cake.storage << endl;
    os << "GlutenFree: " << cake.glutenFree << endl;

    return os;
}