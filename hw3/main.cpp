#include "Trip.h"
int MAX_ANS_LEN = 10;
int MAX_DES_LEN = 20;

bool IsEmpty(int size);
void Print(Trip *arr, int size);
void EditTrip(Trip *arr, int size);
Trip *AddTrip(Trip *arr, int size);

int main()
{
    int option;
    Trip *arr = new Trip[0];
    int size = 0;
    do
    {
        cout << "please select an option: \n1.print trips \n2.Edit \n3.Add trip \n4.exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            Print(arr, size);
            break;
        case 2:
            EditTrip(arr, size);
            break;
        case 3:
            arr = AddTrip(arr, size);
            size++;
            break;
        case 4:
            cout << "bye bye!" << endl;
            break;
        default:
            cout << "invaild option" << endl;
            break;
        }

    } while (option != 4);
}

bool IsEmpty(int size)
{
    if (size == 0)
    {
        cout << "there is no trips in the arr" << endl;
        return true;
    }
    else
        return false;
}
void Print(Trip *arr, int size)
{
    if (IsEmpty(size))
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i].PrintTrip();
        cout << endl;
    }
}
void EditTrip(Trip *arr, int size)
{
    if (IsEmpty(size) == true)
    {
        return;
    }
    cout << "write a tripId you would like to edit" << endl;
    int tripId;
    cin >> tripId;
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].getTripId() == tripId)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "no trip with this TripId found" << endl;
        return;
    }
    char *answer1 = new char[MAX_ANS_LEN];
    char *answer2 = new char[MAX_ANS_LEN];
    cout << "current destination:" << arr[index].getDestination() << " .would you like to update the destination(press y for yes or any for no)?" << endl;
    cin >> answer1;
    if (strcmp(answer1, "y") == 0)
    {
        char *des = new char[MAX_DES_LEN];
        cout << "enter trip destination:" << endl;
        cin >> des;
        arr[index].setDestination(des);
    }
    delete[] answer1;
    answer1 = nullptr;
    cout << "would you like to update the date(press y for yes or any for no) ?" << endl;
    cin >> answer2;
    if (strcmp(answer2, "y") == 0)
    {
        int day, month, year;
        cout << "enter trip date, day:" << endl;
        cin >> day;
        cout << "month" << endl;
        cin >> month;
        cout << "year:" << endl;
        cin >> year;
        Date newTripDate(day, month, year);
        arr[index].setTripDate(newTripDate);
    }
    delete[] answer2;
    answer2 = nullptr;
}
Trip *AddTrip(Trip *arr, int size)
{
    int day, month, year;
    int tripId;
    char *destination = new char[MAX_DES_LEN];
    cout << "enter trip ID:" << endl;
    cin >> tripId;
    cout << "enter trip destination:" << endl;
    cin >> destination;
    cout << "enter trip date, day:" << endl;
    cin >> day;
    cout << "month" << endl;
    cin >> month;
    cout << "year:" << endl;
    cin >> year;

    Trip *newArr = new Trip[size + 1];

    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    Date newTripDate(day, month, year);
    Trip newTrip(tripId, destination, newTripDate);
    newArr[size] = newTrip;
    return newArr;
}