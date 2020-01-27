#include <string>

#include <gtest/gtest.h>
#include <coding/tree.h>
#include <coding/red-black-tree.h>

#include "serialize-and-deserialize-binary-tree.h"

using namespace binary_tree;
using namespace coding::tree;
using std::string;

TEST(binary_tree, basic)
{
    TreeNode *root = nullptr;
    string s;
    s = "# ";
    EXPECT_EQ(SerializedBinaryTree((root = DeserializedBinaryTree(s))), s);
    FreeBinaryTree(root);
    s = "1 2 3 # # 4 5 # # # # ";
    EXPECT_EQ(SerializedBinaryTree((root = DeserializedBinaryTree(s))), s);
    FreeBinaryTree(root);
    s = "1 2 3 4 5 # # # # # # ";
    EXPECT_EQ(SerializedBinaryTree((root = DeserializedBinaryTree(s))), s);
    FreeBinaryTree(root);
    s = "1 # 2 # 3 # 4 # 5 # # ";
    EXPECT_EQ(SerializedBinaryTree((root = DeserializedBinaryTree(s))), s);
    FreeBinaryTree(root);
    s = "1 # # ";
    EXPECT_EQ(SerializedBinaryTree((root = DeserializedBinaryTree(s))), s);
    FreeBinaryTree(root);
    s = "1 2 # 3 # 4 # 5 # 6 # 7 # # # ";
    EXPECT_EQ(SerializedBinaryTree((root = DeserializedBinaryTree(s))), s);
    FreeBinaryTree(root);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
