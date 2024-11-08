#include <gtest/gtest.h>
#include "Time.h"

TEST(InitTests, ParamConstructor) {
	Time t(3, 0, 10);
	EXPECT_EQ(t.GetSeconds(), 10);
	EXPECT_EQ(t.GetMinutes(), 0);
	EXPECT_EQ(t.GetHours(), 3);
}
TEST(InitTests, CopyConstructor) {
	Time t2(3, 0, 10);
	Time t(t2);
	EXPECT_EQ(t.GetSeconds(), 10);
	EXPECT_EQ(t.GetMinutes(), 0);
	EXPECT_EQ(t.GetHours(), 3);
}
TEST(InitTests, DefaultConstructor) {
	Time t;
	EXPECT_EQ(t.GetSeconds(), 0);
	EXPECT_EQ(t.GetMinutes(), 0);
	EXPECT_EQ(t.GetHours(), 0);
}

TEST(Setters, SetSeconds) {
	Time t(0, 0, 0);
	EXPECT_EQ(t.GetSeconds(), 0);
	t.SetSeconds(5);
	EXPECT_EQ(t.GetSeconds(), 5);
}
TEST(Setters, SetMinutes) {
	Time t(0, 0, 0);
	EXPECT_EQ(t.GetMinutes(), 0);
	t.SetMinutes(5);
	EXPECT_EQ(t.GetMinutes(), 5);
}
TEST(Setters, SetHours) {
	Time t(0, 0, 0);
	EXPECT_EQ(t.GetHours(), 0);
	t.SetHours(5);
	EXPECT_EQ(t.GetHours(), 5);
}

TEST(Operators, Add) {
	Time t(0, 0, 4);
	Time t2(0, 0, 9);
	EXPECT_EQ(t.GetSeconds() + 5, 9);

	t += 9;
	EXPECT_EQ(t.GetSeconds(), 13);
}
TEST(Operators, Sub) {
	Time t(0, 0, 4);
	Time t2(0, 0, 9);
	EXPECT_EQ(t2.GetSeconds() - 5, 4);

	t2 -= 4;
	EXPECT_EQ(t2.GetSeconds(), 5);
}

TEST(OperatorsBool, EqualsOp) {
	Time t(1, 3, 4);
	Time t2(1, 3, 4);
	EXPECT_TRUE(t == t2);
}
TEST(OperatorsBool, NotEqualsOp) {
	Time t(1, 12, 4);
	Time t2(1, 3, 52);
	EXPECT_TRUE(t != t2);
}
TEST(OperatorsBool, Greater) {
	Time t(1, 12, 4);
	Time t2(1, 3, 52);
	EXPECT_TRUE(t > t2);
}
TEST(OperatorsBool, GreaterOrEqual) {
	Time t(1, 12, 4);
	Time t2(1, 3, 52);
	EXPECT_TRUE(t >= t2);
	Time t3(1, 3, 52);
	EXPECT_TRUE(t2 >= t3);
}
TEST(OperatorsBool, Lesser) {
	Time t(1, 12, 4);
	Time t2(1, 3, 52);
	EXPECT_TRUE(t2 < t);
}
TEST(OperatorsBool, LesserOrEqual) {
	Time t(1, 12, 4);
	Time t2(1, 3, 52);
	EXPECT_TRUE(t2 <= t);
	Time t3(1, 3, 52);
	EXPECT_TRUE(t3 <= t2);
}