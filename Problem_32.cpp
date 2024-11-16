#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int RandomNumbers(int to, int From)
{
    return (rand() % (From - to + 1) + to);
}
void FullArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "Enter number of elements:\n";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumbers(1, 100);
    }
}
void CopyArrayInReversedOrder(int arr[100], int arr2[100], int Length)
{
    int size = Length - 1;
    for (int i = 0; i < Length; i++)
    {
        arr2[i] = arr[size];
        size--;
    }
}
void PrintArrays(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        cout << " " << arr[i];
    }
}
int main()
{
    // Seeds the random number generator in C++ , called only once
    srand((unsigned)time(NULL));
    int arr[100], Length;

    FullArrayWithRandomNumbers(arr, Length);

    int arr2[100];
    cout << "\nArray 1 elements :\n";
    PrintArrays(arr, Length);
    cout << endl;

    CopyArrayInReversedOrder(arr, arr2, Length);
    cout << "Array 2 elements after copying array 1 in reversed order:\n";
    PrintArrays(arr2, Length);
    cout << endl;
}
