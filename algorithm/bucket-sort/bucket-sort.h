#ifndef BUCKET_SORT_H_
#define BUCKET_SORT_H_
#include <vector>

namespace sort
{
class BucketSort
{
    struct Node {
        int val;
        Node *next;
        Node(int x) : val(x), next(nullptr) {}
    };
    static void InsertBucket(std::vector<Node *> &vec, int hash, int val);

public:
    static std::vector<int> sort(const std::vector<int> &src);
};

}  // namespace sort

#endif /* BUCKET_SORT_H_ */
