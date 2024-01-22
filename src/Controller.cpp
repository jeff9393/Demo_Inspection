#include "Controller.h"

void Controller::StartInspection()
{
	qDebug() << "Inspection thread: " << QThread::currentThreadId();

	try
	{
		/* process */
		autofocus->Process();
		positioning->Process();
		inspect_method->Process();

		/* update result to UI */
		emit NotifyResult(inspect_method->GetResult());

		qDebug() << "Process executed successfully.";
	}
	catch (const InterfaceException& e)
	{
		ExceptionHandler handler;
		handler.HandleException(e);
		emit NotifyResult(false);
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
	/* Create factory */
	factory = InspectFactory::Create(product);

	/* get object by factory */
	autofocus = factory->GetAutofocus();
	positioning = factory->GetPositioning();
	inspect_method = factory->GetInspectMethod();

	/* Dependency injection */
	data = new DependencyData();
	autofocus->SetDependency(data);
	positioning->SetDependency(data);
	inspect_method->SetDependency(data);
}

void Controller::DestroyFactory()
{
	delete factory;
	delete autofocus;
	delete positioning;
	delete inspect_method;
	delete data;
}