#include <cmath>
#include <climits>

#include "maximum-subarray.h"

namespace subarr {

using std::vector;

std::pair<const int, const int>
MaxSubarray::FindMaxSubarray(const vector<int> &vec,
        const int front,
        const int end,
        int *max_sum)
{
    if (front == end) {
        *max_sum = vec[front];
        return std::make_pair(front, front);
    }
    const int mid = floor((double) (front + end) / 2.0);
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int cross_sum = INT_MIN;
    auto left = FindMaxSubarray(vec, front, mid, &left_sum);
    auto right = FindMaxSubarray(vec, mid + 1, end, &right_sum);
    auto cross = FindMaxCrossarray(vec, front, mid, end, &cross_sum);

    if (left_sum >= right_sum && left_sum >= cross_sum) {
        *max_sum = left_sum;
        return left;
    } else if (right_sum > left_sum && right_sum >= cross_sum) {
        *max_sum = right_sum;
        return right;
    } else {
        *max_sum = cross_sum;
        return cross;
    }
}

std::pair<const int, const int>
MaxSubarray::FindMaxCrossarray(const vector<int> &vec,
        const int front,
        const int mid,
        const int end,
        int *max_sum)
{
    if (front > mid || end < (mid + 1)) {
        *max_sum = INT_MIN;
        return std::make_pair(front, front);
    }
    int left = mid;
    int right = mid;
    int sum = 0;
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    for (int i = mid; i >= front; --i) {
        sum += vec[i];
        if (sum > left_sum) {
            left = i;
            left_sum = sum;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= end; ++i) {
        sum += vec[i];
        if (sum > right_sum) {
            right = i;
            right_sum = sum;
        }
    }
    *max_sum = left_sum + right_sum;
    return std::make_pair(left, right);
}

int MaxSubarray::FindMaxSum(const vector<int> &vec)
{
    int sum = 0;
    FindMaxSubarray(vec, 0, vec.size() - 1, &sum);
    return sum;
}

int MaxSubarray::BruteFindMaxSum(const vector<int> &vec)
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
