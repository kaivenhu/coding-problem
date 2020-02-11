#include <gtest/gtest.h>
#include <coding/tree.h>

#include "balanced-binary-tree.h"

using namespace balanced_tree;
using namespace coding::tree;

TEST(balanced_tree, valid)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_TRUE(s.isBalanced(
                p = DeserializedBinaryTree("")));
    FreeBinaryTree(p);
    EXPECT_TRUE(s.isBalanced(
                p = DeserializedBinaryTree("1")));
    FreeBinaryTree(p);
    EXPECT_TRUE(s.isBalanced(
                p = DeserializedBinaryTree("1 2 3")));
    FreeBinaryTree(p);
    EXPECT_TRUE(s.isBalanced(
                p = DeserializedBinaryTree("1 2 3 4 # # 5")));
    FreeBinaryTree(p);
    EXPECT_TRUE(s.isBalanced(
                p = DeserializedBinaryTree("1 2 3 4 5 6 7 8 # # # 9 # 10")));
    FreeBinaryTree(p);
}

TEST(balanced_tree, invalid)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_FALSE(s.isBalanced(
                p = DeserializedBinaryTree("1 2 # 3")));
    FreeBinaryTree(p);
    EXPECT_FALSE(s.isBalanced(
                p = DeserializedBinaryTree("1 2 3 4 # # 5 6")));
    FreeBinaryTree(p);
    EXPECT_FALSE(s.isBalanced(
                p = DeserializedBinaryTree("1 2 3 4 5 # 6 7 8 # 9 # 10")));
    FreeBinaryTree(p);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
