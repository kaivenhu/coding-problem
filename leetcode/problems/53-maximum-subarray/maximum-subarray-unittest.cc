#include <cstdlib>
#include <ctime>
#include <climits>

#include <gtest/gtest.h>

#include "maximum-subarray.h"

using namespace max_subarr;
using std::vector;

namespace {

int BruteFindMaxSum(const vector<int> &vec)
{
    int max_sum = INT_MIN;
    int sum = 0;
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i) {
        sum = 0;
        for (decltype(vec.size()) j = i; j < vec.size(); ++j) {
            sum += vec[j];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}

}

TEST(max_subarr, one)
{
    Solution s;
    vector<int> x = {1234};
    EXPECT_EQ(1234, BruteFindMaxSum(x));
    EXPECT_EQ(1234, s.maxSubArray(x));
    x = {-4321};
    EXPECT_EQ(-4321, BruteFindMaxSum(x));
    EXPECT_EQ(-4321, s.maxSubArray(x));
}

TEST(max_subarr, postive)
{
    Solution s;
    vector<int> x = {1, 2, 3, 4};
    EXPECT_EQ(10, BruteFindMaxSum(x));
    EXPECT_EQ(10, s.maxSubArray(x));
}

TEST(max_subarr, negative)
{
    Solution s;
    vector<int> x = {-1, -2, -3, -4};
    EXPECT_EQ(-1, BruteFindMaxSum(x));
    EXPECT_EQ(-1, s.maxSubArray(x));
}

TEST(max_subarr, random)
{
    Solution s;
    srand(time(NULL));
    for (int run = 0; run < 100; ++run) {
        vector<int> vec;

        int num = rand() % 1000;
        for (int i = 0; i < num; ++i) {
            int x = (rand() % 1000) - 500;
            vec.push_back(x);
        }
        EXPECT_EQ(BruteFindMaxSum(vec), s.maxSubArray(vec));
    }
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
