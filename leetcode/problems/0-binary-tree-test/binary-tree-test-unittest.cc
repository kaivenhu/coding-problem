#include <iostream>
#include <cstdlib>
#include <ctime>

#include <gtest/gtest.h>
#include <coding/tree.h>
#include <coding/red-black-tree.h>

#include "binary-tree-test.h"

using namespace binary_tree;
using namespace coding::tree;
using std::cout;
using std::endl;

TEST(binary_tree, large_random)
{
    for (int run = 0; run < 5; ++run) {
        RBTree rbtree;
        int num = rand() % 100;
        bool is_valid = false;
        for (int i = 0; i < num; ++i) {
            int val = rand() % 1000;
            if (!rbtree.IsExistVal(val)) {
                rbtree.Insert(val);
            }
        }
        EXPECT_TRUE((is_valid = IsValidBst(rbtree.root())));
        if (!is_valid) {
            cout << SerializedBinaryTree(rbtree.root()) << endl;
        }
    }
}

TEST(binary_tree, short_random)
{
    for (int run = 0; run < 5; ++run) {
        RBTree rbtree;
        int num = rand() % 20;
        for (int i = 0; i < num; ++i) {
            int val = rand() % 100;
            if (!rbtree.IsExistVal(val)) {
                rbtree.Insert(val);
            }
        }
        EXPECT_TRUE(IsValidBst(rbtree.root()));
        cout << SerializedBinaryTree(rbtree.root()) << endl;
    }
}

TEST(binary_tree, basic)
{
    RBTree rbtree;
    for (auto x : {1, 2, 3, 4, 5, 6, 7, 8}) {
        rbtree.Insert(x);
    }
    EXPECT_TRUE(IsValidBst(rbtree.root()));
    cout << SerializedBinaryTree(rbtree.root()) << endl;
}

TEST(binary_tree, one)
{
    RBTree rbtree;
    rbtree.Insert(1);
    EXPECT_TRUE(IsValidBst(rbtree.root()));
    cout << SerializedBinaryTree(rbtree.root()) << endl;
}

TEST(binary_tree, empty)
{
    RBTree rbtree;
    EXPECT_TRUE(IsValidBst(rbtree.root()));
    cout << SerializedBinaryTree(rbtree.root()) << endl;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
