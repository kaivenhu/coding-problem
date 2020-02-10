#include <gtest/gtest.h>

#include "convert-sorted-array-to-binary-search-tree.h"

using namespace convert_tree;
using namespace coding::tree;
using std::vector;

TEST(convert_tree, odd_num)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_EQ(SerializedBinaryTree(
                p = s.sortedArrayToBST({1, 2, 3})),
            "2 1 3 # # # # ");
    FreeBinaryTree(p);
}

TEST(convert_tree, even_num)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_EQ(SerializedBinaryTree(
                p = s.sortedArrayToBST({1, 2, 3, 4})),
            "3 2 4 1 # # # # # ");
    FreeBinaryTree(p);
}

TEST(convert_tree, one)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_EQ(SerializedBinaryTree(
                p = s.sortedArrayToBST({1})),
            "1 # # ");
    FreeBinaryTree(p);
}

TEST(convert_tree, empty)
{
    Solution s;
    TreeNode *p = nullptr;
    EXPECT_EQ(SerializedBinaryTree(
                p = s.sortedArrayToBST({})),
            "# ");
    FreeBinaryTree(p);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
