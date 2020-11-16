/* Copyright (C) 2019 Panagiotis Klironomos - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the GNU GENERAL PUBLIC LICENSE 
 */
# pragma once
# include "Square.cpp"
# include "Piece.cpp"
# include "Position.cpp"
#include <fstream>
# include <vector>
#include <windows.h>

class Board
{
	private:
		Square squares[8][8];
	public:
		void initBoard();
		void printBoard(HANDLE WINAPI hConsole);
		Board(){}
		Board (const Board &);
		bool isMoveValid(Position * now, Position * next);
		bool pawnMoveValid(Position * now, Position * next);
		bool knightMoveValid(Position * now, Position * next);
		bool bishopMoveValid(Position * now, Position * next);
		bool rookMoveValid(Position * now, Position * next);
		bool queenMoveValid(Position * now, Position * next);
		bool kingMoveValid(Position * now, Position * next);
		bool makeMove(Position * now, Position * next);
		bool IsInCheck(string Color);
		bool CanMove(string  Color);
		bool IsGameOver(string currentColor, string * endMessage);
		Square getSquares(int rows, int cols){return squares [rows][cols];}
		void writeFile();
		void readFile();

};

