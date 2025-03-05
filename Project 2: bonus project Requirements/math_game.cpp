#include <iostream>

using namespace std;

enum	enQuizzLevel { Easy = 1 , Mad = 2, Hard = 3, Mix = 4};

struct	stQuizz
{
	
};

void	ResetSecreen()
{
	system("clr");
	system("color 0F");
}

void	StartGameMath()
{
	char PlayAgain = 'y';

	do
	{
		ResetSecreen();
	} while (PlayAgain == 'y' || PlayAgain == 'Y');
	
}

int	main()
{
	srand((unsigned)time(NULL));

	StartGameMath();
}