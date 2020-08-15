#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>

#include <coding/vec.h>
#include "bucket-sort.h"

using namespace sort;
using namespace coding::vec;
using std::vector;

TEST(bucket_sort, empty)
{
    EXPECT_TRUE(IsVectorEqual({}, BucketSort::sort({})));
}

TEST(bucket_sort, one)
{
    EXPECT_TRUE(IsVectorEqual({1}, BucketSort::sort({1})));
}

TEST(bucket_sort, basic)
{
    EXPECT_TRUE(IsVectorEqual({1, 2, 3}, BucketSort::sort({2, 1, 3})));
}

TEST(bucket_sort, full_bucket)
{
    vector<int> vec;
    for (int i = 0; i < 1000; ++i) {
        vec.push_back(i);
    }

    EXPECT_TRUE(IsVectorEqual(vec, BucketSort::sort(vec)));
}

TEST(bucket_sort, random)
{
    srand(time(NULL));
    for (int run = 0; run < 1000; ++run) {
        vector<int> vec;
        vector<int> ans;

        int num = rand() % 1000;
        for (int i = 0; i < num; ++i) {
            int x = (rand() % 10000);
            vec.push_back(x);
        }
        ans = vec;
        std::sort(ans.begin(), ans.end());
        EXPECT_TRUE(IsVectorEqual(ans, BucketSort::sort(vec)));
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
