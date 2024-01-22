#include "Modules.h"

void InspectMethod_1::Process()
{
	qDebug() << "InspectMethod_1::Process()";

	// do something
	data->inspect_pass = true;
}

void InspectMethod_2::Process()
{
	qDebug() << "InspectMethod_2::Process()";

	// do something
	data->inspect_pass = false;
}