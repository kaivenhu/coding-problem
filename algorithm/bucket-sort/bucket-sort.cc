#include <cassert>
#include <cmath>

#include <algorithm>

#include "bucket-sort.h"

#define BUCKET_SIZE 1000

namespace sort
{
using std::vector;

void BucketSort::InsertBucket(vector<Node *> &buckets, int hash, int val)
{
    int idx = val / hash;
    assert(idx < BUCKET_SIZE);

    Node *x = new Node(val);
    Node **cur = &(buckets[idx]);
    for (; *cur && val >= (*cur)->val; cur = &((*cur)->next)) {
        ;
    }
    x->next = *cur;
    *cur = x;
}

vector<int> BucketSort::sort(const vector<int> &src)
{
    if (!src.size()) {
        return vector<int>();
    }

    int hash =
        (*std::max_element(src.begin(), src.end()) / (BUCKET_SIZE - 1)) + 1;

    vector<Node *> buckets(BUCKET_SIZE, nullptr);

    for (const auto x : src) {
        InsertBucket(buckets, hash, x);
    }
    vector<int> ret;
    Node *cur, *tmp;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        cur = buckets[i];
        while (cur) {
            ret.push_back(cur->val);
            tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
    return ret;
}

}  // namespace sort
