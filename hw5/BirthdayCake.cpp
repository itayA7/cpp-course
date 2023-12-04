#include "BirthdayCake.h"
#include <cstring>
using namespace std;

BirthdayCake::BirthdayCake(Date expiryDate, double height, double price, int storage, bool glutenFree, char *description)
    : Cake(expiryDate, height, price, storage, glutenFree)
{
    this->text = new char[strlen(description) + 1];
    strcpy(this->text, description);
}

BirthdayCake::BirthdayCake(BirthdayCake &other)
{
    this->expiryDate = other.expiryDate;
    this->height = other.height;
    this->price = other.price;
    this->storage = other.storage;
    this->glutenFree = other.glutenFree;
    this->text = other.text;
}

BirthdayCake::~BirthdayCake()
{
    delete[] text;
}

BirthdayCake &BirthdayCake::operator=(BirthdayCake &other)
{
    if (this != &other)
    {
        this->expiryDate = other.expiryDate;
        this->height = other.height;
        this->price = other.price;
        this->storage = other.storage;
        this->glutenFree = other.glutenFree;
        this->text = other.text;
    }
    return *this;
}

void BirthdayCake::setText(char *description)
{
    delete[] description;
    this->text = new char[strlen(description) + 1];
    strcpy(this->text, description);
}

char *BirthdayCake::getText()
{
    return text;
}

bool BirthdayCake::operator==(BirthdayCake &other)
{
    return ((expiryDate == other.expiryDate) &&
            (height == other.height) &&
            (price == other.price) &&
            (storage == other.storage) &&
            (glutenFree == other.glutenFree) &&
            (text == other.text));
}

void BirthdayCake::operator+=(int addCakePrice)
{
    price += addCakePrice;
}

std::ostream &operator<<(ostream &os, BirthdayCake &birthdayCake)
{
    os << "Expiry Date: " << birthdayCake.expiryDate << endl;
    os << "Destination: " << birthdayCake.diameter << endl;
    os << "Height: " << birthdayCake.height << endl;
    os << "Price: " << birthdayCake.price << endl;
    os << "Storage: " << birthdayCake.storage << endl;
    os << "GlutenFree: " << birthdayCake.glutenFree << endl;
    os << "Text: " << birthdayCake.text << endl;

    return os;
}