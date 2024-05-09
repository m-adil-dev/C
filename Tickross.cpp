#include <iostream>
using namespace std;
int choice;

void DisplayeTable(char d[3][3])
{
    system("cls");
    cout << "\n\t\t _______________________________________________"; // this is first line of table
    for (int i = 0; i < 3; i++)
    {
        int j = 0;
        cout << "\n\t\t|\t\t|\t\t|\t\t|";                                                        // this is empty line of the table
        cout << "\n\t\t|\t\t|\t\t|\t\t|";                                                        // this is empty line of the table
        cout << "\n\t\t|\t" << d[i][j] << "\t|\t" << d[i][++j] << "\t|\t" << d[i][++j] << "\t|"; // this is second line of the table
        cout << "\n\t\t|\t\t|\t\t|\t\t|";                                                        // this is empty line of the table
        cout << "\n\t\t|_______________|_______________|_______________|";                       // this is third line of the table
    }
};

void playerturn(char data[3][3], char &turn)
{

    int row, colum;
    if (turn == 'X')
    {
        cout << "\n\tPlayer 1 turn ( X ): ";
    }
    else if (turn == 'O')
    {
        cout << "\n\tPlayer 2 turn ( O ): ";
    }
    cin >> choice;

    while ((choice < 1) || (choice > 9))
    {
        cout << "\n\tInvalid choice please select again.";
        cin >> choice;
    }

    switch (choice)
    {
    case 1:
        colum = 0;
        row = 0;
        break;
    case 2:
        colum = 0;
        row = 1;
        break;
    case 3:
        colum = 0;
        row = 2;
        break;
    case 4:
        colum = 1;
        row = 0;
        break;
    case 5:
        colum = 1;
        row = 1;
        break;
    case 6:
        colum = 1;
        row = 2;
        break;
    case 7:
        colum = 2;
        row = 0;
        break;
    case 8:
        colum = 2;
        row = 1;
        break;
    case 9:
        colum = 2;
        row = 2;
        break;
    }

    if (turn == 'X' && data[colum][row] != 'X' && data[colum][row] != 'O')
    {
        data[colum][row] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && data[colum][row] != 'X' && data[colum][row] != 'O')
    {
        data[colum][row] = 'O';
        turn = 'X';
    }

    else
    {
        cout << "\n\tInvlid Box already filled.";
        playerturn(data, turn);
    }
};
bool gameover(char data[3][3], char turn)
{
    // check win
    for (int i = 0; i < 3; i++)
    {
        int j = 0;
        if (data[i][j] == data[i][++j] && data[i][j] == data[i][++j])
        {
            if (turn == 'O')
            {
                cout << "\n\tplayer 1( X ) won the game!";
                return false;
            }
            else if (turn == 'X')
            {
                cout << "\n\tplayer 2( O ) won the game!";
                return false;
            }
        }
    }

    for (int j = 0; j < 3; j++)
    {
        int i = 0;
        if (data[i][j] == data[i][j] && data[++i][j] == data[++i][j])
        {
            if (turn == 'O')
            {
                cout << "\n\tplayer 1( X ) won the game!";
                return false;
            }
            else if (turn == 'X')
            {
                cout << "\n\tplayer 2( O ) won the game!";
                return false;
            }
        }
    }
    if (data[0][0] == data[1][1] && data[1][1] == data[2][2])
    {
        if (turn == 'O')
            {
                cout << "\n\tplayer 1( X ) won the game!";
                return false;
            }
            else if (turn == 'X')
            {
                cout << "\n\tplayer 2( O ) won the game!";
                return false;
            }
        
    }
    if (data[0][2] == data[1][1] && data[1][1] == data[2][0])
    {
        if (turn == 'O')
            {
                cout << "\n\tplayer 1( X ) won the game!";
                return false;
            }
            else if (turn == 'X')
            {
                cout << "\n\tplayer 2( O ) won the game!";
                return false;
            }
        
    }

    // if there is no box empty;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (data[i][j] != 'X' && data[i][j] != 'O')
            {
                return true;
            }
        }
    }
    cout << "\n\tGame drow";
    return false;
}

int main()
{
    char data[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char turn = 'X';
    while (gameover(data, turn))
    {

        DisplayeTable(data);
        playerturn(data, turn);
        DisplayeTable(data);
    }

    return 0;
}
