#include <gtest/gtest.h>

#include "queue-stack.h"

using namespace queuestack;

TEST (MinStackTest, basic) {
    MyStack stack;
    stack.push(-2);
    stack.push(0);
    stack.push(-3);
    EXPECT_EQ(-3, stack.pop());
    EXPECT_EQ(0, stack.pop());
    EXPECT_EQ(-2, stack.top());
    EXPECT_EQ(-2, stack.pop());
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(2, stack.top());
    stack.push(-3);
    EXPECT_EQ(-3, stack.top());
    stack.push(3);
    stack.pop();
    stack.pop();
    EXPECT_EQ(2, stack.top());
}

TEST (MinStackTest, test_1) {
    MyStack stack;
    stack.push(512);
    stack.push(-1024);
    stack.push(-1024);
    stack.push(512);
    EXPECT_EQ(512, stack.top());
    stack.pop();
    EXPECT_EQ(-1024, stack.top());
    stack.pop();
    EXPECT_EQ(-1024, stack.top());
    stack.pop();
    EXPECT_EQ(512, stack.top());
    EXPECT_FALSE(stack.empty());
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST (MinStackTest, onlyone) {
    MyStack stack;
    stack.push(-2);
    EXPECT_EQ(-2, stack.top());
    EXPECT_FALSE(stack.empty());
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST (MinStackTest, test_2) {
    MyStack stack;
    stack.push(85);
    stack.push(-99);
    stack.push(67);
    EXPECT_EQ(67, stack.top());
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
    EXPECT_EQ(-66, stack.top());
    stack.push(-89);
    EXPECT_EQ(-89, stack.top());
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
