#pragma once

#include <QDebug>

/* announcement */
class Autofocus;
class Autofocus_1;
class Autofocus_2;
class Positioning;
class Positioning_1;
class Positioning_2;
class InspectMethod;
class InspectMethod_1;
class InspectMethod_2;

class Autofocus
{
public:
	Autofocus()
	{

	}

	virtual bool Process() = 0;
};

class Autofocus_1 : public Autofocus
{
public:
	Autofocus_1()
	{
		qDebug() << "Autofocus: Autofocus_1";
	}

	bool Process() override;
};

class Autofocus_2 : public Autofocus
{
public:
	Autofocus_2()
	{
		qDebug() << "Autofocus: Autofocus_2";
	}

	bool Process() override;
};

class Positioning
{
public:
	Positioning()
	{

	}

	virtual bool Process() = 0;
};

class Positioning_1 : public Positioning
{
public:
	Positioning_1()
	{
		qDebug() << "Positioning: Positioning_1";
	}

	bool Process() override;
};

class Positioning_2 : public Positioning
{
public:
	Positioning_2()
	{
		qDebug() << "Positioning: Positioning_2";
	}

	bool Process() override;
};

class InspectMethod
{
public:
	InspectMethod()
	{

	}

	virtual bool Process() = 0;
};

class InspectMethod_1 : public InspectMethod
{
public:
	InspectMethod_1()
	{
		qDebug() << "InspectMethod: InspectMethod_1";
	}

	bool Process() override;
};

class InspectMethod_2 : public InspectMethod
{
public:
	InspectMethod_2()
	{
		qDebug() << "InspectMethod: InspectMethod_2";
	}

	bool Process() override;
};