#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharater = 3, Digit = 4 };
int ReadposetiveNumber(string Messsage);
char GetRandomCharacter(enCharType type);
int RandomNumber(int to, int from);
void FullArrayWithkeys(string arr[100], int length);
string GenerateWord(enCharType type, short length);
void printStringArrys(string arry[100], int length);
string GeneratKeys(short nbr);



int ReadposetiveNumber(string Messsage)
{
	int nbr;

	do
	{
		cout << Messsage;
		cin >> nbr;
	}while (nbr < 0);
	return nbr;
}
int RandomNumber(int to, int from)
{
	return (rand() % (from - to +1) + to);
}
char GetRandomCharacter(enCharType type)
{
	switch (type)
	{
		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));
		case enCharType::SpecialCharater:
			return char(RandomNumber(33, 47));
		case enCharType::Digit:
			return char(RandomNumber(48, 57));
		default:
			return char(RandomNumber(48, 57));
	}
}
void FullArrayWithkeys(string arr[100], int length)
{
	for (int i = 0; i < length; i++)
		arr[i] = GeneratKeys(4);
}

string GenerateWord(enCharType type, short length)
{
	string Word;

	for (int i = 0; i < length; i++)
		Word += GetRandomCharacter(type);
	return Word;
}
string GeneratKeys(short nbr)
{
		string key = "";

	for (int i = 0; i < nbr; i++)
	{
		if (i > 1)
			key += "-";
		key += GenerateWord(enCharType::CapitalLetter, nbr);
	}
	return key;
}
void printStringArrys(string arry[100], int length)
{
	cout << "\n Array elemnts :\n\n";
	for (int i = 0; i < length; i++)
	{
		cout << "Arry["<< i+1 <<"] : ";
		cout << arry[i] << endl;
	}
	cout << endl;
}
int main()
{
	srand((unsigned)time(NULL));
	string arry[100];
	int length = 0;

	length = ReadposetiveNumber("How to many keys to want to generate?\n");

	FullArrayWithkeys(arry, length);
	printStringArrys(arry, length);
}
