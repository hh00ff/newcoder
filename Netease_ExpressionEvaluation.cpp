//
// Created by hfq on 9/6/19.
//

#include <iostream>
#include <algorithm>

class Solution {
public:
    int maxValue(int a, int b, int c) {
        int res = 0;
        int res0 = a + b + c;
        res = std::max(res0, res);
        res0 = a * b * c;
        res = std::max(res0, res);
        res0 = (a + b) * c;
        res = std::max(res0, res);
        res0 = a + b * c;
        res = std::max(res0, res);
        res0 = a * b + c;
        res = std::max(res0, res);
        res0 = a * (b + c);
        res = std::max(res0, res);
        return res;
    }
};

int main(int argc, char** argv) {
    int a, b, c;
    std::cin >> a >> b >> c;
    auto sol = Solution();
    std::cout << sol.maxValue(a, b, c) << std::endl;
    return 0;
}