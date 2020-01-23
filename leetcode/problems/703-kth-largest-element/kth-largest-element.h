#ifndef KTH_LARGEST_ELEMENT_H_
#define KTH_LARGEST_ELEMENT_H_
#include <vector>

namespace klargest {

using std::vector;

class KthLargest {
    int *min_heap_;
    int size_;
    int k_;
    void Adjust(int idx);
    void Insert(int idx);
public:
    KthLargest(int k, vector<int>& nums);
    ~KthLargest();
    int add(int val);
};

}

#endif /* KTH_LARGEST_ELEMENT_H_ */
