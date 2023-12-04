#include "ManagmentTrips.h"

void deleteTrips(ManagementTrips *mts);
void AddTrip(ManagementTrips *mts);

int main()
{
    ManagementTrips mts;
    cout << "counter is:" << Trip::counter << endl;
    int option;
    do
    {
        cout << "Please Select an option: \n1. Print Trips \n2. Delete Trips \n3. Add Trip\n4. Exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << mts; // Using the operator<< defined in ManagementTrips
            break;
        case 2:
            deleteTrips(&mts);
            break;
        case 3:
            AddTrip(&mts);
            break;
        case 4:
            cout << "bye bye!" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    } while (option != 4);

    return 0;
}

void deleteTrips(ManagementTrips *mts)
{
    int day, month, year;
    cout << "Enter a date to delete trips : ";
    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;
    Date newTripDate(day, month, year);
    *mts -= newTripDate;
}

void AddTrip(ManagementTrips *mts)
{
    int day, month, year;
    cout << "Enter trip details:" << endl;
    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;
    Date newTripDate(day, month, year);
    char destination[20];
    cout << "Destination: ";
    cin.ignore();
    cin.getline(destination, 20);
    Trip newTrip(destination, newTripDate);
    *mts += newTrip;
}