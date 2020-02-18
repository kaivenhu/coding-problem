#include <gtest/gtest.h>
#include <coding/tree.h>

#include "subtree-of-another-tree.h"

using namespace sub_tree;
using namespace coding::tree;

TEST(sub_tree, true)
{
    Solution s;
    TreeNode *p = nullptr;
    TreeNode *q = nullptr;
    EXPECT_TRUE(s.isSubtree(
                p = DeserializedBinaryTree(""),
                q = DeserializedBinaryTree("")));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
    EXPECT_TRUE(s.isSubtree(
                p = DeserializedBinaryTree("3 4 5 1 2"),
                q = DeserializedBinaryTree("4 1 2")));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
    EXPECT_TRUE(s.isSubtree(
                p = DeserializedBinaryTree("3 4 5 1 2"),
                q = DeserializedBinaryTree("5")));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
    EXPECT_TRUE(s.isSubtree(
                p = DeserializedBinaryTree("3 4 5 1 2 # # # # 0"),
                q = DeserializedBinaryTree("2 0")));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
    EXPECT_TRUE(s.isSubtree(
                p = DeserializedBinaryTree("1"),
                q = DeserializedBinaryTree("1")));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
}

TEST(sub_tree, false)
{
    Solution s;
    TreeNode *p = nullptr;
    TreeNode *q = nullptr;
    EXPECT_FALSE(s.isSubtree(
                p = DeserializedBinaryTree("12"),
                q = DeserializedBinaryTree("2")));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
    EXPECT_FALSE(s.isSubtree(
                p = DeserializedBinaryTree(""),
                q = DeserializedBinaryTree("1")));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
    EXPECT_FALSE(s.isSubtree(
                p = DeserializedBinaryTree("1"),
                q = DeserializedBinaryTree("")));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
    EXPECT_FALSE(s.isSubtree(
                p = DeserializedBinaryTree("3 4 5 1 2"),
                q = DeserializedBinaryTree("4 1")));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
    EXPECT_FALSE(s.isSubtree(
                p = DeserializedBinaryTree("3 4 5 1 2 # # # # 0"),
                q = DeserializedBinaryTree("4 1 2")));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
