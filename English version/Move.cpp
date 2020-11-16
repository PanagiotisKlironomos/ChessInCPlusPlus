/* Copyright (C) 2019 Panagiotis Klironomos - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the GNU GENERAL PUBLIC LICENSE 
 */
#pragma once
#include "Move.h"
Move::Move(){}
Move::Move(Position* _now, Position* _next)
{
	now = _now;
	next= _next;
}
void Move::setNow(Position* _now)
{
	now = _now;
}
Position* Move::getNow()
{
	return now;
}
void Move::setNext(Position* _next)
{
	next=_next;
}
Position* Move::getNext()
{
	return next;
}	
