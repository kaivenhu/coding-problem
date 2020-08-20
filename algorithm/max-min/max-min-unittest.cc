#include <gtest/gtest.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "max-min.h"

using namespace max_min;
using std::pair;
using std::vector;

TEST(max_min, single)
{
    auto max_min = MaxMin::get({0});
    EXPECT_EQ(max_min.first, 0);
    EXPECT_EQ(max_min.second, 0);
}

TEST(max_min, two)
{
    auto max_min = MaxMin::get({0, 9});
    EXPECT_EQ(max_min.first, 9);
    EXPECT_EQ(max_min.second, 0);
}

TEST(max_min, three)
{
    auto max_min = MaxMin::get({-1, 0, 9});
    EXPECT_EQ(max_min.first, 9);
    EXPECT_EQ(max_min.second, -1);
}

TEST(max_min, basic)
{
    auto max_min = MaxMin::get({0, 2, 3, 5, 10, 50, -1, -4, -7, -99, 100, 30});
    EXPECT_EQ(max_min.first, 100);
    EXPECT_EQ(max_min.second, -99);
}

TEST(max_min, random)
{
    srand(time(NULL));
    for (int run = 0; run < 1000; ++run) {
        vector<int> vec;

        int num = rand() % 1000 + 1;
        for (int i = 0; i < num; ++i) {
            int x = (rand() % 10000) - 5000;
            vec.push_back(x);
        }
        auto max_min = MaxMin::get(vec);
        auto ans = std::minmax_element(vec.begin(), vec.end());
        EXPECT_EQ(max_min.first, *(ans.second));
        EXPECT_EQ(max_min.second, *(ans.first));
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
