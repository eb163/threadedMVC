#include "Viewer.h"

Viewer::Viewer()
{
}


Viewer::~Viewer()
{

}

void Viewer::connectModel(Model& m)
{
	mptr = &m;
}

void Viewer::connectController(Controller& c)
{
	cptr = &c;
}

void Viewer::draw()
{

}

void Viewer::takeEvent(Event* e)
{
	cout << "Viewer.takeEvent()" << endl;
	eventQueue.push(e);
}

void Viewer::processEvent(Event* e)
{
	//do stuff based on event here

	//avoid memory leaks by deleting events at the end of the event process (from model through to viewer)
	if (e != nullptr)
	{
		delete e;
		e = nullptr;
	}

}

void Viewer::updateDisplay()
{
	//do stuff here
}

bool Viewer::pollInput()
{
	return (!inputQueue.empty());
}

Input* Viewer::getInput()
{
	if (inputQueue.empty())
	{
		throw std::out_of_range("Input queue is empty");
	}
	Input* i = inputQueue.front();
	inputQueue.pop();
	return i;
}

void Viewer::update()
{
	cout << "Viewer.update()" << endl;
	//process each event in queue
	while (eventQueue.empty() == false)
	{
		cout << "Viewer is processing an event" << endl;
		Event* e = eventQueue.front();
		eventQueue.pop();
		processEvent(e);
	}
}