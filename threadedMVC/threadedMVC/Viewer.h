#pragma once
#ifndef VIEWER_H
#define VIEWER_H
#include "ViewerInterface.h"
#include "Controller.h"
#include "Model.h"
#include <queue>
#include <exception>

#include "debug.h"

class Controller; //avoids recursive includes

using std::queue;

class Viewer : public ViewerInterface
{
private:
	Model *mptr = nullptr;
	Controller *cptr = nullptr;
	queue<Input*> inputQueue;
	queue<Event*> eventQueue;

public:
	Viewer();
	~Viewer();

	void connectModel(Model& m);

	void connectController(Controller& c);

	void draw(); //updates viewer display

	void takeEvent(Event* e); //adds an event to the queue to be processed by the Viewer

	//viewer must:
	//update graphics when model sends a notification
	//send input to controller
	//todo:
	//implement Interface methods
	void processEvent(Event* e);
	void updateDisplay();
	bool pollInput();
	Input* getInput();

	void update();
};

#endif

