/* Copyright (C) 2019 Panagiotis Klironomos - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the GNU GENERAL PUBLIC LICENSE 
 */
#pragma once
#include"Position.h"
Position::Position() {}

Position::Position( char _horizontal, char _vertical )
{
	horizontal= _horizontal;
	vertical = _vertical;
}

Position::Position(const Position &x)
{
	horizontal = x.horizontal;
	vertical = x.vertical;
}

void Position::setHorizontal(char _horizontal)
{
	horizontal= _horizontal;
}

char  Position::getHorizontal()
{
	return horizontal;
}

void Position::setVertical(char _vertical)
{
	vertical = _vertical;
}

char  Position::getVertical()
{
	return vertical;
}
