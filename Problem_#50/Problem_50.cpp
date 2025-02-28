#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber(string Message)
{
    float Number;
    cout << Message << endl;
    cin >> Number;
    return (Number);
}

float    MySqrt(float Number)
{
    return (pow(Number, 0.5));
}

int main()
{
    int Number = ReadNumber("Please enter Number : ");
    cout << "My Sqrt Result : " << MySqrt(Number) << endl;
    cout << "C++ sqrt Result : " << sqrt(Number) << endl;
}
