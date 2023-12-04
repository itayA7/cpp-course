#include <iostream>
using namespace std;

// סעיף א
bool IsArithmeticProgression(int *arrPoint, int size = 3)
{
  bool is_true = true;
  int d = arrPoint[1] - arrPoint[0];
  for (int i = 2; i < size; i++)
  {
    if (arrPoint[i] - arrPoint[i - 1] != d)
    {
      is_true = false;
    }
  }
  return is_true;
}

// סעיף ב
bool IsArithmeticProgression(char *arrPoint, int size = 3)
{
  bool is_true = true;
  int d = int(arrPoint[1]) - int(arrPoint[0]);
  for (int i = 2; i < size; i++)
  {
    if (int(arrPoint[i]) - int(arrPoint[i - 1]) != d)
    {
      is_true = false;
    }
  }
  return is_true;
}

int main()
{
  int *arr = NULL;
  char *arr_char = NULL;
  int arr_len = 0;
  cout << "arr len:";
  cin >> arr_len;
  if (arr_len < 3)
  {
    arr_len = 3;
  }

  /// סעיף א
  cout << "write " << arr_len << " numbers" << endl;
  arr = new int[arr_len];
  int current_num = 0;
  for (int i = 0; i < arr_len; i++)
  {
    cin >> current_num;
    arr[i] = current_num;
  }
  if (IsArithmeticProgression(arr, arr_len))
  {
    cout << "this is arithmetic series" << endl;
  }
  else
  {
    cout << "this is not arithmetic series" << endl;
  }

  /* //סעיף ב
 cout<<"write "<<arr_len<<" char"<<endl;
  arr_char=new char[arr_len];
  char current_char;
  for (int i=0;i<arr_len;i++){
    cin>>current_char;
    arr_char[i]=current_char;
  }
  if(IsArithmeticProgression(arr_char,arr_len)){
      cout<<"this is arithmetic series"<<endl;
  }
  else{
      cout<<"this is not arithmetic series"<<endl;
  }
*/

  delete[] arr;
  delete[] arr_char;
}