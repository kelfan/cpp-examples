#include "pch.h"
#include "Out.h"
#include <iostream>
using namespace std;

Out::Out()
{
	std::cout << "the Out object will be constructed" << std::endl;
}


Out::~Out()
{
	std::cout << "the Out object will be destroyed" << std::endl;
}

void Out::setId(int num)
{
	id = num;
	cout << num << endl;
}

int Out::getId()
{
	return id;
}
