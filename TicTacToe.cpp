#include "TicTacToe.h"
#include <string>
#include <iostream>

int playGame()
{
    std::cout << "Player A is 0" << std::endl;
    std::cout << "Player B is 1" << std::endl;
    std::cout << "Moves are made through numbers where position 1 represents a move on the top left corner, 9 represents a move on the bottom right corner, 5 represents a move on the centre block and etc as shown below:\n";
    std::cout << "1|2|3\n-+-+-\n4|5|6\n-+-+-\n7|8|9\n\n";

    std::cout << "GAME START NOW:" << std::endl;
    std::string board = generateEmptyBoard();

    int turnCount = 1;

    while (!gameOver(board))
    {
        std::cout << "Turn: " << turnCount << std::endl;
        int position = -1;
        char symbol = ' ';
        while (isInValidMove(board, position))
        {
            if (isPlayerATurn(turnCount))
            {
                symbol = '0';
            }
            else if (isPlayerBTurn(turnCount))
            {
                symbol = '1';
            };
            position = askPlayerForPosition(board, symbol);
            if (isInValidMove(board, position))
            {
                std::cout << "The provided position, " << position << ", is invalid for board: " << std::endl;
                std::cout << prettyPrint(board) << std::endl;
            }
        }
        board = makeMove(board, position, symbol);
        turnCount++;
    }

    if (isAWinner(board))
    {
        std::cout << prettyPrint(board) << std::endl;
        std::cout << "Player A is the winner" << std::endl;
        return 0;
    }
    else if (isBWinner(board))
    {
        std::cout << prettyPrint(board) << std::endl;
        std::cout << "Player B is the winner" << std::endl;
        return 1;
    }
    else if (boardFull(board))
    {
        std::cout << prettyPrint(board) << std::endl;
        std::cout << "Game is a draw" << std::endl;
        return 2;
    }
    else
    {
        std::cout << "Unsure why game terminated" << std::endl;
        return -1;
    }
}

int askPlayerForPosition(std::string board, char symbol)
{
    if (symbol == '0')
        std::cout << "Player A ";
    else if (symbol == '1')
        std::cout << "Player B ";
    else
        return -1;

    std::cout << "please give a position between 1 and 9 (inclusive) to make a move " << std::endl;
    std::cout << prettyPrint(board) << std::endl;

    int res = -1;
    std::cin >> res;
    return res-1;
}
