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


void DisplayBoard(std::vector<std::vector<std::string>> board) {

	for (int i = 0; i<board.size(); i++) {
		for (int j =0; j< board[i].size(); j++) {
			std::cout<< board[i][j] << " ";
		}
		std::cout<<""<<std::endl;
	}
}

int main(){
  std::vector<std::vector<std::string>> brd = CreateBoard();
  DisplayBoard(brd);
}
