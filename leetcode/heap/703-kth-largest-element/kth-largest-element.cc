#include "kth-largest-element.h"

namespace klargest {

KthLargest::KthLargest(int k, vector<int>& nums)
{
    if (nullptr == (min_heap_ = new int[k])) {
        return;
    }
    size_ = 0;
    k_ = k;
    for (unsigned int i = 0 ;
            i < (unsigned int) k && i < nums.size(); i++) {
        min_heap_[i] = nums[i];
        size_++;
    }
    for (int j = ((k - 1) - 1) / 2; j >= 0; j--) {
        Adjust(j);
    }
    for (unsigned int i = k; i < nums.size(); i++) {
        add(nums[i]);
    }
}

KthLargest::~KthLargest()
{
    if (min_heap_) {
        delete [] min_heap_;
    }
}

void KthLargest::Adjust(int idx)
{
    int left_idx = (idx + 1) * 2 - 1;
    int right_idx = (idx + 1) * 2;
    int adjust_idx = 0;

    if (left_idx >= size_) {
        return;
    } else if (right_idx >= size_) {
        adjust_idx = left_idx;
    } else if (min_heap_[left_idx] < min_heap_[right_idx]) {
        adjust_idx = left_idx;
    } else {
        adjust_idx = right_idx;
    }
    if (min_heap_[idx] > min_heap_[adjust_idx]) {
        int tmp = min_heap_[idx];
        min_heap_[idx] = min_heap_[adjust_idx];
        min_heap_[adjust_idx] = tmp;
        Adjust(adjust_idx);
    }
}

void KthLargest::Insert(int idx)
{
    int parent_idx = (idx - 1) / 2;
    if (idx <= 0) {
        return;
    }

    if (min_heap_[parent_idx] > min_heap_[idx]) {
        auto tmp = min_heap_[idx];
        min_heap_[idx] = min_heap_[parent_idx];
        min_heap_[parent_idx] = tmp;
        Insert(parent_idx);
    }
}

int KthLargest::add(int val)
{
    if (nullptr == min_heap_) {
        return -1;
    }
    if (size_ < k_) {
        min_heap_[size_] = val;
        Insert(size_);
        size_++;
    } else if (val > min_heap_[0]) {
        min_heap_[0] = val;
        Adjust(0);
    }

    return min_heap_[0];
}

}
