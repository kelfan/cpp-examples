#include "pch.h"
#include "Str.h"

TEST(TestCaseName, TestName) {
	Str s = Str("success");
	EXPECT_EQ(s.getContent(), "success");
	EXPECT_TRUE(true);
}