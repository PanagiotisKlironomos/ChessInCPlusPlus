/* Copyright (C) 2019 Panagiotis Klironomos - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the GNU GENERAL PUBLIC LICENSE 
 */
//# pragma once
# include <string>
# include "Piece.cpp"

using namespace std;

class Square
{
	private:
		Piece * piece;
		string colorS;
	public:
		Square();
		Square(Piece* _piece, string _colorS);
		Square(const Square &);
		void setPiece(Piece * _piece);
		Piece *  getPiece();	
		void setColorS(string _colorS);
		string  getColorS();	
		void setEmpty();
		bool getEmpty();
		void insertPiece(Piece * _piece);		
};


