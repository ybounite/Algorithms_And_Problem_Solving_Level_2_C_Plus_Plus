// #include <iostream>

// using namespace std;

// enum	enQuizzLevel { Easy = 1 , Mad = 2, Hard = 3, Mix = 4};
// enum	enOperations { Add = 1, Sub = 2, Mul = 3, Div = 4, Mixe = 5};

// struct	stQuizz
// {
// 	enQuizzLevel	QuestionLevel;
// 	enOperations	Operation;
// 	short			GeneratNumber1;
// 	short			GeneratNumber2;
// };

// string tabs(short HowManyTabs)
// {
// 	string tabs;
// 	for (short counter = 0; counter < HowManyTabs; counter++)
// 		tabs += "\t";
// 	return tabs;
// }

// short	ReadHowManyQuestions(string Message)
// {
// 	short nbr;
// 	do
// 	{
// 		cout << Message << endl;
// 		cin >> nbr;
// 	} while (nbr < 0 && nbr < 11);
// 	return (nbr);
// }

// enQuizzLevel	ReadQuestionsLevel()
// {
// 	short QusetionsLevel;
// 	do
// 	{
// 		cout << "Enter Questions Level" << endl;
// 		cout << "Easy [1], Med [2], Hard [3], Mix [4] ?" << endl;
// 		cout << "Enter your choise : ";
// 		cin >> QusetionsLevel;
// 	} while (QusetionsLevel < 0 || QusetionsLevel > 4);
// 	return ((enQuizzLevel)QusetionsLevel);
// }

// enOperations	ReadOperation()
// {
// 	short Operation;
// 	do 
// 	{
// 		cout << tabs(2) << "Enter OPeration Type ? " << endl;
// 		cout <<  "Add [1], Sub [2] , Mul [3], Mix [5] ?" << endl;
// 		cout << "Enter your choise : ";
// 		cin >> Operation;
// 	}while (Operation < 0 || Operation > 5);
// 	return ((enOperations)Operation);
// }

// void	ResetSecreen()
// {
// 	system("clr");
// 	system("color 0F");
// }



// short RandomNumber(short To, short From)
// {
// 	return (rand() % (From - To - 1) + To);
// }

// // short	AddOperation(short Number1, short Number2)
// // {

// // }
// // short	SubtractionOperation()
// // {

// // }
// // short	multiplyOperation()
// // {

// // }
// // short	multiplyOpearation()
// // {

// // }
// // short	MixOpearation()
// // {

// // }

// stQuizz	PlayGameMath(short HowManyQuestions)
// {
// 	stQuizz QuizzInfo;

// 	for (short Count = 1; Count <= HowManyQuestions; Count++)
// 	{
// 		cout << "Question [" << Count << "/" << HowManyQuestions << "]" << endl;
// 		QuizzInfo.QuestionLevel = ReadQuestionsLevel();
// 		QuizzInfo.Operation = ReadOperation();
// 		QuizzInfo.GeneratNumber1 = RandomNumber(1, 10);
// 		QuizzInfo.GeneratNumber2 = RandomNumber(1, 10);
// 	}
// 	return QuizzInfo;
// }

// void	StartGameMath()
// {
// 	char PlayAgain = 'y';

// 	do
// 	{
// 		ResetSecreen();
// 		stQuizz Quizz = PlayGameMath(ReadHowManyQuestions("How Many Questiond do you want to answer ?"));
		
// 		cout << tabs(0) << "Do you want to play again Y/N" << endl;
// 		cin >> PlayAgain;
// 	} while (PlayAgain == 'y' || PlayAgain == 'Y');
// }

// int	main()
// {
// 	srand((unsigned)time(NULL));

// 	StartGameMath();
// }
#include <iostream>
using namespace std;

enum enOperationType { Add = 1, sub = 2, Mul = 3, Div  = 4, MIX = 5 };
enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4};

struct stQuizz
{
	enQuestionLevel LeveQuestion;
	enOperationType OperationType;
	short			Number1;
	short			Number2;
	short			Answer;
	short			Result;
	char			CharOperationType;
};

short	ReadHowManyQuestions()
{
	short NumberQuestion;
	do
	{
		cout << "How Many Questions do you want to answer ?" << endl;
		cin >> NumberQuestion;
	} while (NumberQuestion < 0 || NumberQuestion > 10);
	return NumberQuestion;
}

enQuestionLevel	ReadQuestionLevel()
{
	short QuestionLevel;
	do
	{
		cout << "Enter Question Level Easy : [1], Med : [2], Hard : [3],  Mix : [4] ?" << endl;
		cin >> QuestionLevel;
	} while (QuestionLevel < 0 || QuestionLevel > 4);
	return (enQuestionLevel)QuestionLevel;
}

enOperationType	ReadOperationType()
{
	short	OperationType;
	do
	{
		cout << "Enter Operation Type ?" << endl;
		cout << "Add : [1], Sub : [2], Mul [3], Div : [4], MIX : [5] ?" << endl;
		cin >> OperationType;
	} while (OperationType < 0 || OperationType > 5);
	return (enOperationType)OperationType;
}

short	RandomNumber(short to, short from)
{
	return (rand() % (from - to + 1) + to);
}

// short OperationAdd(short Number1, short Number2)
// {
	
// }

void	HeaderOperation(stQuizz Quizz)
{
	cout << "  " << Quizz.Number1 << endl;
	cout << "  " << Quizz.Number2 << "  " << Quizz.CharOperationType;
	cout << endl << "------------------------" << endl;
	//cout << "  " << Quizz.Result;
}

short	ReadTheAnswer()
{
	short Answer;
	cin >> Answer;
	return Answer;
}

stQuizz	PlayGameMath(short HowManyQuestions)
{
	stQuizz Quizz;
	Quizz.LeveQuestion = ReadQuestionLevel();
	Quizz.OperationType = ReadOperationType();
	for (int counter = 0; counter < HowManyQuestions; counter++)
	{
		cout << "Question [" << counter + 1 << "]" << endl;
		Quizz.Number1 = RandomNumber(1, 10);
		Quizz.Number2 = RandomNumber(1, 10);
		HeaderOperation(Quizz);
		Quizz.Answer = ReadTheAnswer();
	}
	return Quizz;
}

void	RestartScren()
{
	system("color 0F");
}

void	StartGame()
{
	stQuizz	Quizz;
	char PlayAgaine = 'y';
	do
	{
		RestartScren();
		Quizz = PlayGameMath(ReadHowManyQuestions());
		cout << "Do you Want to Play Againe Y/N?";
		cin >> PlayAgaine;
	} while (PlayAgaine == 'Y' || PlayAgaine == 'y');
}
int main()
{
	srand((unsigned)time(NULL));
	StartGame();
}

