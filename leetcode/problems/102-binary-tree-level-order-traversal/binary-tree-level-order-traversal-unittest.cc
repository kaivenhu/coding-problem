#include <vector>
#include <string>

#include <coding/tree.h>
#include <coding/vec.h>
#include <gtest/gtest.h>

#include "binary-tree-level-order-traversal.h"

using namespace traverse_tree;
using namespace coding::tree;
using namespace coding::vec;
using std::vector;
using std::string;


TEST(traverse_tree, empty)
{
    Solution s;
    string x;
    TreeNode *p = nullptr;
    x = "";
    EXPECT_TRUE(IsVectorEqual<vector<int>>(
            s.levelOrder(p = DeserializedBinaryTree(x)),
            {}));
    FreeBinaryTree(p);
}

TEST(traverse_tree, test_1)
{
    Solution s;
    string x;
    TreeNode *p = nullptr;
    x = "3 9 20 # # 15 7";
    EXPECT_TRUE(IsVectorEqual<vector<int>>(
            s.levelOrder(p = DeserializedBinaryTree(x)),
            {{3}, {9, 20}, {15, 7}}));
    FreeBinaryTree(p);
}

TEST(traverse_tree, test_2)
{
    Solution s;
    string x;
    TreeNode *p = nullptr;
    x = "1 # 2 # 3 # 4 # 5";
    EXPECT_TRUE(IsVectorEqual<vector<int>>(
            s.levelOrder(p = DeserializedBinaryTree(x)),
            {{1}, {2}, {3}, {4}, {5}}));
    FreeBinaryTree(p);
}

TEST(traverse_tree, test_3)
{
    Solution s;
    string x;
    TreeNode *p = nullptr;
    x = "1 2 # 3 # 4 # 5";
    EXPECT_TRUE(IsVectorEqual<vector<int>>(
            s.levelOrder(p = DeserializedBinaryTree(x)),
            {{1}, {2}, {3}, {4}, {5}}));
    FreeBinaryTree(p);
}

TEST(traverse_tree, test_4)
{
    Solution s;
    string x;
    TreeNode *p = nullptr;
    x = "1 2 3 4 5 6 7";
    EXPECT_TRUE(IsVectorEqual<vector<int>>(
            s.levelOrder(p = DeserializedBinaryTree(x)),
            {{1}, {2, 3}, {4, 5, 6, 7}}));
    FreeBinaryTree(p);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
