#include "Controller.h"

void Controller::StartInspection()
{
	qDebug() << "Inspection thread: " << QThread::currentThreadId();

	factory = InspectFactory::Create(InspectFactory::PRODUCT_2);

	/* construct factory */
	autofocus = factory->GetAutofocus();
	positioning = factory->GetPositioning();
	inspect_method = factory->GetInspectMethod();

	/* do */
	autofocus->Process();
	positioning->Process();
	inspect_method->Process();

	delete factory;
	delete autofocus;
	delete positioning;
	delete inspect_method;
}