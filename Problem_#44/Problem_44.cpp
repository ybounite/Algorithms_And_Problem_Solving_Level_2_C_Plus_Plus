#include <iostream>

using namespace std;
// Count Positive number in Array
int ReadNumber(string Message)
{
    int nbr;

    nbr = 0;
    do 
    {
        cout << Message << endl;
        cin >> nbr;
    }while (nbr < 0);
    return (nbr);
}

int RandomNumber(int To, int From)
{
    return (rand() % (From - To - 1) + To);
}

void    fullArray(int arr[100], int &Length)
{
    Length = ReadNumber("Enter Number of element : ");
    for (int i = 0; i < Length; i++)
    {
        arr[i] = RandomNumber(-100, 100);
    }
}

int PositiveCount(int arr[100], int Length)
{
    int Count;

    Count = 0;
    for (int i = 0; i < Length; i++)
    {
        if (arr[i] > 0)
            Count++;
    }
    return (Count);
}

void    PrintArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << " " << arr[i];
}

int main()
{
    // Seeds the random number geneeate in C++, called only once
    srand((unsigned)time(NULL));
    int arr[100], Length;
    fullArray(arr, Length);

    cout << "\n Array Elements :";
    PrintArray(arr, Length);
    cout << "\nPositive Numbers count is : ";
    cout << PositiveCount(arr, Length) << endl;
}