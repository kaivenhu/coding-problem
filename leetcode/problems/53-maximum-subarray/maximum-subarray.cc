#include <climits>

#include "maximum-subarray.h"

namespace max_subarr {

using std::vector;

int Solution::maxSubArray(const vector<int> &nums) {
    int max_sum = INT_MIN;
    int sum = 0;
    for (auto n : nums) {
        sum += n;
        if (sum > max_sum) {
            max_sum = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return max_sum;
}

}
