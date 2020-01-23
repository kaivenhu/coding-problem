#ifndef LAST_STONE_WEIGHT_H_
#define LAST_STONE_WEIGHT_H_
#include <vector>

namespace stoneweight {

using std::vector;

class Solution {
    int *max_heap_ = nullptr;
    int size_ = 0;
    int rear_ = 0;
    void AdjustBottom(int idx);
    void AdjustTop(int idx);
    int PopMax(void);
    void Push(int val);
public:
    Solution() = default;
    ~Solution();
    int lastStoneWeight(const vector<int>& stones);
};

}

#endif /* LAST_STONE_WEIGHT_H_ */
