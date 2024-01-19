#pragma once

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
		moveToThread(&controller_thread);
		controller_thread.start();
	}

	~Controller()
	{
		controller_thread.quit();
		controller_thread.wait();
	}

public slots:
	void StartInspection();
};