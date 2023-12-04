#ifndef MANAGMENT_H
#define MANAGMENT_H
#include "Trip.h"

class ManagementTrips
{
private:
    Trip **trips;
    int index;

public:
    ManagementTrips();
    ManagementTrips(const ManagementTrips &other);
    ~ManagementTrips();
    ManagementTrips &operator=(const ManagementTrips &other);
    ManagementTrips &operator+=(Trip &newTrip);
    ManagementTrips &operator-=(const Date &date);
    friend ostream &operator<<(ostream &os, const ManagementTrips &mt);
};

ManagementTrips::ManagementTrips()
{
    trips = new Trip *[0];
    index = 0;
}

ManagementTrips::ManagementTrips(const ManagementTrips &other)
{
    index = other.index;
    trips = new Trip *[index];

    for (int i = 0; i < index; ++i)
    {
        trips[i] = new Trip(*(other.trips[i]));
    }
}

ManagementTrips::~ManagementTrips()
{
    for (int i = 0; i < index; ++i)
    {
        delete trips[i]; // Delete each Trip object
    }

    delete[] trips; // Delete the array of pointers
}

ManagementTrips &ManagementTrips::operator=(const ManagementTrips &other)
{
    if (this != &other)
    {
        for (int i = 0; i < index; ++i)
        {
            delete trips[i];
        }
        delete[] trips;
        index = other.index;
        trips = new Trip *[index];

        for (int i = 0; i < index; ++i)
        {
            trips[i] = new Trip(*(other.trips[i]));
        }
    }
    return *this;
}

ManagementTrips &ManagementTrips::operator+=(Trip &newTrip)
{
    Trip **newTrips = new Trip *[index + 1];
    for (int i = 0; i < index; ++i)
    {
        newTrips[i] = trips[i];
    }

    newTrips[index] = new Trip(newTrip);
    ++index;
    delete[] trips;
    trips = newTrips;
    return *this;
}

ManagementTrips &ManagementTrips::operator-=(const Date &date)
{
    int count = 0;
    for (int i = 0; i < index; ++i)
    {
        if (trips[i]->getTripDate() == date)
        {
            ++count;
        }
    }

    Trip **newTrips = new Trip *[index - count];
    int newIndex = 0;
    for (int i = 0; i < index; ++i)
    {
        if (!(trips[i]->getTripDate() == date))
        {
            newTrips[newIndex++] = trips[i];
        }
        else
        {
            delete trips[i];
        }
    }
    delete[] trips;
    trips = newTrips;
    index -= count;
    return *this;
}

ostream &operator<<(ostream &os, const ManagementTrips &mt)
{
    if (mt.index == 0)
    {
        os << "empty list" << endl;
    }
    else
    {
        os << "List of Trips:" << endl;
        for (int i = 0; i < mt.index; ++i)
        {
            os << *(mt.trips[i]) << endl;
        }
    }
    return os;
}

#endif