#pragma once
#include <iostream>
#include "Position.cpp"
using namespace std;
class Move{
	private:
		Position *now;
		Position *next;
	public:
		Move();
		Move(Position *_now, Position *_next);
		void setNow(Position *_now);
		Position* getNow();
		void setNext(Position *_next);
		Position* getNext();	
		
};


