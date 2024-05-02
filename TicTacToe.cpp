#include <iostream>
#include <string>
using namespace std;

void print_board(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        cout << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << endl;
        if (i < 2) {
            cout << "-+-+-" << endl;
        }
    }
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    int row = -1;
    int col = -1;
    char winner = ' ';

    for (int i = 0; i < 9; ++i) {
        print_board(board);

        if (winner != ' ') {
            break;
        }

        cout << "Current Player is Player " << currentPlayer << endl;
        while (true) {
            cout << "Enter row and column from 0 to 2 :";
            cin >> row >> col;
            if (row < 0 || row > 2 || col < 0 || col > 2) {
                cout << "Invalid input, try again." << endl;
            }
            else if (board[row][col] != ' ') {
                cout << "Tile is full, try again." << endl;
            } else {
                break;
            }

            //reset values
            row = -1;
            col = -1;
            cin.clear(); // clear error flags
            cin.ignore(10000, '\n'); //discard values
            // (skips to the next new line \n up to 1000 char) already in input stream
        }


        board[row][col] = currentPlayer;
        if (currentPlayer == playerX) {
            currentPlayer = playerO;
        } else {
            currentPlayer = playerX;
        }

        // check winners

        // rows - horizontal
        for (int r = 0; r < 3; ++r) {
            if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2]) {
                winner = board[r][0];
                break;
            }
        }

        // columns -vertical
        for (int c = 0; c < 3; ++c) {
            if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
                winner = board[0][c];
                break;
            }
        }

        // diagonal - left to right
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
        } // diagonal - right to left
        else if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
            winner = board[2][0];
        }
    }

    if (winner != ' ') {
        cout << "Player " << winner << " is the winner!" << endl;
    } else {
        cout << "TIE!" << endl;
    }

    return 0;
}