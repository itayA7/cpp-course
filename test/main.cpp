#include <iostream>
using namespace std;
class A
{
private:
    int d;

public:
    A() { cout << 'a'; }
    ~A() { cout << 'A'; }
};
class B : public A
{
private:
    int a;

public:
    B() { cout << 'b'; }
    ~B() { cout << 'B'; }
};
int main()
{
    B b;
}