#include <gtest/gtest.h>

#include "minimum-depth-of-binary-tree.h"

using namespace coding::tree;
using namespace min_tree_depth;

TEST(min_tree_depth, empty)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_EQ(s.minDepth(
                p = DeserializedBinaryTree("")), 0);
    FreeBinaryTree(p);
}

TEST(min_tree_depth, one)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_EQ(s.minDepth(
                p = DeserializedBinaryTree("1")), 1);
    FreeBinaryTree(p);
}

TEST(min_tree_depth, basic)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_EQ(s.minDepth(
                p = DeserializedBinaryTree("1 2")), 2);
    FreeBinaryTree(p);
    EXPECT_EQ(s.minDepth(
                p = DeserializedBinaryTree("1 2 3")), 2);
    FreeBinaryTree(p);
    EXPECT_EQ(s.minDepth(
                p = DeserializedBinaryTree("1 2 3 # # 4 5")), 2);
    FreeBinaryTree(p);
    EXPECT_EQ(s.minDepth(
                p = DeserializedBinaryTree("1 2 3 4 # 4 5")), 3);
    FreeBinaryTree(p);
    EXPECT_EQ(s.minDepth(
                p = DeserializedBinaryTree("1 # 2 # 3 # 4 # 5")), 5);
    FreeBinaryTree(p);
    EXPECT_EQ(s.minDepth(
                p = DeserializedBinaryTree("1 2 # 3 # 4 # 5")), 5);
    FreeBinaryTree(p);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
