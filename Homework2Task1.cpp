#include <iostream>
#include<windows.h>

using namespace std;

bool CheckFull(char board[20][40], int n, int m)
{
    bool full = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
            {
                full = false;
            }
        }
    }
    return full;
}


bool CheckWin(char board[20][40], int n, int m)
{
    bool win = false;

    //Checking ---
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'X' || board[i][j] == 'O')
            {
                if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3])
                {
                    win = true;
                    //cout << "Made a row!\n";
                }
            }
        }
    }
    //Checking |
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'X' || board[i][j] == 'O')
            {
                if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i + 2][j] == board[i + 3][j])
                {
                    win = true;
                    //cout << "Made a column!\n";
                }
            }
        }
    }
    //Checking Head Diagonal
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'X' || board[i][j] == 'O')
            {
                if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i - 2][j + 2] && board[i - 2][j + 2] == board[i - 3][j + 3])
                {
                    win = true;
                    //cout << "Made a Diagonal(\)!\n";
                }
            }
        }
    }
    //Checking Secondary Diagonal
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'X' || board[i][j] == 'O')
            {
                if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3])
                {
                    win = true;
                    //cout << "Made a Diagonal(/)!\n";
                }
            }
        }
    }
    return win;
}

void DisplayBoard(char board[20][40], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j];
            if (j < m - 1)cout << "|";
        }
        cout << "|\n";
    }
}

int main()
{
    int n = 0, m = 0;
    cout << "Set the amount of rows(max 20): ";
    while (n < 4 || n>20)
    {
        cin >> n;
        if (n < 4 || n>20)
        {
            cout << "Invlaid amount of rows! Please try again: ";
        }
    }
    cout << "Set the amount of columns(max 40): ";
    while (m < 4 || m>40)
    {
        cin >> m;
        if (m < 4 || m>40)
        {
            cout << "Invlaid amount of rows! Please try again: ";
        }
    }

    //system("CLS");//Clears the screen.

    char board[20][40] = {};
    bool win1 = false, win2 = false;
    int move1 = 0, move2 = 0;
    int turn = 1;// if=1 Player1| if=2 Player2
    bool gameEnded = false;

    //bool restart = false;
    //int mediumDothis = 0;
    //bool heWillWin = false;

    srand((unsigned)time(0));
    int a;
    int decision = 0;

    cout << "Would you like to play against another player or bot?\n 1 to play against another player, 2 to play against bot, 3 to watch bot vs bot\nYour Choice: ";
    while (decision < 1 || decision > 3)
    {
        cin >> decision;
        if (decision < 1 || decision > 3)
        {
            cout << "Invalid option! Try again: ";
        }
    }

    cout << "Okay! Please wait while the board is being prepared!\n[";
    for (int i = 0; i < 10; i++)
    {
        cout << "-";
        Sleep(200);
    }
    cout << "]\n";
    cout << "DONE!";
    Sleep(500);

    system("CLS");

    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j];
            if (j < m - 1)cout << "|";
        }
        cout << "|\n";
    }
    if (decision == 1)
    {
        while (gameEnded == false)
        {
            if (turn == 1)
            {
                do//
                {
                    cout << "Player1's turn: ";
                    cin >> move1;
                    if (((move1 > m) || (move1 < 1)) || ((board[0][move1 - 1] == 'X') || (board[0][move1 - 1] == 'O')))
                    {
                        cout << "Invalid move! Try again!!1-1\n";
                        move1 = 100;
                    }
                } while (board[0][move1 - 1] != 0 || move1 - 1 > m); // Çhecking if Player1's move is valid.
                move1 -= 1;//Decreaasing it because of the indexes.
                for (a = n; a >= 0; a--)
                {
                    if (board[a - 1][move1] == 0)
                    {
                        board[a - 1][move1] = 'X';
                        a = 0;
                    }
                }
            }
            else if (turn == 2)
            {
                do//
                {
                    cout << "Player2's turn: ";
                    cin >> move2;
                    if (((move2 > m) || (move2 < 1)) || ((board[0][move2 - 1] == 'X') || (board[0][move2 - 1] == 'O')))
                    {
                        cout << "Invalid move! Try again!!2-1\n";
                        move1 = 100;
                    }

                } while (board[0][move2 - 1] != 0 || move2 - 1 > m); // Checking if Player2's move is valid.
                move2 -= 1;//Decreaasing it because of the indexes.
                for (a = n; a >= 0; a--)
                {
                    if (board[a - 1][move2] == 0)
                    {
                        board[a - 1][move2] = 'O';
                        a = 0;
                    }
                }

            }

            system("CLS");

            DisplayBoard(board, n, m);
            if (CheckWin(board, n, m) == true)
            {
                cout << "Player" << turn << " is the winner!" << endl;
                break;
            }
            if (CheckFull(board, n, m) == true)
            {
                cout << "The game has ended with no winner!" << endl;
                break;
            }


            if (turn == 1)
            {
                turn += 1;
            }
            else if (turn == 2)
            {
                turn -= 1;
            }

        }
    }
    else if (decision == 2)//VS EASY BOT!
    {
        while (!gameEnded)
        {
            if (turn == 1)
            {
                do//
                {
                    cout << "Player's turn: ";
                    cin >> move1;
                    if (((move1 > m) || (move1 < 1)) || ((board[0][move1 - 1] == 'X') || (board[0][move1 - 1] == 'O')))
                    {
                        cout << "Invalid move! Try again!!1-1\n";
                        move1 = 100;
                    }
                } while (board[0][move1 - 1] != 0 || move1 - 1 > m); // Çhecking if Player's move is valid.
                move1 -= 1;//Decreaasing it because of the indexes.
                for (a = n; a >= 0; a--)
                {
                    if (board[a - 1][move1] == 0)
                    {
                        board[a - 1][move1] = 'X';
                        a = 0;
                    }
                }

            }
            else if (turn == 2)//EASY BOT!
            {
                do//
                {
                    move2 = rand();
                    if (((move2 > m) || (move2 < 1)) || ((board[0][move2 - 1] == 'X') || (board[0][move2 - 1] == 'O')))
                    {
                        move2 = 100;
                    }

                } while (board[0][move2 - 1] != 0 || move2 - 1 > m); // Checking if the bot's move is valid.

                cout << "Bot: Hmm... Let me think a bit...\n";
                Sleep(2000);
                cout << "Okay, I am droping at column " << move2 << "!\n";
                Sleep(1000);

                move2 -= 1;//Decreaasing it because of the indexes.
                for (a = n; a >= 0; a--)
                {
                    if (board[a - 1][move2] == 0)
                    {
                        board[a - 1][move2] = 'O';
                        a = 0;
                    }
                }

            }

            system("CLS");

            DisplayBoard(board, n, m);
            if (CheckWin(board, n, m) == true)
            {
                if (turn == 1)
                {
                    cout << "You are the winner! Congratulations!" << endl;
                    break;
                }
                if (turn == 2)
                {
                    cout << "The Bot won!" << endl;
                    break;
                }
                break;
            }
            if (CheckFull(board, n, m) == true)
            {
                cout << "The game has ended with no winner!" << endl;
                break;
            }

            if (turn == 1)
            {
                turn += 1;
            }
            else if (turn == 2)
            {
                turn -= 1;
            }
        }
    }
    else if (decision == 3)//Stupid BOT VS Stupid BOT
    {
        while (!gameEnded)
        {
            if (turn == 1)//Anthony
            {
                do//
                {
                    move1 = rand();//Doing a random move for the bot.
                    if (((move1 > m) || (move1 < 1)) || ((board[0][move1 - 1] == 'X') || (board[0][move1 - 1] == 'O')))
                    {
                        move1 = 100;
                    }

                } while (board[0][move1 - 1] != 0 || move1 - 1 > m); // Checking if the bot's move is valid.

                cout << "Joshua: Hmm... Let me think a bit...\n";
                Sleep(2000);
                cout << "Joshua: Okay, I am droping at column " << move1 << "!\n";
                Sleep(1000);

                move1 -= 1;//Decreaasing it because of the indexes.
                for (a = n; a >= 0; a--)
                {
                    if (board[a - 1][move1] == 0)
                    {
                        board[a - 1][move1] = 'X';
                        a = 0;
                    }
                }
            }
            else if (turn == 2)//KUBRAT
            {
                do//
                {
                    move2 = rand();
                    if (((move2 > m) || (move2 < 1)) || ((board[0][move2 - 1] == 'X') || (board[0][move2 - 1] == 'O')))
                    {
                        move2 = 100;
                    }

                } while (board[0][move2 - 1] != 0 || move2 - 1 > m); // Checking if the bot's move is valid.

                cout << "Pulev: Hmm... Let me think a bit...\n";
                Sleep(2000);
                cout << "Pulev: Okay, I am droping at column " << move2 << "!\n";
                Sleep(1000);

                move2 -= 1;//Decreaasing it because of the indexes.
                for (a = n; a >= 0; a--)
                {
                    if (board[a - 1][move2] == 0)
                    {
                        board[a - 1][move2] = 'O';
                        a = 0;
                    }
                }

            }

            system("CLS");

            DisplayBoard(board, n, m);
            if (CheckWin(board, n, m) == true)
            {
                if (turn == 1)
                {
                    cout << "Joshua won!" << endl;
                    break;
                }
                if (turn == 2)
                {
                    cout << "Pulev won!" << endl;
                    break;
                }
                break;
            }
            if (CheckFull(board, n, m) == true)
            {
                cout << "The game has ended with no winner!" << endl;
                break;
            }

            if (turn == 1)
            {
                turn += 1;
            }
            else if (turn == 2)
            {
                turn -= 1;
            }

        }
        //Sadly the bot still can not play as I intented in the beginning! :(
    }

    return 0;
}