#include <algorithm>
#include <cstdlib>

#include <gtest/gtest.h>
#include <coding/vec.h>

#include "insertion-sort.h"

using namespace insertion;
using namespace coding::vec;
using std::vector;

TEST(insertion, empty)
{
    EXPECT_TRUE(IsVectorEqual({}, InsertSort::sort({})));
}

TEST(insertion, one)
{
    EXPECT_TRUE(IsVectorEqual({1}, InsertSort::sort({1})));
}

TEST(insertion, basic)
{
    EXPECT_TRUE(IsVectorEqual({1, 2, 3}, InsertSort::sort({2, 1, 3})));
}

TEST(insertion, random)
{
    for (int run = 0; run < 100; ++run) {
        vector<int> vec;
        vector<int> ans;

        int num = rand() % 1000;
        for (int i = 0; i < num; ++i) {
            vec.push_back(rand());
        }
        ans = vec;
        std::sort(ans.begin(), ans.end());
        EXPECT_TRUE(IsVectorEqual(ans, InsertSort::sort(vec)));
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
