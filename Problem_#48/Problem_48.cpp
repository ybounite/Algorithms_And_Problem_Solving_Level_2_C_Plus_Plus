#include <iostream>
#include <cmath>
using namespace std;

float   ReadNumber(string Message)
{
    float nbr;
    cout << Message;
    cin >> nbr;
    return (nbr);
}
int MyFloor(float Number)
{
    float FractionPart = Number - int(Number); 
    if (Number < 0 && abs(FractionPart) >= .1)
        Number--;
    return(int (Number));
}

int main()
{
    float Number = ReadNumber("Please enter Number : ");
    cout << "My MYFloor Result : " << MyFloor(Number) << endl;
    cout << "C++ floor Result : " << floor(Number) << endl;
    return (0);
}