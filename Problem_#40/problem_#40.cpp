#include <iostream>

using namespace std;
void FillArray(int arr[100], int &arrLength)
{
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = -1;
    arr[6] = 60;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 70;
    arrLength = 10;
}
void addArrNumber(int Number, int arr[100], int &Length)
{
	Length++;
	arr[Length - 1] = Number;
}
int IsNumberInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (Number == arr[i])
            return (1);
    }
    return (0);
}
void CpyDistictNumber(int arrsourc[100], int arrDestinatoin[100], int arr1Length, int &length2)
{
	for (int i = 0; i < arr1Length; i++)
	{
		if (!IsNumberInArray(arrsourc[i], arrDestinatoin, length2))
			addArrNumber(arrsourc[i], arrDestinatoin, length2);
	}
}

void PrintArray(int arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
    int arr1[100], arr2[100];
    int lenght1 = 0, lenght2 = 0;
    FillArray(arr1, lenght1);
    CpyDistictNumber(arr1, arr2, lenght1, lenght2);
    cout << "Array 1 elements :\n";
    PrintArray(arr1, lenght1);
    cout << "\nArray 2 distinct elements:\n";
    PrintArray(arr2, lenght2);
}