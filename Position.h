#pragma once
#include <iostream>

class Position
{
	private:
		char horizontal;
		char vertical;
	public:
		Position ();
		Position (char horizontal, char vertical);
		Position(const Position &);
		void setHorizontal(char _horizontal);
		char  getHorizontal();
		void setVertical(char _vertical);
		char  getVertical();		
};

