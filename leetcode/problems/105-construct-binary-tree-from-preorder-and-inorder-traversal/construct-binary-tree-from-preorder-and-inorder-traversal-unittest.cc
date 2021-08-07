#include <gtest/gtest.h>
#include <string>

#include "construct-binary-tree-from-preorder-and-inorder-traversal.h"

using namespace order;
using std::string;

TEST(order, basic)
{
    Solution s;
    TreeNode *p = nullptr;
    vector<int> preorder;
    vector<int> inorder;
    string ans;

    preorder = {3, 9, 20, 15, 7};
    inorder = {9, 3, 15, 20, 7};
    p = s.buildTree(preorder, inorder);
    ans = "3 9 20 # # 15 7 # # # # ";
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
    preorder = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    inorder = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    p = s.buildTree(preorder, inorder);
    ans = "1 2 3 4 5 6 7 # # # # 8 9 # # # # # # ";
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
}

TEST(order, corner)
{
    Solution s;
    TreeNode *p = nullptr;
    vector<int> preorder;
    vector<int> inorder;
    string ans;

    preorder = {1, 2, 3, 4};
    inorder = {1, 2, 3, 4};
    p = s.buildTree(preorder, inorder);
    ans = "1 # 2 # 3 # 4 # # ";
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
    preorder = {1, 2, 3, 4};
    inorder = {4, 3, 2, 1};
    p = s.buildTree(preorder, inorder);
    ans = "1 2 # 3 # 4 # # # ";
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
    preorder = {1, 2, 3, 4, 5, 6, 7};
    inorder = {4, 7, 6, 5, 3, 2, 1};
    p = s.buildTree(preorder, inorder);
    ans = "1 2 # 3 # 4 # # 5 6 # 7 # # # ";
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
    preorder = {1, 2, 3, 4, 5, 6, 7};
    inorder = {4, 3, 7, 6, 5, 2, 1};
    p = s.buildTree(preorder, inorder);
    ans = "1 2 # 3 # 4 5 # # 6 # 7 # # # ";
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
