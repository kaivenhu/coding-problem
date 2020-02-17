#include <gtest/gtest.h>
#include <coding/tree.h>
#include <coding/vec.h>

#include "find-mode-in-binary-search-tree.h"

using namespace bst_mode;
using namespace coding::tree;
using namespace coding::vec;
using std::vector;

TEST(bst_mode, empty)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_TRUE(IsVectorEqual<int>(
                s.findMode(p = DeserializedBinaryTree("")),
                {}));
    FreeBinaryTree(p);
}

TEST(bst_mode, one)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_TRUE(IsVectorEqual<int>(
                s.findMode(p = DeserializedBinaryTree("1")),
                {1}));
    FreeBinaryTree(p);
}

TEST(bst_mode, test_1)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_TRUE(IsVectorEqual<int>(
                s.findMode(p = DeserializedBinaryTree("1 # 2 2 ")),
                {2}));
    FreeBinaryTree(p);
}

TEST(bst_mode, test_2)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_TRUE(IsVectorEqual<int>(
                s.findMode(p = DeserializedBinaryTree("1 # 2 2 4 # # 4")),
                {2, 4}));
    FreeBinaryTree(p);
}

TEST(bst_mode, test_3)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_TRUE(IsVectorEqual<int>(
                s.findMode(p = DeserializedBinaryTree("1 1 2 0 1 2 4 # # # # # # 4")),
                {1}));
    FreeBinaryTree(p);
}

TEST(bst_mode, test_4)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_TRUE(IsVectorEqual<int>(
                s.findMode(p = DeserializedBinaryTree("1 1 2 0 # 2 4 # # # # 4")),
                {1, 2, 4}));
    FreeBinaryTree(p);
}

TEST(bst_mode, test_5)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_TRUE(IsVectorEqual<int>(
                s.findMode(p = DeserializedBinaryTree("1 1 2 0 # 2 4 # # # # 4 4")),
                {4}));
    FreeBinaryTree(p);
}

TEST(bst_mode, test_6)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_TRUE(IsVectorEqual<int>(
                s.findMode(p = DeserializedBinaryTree("1 # 2")),
                {1, 2}));
    FreeBinaryTree(p);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
