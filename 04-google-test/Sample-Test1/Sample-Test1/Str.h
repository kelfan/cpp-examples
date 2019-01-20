#include <string>
using namespace std;

#pragma once
class Str
{
public:
	string content = "";
	Str(string txt);
	~Str();

	string getContent();
};

