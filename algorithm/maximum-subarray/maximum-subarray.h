#ifndef MAXIMUM_SUBARRAY_H_
#define MAXIMUM_SUBARRAY_H_
#include <utility>
#include <vector>

namespace subarr {

class MaxSubarray {
    static std::pair<const int, const int>
    FindMaxSubarray(const std::vector<int> &vec,
            const int front, const int end, int *max_sum);
    static std::pair<const int, const int>
    FindMaxCrossarray(const std::vector<int> &vec,
            const int front, const int mid, const int end, int *max_sum);

public:
    static int FindMaxSum(const std::vector<int> &vec);
    static int BruteFindMaxSum(const std::vector<int> &vec);
};

}

#endif /* MAXIMUM_SUBARRAY_H_ */
