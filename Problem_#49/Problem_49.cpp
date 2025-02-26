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

int MyCeil(float Number)
{
   float fractionPart = Number - int(Number);
   if (Number > 0 && fractionPart >= 0.01)
        Number++;
    return (int(Number));
}

int main()
{
    float Number;

    Number = ReadNumber("Please Enter Number : ");
    cout << "My MyCeil Result : " << MyCeil(Number) << endl;
    cout << "C++ Ceil Result : " << ceil(Number) << endl;
    return (0);
}