// PE4
// Tic-tac-toe.cpp
// Team members: Devin Sharpe, Mingyu Hu

#include <iostream>
#include <vector>
#include <string>

// This function initialize an 3-by-3 "empty" board for the tic-tac-toe game.
// Output: a pointer to a 3-by-3 vector of type string.
std::vector<std::vector<std::string>> *CreateBoard(){
  std::vector<std::vector<std::string>> *board  = new std::vector<std::vector<std::string> >(3, std::vector<std::string>(3));
  (*board) = {
        {"1", "2", "3"},
        {"4", "5", "6"},
        {"7", "8", "9"}
    };
    return board;
}

// This function displays the current board on terminal.
// Input: the pointer to the board
void DisplayBoard(std::vector<std::vector<std::string>> *board) {

	for (int i = 0; i<(*board).size(); i++) {
		for (int j =0; j< (*board)[i].size(); j++) {
			std::cout<< (*board)[i][j] << " ";
		}
		std::cout<<""<<std::endl;
	}
}

// This function updates the board by placing either "X" or "O" for the current player.
// Input: int player, a string within "1" to "9" for the location choice,
//        the pointer to the board.
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


// This function gets the location choice of the given player from user input.
// Input: int player, the pointer to the board.
// Output: The string of user input location to place its marker.
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


// The main function simulates a complete tic-tac-toe game.
// The game ends until all 9 spots are filled.
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
