#include <gtest/gtest.h>

#include "min-stack.h"

TEST (MinStackTest, basic) {
    MinStack stack;
    stack.push(-2);
    stack.push(0);
    stack.push(-3);
    EXPECT_EQ(-3, stack.getMin());
    stack.pop();
    EXPECT_EQ(0, stack.top());
    EXPECT_EQ(-2, stack.getMin());
    stack.pop();
    EXPECT_EQ(-2, stack.top());
    EXPECT_EQ(-2, stack.getMin());
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(2, stack.top());
    stack.push(-3);
    EXPECT_EQ(-3, stack.getMin());
    stack.push(3);
    stack.pop();
    stack.pop();
    EXPECT_EQ(-2, stack.getMin());
}

TEST (MinStackTest, test_1) {
    MinStack stack;
    stack.push(512);
    stack.push(-1024);
    stack.push(-1024);
    stack.push(512);
    EXPECT_EQ(-1024, stack.getMin());
    stack.pop();
    EXPECT_EQ(-1024, stack.getMin());
    stack.pop();
    EXPECT_EQ(-1024, stack.getMin());
    stack.pop();
    EXPECT_EQ(512, stack.getMin());
}

TEST (MinStackTest, onlyone) {
    MinStack stack;
    stack.push(-2);
    EXPECT_EQ(-2, stack.getMin());
    EXPECT_EQ(-2, stack.top());
    stack.pop();
}

TEST (MinStackTest, test_2) {
    MinStack stack;
    stack.push(85);
    stack.push(-99);
    stack.push(67);
    EXPECT_EQ(-99, stack.getMin());
    stack.push(-27);
    stack.push(61);
    stack.push(-97);
    stack.push(-27);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.push(35);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    EXPECT_EQ(35, stack.top());
    stack.push(99);
    stack.push(-66);
    EXPECT_EQ(-99, stack.getMin());
    stack.push(-89);
    EXPECT_EQ(-99, stack.getMin());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
