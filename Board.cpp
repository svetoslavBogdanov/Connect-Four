#include "Board.h"
#include <iostream>

Board::Board(int height, int width) : height(height), width(width)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

void Board::print() const
{
    std::cout << "\n\t\tPlayer 1: @\n\t\tPlayer 2: #\n\n";
    // std::cout << "\t\tturns: " << turns++;
    std::cout << "\n\n\n\n";

    std::cout << "\t\t";
    for (int j = 0; j < 2*width + 1; ++j)
        std::cout << "_";

    std::cout << "\n";
    for (int i = 0; i < height; ++i)
    {
        std::cout << "\t\t|";
        for (int j = 0; j < width; ++j)
        {
            std::cout << board[i][j] << "|";
        }
        std::cout << "\n";
    }
    std::cout << "\t\t";

    for (int j = 0; j < 2*width + 1; ++j)
        std::cout << "-";
}

void Board::update(int column)
{
    lastColumn = column;

    board[lastRow][lastColumn] = (!turn ? '@' : '#');
    turn = (turn + 1) % 2;
}

bool Board::win() const
{
    int count = 0;

    const char check[2] = { '@', '#' };

    // horizontal
    for (int i = lastColumn - 3; i <= lastColumn + 3; ++i)
    {
        if (i >= 0 || i < width)
        {
            if (board[lastRow][i] == check[turn])
                ++count;
            else
                count = 0;
        }
        if (count == 4)
        {
            std::cout << "\n\t\tPlayer " << turn + 1 << " wins.\n\n";
            return true;
        }
    }

    // 1st diagonal

    // 2nd diagonal

    // vertical

    return false;
}