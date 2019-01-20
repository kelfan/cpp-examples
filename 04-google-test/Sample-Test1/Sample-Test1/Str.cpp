#include "pch.h"
#include "Str.h"


Str::Str(string txt)
{
	content = txt;
}

Str::~Str()
{
}

string Str::getContent()
{
	return content;
}
