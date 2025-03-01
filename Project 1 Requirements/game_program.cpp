#include <iostream>
#include <string>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissor = 3 };
enum enWinner { Draw = 0, Player = 1, Computer = 2 };

struct stGameResults
{
    short GameRound = 0;
    short PlayerWinTimes = 0;// win player 
    short ComputerWinTimes = 0;//winner coumpter
    short DrawTimes; // equal
    enWinner GameWinner;
    string WinnerName = "";//winner name of all gime
};

struct stRoundInfo
{
    short           RoundNumber = 0;
    enGameChoice    PlayerChoce;
    enGameChoice    ComputerChoise;
    enWinner        Winner;
    string          WinnerName;
};

void StartGame();

short ReadHownamyRound(string Message)
{
    short GameRounds;
    do
    {
        cout << Message << endl;
        cin >> GameRounds;
    } while (GameRounds < 1 || GameRounds > 10);

    return (GameRounds);
}

int RandomNumber(int to, int from)
{
	return (rand() % (from - to + 1) + to);
}

short ReadChoise(string Message)
{
    short choise = 1;
    do
    {
        cout << Message;
        cin >> choise;
    } while (choise < 1 || choise > 3);
    return choise;
}

enGameChoice ReadPlayerChoise()
{
    short check = 0;
    cout << "\n         what is your choise" << endl;
    cout << "STONE : [1] OR PAPER : [2] OR SCISSER : [3]?" << endl;
    check = ReadChoise("ENTER : ");
    return ((enGameChoice)check);
}

string  ChoiceName(enGameChoice ChoiceName)
{
    if (ChoiceName == enGameChoice::Stone)
        return ("Stone");
    else if (ChoiceName == enGameChoice::Paper)
        return ("Paper");
    else
        return ("Scissor");
}

void PrintRoundResult(stRoundInfo DataGame)
{
    cout << "-------------------Round [" << DataGame.RoundNumber << "]----------------"<< endl;
    cout << "Player Choice   : " << ChoiceName(DataGame.PlayerChoce) <<  endl;
    cout << "Computer Choice : " <<  ChoiceName(DataGame.ComputerChoise) << endl;
    cout << "RoundWinner     : [" << DataGame.WinnerName << "]" << endl;
    cout << "--------------------------------------------" << endl;
}

void SetWinnerScreenColor(enWinner GameWinner)
{
    switch (GameWinner)
    {
    case  enWinner::Player:
        system("color 2F"); // turn screen to Green
        break;
    case enWinner::Computer:
        system("color 4F"); // turn screen to Red
        cout << "\a";
    default:
        system("color 6F"); //turn screen to Yellow
        break;
    }
}

void ShowFinalGameResult(stGameResults DataGame)
{
    cout << "\n          _______________________[ Game Results ]____________________" << endl;
    cout << "           Game Rounds      : " << DataGame.GameRound << endl;
    cout << "           Player1 won  time: " << DataGame.PlayerWinTimes << endl;
    cout << "           Computer won time: " << DataGame.ComputerWinTimes << endl;
    cout << "           Draw time        : " << DataGame.DrawTimes << endl; 
    cout << "           Final Winner     : " << DataGame.WinnerName << endl;
    cout << "_______________________________________________________________________\n" << endl;
    SetWinnerScreenColor(DataGame.GameWinner);
}

enGameChoice    GetComputerChoise()
{
    return ((enGameChoice)RandomNumber(1, 3));
}

enWinner    WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.PlayerChoce == RoundInfo.ComputerChoise)
        return (enWinner::Draw);
    switch (RoundInfo.PlayerChoce)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoise == enGameChoice::Paper)
            return (enWinner::Computer);
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoise == enGameChoice::Scissor)
            return (enWinner::Computer);
        break;
    case enGameChoice::Scissor:
        if (RoundInfo.ComputerChoise == enGameChoice::Stone)
            return (enWinner::Computer);
        break;   
    }
    return (enWinner::Player);
}

string  WinnerName(enWinner Winner)
{
    string ArrWinnerName[3] = {"Draw", "Player", "Computer"};
    return (ArrWinnerName[Winner]);
}

void    ResetScreen()
{
    // clear in Secreen ?
    // and return in Secreen black ?
    system("cls");
    system("color 0F");
}

enWinner    WhoWonTheGame(short PlayerWinTime, short ComputerWinTime)
{
    if (PlayerWinTime > ComputerWinTime)
        return enWinner::Player;
    else if (PlayerWinTime< ComputerWinTime)
        return enWinner::Computer;
    return enWinner::Draw;
}

stGameResults   FillGameResult(short GameRound, short PlayWinTime, short ComputerWintime, short DrawTime)
{
    stGameResults   GameResults;
    GameResults.GameRound = GameRound;
    GameResults.PlayerWinTimes = PlayWinTime;
    GameResults.ComputerWinTimes = ComputerWintime;
    GameResults.DrawTimes = DrawTime;
    GameResults.GameWinner = WhoWonTheGame(PlayWinTime, ComputerWintime);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);

    return (GameResults);
}

stGameResults   PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    
    short   PlayWinTime = 0, ComputerWintime = 0, DrawTime = 0;
    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\n Round [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.PlayerChoce = ReadPlayerChoise();
        RoundInfo.ComputerChoise = GetComputerChoise();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
        
        // Increase win/Drae Counters
        if (RoundInfo.Winner == enWinner::Player)
            PlayWinTime++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWintime++;
        else
            DrawTime++;
        PrintRoundResult(RoundInfo);
    }
    return (FillGameResult(HowManyRounds, PlayWinTime, ComputerWintime, DrawTime));
}

void    ShowGameOverScreen()
{
    cout << "_____________________________________________________________________" << endl;
    cout << "                              +++ G a m e  O v e r +++" << endl;
    cout << "_____________________________________________________________________" << endl;

}

void    StartGame()
{
    char    PlayAgain = 'y';

    do
    {
        ResetScreen();
        stGameResults DataGame = PlayGame(ReadHownamyRound("How Many Rounds 1 to 10 ?"));
        ShowGameOverScreen();//print in gime over
        ShowFinalGameResult(DataGame);//print final result of game ?

        cout << endl << "           Do you want to play again ? Y/N";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();
}
