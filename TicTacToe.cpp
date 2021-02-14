// Tic-tac-toe.cpp

#include <iostream>
#include <vector>

std::vector<std::vector<std::string>> CreateBoard(){
  std::vector<std::vector<std::string>> board
    {
        {"1", "2", "3"},
        {"4", "5", "6"},
        {"7", "8", "9"}
    };
    return board;
}

int main(){
  std::vector<std::vector<std::string>> brd = CreateBoard();
}
