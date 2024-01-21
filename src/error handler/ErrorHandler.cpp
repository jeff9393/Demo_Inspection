#include "ErrorHandler.h"

void ExceptionHandler::HandleException(const InterfaceException& e)
{
	ErrorCode error_code = e.GetErrorCode();
	qDebug() << "Handling exception with error code: " << error_code;

	switch (error_code)
	{
	case AUTOFOCUS_FAIL:
		// handler..
		break;
	case POSITIONING_FAIL:
		// handler..
		break;
	case INSPECTION_FAIL:
		// handler..
		break;
	default:
		break;
	}
}