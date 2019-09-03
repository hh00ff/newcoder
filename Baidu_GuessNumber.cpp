//
// Created by hfq on 2019/8/28.
//
#include <iostream>

class Solution {
public:
    long guessNumber(long x, long y) {

        if(x + x - 1 < y) {
            return 0;
        }
        if(x >= y) {
            x = y - 1;
        }

        return x - y / 2;
    }
};

int main(int argc, char** argv) {
    long x, y;
    std::cin >> x >> y;
    auto sol = Solution();
    std::cout << sol.guessNumber(x, y) << std::endl;
    return 0;
}
