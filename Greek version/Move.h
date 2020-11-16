/* Copyright (C) 2019 Panagiotis Klironomos - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the GNU GENERAL PUBLIC LICENSE 
 */
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


