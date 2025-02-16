#include <iostream>

using namespace std;

int ReadPositveNuber(string Message)
{
    int nbr;

    nbr = 0;
    do
    {
        cout << Message << endl;
        cin >> nbr;
    } while (nbr < 0);
    return (nbr);
}

int RandomNumber(int To, int From)
{
    return (rand() % (From - To - 1) + To);
}

void    fullArrays(int arr[100], int &arrlength)
{
    arrlength = ReadPositveNuber("Enter number of elements: ");
    for (int i = 0; i < arrlength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

int EvenCount(int arr[100], int Length)
{
    int Count;

    Count = 0;
    for (int i = 0; i < Length; i++)
    {
        if (arr[i] % 2 == 0)
            Count++;
    }
    return (Count);
}

void    PrintArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        cout << " " << arr[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], Length;
    fullArrays(arr, Length);
    
    cout << "\nArray Elements : ";
    PrintArray(arr, Length);

    cout << "\nEven Number count is : ";
    cout << EvenCount(arr, Length) << endl;
}
