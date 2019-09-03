//
// Created by hfq on 9/3/19.
//

#include <iostream>

class Solution {
public:
    int exactDivision(int begin, int end) {
        int res = 0;
        if(begin > end) {
            return res;
        }
        if(begin % 3 == 2) {
            begin++;
            res++;
        }
        if(begin > end) {
            return res;
        }
        if(begin % 3 == 0) {
            begin++;
            res++;
        }
        if(begin > end) {
            return res;
        }
        if(end % 3 == 0) {
            end--;
            res++;
        }
        if(begin > end) {
            return res;
        }
        if(end % 3 == 2) {
            end--;
            res++;
        }
        if(begin > end) {
            return res;
        }
        res += 2 * (end - begin) / 3;
        return res;
    }
};

int main(int argc, char** argv) {
    int l, r;
    std::cin >> l >> r;
    auto sol = Solution();
    auto&& res = sol.exactDivision(l, r);
    std::cout << res << std::endl;
    return 0;
}