#include "Controller.h"
#include "interface/Modules.h"
#include "abstract/InspectFactory.h"

void Controller::StartInspection()
{
	qDebug() << "Inspection thread: " << QThread::currentThreadId();

	InspectFactory* factory = nullptr;
	factory = InspectFactory::Create(InspectFactory::PRODUCT_1);

	autofocus = factory->GetAutofocus();
	positioning = factory->GetPositioning();
	inspect_method = factory->GetInspectMethod();

	/* construct factory */

}