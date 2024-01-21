#pragma once

#include <QDebug>

/* announcement */
class Autofocus;
class Positioning;
class InspectMethod;

class Autofocus
{
public:
	Autofocus()
	{

	}

	virtual void Process() = 0;
};

class Autofocus_1 : public Autofocus
{
public:
	Autofocus_1()
	{
		qDebug() << "Autofocus: Autofocus_1";
	}

	void Process() override;
};

class Autofocus_2 : public Autofocus
{
public:
	Autofocus_2()
	{
		qDebug() << "Autofocus: Autofocus_2";
	}

	void Process() override;
};

class Positioning
{
public:
	Positioning()
	{

	}

	virtual void Process() = 0;
};

class Positioning_1 : public Positioning
{
public:
	Positioning_1()
	{
		qDebug() << "Positioning: Positioning_1";
	}

	void Process() override;
};

class Positioning_2 : public Positioning
{
public:
	Positioning_2()
	{
		qDebug() << "Positioning: Positioning_2";
	}

	void Process() override;
};

class InspectMethod
{
public:
	InspectMethod()
	{

	}

	virtual void Process() = 0;
};

class InspectMethod_1 : public InspectMethod
{
public:
	InspectMethod_1()
	{
		qDebug() << "InspectMethod: InspectMethod_1";
	}

	void Process() override;
};

class InspectMethod_2 : public InspectMethod
{
public:
	InspectMethod_2()
	{
		qDebug() << "InspectMethod: InspectMethod_2";
	}

	void Process() override;
};