#include <algorithm>
#include <cstdlib>

#include <gtest/gtest.h>
#include <coding/vec.h>

#include "merge-sort.h"

using namespace merge_sort;
using namespace coding::vec;
using std::vector;

TEST(merge_sort, empty)
{
    EXPECT_TRUE(IsVectorEqual({}, MergeSort::sort({})));
}

TEST(merge_sort, one)
{
    EXPECT_TRUE(IsVectorEqual({1}, MergeSort::sort({1})));
}

TEST(merge_sort, basic)
{
    EXPECT_TRUE(IsVectorEqual({1, 2, 3}, MergeSort::sort({2, 1, 3})));
}

TEST(merge_sort, random)
{
    for (int run = 0; run < 1000; ++run) {
        vector<int> vec;
        vector<int> ans;

        int num = rand() % 1000;
        for (int i = 0; i < num; ++i) {
            vec.push_back(rand());
        }
        ans = vec;
        std::sort(ans.begin(), ans.end());
        EXPECT_TRUE(IsVectorEqual(ans, MergeSort::sort(vec)));
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
