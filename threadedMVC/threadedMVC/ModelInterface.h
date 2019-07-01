#pragma once
#include "Event.h"
#include "Input.h"

class ModelInterface
{
public:
	virtual void update() = 0;
	virtual void notifyViewer(Event* e) = 0;
	virtual void updateModel(float timestep) = 0;
	virtual void takeEvent(Event* e) = 0;
};