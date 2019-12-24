#include "last-stone-weight.h"

namespace stoneweight {


Solution::~Solution()
{
    if (max_heap_) {
        delete [] max_heap_;
    }
}

void Solution::AdjustBottom(int idx)
{
    int left_idx = (idx + 1) * 2 - 1;
    int right_idx = (idx + 1) * 2;
    int adjust_idx = 0;
    if (left_idx >= rear_) {
        return;
    } else if (right_idx >= rear_
        || max_heap_[left_idx] >= max_heap_[right_idx]) {
        adjust_idx = left_idx;
    } else {
        adjust_idx = right_idx;
    }
    if (max_heap_[adjust_idx] > max_heap_[idx]) {
        auto tmp = max_heap_[idx];
        max_heap_[idx] = max_heap_[adjust_idx];
        max_heap_[adjust_idx] = tmp;
        AdjustBottom(adjust_idx);
    }
}

void Solution::AdjustTop(int idx)
{
    int parent_idx = (idx - 1) / 2;
    if (0 >= idx) {
        return;
    }
    if (max_heap_[idx] > max_heap_[parent_idx]) {
        auto tmp = max_heap_[idx];
        max_heap_[idx] = max_heap_[parent_idx];
        max_heap_[parent_idx] = tmp;
        AdjustTop(parent_idx);
    }
}

int Solution::PopMax(void)
{
    int max_num = 0;
    if (0 >= rear_) {
        return -1;
    }
    max_num = max_heap_[0];
    rear_--;
    max_heap_[0] = max_heap_[rear_];
    AdjustBottom(0);
    return max_num;
}

void Solution::Push(int val)
{
    if (rear_ >= size_) {
        return;
    }
    max_heap_[rear_] = val;
    AdjustTop(rear_);
    rear_++;
}

int Solution::lastStoneWeight(const vector<int>& stones)
{
    if (max_heap_) {
        delete [] max_heap_;
        max_heap_ = nullptr;
    }
    rear_ = size_ = stones.size();
    max_heap_ = new int[size_];
    for (int i = 0; i < size_; i++) {
        max_heap_[i] = stones[i];
    }
    for (int j = ((size_ - 1) - 1) / 2;
            j >= 0; j--) {
        AdjustBottom(j);
    }
    while (1 < rear_) {
        int stone_1 = PopMax();
        int stone_2 = PopMax();
        if (stone_1 != stone_2) {
            Push(stone_1 - stone_2);
        }
    }
    if (0 == rear_) {
        return 0;
    } else {
        return max_heap_[0];
    }
}


}
