#pragma once

#include "Event.h"
#include "Input.h"

class ViewerInterface
{
public:
	virtual void update() = 0;
	virtual bool pollInput() = 0;
	virtual Input* getInput() = 0;
	virtual void processEvent(Event* e) = 0;
	virtual void updateDisplay() = 0;
};