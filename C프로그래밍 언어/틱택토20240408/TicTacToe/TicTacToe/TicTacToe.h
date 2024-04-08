#include <vector>
#include <iostream>

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
public:
    TicTacToe();
    void play();

private:
    char board[3][3];
    char turn;
    int count;

    void initializeBoard();
    void displayBoard();
    bool makeMove(int row, int col);
    bool checkWin();
    bool checkDraw();
};

#endif

