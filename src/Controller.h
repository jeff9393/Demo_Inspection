#pragma once

#include "interface/Modules.h"
#include "abstract/InspectFactory.h"
#include <QMainWindow>
#include <QObject> 
#include <QDebug> 
#include <QThread> 

class Controller : public QObject
{
	Q_OBJECT

public:
	QThread controller_thread;

	Controller()
	{
		factory = nullptr;
		autofocus = nullptr;
		positioning = nullptr;
		inspect_method = nullptr;
		moveToThread(&controller_thread);
		controller_thread.start();
	}

	~Controller()
	{
		controller_thread.quit();
		controller_thread.wait();
	}

private:
	/* factory object */
	InspectFactory *factory;
	Autofocus *autofocus;
	Positioning *positioning;
	InspectMethod *inspect_method;

public slots:
	void StartInspection();
};