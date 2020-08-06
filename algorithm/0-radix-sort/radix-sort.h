#ifndef RADIX_SORT_H_
#define RADIX_SORT_H_
#include <vector>

namespace sort {

class RadixSort {
public:
    static std::vector<int> sort(const std::vector<int> &src);
private:
    static std::vector<int> counting_sort(const std::vector<int> &src, int digit);
};


}

#endif /* RADIX_SORT_H_ */
