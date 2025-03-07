#include <iostream>

using namespace std;

enum	enQuizzLevel { Easy = 1 , Mad = 2, Hard = 3, Mix = 4};
enum	enOperations { Add = 1, Sub = 2, Mul = 3, Div = 4, Mixe = 5};

struct	stQuizz
{
	enQuizzLevel	QuestionLevel;
	enOperations	Operation;
	short			GeneratNumber1;
	short			GeneratNumber2;
};

string tabs(short HowManyTabs)
{
	string tabs;
	for (short counter = 0; counter < HowManyTabs; counter++)
		tabs += "\t";
	return tabs;
}

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
		cout << tabs(2) << "Enter OPeration Type ? " << endl;
		cout <<  "Add [1], Sub [2] , Mul [3], Mix [5] ?" << endl;
		cout << "Enter your choise : ";
		cin >> Operation;
	}while (Operation < 0 || Operation > 5);
	return ((enOperations)Operation);
}

void	ResetSecreen()
{
	system("clr");
	system("color 0F");
}



short RandomNumber(short To, short From)
{
	return (rand() % (From - To - 1) + To);
}

// short	AddOperation(short Number1, short Number2)
// {

// }
// short	SubtractionOperation()
// {

// }
// short	multiplyOperation()
// {

// }
// short	MixOpearation()
// {

// }

stQuizz	PlayGameMath(short HowManyQuestions)
{
	stQuizz QuizzInfo;

	for (short Count = 1; Count <= HowManyQuestions; Count++)
	{
		cout << "Question [" << Count << "/" << HowManyQuestions << "]" << endl;
		QuizzInfo.QuestionLevel = ReadQuestionsLevel();
		QuizzInfo.Operation = ReadOperation();
		QuizzInfo.GeneratNumber1 = RandomNumber(1, 10);
		QuizzInfo.GeneratNumber2 = RandomNumber(1, 10);
	}
	return QuizzInfo;
}

void	StartGameMath()
{
	char PlayAgain = 'y';

	do
	{
		ResetSecreen();
		stQuizz Quizz = PlayGameMath(ReadHowManyQuestions("How Many Questiond do you want to answer ?"));

		cout << tabs(0) << "Do you want to play again Y/N" << endl;
		cin >> PlayAgain;
	} while (PlayAgain == 'y' || PlayAgain == 'Y');
	
}

int	main()
{
	srand((unsigned)time(NULL));

	StartGameMath();
}