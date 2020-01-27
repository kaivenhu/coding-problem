#include <gtest/gtest.h>

#include "same-tree.h"

using namespace same_tree;
using namespace coding::tree;

TEST(same_tree, basic)
{
    Solution s;
    TreeNode *p = nullptr;
    TreeNode *q = nullptr;
    EXPECT_TRUE(s.isSameTree(
            (p = DeserializedBinaryTree("")),
            (q = DeserializedBinaryTree(""))));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
    EXPECT_TRUE(s.isSameTree(
            (p = DeserializedBinaryTree("1 2 3")),
            (q = DeserializedBinaryTree("1 2 3"))));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
    EXPECT_FALSE(s.isSameTree(
            (p = DeserializedBinaryTree("1 2")),
            (q = DeserializedBinaryTree("1 # 2"))));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
    EXPECT_FALSE(s.isSameTree(
            (p = DeserializedBinaryTree("1 2 1")),
            (q = DeserializedBinaryTree("1 1 2"))));
    FreeBinaryTree(p);
    FreeBinaryTree(q);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
