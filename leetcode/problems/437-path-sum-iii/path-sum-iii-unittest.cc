#include <gtest/gtest.h>

#include "path-sum-iii.h"

using namespace path_sum;
using namespace coding::tree;

TEST(path_sum, empty)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_EQ(s.pathSum(
                p = DeserializedBinaryTree(""), 1), 0);
    FreeBinaryTree(p);
}

TEST(path_sum, one)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_EQ(s.pathSum(
                p = DeserializedBinaryTree("1"), 1), 1);
    FreeBinaryTree(p);
    EXPECT_EQ(s.pathSum(
                p = DeserializedBinaryTree("0"), 1), 0);
    FreeBinaryTree(p);
}

TEST(path_sum, basic)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_EQ(s.pathSum(
                p = DeserializedBinaryTree("1 1 1"), 1), 3);
    FreeBinaryTree(p);
    EXPECT_EQ(s.pathSum(
                p = DeserializedBinaryTree("1 1 1"), 2), 2);
    FreeBinaryTree(p);
    EXPECT_EQ(s.pathSum(
                p = DeserializedBinaryTree("10 5 -3 3 2 # 11 3 -2 # 1"), 8), 3);
    FreeBinaryTree(p);
    EXPECT_EQ(s.pathSum(
                p = DeserializedBinaryTree("10 5 -3 3 2 # 11 3 -2 # 1 # # # # -8"), 8), 4);
    FreeBinaryTree(p);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
