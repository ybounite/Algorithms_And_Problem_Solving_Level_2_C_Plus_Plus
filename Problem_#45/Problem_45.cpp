#include <iostream>

using namespace std;
// Count Negative Numbers in Array
int ReadNumber(string Message)
{
    int nbr;

    nbr = 0;
    do
    {
        cout << Message;
        cin >> nbr;
    } while (nbr < 0);
    return (nbr);
}

int RandomNumber(int To, int From)
{
    return (rand() % (From - To - 1) + To);
}

void    fullArray(int arr[100], int &Length)
{
    Length = ReadNumber("Enter element number : ");
    for (int i = 0; i < Length; i++)
        arr[i] = RandomNumber(-100, 100);
}

void    PrintArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << " " << arr[i];
}

int NegativeCount(int arr[100], int Length)
{
    int Count;

    Count = 0;
    for (int i = 0; i < Length; i++)
    {
        if (arr[i] < 0)
            Count++;
    }
    return (Count);
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], Length;
    fullArray(arr, Length);

    cout << "\nArray Elements : ";
    PrintArray(arr, Length);

    cout << "\nNegative number count is : ";
    cout << NegativeCount(arr, Length) << endl;;
    return (0);
}
