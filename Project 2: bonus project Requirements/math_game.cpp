#include <iostream>
using namespace std;

enum enOperationType { Add = 1, sub = 2, Mul = 3, Div = 4, MIX = 5 };
enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enGameAnswer { AnswerError = 0, RightAnswer = 1 };

struct stQuizz
{
	enQuestionLevel LeveQuestion;
	enOperationType OperationType;
	enGameAnswer	IstrueAnswer;
	short			RightAnswer;
	short			WrongAnswer;
	short			NumberOfQuestion;
	short			Number1;
	short			Number2;
	short			Answer;
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
		cout << "Enter Operation Type ";
		cout << "Add : [1], Sub : [2], Mul [3], Div : [4], MIX : [5] ?" << endl;
		cin >> OperationType;
	} while (OperationType < 0 || OperationType > 5);
	return (enOperationType)OperationType;
}

short	ReadTheAnswer()
{
	short Answer;
	cin >> Answer;
	return Answer;
}

short	RandomNumber(short to, short from)
{
	return (rand() % (from - to + 1) + to);
}

void	HeaderOperation(stQuizz Quizz)
{
	cout << "  " << Quizz.Number1 << endl;
	cout << "  " << Quizz.Number2 << "  " << Quizz.CharOperationType;
	cout << endl << "------------------------" << endl;
	//cout << "  " << Quizz.Result;
}

bool	CheckAnswerIstrue(short Answerture, short UserAnswer)
{
	return (Answerture == UserAnswer);
}

void	SetWinnerScreenColor(enGameAnswer Answer)
{
	switch (Answer)
	{
	case  enGameAnswer::RightAnswer:
		system("color 2F"); // turn screen to Green
		break;
	case enGameAnswer::AnswerError:
		system("color 4F"); // turn screen to Red
		cout << "\a";
		break;
	default:
		system("color 6F"); //turn screen to Yellow
		break;
	}
}

void	PrintAnswer(enGameAnswer Answer, short AnswerTure)
{

	switch (Answer)
	{
	case enGameAnswer::RightAnswer:
		cout << "Right Answer :-) " << endl;
		break;
	default:
		cout << "Wrong Answer :-( " << endl;
		cout << "The right answer is " << AnswerTure << endl;
		break;
	}
}

short	ReturnAnswerTrue(short Number1, short Number2, char OperationType)
{
	short	Result = 0;
	switch (OperationType)
	{
	case '+':
		Result = Number1 + Number2;
		break;
	case '-':
		Result = Number1 - Number2;
		break;
	case '*':
		Result = Number1 * Number2;
		break;
	case '/':
		Result = Number1 / Number2;
		break;
	}
	return Result;
}

char	CharOperationType(enOperationType Operation)
{
	char OperationType;
	if (Operation == enOperationType::MIX)
		Operation = (enOperationType)RandomNumber(1, 4);
	switch (Operation)
	{
	case enOperationType::Add:
		OperationType = '+';
		break;
	case enOperationType::sub:
		OperationType = '-';
		break;
	case enOperationType::Mul:
		OperationType = '*';
		break;
	case enOperationType::Div:
		OperationType = '/';
		break;
	}
	return OperationType;
}

void	ControlLevelQuestion(stQuizz &Quizz)
{
	enQuestionLevel Question = Quizz.LeveQuestion;
	if (Question == enQuestionLevel::Mix)
		Question = (enQuestionLevel)RandomNumber(1, 3);
	switch (Question)
	{
	case enQuestionLevel::Easy:
		cout << "Easy \n";
		Quizz.Number2 = RandomNumber(1, 10);
		Quizz.Number1 = RandomNumber(1, 10);
		break;
	case enQuestionLevel::Med:
		cout << "Med \n";
		Quizz.Number2 = RandomNumber(1, 50);
		Quizz.Number1 = RandomNumber(1, 50);
		break;
	case enQuestionLevel::Hard:
		cout << "Hard \n";
		Quizz.Number2 = RandomNumber(1, 100);
		Quizz.Number1 = RandomNumber(1, 100);
		break;
	}
}

stQuizz	PlayGameMath(short HowManyQuestions)
{
	stQuizz Quizz;
	short	AnswerTure = 0;
	short	RightAnswer = 0;
	short	wrongAnswer = 0;
	Quizz.LeveQuestion = ReadQuestionLevel();
	Quizz.OperationType = ReadOperationType();
	for (int counter = 0; counter < HowManyQuestions; counter++)
	{
		cout << "Question [" << counter + 1 << "/" << HowManyQuestions << "]" << endl << endl;
		ControlLevelQuestion(Quizz);
		Quizz.CharOperationType = CharOperationType(Quizz.OperationType);
		AnswerTure = ReturnAnswerTrue(Quizz.Number1, Quizz.Number2, Quizz.CharOperationType);
		HeaderOperation(Quizz);
		Quizz.Answer = ReadTheAnswer();
		Quizz.IstrueAnswer = (enGameAnswer)CheckAnswerIstrue(AnswerTure, Quizz.Answer);
		PrintAnswer(Quizz.IstrueAnswer, AnswerTure);
		SetWinnerScreenColor(Quizz.IstrueAnswer);
		if (Quizz.IstrueAnswer)
			RightAnswer++;
		else
			wrongAnswer++;
	}
	Quizz.NumberOfQuestion = HowManyQuestions;
	Quizz.RightAnswer = RightAnswer;
	Quizz.WrongAnswer = wrongAnswer;
	return Quizz;
}

void	RestartScren()
{
	system("cls");
	system("color 0F");
}

string	StrQuestionLevel(enQuestionLevel QuestionLevel)
{
	string	strLevelQuestion;
	switch (QuestionLevel)
	{
	case Easy:
		strLevelQuestion = "Easy";
		break;
	case Med:
		strLevelQuestion = "Med";
		break;
	case Hard:
		strLevelQuestion = "Hard";
		break;
	case Mix:
		strLevelQuestion = "Mix";
		break;
	}
	return strLevelQuestion;
}

string	StrOperationType(enOperationType Type)
{
	string OperationType;
	switch (Type)
	{
	case Add:
		OperationType = "Add";
		break;
	case sub:
		OperationType = "Sub";
		break;
	case Mul:
		OperationType = "Mul";
		break;
	case Div:
		OperationType = "Div";
		break;
	case MIX:
		OperationType = "Mix";
		break;
	}
	return OperationType;
}

void	FinalResult(short	RightAnswer, short WrongAnswer)
{
	cout << "-----------------------------------------" << endl;
	if (RightAnswer >= WrongAnswer)
	{
		cout << "	Final Result is Right Answer :-)" << endl;
		SetWinnerScreenColor(enGameAnswer::RightAnswer);
	}
	else
	{
		cout << "	Final Result is Fail :-(" << endl;
		SetWinnerScreenColor(enGameAnswer::AnswerError);
	}
	cout << "-----------------------------------------\n" << endl;
}

void	ShowFinalResult(stQuizz Quizz)
{
	FinalResult(Quizz.RightAnswer, Quizz.WrongAnswer);
	cout << "------------------------------------------------" << endl;
	cout << "Number Of Question : " << Quizz.NumberOfQuestion << endl;
	cout << "Question Level		: " << StrQuestionLevel(Quizz.LeveQuestion) << endl;
	cout << "Operation Type		: " << StrOperationType(Quizz.OperationType) << endl;
	cout << "Number Of Right Answer: " << Quizz.RightAnswer << endl;
	cout << "Number Of Wrong Answer: " << Quizz.WrongAnswer << endl;
	cout << "------------------------------------------------" << endl;
}

void	StartGame()
{
	stQuizz	Quizz;
	char PlayAgain = 'y';
	do
	{
		RestartScren();
		Quizz = PlayGameMath(ReadHowManyQuestions());
		ShowFinalResult(Quizz);
		cout << "Do you Want to Play Again Y/N?";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();
}
