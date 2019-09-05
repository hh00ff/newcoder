//
// Created by hfq on 9/5/19.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int maxVal(int n, int k) {
        k = k > n ? n : k;
        std::vector<int> vals(n);
        std::vector<int> awake(n);
        for(int i = 0; i < n; i++) {
            std::cin >> vals[i];
        }
        for(int i = 0; i < n; i++) {
            std::cin >> awake[i];
        }

        int res = 0, sum0 = 0, max0 = 0;
        for(int i = 0; i < n; i++) {
            if(awake[i] == 1) {
                res += vals[i];
            }
            else {
                sum0 += vals[i];
            }
            if(i - k >= 0) {
                sum0 -= awake[i-k] == 0 ? vals[i-k] : 0;
            }
            max0 = sum0 > max0 ? sum0 : max0;
        }

        res += max0;
        return res;
    }
};

int main(int argc, char** argv) {
    int n, k;
    std::cin >> n >> k;
    auto sol = Solution();
    std::cout << sol.maxVal(n, k) << std::endl;
    return 0;
}