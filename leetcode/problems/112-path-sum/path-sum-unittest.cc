#include <gtest/gtest.h>
#include <coding/tree.h>

#include "path-sum.h"

using namespace path_sum;
using namespace coding::tree;

TEST(path_sum, true)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_TRUE(s.hasPathSum(
                p = DeserializedBinaryTree("1"), 1));
    FreeBinaryTree(p);
    EXPECT_TRUE(s.hasPathSum(
                p = DeserializedBinaryTree("1 5 3"), 4));
    FreeBinaryTree(p);
    EXPECT_TRUE(s.hasPathSum(
                p = DeserializedBinaryTree("1 5 3 4"), 4));
    FreeBinaryTree(p);
}

TEST(path_sum, false)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_FALSE(s.hasPathSum(
                p = DeserializedBinaryTree(""), 0));
    FreeBinaryTree(p);
    EXPECT_FALSE(s.hasPathSum(
                p = DeserializedBinaryTree("1 5 4"), 4));
    FreeBinaryTree(p);
    EXPECT_FALSE(s.hasPathSum(
                p = DeserializedBinaryTree("1 5 3 4"), 6));
    FreeBinaryTree(p);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
