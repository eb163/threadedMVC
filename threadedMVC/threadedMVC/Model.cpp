#include "Model.h"
#include "Viewer.h"

Model::Model()
{

}


Model::~Model()
{

}

void Model::connectViewer(Viewer& v)
{
	vptr = &v;
}

void Model::notifyViewer(Event* e)
{
	vptr->processEvent(e);
}

void Model::updateModel(float timestep)
{
	//stuff goes here
}

void Model::takeEvent(Event* e)
{
	cout << "Model.takeInput()" << endl;
	eventsQueue.push(e);
}

void Model::update()
{
	cout << "Model.update()" << endl;
	while (eventsQueue.empty() == false)
	{
		cout << "Model is processing an event..." << endl;
		Event* e = eventsQueue.front();
		eventsQueue.pop();
		//do stuff based on current Event

		outQueue.push(e);
	}

	while (outQueue.empty() == false)
	{
		cout << "Model is pushing an event to Viewer..." << endl;
		Event* e = outQueue.front();
		outQueue.pop();
		vptr->takeEvent(e);
	}
}
