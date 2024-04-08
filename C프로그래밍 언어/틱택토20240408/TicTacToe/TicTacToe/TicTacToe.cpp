#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe() 
{
    initializeBoard();
}

void TicTacToe::play() 
{
    displayBoard();

    do {
        int row, col;
        std::cout << "Player " << turn << " (row )  : ";
        std::cin >> row;
        std::cout << "Player " << turn << " (column): ";
        std::cin >> col;
        std::cout << std::endl;

        if (makeMove(row, col)) 
        {
            displayBoard();
            if (checkWin()) 
            {
                std::cout << "Player " << turn << " wins!" << std::endl;
                return;
            }
            if (checkDraw()) 
            {
                std::cout << "Nobody wins!" << std::endl;
                return;
            }
            turn = (turn == 'X') ? 'O' : 'X';
        }
    } while (true);
}

void TicTacToe::initializeBoard() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    turn = 'X';
    count = 0;
}

void TicTacToe::displayBoard() 
{
    std::cout << "   0 1 2" << std::endl;
    std::cout << "  ------" << std::endl;
    for (int i = 0; i < 3; i++) 
    {
        std::cout << i << " |";
        for (int j = 0; j < 3; j++) {
            std::cout << " " << board[i][j];
        }
        std::cout << std::endl;
    }
}

bool TicTacToe::makeMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        std::cout << "Invalid move. Try again." << std::endl;
        return false;
    }

    board[row][col] = turn;
    count++;
    return true;
}

bool TicTacToe::checkWin() 
{
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn)
            return true;
        if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn)
            return true;
    }
    if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn)
        return true;
    if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
        return true;
    return false;
}

bool TicTacToe::checkDraw()
{
    return count == 9;
}
