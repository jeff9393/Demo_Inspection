#include "Controller.h"
#include "interface/Modules.h"
#include "abstract/InspectFactory.h"

void Controller::StartInspection()
{
	qDebug() << "Inspection thread: " << QThread::currentThreadId();

	InspectFactory *factory = nullptr;
	factory = InspectFactory::Create(InspectFactory::PRODUCT_1);

	/* construct factory */
	autofocus = factory->GetAutofocus();
	positioning = factory->GetPositioning();
	inspect_method = factory->GetInspectMethod();

	autofocus->Process();
	positioning->Process();
	inspect_method->Process();

	delete factory;
	delete autofocus;
	delete positioning;
	delete inspect_method;
}