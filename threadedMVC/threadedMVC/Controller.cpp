#include "Controller.h"

Controller::Controller()
{
	mptr = new Model();

	vptr = new Viewer();

	mptr->connectViewer(*(vptr));

	vptr->connectModel(*(mptr));
	vptr->connectController(*(this));
}


Controller::~Controller()
{
	if (mptr != nullptr)
	{
		delete mptr;
		mptr = nullptr;
	}

	if (vptr != nullptr)
	{
		delete vptr;
		vptr = nullptr;
	}
}

void Controller::parseInput()
{
	cout << "Controller.parseInput()" << endl;
	while (inputQueue.empty() == false)
	{
		cout << "Controller is parsing an input..." << endl;
		Event* e = nullptr; 
		Input* i = inputQueue.front();
		inputQueue.pop();
		/*
		//parse Event here
		*/

		//deallocate memory
		if (i != nullptr)
		{
			delete i;
			i = nullptr;
		}
	}
}

void Controller::notifyModel()
{
	//send events to model
	cout << "Controller.notifyModel()" << endl;
	while (eventQueue.empty() == false)
	{
		cout << "Sending an event to Model..." << endl;
		Event* e = eventQueue.front();
		eventQueue.pop();
		mptr->takeEvent(e);
	}
}

void Controller::refreshViewer()
{
	vptr->updateDisplay();
}

void Controller::takeInput()
{
	cout << "Controller.takeInput()" << endl;
	while (vptr->pollInput())
	{
		try 
		{
		cout << "Reading input from Viewer..." << endl;
		inputQueue.push(vptr->getInput());
		}
		catch (std::out_of_range err)
		{
			cout << err.what() << endl;
		}
	}
}

void Controller::loop()
{
	cout << "Controller.loop()" << endl;
	isRunning = true;
	while (isRunning)
	{
		cout << "----------------\nNew Controller.loop() iteration" << endl;
		//1. poll Viewer for Inputs and add any Inputs to queue
		this->takeInput();

		//2. process Inputs from InputQueue into Events for EventQueue
		this->parseInput();

		//3. push Events from EventQueue to Model
		this->notifyModel();

		//4. ping Model to update and then push events to Viewer
		mptr->update();

		//5. ping Viewer to update
		vptr->update();
	}


}