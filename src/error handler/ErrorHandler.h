#pragma once

#include <QDebug>

enum ErrorCode 
{
    AUTOFOCUS_FAIL = 1,
    POSITIONING_FAIL,
    INSPECTION_FAIL
};

class InterfaceException
{
public:
	virtual ErrorCode GetErrorCode() const = 0;
	virtual ~InterfaceException() = default;
};

class MyException : public InterfaceException
{
public:
	MyException(ErrorCode code) : error_code(code) {}
	ErrorCode GetErrorCode() const override { return error_code; }

private:
	ErrorCode error_code;
};

class ExceptionHandler
{
public:
	void HandleException(const InterfaceException& e);
};