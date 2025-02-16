#include <iostream>
using namespace std;

// count of odd numbers

int ReadPositiveNumber(string Message)
{
    int nbr;
    do
    {
        cout << Message << endl;
        cin >> nbr;
    }while (nbr < 0);
    return (nbr);
}

int RandomNumber(int to, int from)
{
    return (rand() % (from - to - 1) + to);
}

void fullArray(int arr[100], int &length)
{
    length = ReadPositiveNumber("Enter number of element :");
    for (int i = 0; i < length; i++)
    {
        arr[i] = RandomNumber(100, 1);
    }
}

void    printArray(int arr[100], int length)
{
    cout << "Array Elements :";
    for (int i = 0; i < length; i++)
    {
        cout << " " << arr[i];
    }
}

int OddCount(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        
    }
}
int main()
{
    //Seeds the random number generator in C++, 
    srand((unsigned)time(NULL));
    int arr[100], length;
    fullArray(arr, length);
    printArray(arr, length);
    cout << "\nAdd Numbers count is :";
    cout << OddCount(arr, length) << endl;
    return (0);
}