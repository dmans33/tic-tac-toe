// Tic-tac-toe.cpp

#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> *CreateBoard(){
  std::vector<std::vector<std::string>> *board  = new std::vector<std::vector<std::string> >(3, std::vector<std::string>(3));
  (*board) = {
        {"1", "2", "3"},
        {"4", "5", "6"},
        {"7", "8", "9"}
    };
    return board;
}


void DisplayBoard(std::vector<std::vector<std::string>> *board) {

	for (int i = 0; i<(*board).size(); i++) {
		for (int j =0; j< (*board)[i].size(); j++) {
			std::cout<< (*board)[i][j] << " ";
		}
		std::cout<<""<<std::endl;
	}
}

void PlaceMarker(int player, std::string loc, std::vector<std::vector<std::string>> *board){
  int row;
  int col;
  if (stoi(loc) > 9){
    std::cout << "The input location is invalid. Please choose again."<<std::endl;
  }
  else{
    if (stoi(loc)%3 == 0){
    row = stoi(loc)/3 - 1;
    col = 2;
    }
    else{
      row = stoi(loc)/3;
      col = stoi(loc)%3 - 1;
    }
    if (player == 0){
      (*board)[row][col] = "X";
    }
    else{
      (*board)[row][col] = "O";
    }
  }
}

int main(){
  std::vector<std::vector<std::string>> *brd = CreateBoard();
  DisplayBoard(brd);
  // PlaceMarker(0,"6",brd);
  // DisplayBoard(brd);

  delete brd;
}
