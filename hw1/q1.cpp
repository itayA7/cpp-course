#include <iostream>
using namespace std;
double weightedAverage(double weiarr[], double valArr[], int size);
int main()
{
    int arr_len = 4;
    double arr1[] = {0.2, 0.3, 0.4, 0.5};
    double arr2[] = {2, 3, 4, 5};
    cout << "the average is: " << weightedAverage(arr1, arr2, arr_len)<<endl;
    return 0;
}

double weightedAverage(double weighArr[], double valArr[], int size)
{
    double sum = 0;
    double weighsum = 0;
    double avg = 0;
    for (int i = 0; i < size; i++)
    {
    	sum+=weighArr[i]*valArr[i];
        weighsum+=weighArr[i];
    }
    avg = sum / weighsum;
    return avg;
}