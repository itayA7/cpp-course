#ifndef TRIP_H
#define TRIP_H
#include <cstring>
#include "Date.h"

class Trip
{
private:
    int tripId;
    char *destination = nullptr;
    Date tripDate;

public:
    static int counter;

    Trip operator=(const Trip &other);
    Trip(char *destination, Date tripDate);
    Trip();
    ~Trip();
    Trip(const Trip &other);
    friend ostream &operator<<(ostream &os, const Trip &t);
    int getTripId();
    char *getDestination();
    Date getTripDate();
    void setDestination(char *destination);
    void setTripDate(Date date);
    int getCounter();
};

int Trip::counter = 0;

Trip Trip::operator=(const Trip &other)
{
    if (this == &other)
    {
        return *this;
    }
    tripId = other.tripId;
    setDestination(other.destination);
    tripDate = other.tripDate;
    return *this;
}

Trip::Trip(char *destination, Date tripDate)
{
    this->tripDate = tripDate;
    setDestination(destination);
    tripId = counter;
    counter++;
}

Trip::Trip()
{
    Date newDate;
    Trip("Israel", newDate);
}

Trip::~Trip()
{
    delete[] destination;
}

Trip::Trip(const Trip &other)
{
    counter++;
    tripId = counter;
    setDestination(other.destination);
    tripDate = other.tripDate;
}

int Trip::getTripId()
{
    return this->tripId;
}
char *Trip::getDestination()
{
    return this->destination;
}
Date Trip::getTripDate()
{
    return tripDate;
}

void Trip::setDestination(char *destination)
{
    if (this->destination != nullptr)
    {
        delete[] this->destination;
        this->destination = nullptr;
    }
    int length = strlen(destination);
    for (int i = 0; i < length; i++)
    {

        if (!isalpha(destination[i]))
        {
            this->destination = new char[4];
            strcpy(this->destination, "USA");
            return;
        }
    }
    this->destination = new char[length + 1];
    strcpy(this->destination, destination);
}

void Trip::setTripDate(Date date)
{
    this->tripDate = date;
}

ostream &operator<<(ostream &os, const Trip &t)
{
    os << "trip number:" << t.tripId << "; To:" << t.destination << "; Date:" << t.tripDate << endl;
    return os;
}
#endif