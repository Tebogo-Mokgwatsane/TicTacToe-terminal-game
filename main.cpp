#include <iostream>
#include <string>

#include "TicTacToe.h"
#include "TicTacToeHelper.h"

int main()
{
    std::string exit;
    playGame();
    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    getline(std::cin, exit);
    return 0;
    //g++ *.cpp -o main  && ./main
}