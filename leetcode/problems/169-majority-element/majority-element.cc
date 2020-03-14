#include <cmath>
#include <climits>
#include <algorithm>

#include "majority-element.h"

namespace major_elem {

using std::vector;

size_t Solution::MergeSubArrayMajor(const vector<int> &nums,
        size_t low, size_t high, int *major)
{
    if (high == low) {
        *major = nums[low];
        return 1;
    }

    int l_major = 0;
    int r_major = 0;
    int middle = floor(float(low + high) / 2.0);
    int thr = ceil(float(high + 1 - low) / 2.0);

    int l_num = MergeSubArrayMajor(nums, low, middle, &l_major);
    int r_num = MergeSubArrayMajor(nums, middle + 1, high, &r_major);
    if (l_num != 0) {
        l_num += std::count(nums.begin() + middle + 1,
            nums.begin() + high + 1, l_major);
        if (l_num >= thr) {
            *major = l_major;
            return l_num;
        }
    }
    if (r_num != 0) {
        r_num += std::count(nums.begin() + low,
                nums.begin() + middle + 1, r_major);
        if (r_num >= thr) {
            *major = r_major;
            return r_num;
        }
    }
    return 0;
}

int Solution::BoyerMooreAlgorithm(const vector<int> &nums)
{
    int cand;
    int vote = 0;
    for (const auto &n : nums) {
        if (0 == vote) {
            cand = n;
        }
        if (n == cand) {
            ++vote;
        } else {
            --vote;
        }
    }
    return cand;
}

int Solution::majorityElement(const vector<int> &nums)
{
    return BoyerMooreAlgorithm(nums);
    /*
    int major = 0;
    if (0 == MergeSubArrayMajor(nums, 0, nums.size() - 1, &major)) {
        return nums[0];
    }
    return major;
    */
}

}
