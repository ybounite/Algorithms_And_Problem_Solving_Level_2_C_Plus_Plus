#include <iostream>
#include <math.h>
using namespace std;

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

enPrimNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);
	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
		return enPrimNotPrime::NotPrime;
	}
	return enPrimNotPrime::Prime;
}
int ReadPositiveNumber(string Message)
{
	int nbr;
	do
	{
		cout << Message;
		cin >> nbr;
	} while (nbr <= 0);
	return nbr;
}

int RandomNumber(int to, int from)
{
	return (rand() % (from - to + 1) + to);
}

void PrintArray(int arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void addArrNumber(int Number, int arr[100], int &Length)
{
	Length++;
	arr[Length - 1] = Number;
}

void CpyPrimeNumber(int arrsourc[100], int arrDestinatoin[100], int arr1Length, int &length2)
{
	for (int i = 0; i < arr1Length; i++)
	{
		if (CheckPrime(arrsourc[i]) == enPrimNotPrime::Prime)
			addArrNumber(arrsourc[i], arrDestinatoin, length2);
	}
}

void Fill_Array_With_Random_Numbers(int arr[100], int &Length)
{
	Length = ReadPositiveNumber("Enter number of elements :\n");
	for (int i = 0; i < Length; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

int main()
{
	srand((unsigned)(time(NULL)));
	int arr1[100], arr1Length = 0, arr2Length = 0;
	int arr2[100];

	Fill_Array_With_Random_Numbers(arr1, arr1Length);
	CpyPrimeNumber(arr1, arr2, arr1Length, arr2Length);

	cout << "\nArray 1 Elements : \n";
	PrintArray(arr1, arr1Length);

	cout << "\nArray 2 prime number :\n";
	PrintArray(arr2, arr2Length);
}