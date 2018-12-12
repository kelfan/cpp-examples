// App.cpp : This file contains the 'main' function. Program execution begins and ends there.
// todo
// [*] function
// [*] reference
// [*] class
// [*] unit test
// [ ] patterns
//

#include "pch.h"
#include <iostream>
#include "methods.h"
#include "Out.h"
#include "MySql.h"

using namespace std;

/*
	test function
*/
void output2() {
	cout << "output2" << endl;
}

int main()
{
	output2();
	output3();
	Out out;
	out.setId(10);
	cout << out.getId() << endl;
	MySql mysql;
	cout << "Hello World!\n"; // output hello world
    std::cout << "Hello World!\n"; 
	outputTest();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
