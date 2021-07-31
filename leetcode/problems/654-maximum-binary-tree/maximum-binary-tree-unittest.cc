#include <gtest/gtest.h>
#include <string>

#include "maximum-binary-tree.h"

using namespace binary;
using std::string;

TEST(binary, basic)
{
    Solution s;
    TreeNode *p = nullptr;
    vector<int> vec;
    string ans;
    vec = {3, 2, 1, 6, 0, 5};
    p = s.constructMaximumBinaryTree(vec);
    ans = "6 3 5 # 2 0 # # 1 # # # # ";
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
    vec = {3, 2, 1, 8, 0, 6, 5, 7};
    p = s.constructMaximumBinaryTree(vec);
    ans = "8 3 7 # 2 6 # # 1 0 5 # # # # # # ";
    EXPECT_EQ(SerializedBinaryTree(p), ans);
    FreeBinaryTree(p);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
