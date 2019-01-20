#include "pch.h"
#include <iostream>
#include "../App/methods.h"
#include "../App/Out.h"
using namespace std;

TEST(TestCaseName, TestName) {
	cout << "hello test" << endl;
	outputTest();
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCaseName, TestOut) {
	Out o;
	o.setId(10);
	EXPECT_EQ(10, o.getId());
}

TEST(TestOut, TestError) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}