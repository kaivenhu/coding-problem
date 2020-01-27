#include <gtest/gtest.h>
#include <coding/tree.h>

#include "symmetric-tree.h"

using namespace symmetric_tree;
using namespace coding::tree;

TEST(symmetric_tree, valid)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_TRUE(s.isSymmetric(
                p = DeserializedBinaryTree("")));
    FreeBinaryTree(p);
    EXPECT_TRUE(s.isSymmetric(
                p = DeserializedBinaryTree("1")));
    FreeBinaryTree(p);
    EXPECT_TRUE(s.isSymmetric(
                p = DeserializedBinaryTree("1 2 2 3 4 4 3")));
    FreeBinaryTree(p);
    EXPECT_TRUE(s.isSymmetric(
                p = DeserializedBinaryTree("1 2 2")));
    FreeBinaryTree(p);
    EXPECT_TRUE(s.isSymmetric(
                p = DeserializedBinaryTree("1 2 2 3 4 4 3 7 # # # # # # 7")));
    FreeBinaryTree(p);
    EXPECT_TRUE(s.isSymmetric(
                p = DeserializedBinaryTree("1 2 2 # 3 3 # 5 # # 5")));
    FreeBinaryTree(p);
}

TEST(symmetric_tree, invalid)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_FALSE(s.isSymmetric(
                p = DeserializedBinaryTree("1 2 2 3 4 4 3 7 # # # # # 7 #")));
    FreeBinaryTree(p);
    EXPECT_FALSE(s.isSymmetric(
                p = DeserializedBinaryTree("1 2 1")));
    FreeBinaryTree(p);
    EXPECT_FALSE(s.isSymmetric(
                p = DeserializedBinaryTree("1 2 2 # 3 # 3")));
    FreeBinaryTree(p);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
