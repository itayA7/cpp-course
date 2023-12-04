#ifndef TRIP_H
#define TRIP_H
#include <iostream>
#include <cstring>
#include "Date.h"
using namespace std;

class Trip
{
private:
    int tripId;
    char *destination = nullptr;
    Date tripDate;

public:
    Trip &operator=(const Trip &other)
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

    Trip(int tripid, char *destination, Date tripDate)
    {
        setTripId(tripid);
        setTripDate(tripDate);
        setDestination(destination);
    }
    Trip()
    {
        Date newDate;
        Trip(15, "Israel", newDate);
    }
    int getTripId()
    {
        return this->tripId;
    }
    char *getDestination()
    {
        return this->destination;
    }
    Date getTripDate()
    {
        return tripDate;
    }
    void setTripId(int id)
    {
        if (id <= 0)
        {
            id = 15;
        }
        this->tripId = id;
    }
    void setDestination(char *destination)
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
    void setTripDate(Date date)
    {
        this->tripDate = date;
    }
    void PrintTrip()
    {
        cout << "trip number:" << this->tripId << "  ;To:" << destination << "   ;Date:";
        tripDate.PrintDate();
    }
};
#endif