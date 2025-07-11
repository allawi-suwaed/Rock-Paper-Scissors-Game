#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Enum to represent the game tools: Paper, Stone, and Scissor
enum enGame_Tools
{
    Paper = 1,
    Stone = 2,
    Scissor = 3,
};

// Structure that holds string labels for possible game results
struct stResult_Tools
{
    string Player_Win = "Player";
    string Computer_Win = "Computer";
    string Draws = "[No Winner]";
};

// Structure to count wins, draws, and total rounds
struct stCount
{
    short Player_Win = 0;
    short Computer_Win = 0;
    short Draws = 0;
    short Rounds;
};

// Reads number of rounds from user (between 1 and 10)
short Read_How_Many_Round(string Message)
{
    short Number_Of_Rounds = 0;
    do
    {
        cout << Message << endl;
        cin >> Number_Of_Rounds;
    } while (Number_Of_Rounds > 10 || Number_Of_Rounds < 1);
    return Number_Of_Rounds;
}

// Reads the user's tool choice (1 to 3)
short Read_Inpur_From_User(string Message)
{
    short Input_From_User = 0;
    do
    {
        cout << Message << endl;
        cin >> Input_From_User;
    } while (Input_From_User < 1 || Input_From_User > 3);
    return Input_From_User;
}

// Generates random tool input for the computer (1 to 3)
short Input_From_Computer()
{
    short Input_From_Computer;
    Input_From_Computer = rand() % (3 - 1 + 1) + 1;
    return Input_From_Computer;
}

// Converts numeric input to enum type
enGame_Tools Convert_Input(short Input)
{
    switch(Input)
    {
        case 1:
        return Paper;
        case 2:
        return Stone;
        default:
        return Scissor;
    }
}

// Compares player and computer inputs and returns the winner
string Comprsion_Answer(short Input_From_User,short Input_From_Computer)
{
    stResult_Tools Result;

    if (Convert_Input(Input_From_User) == Paper && Convert_Input(Input_From_Computer) == Stone)
        return Result.Player_Win;
    else if (Convert_Input(Input_From_User) == Stone && Convert_Input(Input_From_Computer) == Scissor)
        return Result.Player_Win;
    else if (Convert_Input(Input_From_User) == Scissor && Convert_Input(Input_From_Computer) == Paper)
        return Result.Player_Win;
    else if (Convert_Input(Input_From_User) == Convert_Input(Input_From_Computer))
        return Result.Draws;
    else
        return Result.Computer_Win;
}

// Updates result counters based on the winner
void Count_Results(stCount &Count_Result, short Input_From_User, short Input_From_Computer)
{
    stResult_Tools Result;
    if (Comprsion_Answer(Input_From_User, Input_From_Computer) == Result.Player_Win)
        Count_Result.Player_Win++;
    else if (Comprsion_Answer(Input_From_User, Input_From_Computer) == Result.Draws)
        Count_Result.Draws++;
    else
        Count_Result.Computer_Win++;
}

// Handles the core game loop for the specified number of rounds
void Start_Round(stCount &Count_Result)
{
    short Read_From_User;
    short Read_From_Computer;
    stResult_Tools Result;
    Count_Result.Player_Win = 0;
    Count_Result.Computer_Win = 0;
    Count_Result.Draws = 0;
    Count_Result.Rounds = 0;
    Count_Result.Rounds = Read_How_Many_Round("Enter How Many Rounds 1 to 10?");
    cout << endl;
    for (short i = 0; i < Count_Result.Rounds; i++)
    {
        cout << "Round [" << i + 1 << "] is begins:" << endl;
        Read_From_User = Read_Inpur_From_User("Your Choise is [1]Paper, [2]Stone, [3]Scissor?");
        cout << "_______________Round[" << i + 1 << "]________________" << endl;
        cout << "Player Choice:" << Convert_Input(Read_From_User) << endl;
        Read_From_Computer = Input_From_Computer();
        cout << "Computer Choice:" << Convert_Input(Read_From_Computer) << endl;
        cout << "Round Winner:";
        if ((Comprsion_Answer(Read_From_User, Read_From_Computer) == Result.Player_Win))
        {
            system("color 20");
            cout << Comprsion_Answer(Read_From_User, Read_From_Computer) << endl;
        }
        else if ((Comprsion_Answer(Read_From_User, Read_From_Computer) == Result.Computer_Win))
        {
            system("color 40");
            cout << Comprsion_Answer(Read_From_User, Read_From_Computer) << endl;
        }
        else
        {
            system("color 60");
            cout << Comprsion_Answer(Read_From_User, Read_From_Computer) << endl;
        }
        cout << "______________________________________" << endl;
        Count_Results(Count_Result, Read_From_User, Read_From_Computer);
    }
}

// Determines the final winner after all rounds
string Final_Winner(stCount &Count_Result)
{
    stResult_Tools Result;
    if (Count_Result.Player_Win > Count_Result.Computer_Win)
        return Result.Player_Win;
    else if (Count_Result.Player_Win < Count_Result.Computer_Win)
        return Result.Computer_Win;
    else
        return Result.Draws;
}

// Starts the game and handles replay logic
void Start_Game()
{
    string Input;
    stCount Count_Result;
    stResult_Tools Result;
    Start_Round(Count_Result);
    cout << "         ______________________________________" << endl;
    cout << "                 + + + G A M E  O V E R + + +            " << endl;
    cout << "         ______________________________________" << endl;
    cout << "         ____________[Game Results]____________" << endl;
    cout << "         Game Rounds: " << Count_Result.Rounds << endl;
    cout << "         Player1 Won times: " << Count_Result.Player_Win << endl;
    cout << "         Computer Won times: " << Count_Result.Computer_Win << endl;
    cout << "         Draw times: " << Count_Result.Draws << endl;
    cout << "         Final Winner: "<<Final_Winner(Count_Result)<<endl;
    cout << "         ______________________________________" << endl;
    do
    {
        cout << "         Do you want to play again? Y/N?" << endl;
        cin >> Input;
    } while (!(Input == "Y" || Input == "N"));

    if (Input == "Y")
    {
        while (Input != "N")
        {
            Start_Round(Count_Result);
            cout << "         ______________________________________" << endl;
            cout << "                 + + + G A M E  O V E R + + +            " << endl;
            cout << "         ______________________________________" << endl;
            cout << "         ____________[Game Results]____________" << endl;
            cout << "         Game Rounds: " << Count_Result.Rounds << endl;
            cout << "         Player1 Won times: " << Count_Result.Player_Win << endl;
            cout << "         Computer Won times: " << Count_Result.Computer_Win << endl;
            cout << "         Draw times: " << Count_Result.Draws << endl;
            cout << "         Final Winner: "<<Final_Winner(Count_Result)<<endl;
            cout << "         ______________________________________" << endl;

            do
            {
                cout << "         Do you want to play again? Y/N?" << endl;
                cin >> Input;
            } while (!(Input == "Y" || Input == "N"));
        }
    }
}

// Main function - initializes random seed and starts the game
int main()
{
    srand((unsigned)time(NULL));
    Start_Game();
    return 0;
}