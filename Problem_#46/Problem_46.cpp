#include <iostream>

using namespace std;
// create in my abs 

float ReadNumber(string Message)
{
    float nbr;
    cout << Message ;
    cin >> nbr;
    return (nbr);
}

float MyABS(float Number)
{
    if (Number < 0)
        Number *= -1;
    return (Number);
}

int main()
{
    float Number = ReadNumber("Please  Enter your Number : ");
    cout << "My abs result : " << MyABS(Number) << endl;
    cout << "C++ abs Result : " << abs(Number) << endl;

    return (0);
}