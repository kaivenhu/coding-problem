#include <gtest/gtest.h>
#include <coding/tree.h>

#include "longest-univalue-path.h"

using namespace uni_path;
using namespace coding::tree;

TEST(uni_path, basic)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_EQ(s.longestUnivaluePath(
                p = DeserializedBinaryTree("")), 0);
    FreeBinaryTree(p);
    EXPECT_EQ(s.longestUnivaluePath(
                p = DeserializedBinaryTree("1")), 0);
    FreeBinaryTree(p);
    EXPECT_EQ(s.longestUnivaluePath(
                p = DeserializedBinaryTree("5 4 5 1 1 # 5")), 2);
    FreeBinaryTree(p);
    EXPECT_EQ(s.longestUnivaluePath(
                p = DeserializedBinaryTree("1 4 5 4 4 # 5")), 2);
    FreeBinaryTree(p);
    EXPECT_EQ(s.longestUnivaluePath(
                p = DeserializedBinaryTree("1 4 5 4 4 # 5 4 4")), 3);
    FreeBinaryTree(p);
    EXPECT_EQ(s.longestUnivaluePath(
                p = DeserializedBinaryTree("1 4 5 4 4 # 5 4 4 4 4")), 4);
    FreeBinaryTree(p);
    EXPECT_EQ(s.longestUnivaluePath(
                p = DeserializedBinaryTree("1 2 # 2 # 3 # 3 # 3")), 2);
    FreeBinaryTree(p);
    EXPECT_EQ(s.longestUnivaluePath(
                p = DeserializedBinaryTree("1 2 3 2 2 3 3 2")), 3);
    FreeBinaryTree(p);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
