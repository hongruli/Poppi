/*
 * Gait.cpp
 *
 *  Created on: 7 janv. 2016
 *      Author: Vincent
 */

#include "../../../include/Useful.h"
#include "../../../include/Hexapode/Gaits/Gait.h"

Gait::Gait(Leg* (*legs)[LEG_COUNT]):
m_legs(legs),
m_direction(Vector3::zero),
stopped(true)
{

}

LegStep::LegStep(Leg &l, LegPosition pos):
		leg(l)
{
	position = pos;
}

Gait::~Gait()
{

}

void Gait::setDirection(Vector3 goal)
{
	for(int i(0); i < LEG_COUNT; ++i)
		(*m_legs)[i]->setDirection(goal);
	stopped = m_direction == Vector3::zero;

	if(!stopped)
		walk();
}

void Gait::init(Vector3 direction)
{
	m_direction = direction;
}

void Gait::stop()
{
	m_direction = Vector3::zero;
	stopped = true;
}


void Gait::update()
{

}