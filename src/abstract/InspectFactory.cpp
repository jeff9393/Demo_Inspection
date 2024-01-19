#include "InspectFactory.h"

InspectFactory* InspectFactory::Create(PRODUCT_TYPE product)
{
	InspectFactory* factory = nullptr;

	switch (product)
	{
	case PRODUCT_1:
		factory = new Product1();
		break;
	case PRODUCT_2:
		factory = new Product2();
		break;
	default:
		break;
	}

	return factory;
}