#ifndef MAX_MIN_H_
#define MAX_MIN_H_
#include <utility>
#include <vector>

namespace max_min
{
class MaxMin
{
public:
    static std::pair<int, int> get(const std::vector<int> &src);
};

}  // namespace max_min

#endif /* MAX_MIN_H_ */
