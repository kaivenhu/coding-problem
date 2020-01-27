#include <string>

#include <gtest/gtest.h>
#include <coding/tree.h>

#include "validate-binary-search-tree.h"

using namespace binary_tree;
using namespace coding::tree;
using std::string;

TEST(binary_tree, valid)
{
    TreeNode *root = nullptr;
    string s;
    s = "2 1 3";
    EXPECT_TRUE(IsValidBst((root = DeserializedBinaryTree(s))));
    FreeBinaryTree(root);
    EXPECT_TRUE(IsValidBst(nullptr));
    s = "1";
    EXPECT_TRUE(IsValidBst((root = DeserializedBinaryTree(s))));
    FreeBinaryTree(root);
    s = "4 2 7 1 3 5 8 # # # # # # # 9";
    EXPECT_TRUE(IsValidBst((root = DeserializedBinaryTree(s))));
    FreeBinaryTree(root);
}

TEST(binary_tree, invalid)
{
    TreeNode *root = nullptr;
    string s;
    s = "1 1";
    EXPECT_FALSE(IsValidBst((root = DeserializedBinaryTree(s))));
    FreeBinaryTree(root);
    s = "5 1 4 # # 3 6";
    EXPECT_FALSE(IsValidBst((root = DeserializedBinaryTree(s))));
    FreeBinaryTree(root);
    s = "4 2 7 1 3 5 8 # # # # 6 # 7 #";
    EXPECT_FALSE(IsValidBst((root = DeserializedBinaryTree(s))));
    FreeBinaryTree(root);
    s = "4 2 7 1 3 5 8 # # # # 4 # 9 #";
    EXPECT_FALSE(IsValidBst((root = DeserializedBinaryTree(s))));
    FreeBinaryTree(root);
    s = "4 2 7 1 3 5 8 # # # # 4 # 7 #";
    EXPECT_FALSE(IsValidBst((root = DeserializedBinaryTree(s))));
    FreeBinaryTree(root);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
