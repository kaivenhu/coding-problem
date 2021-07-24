#include <string>
#include <gtest/gtest.h>

#include "flatten-binary-tree-to-linked-list.h"

using namespace flatten;
using std::string;

TEST(flatten, empty)
{
    Solution s;
    TreeNode *p = nullptr;
    string test;
    string ans;
    test = "";
    ans = "# ";
    p = DeserializedBinaryTree(test);
    s.flatten(p);
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
    test = "1";
    ans = "1 # # ";
    p = DeserializedBinaryTree(test);
    s.flatten(p);
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
}

TEST(flatten, one_side)
{
    Solution s;
    TreeNode *p = nullptr;
    string test;
    string ans;
    test = "1 # 2 # 3 # 4 # 5 # #";
    ans = "1 # 2 # 3 # 4 # 5 # # ";
    p = DeserializedBinaryTree(test);
    s.flatten(p);
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
    test = "1 2 # 3 # 4 # 5 # # #";
    ans = "1 # 2 # 3 # 4 # 5 # # ";
    p = DeserializedBinaryTree(test);
    s.flatten(p);
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
}

TEST(flatten, basic)
{
    Solution s;
    TreeNode *p = nullptr;
    string test;
    string ans;
    test = "1 2 5 3 4 # 6 # # # # # #";
    ans = "1 # 2 # 3 # 4 # 5 # 6 # # ";
    p = DeserializedBinaryTree(test);
    s.flatten(p);
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
