#include "Board.h"
/**************
Reads from a binary file called uniwa.chess
a Board type object
*******************/

void Board::readFile()
{
   /*ifstream infile;                           
   infile.open("uniwa.chess", ios::binary); 
   int i,j; 
  			infile.read( reinterpret_cast<char*> &(this->squares), 64 * sizeof(Square) );
   infile.close();*/
}

/**************
Writes to a binary file called uniwa.chess
a Board type object
*******************/
void Board::writeFile()            
{ 
 /* ofstream outfile;  
  outfile.open("uniwa.chess",ios::binary);
  int i,j;  
  		outfile.write( reinterpret_cast<char*> &(this->squares), 64 * sizeof(Square) );
  outfile.close();*/
  	
  
} 

/**************
copy constructor
*******************/
Board::Board (const Board &x)
{
	int i,j;
	for (i=0;i<8; i++)
		for(j=0; j<8;j++)
			squares[i][j]=x.squares[i][j];
}
/**************
initializes each of the chessboard squares with
the corresponding pieces
*******************/
void Board::initBoard()
{
	int i,j;
	squares[0][0].setPiece(new  Piece( "WHITE",'R')); // Rook
	squares[0][1].setPiece(new  Piece( "WHITE",'N')); // Knight
	squares[0][2].setPiece(new  Piece( "WHITE",'B')); // Bishop
	squares[0][3].setPiece(new  Piece( "WHITE",'Q')); // Queen
	squares[0][4].setPiece(new  Piece( "WHITE",'K')); // King
	squares[0][5].setPiece(new  Piece( "WHITE",'B')); // Bishop
	squares[0][6].setPiece(new  Piece( "WHITE",'N')); // Knight
	squares[0][7].setPiece(new  Piece( "WHITE",'R')); // Rook
	
	squares[7][0].setPiece(new  Piece( "BLACK",'r')); // Rook;
	squares[7][1].setPiece(new  Piece( "BLACK",'n')); // Knight
	squares[7][2].setPiece(new  Piece( "BLACK",'b')); // Bishop
	squares[7][3].setPiece(new  Piece( "BLACK",'q')); // Queen
	squares[7][4].setPiece(new  Piece( "BLACK",'k')); // King
	squares[7][5].setPiece(new  Piece( "BLACK",'b')); // Bishop
	squares[7][6].setPiece(new  Piece( "BLACK",'n')); // Knight;
	squares[7][7].setPiece(new  Piece( "BLACK",'r')); // Rook
		
	for ( i = 0; i < 8; i++)
	{
		squares[1][i].setPiece(new  Piece( "WHITE",'P')); // Pawn
		squares[6][i].setPiece(new  Piece( "BLACK",'p')); // Pawn
	}
	for ( j = 2; j < 6; j++)
	{
		for ( i = 0; i < 8; i++)
			squares[j][i].setPiece(new Piece( "BLANK",  '0')); // Blank

	}
		
	
}
/**************
Print the chessboard using the windows.h library
for better visual effect
*******************/
void Board::printBoard(HANDLE WINAPI hConsole) {
	using namespace std;
	
	SetConsoleTextAttribute(hConsole, 15);
	cout << "      A  B  C  D  E  F  G  H " << endl  << endl;
	int i,j;
	for (i = 7; i >= 0; i--)
	{
		cout << " " << i+1 << "   ";
		for ( j = 0; j < 8; j++)
		{
		  if ( squares[i][j].getPiece() -> getType() != '0' )
		  {
			char  p = squares[i][j].getPiece() -> getType();
			if((i+j)%2 == 0)
			{				
				SetConsoleTextAttribute(hConsole, 15);
				cout<< " " << p << " ";
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 240);
				cout<< " " << p << " ";
			}
	
		  }
      	  else 
      	  {
		
			if((i+j)%2 == 0) 
			{
				SetConsoleTextAttribute(hConsole, 15);
				cout<< "   ";
			}
			else 
			{
				SetConsoleTextAttribute(hConsole, 240);
				cout<< "   " ;
			}
		 }
		}
		SetConsoleTextAttribute(hConsole, 15);
		cout << " "<<endl;
		
	 }
}

/**************
Move a pawn to another square
of the chessboard
*******************/
bool Board::makeMove(Position * now, Position * next)
{
	
	squares[(int)next->getVertical()- '0'][(int)next->getHorizontal()- '0'].insertPiece(squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece());
	if ( ! ( ( next->getVertical() == now->getVertical() ) && (next->getHorizontal() == now->getHorizontal() ) ) )
	squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].setEmpty();
	
}
/**************
checking the correctness of a movement
pawn in another square of the chessboard
*******************/
bool Board::isMoveValid(Position * now, Position * next)
{
	if(squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece()->getType() == 'P' ||
		squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece()->getType() == 'p' )
	{	
		return pawnMoveValid(now, next);
	}
	else if(squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece()->getType() == 'N' ||
		squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece()->getType() == 'n' )
	{	
		return knightMoveValid( now, next);
	}
	else if(squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece()->getType() == 'B' ||
		squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece()->getType() == 'b' )
	{	
		return bishopMoveValid( now, next);
	}	
	else if(squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece()->getType() == 'R' ||
		squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece()->getType() == 'r' )
	{	
		return rookMoveValid( now, next);
	}	
	else if(squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece()->getType() == 'Q' ||
		squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece()->getType() == 'q' )
	{	
		return queenMoveValid( now, next);
	}
	else if(squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece()->getType() == 'K' ||
		squares[(int)now->getVertical()- '0'][(int)now->getHorizontal()- '0'].getPiece()->getType() == 'k' )
	{	
		return kingMoveValid( now, next);
	}
	

	return false; // tha svistei
}
/**************
checking the correctness of a movement
pawn soldier in another square of chessboard
*******************/
bool Board::pawnMoveValid(Position * now, Position * next)
{
		int iSrcCol= (int)now->getHorizontal()- '0' ;
		int iDestCol= (int)next->getHorizontal()- '0' ;
		int iSrcRow = (int)now->getVertical()- '0' ;
		int iDestRow = (int)next->getVertical()- '0' ;
		if (squares[iDestRow][iDestCol].getPiece()->getType() == '0') {
			// Destination square is unoccupied
			if (iSrcCol == iDestCol) {
				if (squares[iSrcRow][iSrcCol].getPiece()->getColor() == "WHITE") {
					if (iDestRow == (iSrcRow ) + 1    ||  (squares[iSrcRow][iSrcCol].getPiece()->getHasMoved()==0 && iDestRow == (iSrcRow ) + 2  ) ) {
					
						return true;
					}
				} else {
					if (iDestRow == (iSrcRow ) - 1    ||  (squares[iSrcRow][iSrcCol].getPiece()->getHasMoved()==0 && iDestRow == (iSrcRow ) - 2  )  ) {
					
						return true;
					}
				}
			}
		} else {
			// Dest holds piece of opposite color
			if ((iSrcCol == (iDestCol) + 1) || (iSrcCol == (iDestCol) - 1)) {
				if (squares[iSrcRow][iSrcCol].getPiece()->getColor() == "WHITE") {
					if (iDestRow == (iSrcRow ) + 1) {
					
						return true;
					}
				} else {
					if (iDestRow == (iSrcRow ) - 1) {
					
						return true;
					}
				}
			}
		}
		
		return false;
}
/**************
checking the correctness of a movement
pawn horse in another square of the chessboard
*******************/
bool Board::knightMoveValid(Position * now, Position * next)
{
		int iSrcCol= (int)now->getHorizontal()- '0' ;
		int iDestCol= (int)next->getHorizontal()- '0' ;
		int iSrcRow = (int)now->getVertical()- '0' ;
		int iDestRow = (int)next->getVertical()- '0' ;
		// Destination square is unoccupied or occupied by opposite color
		if ((iSrcCol == iDestCol + 1) || (iSrcCol == iDestCol - 1)) {
			if ((iSrcRow == iDestRow + 2) || (iSrcRow == iDestRow - 2)) {
				
				return true;
			}
		}
		if ((iSrcCol == iDestCol + 2) || (iSrcCol == iDestCol - 2)) {
			if ((iSrcRow == iDestRow + 1) || (iSrcRow == iDestRow - 1)) {
				
				return true;
			}
		}
		
		return false;
}
/**************
checking the correctness of a movement
pawn officer in another square of the chessboard
*******************/
bool Board::bishopMoveValid(Position * now, Position * next)
{
	int iSrcCol= (int)now->getHorizontal()- '0' ;
	int iDestCol= (int)next->getHorizontal()- '0' ;
	int iSrcRow = (int)now->getVertical()- '0' ;
	int iDestRow = (int)next->getVertical()- '0' ;
	if ((iDestCol - iSrcCol == iDestRow - iSrcRow) || (iDestCol - iSrcCol == iSrcRow - iDestRow)) {
		// Make sure that all invervening squares are empty
		int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
		int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
		int iCheckRow;
		int iCheckCol;
		for (iCheckRow=iSrcRow+iRowOffset, iCheckCol=iSrcCol+iColOffset; iCheckRow!=iDestRow; iCheckRow=iCheckRow+iRowOffset, iCheckCol=iCheckCol+iColOffset)
		{
			if (squares[iCheckRow][iCheckCol].getPiece()->getType() != '0') 
			
				return false;
		}
		
		return true;
	}
	
	return false;
}
/**************
checking the correctness of a movement
pawn tower in another square of the chessboard
*******************/
bool Board::rookMoveValid(Position * now, Position * next)
{
	int iSrcCol= (int)now->getHorizontal()- '0' ;
	int iDestCol= (int)next->getHorizontal()- '0' ;
	int iSrcRow = (int)now->getVertical()- '0' ;
	int iDestRow = (int)next->getVertical()- '0' ;
	int iCheckRow;
	int iCheckCol;
		if (iSrcRow == iDestRow) {
			// Make sure that all invervening squares are empty
			int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
			for ( iCheckCol = iSrcCol + iColOffset; iCheckCol !=  iDestCol; iCheckCol = iCheckCol + iColOffset) {
				if (squares[iSrcRow][iCheckCol].getPiece()->getType() !='0') {
					
					return false;
				}
			}
			
			return true;
		} else if (iDestCol == iSrcCol) {
			// Make sure that all invervening squares are empty
			int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
			for ( iCheckRow = iSrcRow + iRowOffset; iCheckRow !=  iDestRow; iCheckRow = iCheckRow + iRowOffset) {
				if (squares[iCheckRow][iSrcCol].getPiece()->getType() != '0') {
					
					return false;
				}
			}
			
			return true;
		}
		
		return false;
	
	
}
/**************
checking the correctness of a movement
pawn queen in another square of the chessboard
*******************/
bool Board::queenMoveValid(Position * now, Position * next)
{
	int iSrcCol= (int)now->getHorizontal()- '0' ;
	int iDestCol= (int)next->getHorizontal()- '0' ;
	int iSrcRow = (int)now->getVertical()- '0' ;
	int iDestRow = (int)next->getVertical()- '0' ;
	int iCheckRow;
	int iCheckCol;
		if (iSrcRow == iDestRow) {
			// Make sure that all invervening squares are empty
			int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
			for (iCheckCol = iSrcCol + iColOffset; iCheckCol !=  iDestCol; iCheckCol = iCheckCol + iColOffset) {
				if (squares[iSrcRow][iCheckCol].getPiece()->getType() != '0') {
					
					return false;
				}
			}
			return true;
		} else if (iDestCol == iSrcCol) {
			// Make sure that all invervening squares are empty
			int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
			for (iCheckRow = iSrcRow + iRowOffset; iCheckRow !=  iDestRow; iCheckRow = iCheckRow + iRowOffset) {
				if (squares[iCheckRow][iSrcCol].getPiece()->getType() != '0' ) {
					
					return false;
				}
			}
			return true;
		} else if ((iDestCol - iSrcCol == iDestRow - iSrcRow) || (iDestCol - iSrcCol == iSrcRow - iDestRow)) {
			// Make sure that all invervening squares are empty
			int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
			int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
			for (iCheckRow = iSrcRow + iRowOffset, iCheckCol = iSrcCol + iColOffset;
				iCheckRow !=  iDestRow;
				iCheckRow = iCheckRow + iRowOffset, iCheckCol = iCheckCol + iColOffset)
			{
				if (squares[iCheckRow][iCheckCol].getPiece()->getType() != '0' ) {
					
					return false;
				}
			}
			return true;
		}
		return false;
	
}
/**************
checking the correctness of a movement
pawn king in another square of the chessboard
*******************/
bool Board::kingMoveValid(Position * now, Position * next)
{
	int iSrcCol= (int)now->getHorizontal()- '0' ;
	int iDestCol= (int)next->getHorizontal()- '0' ;
	int iSrcRow = (int)now->getVertical()- '0' ;
	int iDestRow = (int)next->getVertical()- '0' ;
		int iRowDelta = iDestRow - iSrcRow;
		int iColDelta = iDestCol - iSrcCol;
		if (((iRowDelta >= -1) && (iRowDelta <= 1)) &&
			((iColDelta >= -1) && (iColDelta <= 1)))
		{
			return true;
		}
		return false;	
}

/**************
checkmate control of each king
*******************/
bool Board::IsInCheck(string Color) {
	int iRow,iCol;
	// Find the king
	int iKingRow;
	int iKingCol;
	for ( iRow = 0; iRow < 8; ++iRow) {
		for ( iCol = 0; iCol < 8; ++iCol) {
			if (squares[iRow][iCol].getPiece()->getType() != '0') { // αν δεν ειναι blank
				if (squares[iRow][iCol].getPiece()->getColor() == Color) { // και ειναι ιδιου χρωματος
					if (squares[iRow][iCol].getPiece()->getType() == 'K' || squares[iRow][iCol].getPiece()->getType()== 'k' ) { //και τυπου king
						iKingRow = iRow;
						iKingCol = iCol;
					}
				}
			}
		}
	}
	// Run through the opponent's pieces and see if any can take the king
	for ( iRow = 0; iRow < 8; ++iRow) {
		for ( iCol = 0; iCol < 8; ++iCol) {
			if (squares[iRow][iCol].getPiece()->getType() != '0') {
				if (squares[iRow][iCol].getPiece()->getColor() != Color) {
					if (isMoveValid(new Position((char )iCol+'0', (char )iRow+'0'), new Position((char )iKingCol+'0', (char )iKingRow+'0'))) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
/**************
one player mobility check
*******************/
bool Board::CanMove(string  Color) {
	int iMoveCol, iMoveRow,iRow,iCol;
	bool bCanMove;
		// Run through all pieces
		for ( iRow = 0; iRow < 8; ++iRow) { 
			for ( iCol = 0; iCol < 8; ++iCol) { 
				if (squares[iRow][iCol].getPiece()->getType() != '0') { 
					// If it is a piece of the current player, see if it has a legal move
					if (squares[iRow][iCol].getPiece()->getColor() == Color) { 
						for ( iMoveRow = 0; iMoveRow < 8; ++iMoveRow) { 
							for ( iMoveCol = 0; iMoveCol < 8; ++iMoveCol) { 
								if (isMoveValid(new Position((char )iCol +'0',(char ) iRow +'0'), new Position((char )iMoveCol+'0', (char )iMoveRow+'0'))) { 
									// Make move and check whether king is in check
									Piece* temp					= squares[iMoveRow][iMoveCol].getPiece();
									squares[iMoveRow][iMoveCol].setPiece(squares[iRow][iCol].getPiece());	
									squares[iRow][iCol].setPiece(new Piece("BLANK", '0'));
									bool bCanMove = !IsInCheck(Color); 
									// Undo the move
									squares[iRow][iCol].setPiece(squares[iMoveRow][iMoveCol].getPiece());
									squares[iMoveRow][iMoveCol].setPiece(temp);	
									if (bCanMove) {
										return true;
									}
									else return false;
								}
							}
						}
					}
				}
			}
		}
		return false;
	}
/**************
game end control
*******************/
bool Board::IsGameOver(string currentColor, string * endMessage) { 
	// Check that the current player can move
	// If not, we have a stalemate or checkmate
	string winColor;
	if (currentColor== "WHITE") winColor="μαύρα"; else  winColor="άσπρα";
	bool bCanMove=false;
	bCanMove = CanMove(currentColor);
	if (!bCanMove) { 
		if (IsInCheck(currentColor)) {
			*endMessage =  "Ρουά Ματ , κέρδισαν τα " + winColor + "!!"  ;
		} else {
			*endMessage = "Ισοπαλία!" ;
		}
	}
	return bCanMove; 
}


