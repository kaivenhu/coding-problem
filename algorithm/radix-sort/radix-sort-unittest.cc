#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>

#include <coding/vec.h>
#include "radix-sort.h"

using namespace sort;
using namespace coding::vec;
using std::vector;

TEST(radix_sort, empty)
{
    EXPECT_TRUE(IsVectorEqual({}, RadixSort::sort({})));
}

TEST(radix_sort, one)
{
    EXPECT_TRUE(IsVectorEqual({1}, RadixSort::sort({1})));
}

TEST(radix_sort, basic)
{
    EXPECT_TRUE(IsVectorEqual({1, 2, 3}, RadixSort::sort({2, 1, 3})));
}

TEST(radix_sort, two_digit)
{
    EXPECT_TRUE(IsVectorEqual({1, 12, 13, 24, 25, 36, 37, 48}, RadixSort::sort({37, 48, 25, 36, 12, 1, 13, 24})));
}

TEST(radix_sort, random)
{
    srand(time(NULL));
    for (int run = 0; run < 1000; ++run) {
        vector<int> vec;
        vector<int> ans;

        int num = rand() % 1000;
        for (int i = 0; i < num; ++i) {
            int x = (rand() % 1000);
            vec.push_back(x);
        }
        ans = vec;
        std::sort(ans.begin(), ans.end());
        EXPECT_TRUE(IsVectorEqual(ans, RadixSort::sort(vec)));
    }
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
