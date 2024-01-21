#include "Controller.h"

void Controller::StartInspection()
{
	qDebug() << "Inspection thread: " << QThread::currentThreadId();

	autofocus->Process();
	positioning->Process();
	inspect_method->Process();
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