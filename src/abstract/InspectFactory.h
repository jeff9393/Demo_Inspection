#pragma once

#include "../interface/Modules.h"

/* announcement */
class Product1;
class Product2;

class InspectFactory
{
public:
	enum PRODUCT_TYPE
	{
		PRODUCT_1 = 1,
		PRODUCT_2
	};

	static InspectFactory *Create(PRODUCT_TYPE factory);

	/* interface */
	virtual Autofocus *GetAutofocus() = 0;
	virtual Positioning *GetPositioning() = 0;
	virtual InspectMethod *GetInspectMethod() = 0;

};

class Product1 : public InspectFactory
{
public:
	Autofocus *GetAutofocus() override
	{
		return new Autofocus_1();
	}

	Positioning *GetPositioning() override
	{
		return new Positioning_2();
	}

	InspectMethod *GetInspectMethod() override
	{
		return new InspectMethod_1();
	}
};

class Product2 : public InspectFactory
{
public:
	Autofocus *GetAutofocus() override
	{
		return new Autofocus_2();
	}

	Positioning *GetPositioning() override
	{
		return new Positioning_1();
	}

	InspectMethod *GetInspectMethod() override
	{
		return new InspectMethod_2();
	}
};

