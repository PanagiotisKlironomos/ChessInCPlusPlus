#include "Square.h"
Square::Square(){}

Square::Square(Piece* _piece, string _colorS)
{
	piece = _piece;
	colorS = _colorS;
}

Square::Square(const Square &x)
{
	piece = x.piece;
	colorS = x.colorS;
}

void Square::setPiece(Piece * _piece)
{
	piece = _piece;
}

Piece *  Square::getPiece()
{
	return piece;
}

void Square::setColorS(string _colorS)
{
	colorS = _colorS;
}

string  Square::getColorS()
{
	return colorS;
}
bool Square::getEmpty()
{
	if(piece -> getColor()=="BLANK"  ) return true;
	else return false;
}
void Square::setEmpty()
{
	piece -> setColor("BLANK");
	piece -> setType('0');
	piece->setHasMoved( 0 );
}
void Square::insertPiece(Piece * _piece)
{
	piece->setColor ( _piece->getColor() );
	piece->setType(_piece->getType() );
	piece->setHasMoved( (_piece->getHasMoved()) +1 );
}


