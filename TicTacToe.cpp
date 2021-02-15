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

std::string GetPlayerChoice (int player, std::vector<std::vector<std::string>> *board) {
	std::vector<std::string> validChoices;
	for (int i = 0; i<(*board).size(); i++) {
		for (int j =0; j< (*board)[i].size(); j++) {
			if ((*board)[i][j] != "X" && (*board)[i][j] != "O") {
				validChoices.push_back((*board)[i][j]);
			}
		}
	}

	std::string userChoice;
	std::cout<<"Player "<<player+1<<" please choose where to place your marker! The valid moves are ";
	for (int f = 0; f<validChoices.size(); f++) {
		std::cout<<validChoices[f]<<" ";
	}
	std::cout<<":"<<std::endl;
	std::cin>>userChoice;

	for (int f = 0; f<validChoices.size(); f++) {
		if (userChoice == validChoices[f]) {
			return userChoice;
		}
	}

	while (true) {
		std::cout<<"That was not a valid choice. Please enter a valid move!"<<std::endl;
		std::cin>>userChoice;
		for (int f = 0; f<validChoices.size(); f++) {
			if (userChoice == validChoices[f]) {
				return userChoice;
			}
		}
	}
}

int main(){
  std::vector<std::vector<std::string>> *brd = CreateBoard();
  DisplayBoard(brd);
  int whichPlayer = 0;
  std::string userChoice;
  for (int i = 0; i<9; i++) {
  	userChoice = GetPlayerChoice(whichPlayer, brd);
  	PlaceMarker(whichPlayer, userChoice, brd);
  	DisplayBoard(brd);
  	if (whichPlayer==0) {
  		whichPlayer++;
  	}
  	else {
  		whichPlayer--;
  	}
  }
  delete brd;
}
