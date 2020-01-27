#include <iostream>

#include <gtest/gtest.h>
#include <coding/tree.h>
#include <coding/red-black-tree.h>

#include "binary-tree-test.h"

using namespace binary_tree;
using namespace coding::tree;
using std::cout;
using std::endl;

TEST(binary_tree, basic)
{
    RBTree rbtree;
    for (auto x : {1, 2, 3, 4, 5, 6, 7, 8}) {
        rbtree.Insert(x);
    }
    cout << SerializedBinaryTree(rbtree.root()) << endl;
}

TEST(binary_tree, one)
{
    RBTree rbtree;
    rbtree.Insert(1);
    cout << SerializedBinaryTree(rbtree.root()) << endl;
}

TEST(binary_tree, empty)
{
    RBTree rbtree;
    cout << SerializedBinaryTree(rbtree.root()) << endl;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
