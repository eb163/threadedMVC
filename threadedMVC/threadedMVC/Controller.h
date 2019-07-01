#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "ControllerInterface.h"
#include <queue>
#include "Model.h"
#include "Viewer.h"
#include "debug.h"

using std::queue;

class Controller : public ControllerInterface
{
private:
	Model* mptr = nullptr;
	Viewer* vptr = nullptr;

	queue<Input*> inputQueue;
	queue<Event*> eventQueue;

	bool isRunning = false; //for running the main loop

public:
	Controller();
	~Controller();

	//controller must:
	//parse input from user
	//pass commands and parsed input to model
	//force viewer to update as necessary

	//generally the controller handles passing data from model to viewer in the control loop

	//todo
	//implement Interface methods
	void parseInput();
	void notifyModel();
	void takeInput(); //read all inputs from View
	void refreshViewer();

	void loop();

};

#endif

