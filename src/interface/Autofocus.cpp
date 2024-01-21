#include "Modules.h"
#include "../error handler/ErrorHandler.h"

void Autofocus_1::Process()
{
	qDebug() << "Autofocus_1::Process()";

	bool focus_failed = true; // Error case for test
	if (focus_failed)
	{
		throw MyException(AUTOFOCUS_FAIL);
	}	
}

void Autofocus_2::Process()
{
	qDebug() << "Autofocus_2::Process()";
}
