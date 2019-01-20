#include "pch.h"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;

TEST(TestExternal, Test2) {
	cout << "external test2" << endl;
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}