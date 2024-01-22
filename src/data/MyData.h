#pragma once

#include <iostream>
using namespace std;

class DependencyData
{
public:
	DependencyData()
	{
		src_image = "";
		positioning_image = "";
		inspect_pass = false;
	}

	string src_image;
	string positioning_image;
	bool inspect_pass;
};
