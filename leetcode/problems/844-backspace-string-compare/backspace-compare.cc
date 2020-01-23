#include <algorithm>

#include "backspace-compare.h"

namespace solution {

bool Solution::backspaceCompare(string S, string T)
{
    int run = std::max(S.size(), T.size());
    std::string::reverse_iterator s_riter = S.rbegin();
    std::string::reverse_iterator t_riter = T.rbegin();
    int s_mask = 0;
    int t_mask = 0;

    for (int i = 0; i < run; i++) {
        for (; s_riter != S.rend(); ++s_riter) {
            if ('#' == *s_riter) {
                s_mask++;
            } else if (s_mask) {
                s_mask--;
            } else {
                break;
            }
        }
        for (; t_riter != T.rend(); ++t_riter) {
            if ('#' == *t_riter) {
                t_mask++;
            } else if (t_mask) {
                t_mask--;
            } else {
                break;
            }
        }
        if ((s_riter == S.rend())
            || (t_riter == T.rend())) {
            return (s_riter == S.rend()) & (t_riter == T.rend());
        } else if (*t_riter != *s_riter) {
            return false;
        } else {
            s_riter++;
            t_riter++;
        }
    }

    return true;
}

}
