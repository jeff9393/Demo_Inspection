#include "Controller.h"

void Controller::StartInspection()
{
	qDebug() << "Inspection thread: " << QThread::currentThreadId();
}