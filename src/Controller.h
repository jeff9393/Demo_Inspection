#pragma once

#include "interface/Modules.h"
#include "abstract/InspectFactory.h"
#include "error handler/ErrorHandler.h"
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

		factory = nullptr;
		autofocus = nullptr;
		positioning = nullptr;
		inspect_method = nullptr;
		data = nullptr;
		product = InspectFactory::PRODUCT_TYPE::PRODUCT_1;
		ConstructFactory();
	}

	~Controller()
	{
		DestroyFactory();
		controller_thread.quit();
		controller_thread.wait();
	}

private:
	/* factory object */
	InspectFactory *factory;
	Autofocus *autofocus;
	Positioning *positioning;
	InspectMethod *inspect_method;

	/* variables */
	InspectFactory::PRODUCT_TYPE product;
	DependencyData *data;

	/* function */
	void ConstructFactory();
	void DestroyFactory();

signals:
	void NotifyResult(bool result);

public slots:
	void StartInspection();
	void UpdateFactory(int index);
};