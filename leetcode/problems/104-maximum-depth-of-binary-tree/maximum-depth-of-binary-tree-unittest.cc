#include <gtest/gtest.h>
#include <coding/tree.h>

#include "maximum-depth-of-binary-tree.h"

using namespace tree_depth;
using namespace coding::tree;

TEST(tree_depth, basic)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_EQ(s.maxDepth(
                p = DeserializedBinaryTree("")),
            0);
    FreeBinaryTree(p);
    EXPECT_EQ(s.maxDepth(
                p = DeserializedBinaryTree("1")),
            1);
    FreeBinaryTree(p);
    EXPECT_EQ(s.maxDepth(
                p = DeserializedBinaryTree("1 2 3")),
            2);
    FreeBinaryTree(p);
    EXPECT_EQ(s.maxDepth(
                p = DeserializedBinaryTree("3 9 20 # # 15 7")),
            3);
    FreeBinaryTree(p);
    EXPECT_EQ(s.maxDepth(
                p = DeserializedBinaryTree("1 # 2 # 3 # 4 # 5")),
            5);
    FreeBinaryTree(p);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
