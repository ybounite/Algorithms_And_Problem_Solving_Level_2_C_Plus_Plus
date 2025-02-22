#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber(string Message)
{
    float Number;
    cout << Message ;
    cin >> Number;
    return (Number);
}
float GetFractionPart(float Number)
{
    return (Number - int(Number));
}

int MyRound(float Number)
{
    int IntPart;
    IntPart = int(Number);

    float FractionPart = GetFractionPart(Number);
    if (abs(FractionPart) >= .5)
    {
        if (Number > 0)
            return (++IntPart);
        else
            return (--IntPart);
    }
    else
        return (IntPart);
}

int main()
{
    float Number = ReadNumber("Enter your Number : ");
    cout << "My Round Result : " << MyRound(Number) << endl;
    cout << "C++ Round Result : " << round(Number) << endl;
}