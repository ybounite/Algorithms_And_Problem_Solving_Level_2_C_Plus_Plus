#include <iostream>

using namespace std;

enum	enQuizzLevel { Easy = 1 , Mad = 2, Hard = 3, Mix = 4};
enum	enOperations { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5};

struct	stQuizz
{
	enQuizzLevel QuestionLevel;
	enOperations Operation;
};

short	ReadHowManyQuestions(string Message)
{
	short nbr;
	do
	{
		cout << Message << endl;
		cin >> nbr;
	} while (nbr < 0 && nbr < 11);
	return (nbr);
}

enQuizzLevel	ReadQuestionsLevel()
{
	short QusetionsLevel;
	do
	{
		cout << "Enter Questions Level" << endl;
		cout << "Easy [1], Med [2], Hard [3], Mix [4] ?" << endl;
		cout << "Enter your choise : ";
		cin >> QusetionsLevel;
	} while (QusetionsLevel < 0 || QusetionsLevel > 4);
	return ((enQuizzLevel)QusetionsLevel);
}

enOperations	ReadOperation()
{
	short Operation;
	do 
	{
		cout << "Enter OPeration Type : Add [1], Sub [2] , Mul [3], Mix [5] ?";
		cin >> Operation;
	}while (Operation < 0 || Operation > 5);
	return ((enOperations)Operation);
}

void	ResetSecreen()
{
	system("clr");
	system("color 0F");
}

string tabs(short HowManyTabs)
{
	string tabs;
	for (short counter = 0; counter < HowManyTabs; counter++)
		tabs += "\t";
	return tabs;
}

short RandomNumber(short To, short From)
{
	return (rand() % (From - To - 1) + To);
}

stQuizz	PlayGameMath(short HowManyQuestions)
{
	stQuizz Quizz;
	for (short Count = 0; Count < HowManyQuestions; Count++)
	{
		
	}
	return Quizz;
}

void	StartGameMath()
{
	char PlayAgain = 'y';

	do
	{
		ResetSecreen();
		stQuizz Quizz = PlayGameMath(ReadHowManyQuestions("How Many Questiond do you want to answer ?"));
		cout << tabs(4) << "Do you want to play again Y/N \n?" ;
	} while (PlayAgain == 'y' || PlayAgain == 'Y');
	
}

int	main()
{
	srand((unsigned)time(NULL));

	StartGameMath();
}