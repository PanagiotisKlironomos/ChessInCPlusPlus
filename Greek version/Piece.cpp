#pragma once
#include"Piece.h"

Piece::Piece(){}

Piece::Piece( string _color, char _type, int hasMoved)
{
	color = _color;
	hasMoved = 0;
	type = _type;
}

Piece::Piece( string _color, char _type)
{
	color = _color;
	hasMoved = 0;
	type = _type;
}

Piece::Piece(const Piece &x)
{
	color = x.color;
	hasMoved = x.hasMoved;
	type = x.type;
}

void Piece::setColor(string _color)
{
	color= _color;
}

string Piece::getColor()
{
	return color;
}

void Piece::setHasMoved(int _hasMoved)
{
	hasMoved= _hasMoved;
}

int Piece::getHasMoved()
{
	return hasMoved;
}

void Piece::setType(char _type)
{
	type= _type;
}

char Piece::getType()
{
	return type;
}


