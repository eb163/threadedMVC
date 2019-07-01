#pragma once
#ifndef MODEL_H
#define MODEL_H
#include "ModelInterface.h"
#include <queue>
#include "debug.h"
//#include "Viewer.h"

class Viewer; //avoids recursive includes

using std::queue;

class Model : public ModelInterface
{
private:
	Viewer *vptr = nullptr;
	queue<Event*> eventsQueue; //for events from controller
	queue<Event*> outQueue; //for events to send to viewer

public:
	Model();
	~Model();

	void connectViewer(Viewer& v);

	//model must:
	//take commands or processed input from controller
	//operate on internal data structures
	//pass notifications to viewer

	void notifyViewer(Event* e);
	void updateModel(float timestep);
	void takeEvent(Event* e);
	void update();
};

#endif