#include "Controller.h"

void Controller::StartInspection()
{
	qDebug() << "Inspection thread: " << QThread::currentThreadId();

	try
	{
		autofocus->Process();
		positioning->Process();
		inspect_method->Process();

		qDebug() << "Process executed successfully.";
	}
	catch (const InterfaceException& e)
	{
		ExceptionHandler handler;
		handler.HandleException(e);
	}
	catch (...)
	{
		qDebug() << "Caught unknown exception";
	}
}

void Controller::UpdateFactory(int index)
{
	qDebug() << "Product index: " << index;

	switch (index)
	{
	case 0:
		product = InspectFactory::PRODUCT_TYPE::PRODUCT_1;
		break;
	case 1:
		product = InspectFactory::PRODUCT_TYPE::PRODUCT_2;
		break;
	default: 
		break;
	}
	DestroyFactory();
	ConstructFactory();
}

void Controller::ConstructFactory()
{
	factory = InspectFactory::Create(product);
	autofocus = factory->GetAutofocus();
	positioning = factory->GetPositioning();
	inspect_method = factory->GetInspectMethod();
}

void Controller::DestroyFactory()
{
	delete factory;
	delete autofocus;
	delete positioning;
	delete inspect_method;
}