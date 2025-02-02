#include <iostream>
using namespace std;

void fullArray(int arr[100], int &length)
{
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
    length = 6;
}

bool IspalindromNumber(int firstNumber, int lastNumber)
{
    return (firstNumber == lastNumber);
}

void CheckIsPalindromArray(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (!IspalindromNumber(arr[i], arr[length - i - 1]))
        {
            cout << "\nNO array is NO Palindrom\n";
                return ;
        }
    }
    cout << "\nYES array is Palindrom\n";
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
    int arr1[100];
    int length1;

    length1 = 0;
    fullArray(arr1, length1);
    cout << "\nArray Elements:\n";
    PrintArray(arr1, length1);
    CheckIsPalindromArray(arr1, length1);
}
