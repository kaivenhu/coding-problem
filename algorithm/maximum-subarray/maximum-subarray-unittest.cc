#include <cstdlib>
#include <ctime>

#include <gtest/gtest.h>

#include "maximum-subarray.h"

using namespace subarr;
using std::vector;

TEST(subarr, one)
{
    vector<int> x = {1234};
    EXPECT_EQ(1234, MaxSubarray::BruteFindMaxSum(x));
    EXPECT_EQ(1234, MaxSubarray::FindMaxSum(x));
    x = {-4321};
    EXPECT_EQ(-4321, MaxSubarray::BruteFindMaxSum(x));
    EXPECT_EQ(-4321, MaxSubarray::FindMaxSum(x));
}

TEST(subarr, postive)
{
    vector<int> x = {1, 2, 3, 4};
    EXPECT_EQ(10, MaxSubarray::BruteFindMaxSum(x));
    EXPECT_EQ(10, MaxSubarray::FindMaxSum(x));
}

TEST(subarr, negative)
{
    vector<int> x = {-1, -2, -3, -4};
    EXPECT_EQ(-1, MaxSubarray::BruteFindMaxSum(x));
    EXPECT_EQ(-1, MaxSubarray::FindMaxSum(x));
}

TEST(subarr, random)
{
    srand(time(NULL));
    for (int run = 0; run < 100; ++run) {
        vector<int> vec;

        int num = rand() % 1000;
        for (int i = 0; i < num; ++i) {
            int x = (rand() % 1000) - 500;
            vec.push_back(x);
        }
        EXPECT_EQ(MaxSubarray::BruteFindMaxSum(vec), MaxSubarray::FindMaxSum(vec));
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
