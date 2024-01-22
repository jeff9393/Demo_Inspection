#include "Modules.h"
#include "../error handler/ErrorHandler.h"

void Autofocus_1::Process()
{
	qDebug() << "Autofocus_1::Process()";

	data->src_image = "GetImage";

	if (data->src_image != "GetImage")
	{
		throw MyException(AUTOFOCUS_FAIL);
	}	
}

void Autofocus_2::Process()
{
	qDebug() << "Autofocus_2::Process()";

	data->src_image = "Failure to focus";

	if (data->src_image != "GetImage")
	{
		throw MyException(AUTOFOCUS_FAIL);
	}
}
