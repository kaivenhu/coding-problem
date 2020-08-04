#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>

#include <coding/vec.h>
#include "quick-sort.h"

using namespace sort;
using namespace coding::vec;
using std::vector;

TEST(quick_sort, empty)
{
    EXPECT_TRUE(IsVectorEqual({}, QuickSort::sort({})));
}

TEST(quick_sort, one)
{
    EXPECT_TRUE(IsVectorEqual({1}, QuickSort::sort({1})));
}

TEST(quick_sort, basic)
{
    EXPECT_TRUE(IsVectorEqual({1, 2, 3}, QuickSort::sort({2, 1, 3})));
}

TEST(quick_sort, sequence)
{
    EXPECT_TRUE(IsVectorEqual({1, 2, 3, 4, 5, 6, 7, 8}, QuickSort::sort({1, 2, 3, 4, 5, 6, 7, 8})));
}

TEST(quick_sort, reverse)
{
    EXPECT_TRUE(IsVectorEqual({1, 2, 3, 4, 5, 6, 7, 8}, QuickSort::sort({8, 7, 6, 5, 4, 3, 2, 1})));
}

TEST(quick_sort, random)
{
    srand(time(NULL));
    for (int run = 0; run < 1000; ++run) {
        vector<int> vec;
        vector<int> ans;

        int num = rand() % 1000;
        for (int i = 0; i < num; ++i) {
            int x = (rand() % 1000) - 500;
            vec.push_back(x);
        }
        ans = vec;
        std::sort(ans.begin(), ans.end());
        EXPECT_TRUE(IsVectorEqual(ans, QuickSort::sort(vec)));
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
