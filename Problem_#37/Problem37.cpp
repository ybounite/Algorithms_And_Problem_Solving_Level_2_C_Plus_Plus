#include <iostream>
using namespace std;

int ReadPositveNumber(string Message)
{

    int nbr;
    do
    {
        cout << Message;
        cin >> nbr;
    } while (nbr < 0);
    return nbr;
}

int randomNumber(int to, int from)
{
    return (rand() % (from - to + 1) + to);
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    arrLength = ReadPositveNumber("Enter number of elements :\n");
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = randomNumber(1, 100);
    }
}

void addArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void copyArrayUsingAddarrayElement(int arrSource[100], int arrDestinatoin[100], int arrLength, int &arr2Length)
{
    for (int i = 0; i < arrLength; i++)
        addArrayElement(arrSource[i], arrDestinatoin, arr2Length);

}

void PrintArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << arr[i] << " ";
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength = 0, arr2Length = 0;

    FillArrayWithRandomNumbers(arr, arrLength);
    int arr2[100];
    copyArrayUsingAddarrayElement(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements : ";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 elements after copy : ";
    PrintArray(arr2, arr2Length);
}