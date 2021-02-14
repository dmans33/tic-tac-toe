# Mingyu Hu
# This is Makefile for PE4

CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: tictactoe

tictactoe: TicTacToe.cpp
	$(CXX) $(CXXFLAGS) TicTacToe.cpp -o tictactoe

clean:
	rm tictactoe
