#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number < 0);
    return Number;
}
int RandomNumber(int to, int from)
{
    return (rand() % (from - to + 1) + to);
}

void FillArrayWithRandomNumbers(int arr[100], int &Length)
{
    Length = ReadPositiveNumber("Enter number of elements :\n");
    for (int i = 0; i < Length; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << arr[i] << " ";
}

void addArrayElement(int Number, int arr[100], int& Length)
{
    Length++;
    arr[Length - 1] = Number;
}
void CopyOddNumber(int arrSource[100], int arrDestinatoin[100], int Length, int& oddLength)
{
    for (int i = 0; i < Length; i++)
    {
        if (arrSource[i] % 2 != 0)
            addArrayElement(arrSource[i], arrDestinatoin, oddLength);
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100], Length = 0, odd_Length = 0;

    FillArrayWithRandomNumbers(arr, Length);
    int arr2[100];
    CopyOddNumber(arr, arr2, Length, odd_Length);
    cout << "\n Array 1 elements.\n";
    PrintArray(arr, Length);
    cout << "\nArray 2 odd numbers:\n";
    PrintArray(arr2, odd_Length);
}