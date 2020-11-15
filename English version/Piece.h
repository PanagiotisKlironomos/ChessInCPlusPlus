#pragma once
#include <iostream>
#include <string>

using namespace std;

class Piece
{
	protected:
		string color;
		int hasMoved;
		char type;
	public:
		Piece();
		Piece( string _color, char _type, int hasMoved);
		Piece(string _color, char _type);
		Piece(const Piece &);
		void setColor(string _color);
		string  getColor();
		void setHasMoved(int _hasMoved);
		int getHasMoved();
		void setType(char _type);
		char getType();	
};


