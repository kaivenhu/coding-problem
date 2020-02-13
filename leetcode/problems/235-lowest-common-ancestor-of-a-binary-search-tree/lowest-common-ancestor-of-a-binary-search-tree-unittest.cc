#include <gtest/gtest.h>
#include <coding/tree.h>

#include "lowest-common-ancestor-of-a-binary-search-tree.h"

using namespace common_ancestor;
using namespace coding::tree;

TEST(common_ancestor, basic)
{
    Solution s;
    TreeNode *p = nullptr;
    TreeNode *r = nullptr;
    r = s.lowestCommonAncestorBase(
            p = DeserializedBinaryTree("1"), 1, 1);
    EXPECT_EQ(r->val, 1);
    FreeBinaryTree(p);
    r = s.lowestCommonAncestorBase(
            p = DeserializedBinaryTree("6 2 8 0 4 7 9 # # 3 5"), 2, 8);
    EXPECT_EQ(r->val, 6);
    FreeBinaryTree(p);
    r = s.lowestCommonAncestorBase(
            p = DeserializedBinaryTree("6 2 8 0 4 7 9 # # 3 5"), 2, 7);
    EXPECT_EQ(r->val, 6);
    FreeBinaryTree(p);
    r = s.lowestCommonAncestorBase(
            p = DeserializedBinaryTree("6 2 8 0 4 7 9 # # 3 5"), 2, 7);
    EXPECT_EQ(r->val, 6);
    FreeBinaryTree(p);
    r = s.lowestCommonAncestorBase(
            p = DeserializedBinaryTree("6 2 8 0 4 7 9 # # 3 5"), 0, 9);
    EXPECT_EQ(r->val, 6);
    FreeBinaryTree(p);
    r = s.lowestCommonAncestorBase(
            p = DeserializedBinaryTree("6 2 8 0 4 7 9 # # 3 5"), 2, 5);
    EXPECT_EQ(r->val, 2);
    FreeBinaryTree(p);
    r = s.lowestCommonAncestorBase(
            p = DeserializedBinaryTree("6 2 8 0 4 7 9 # # 3 5"), 0, 3);
    EXPECT_EQ(r->val, 2);
    FreeBinaryTree(p);
    r = s.lowestCommonAncestorBase(
            p = DeserializedBinaryTree("6 2 8 0 4 7 9 # # 3 5"), 3, 5);
    EXPECT_EQ(r->val, 4);
    FreeBinaryTree(p);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
