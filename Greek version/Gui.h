/* Copyright (C) 2019 Panagiotis Klironomos - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the GNU GENERAL PUBLIC LICENSE 
 */
#pragma once
# include "Board.cpp"
#include "Move.cpp"
#include <windows.h>
using namespace std;

class Gui{
	public:
	void refresh(Board b);
	void  takeInput( char  input[], string message);
	void newGame (Board b) ;
	void startMenu (Board b);
	void takeStartInput(Board * b, string message);
	void startProcess();
		
};

