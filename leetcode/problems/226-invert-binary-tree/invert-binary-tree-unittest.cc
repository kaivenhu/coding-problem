#include <string>

#include <gtest/gtest.h>
#include <coding/tree.h>

#include "invert-binary-tree.h"

using namespace invert_tree;
using namespace coding::tree;
using std::string;

TEST(invert_tree, basic)
{
    Solution s;
    TreeNode *p = nullptr;
    string test;
    string ans;
    test = "";
    ans = "# ";
    EXPECT_EQ(
            SerializedBinaryTree(
                s.invertTree(
                p = DeserializedBinaryTree(test))),
            ans);
    FreeBinaryTree(p);
    test = "1";
    ans = "1 # # ";
    EXPECT_EQ(
            SerializedBinaryTree(
                s.invertTree(
                p = DeserializedBinaryTree(test))),
            ans);
    FreeBinaryTree(p);
    test = "1 2 3";
    ans = "1 3 2 # # # # ";
    EXPECT_EQ(
            SerializedBinaryTree(
                s.invertTree(
                p = DeserializedBinaryTree(test))),
            ans);
    FreeBinaryTree(p);
    test = "1 2 3 4 5 6 7 ";
    ans = "1 3 2 7 6 5 4 # # # # # # # # ";
    EXPECT_EQ(
            SerializedBinaryTree(
                s.invertTree(
                p = DeserializedBinaryTree(test))),
            ans);
    FreeBinaryTree(p);
    test = "1 2 3 4 # # 7 ";
    ans = "1 3 2 7 # # 4 # # # # ";
    EXPECT_EQ(
            SerializedBinaryTree(
                s.invertTree(
                p = DeserializedBinaryTree(test))),
            ans);
    FreeBinaryTree(p);
    test = "1 # 2 # 3 # 4 # 5";
    ans = "1 2 # 3 # 4 # 5 # # # ";
    EXPECT_EQ(
            SerializedBinaryTree(
                s.invertTree(
                p = DeserializedBinaryTree(test))),
            ans);
    FreeBinaryTree(p);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
