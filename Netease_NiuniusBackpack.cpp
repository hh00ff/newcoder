//
// Created by hfq on 9/4/19.
//

#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    int selectSlacks(std::vector<int>& slacks, int volume) {
        long long sum = 0;
        for(auto& s : slacks) {
            sum += s;
        }
        if(sum <= volume) {
            return (int)pow(2, slacks.size());
        }
        return selectSlacksCore(slacks, 0, volume);
    }

    int selectSlacksCore(std::vector<int>& slacks, int begin, int volume) {
        if(begin == slacks.size() - 1) {
            if(slacks[begin] <= volume) {
                return 2;
            }
            else {
                return 1;
            }
        }
        if(slacks[begin] <= volume) {
            return selectSlacksCore(slacks, begin + 1, volume) +
                        selectSlacksCore(slacks, begin + 1, volume - slacks[begin]);
        }
        else {
            return selectSlacksCore(slacks, begin + 1, volume);
        }
    }
};

int main(int argc, char** argv) {
    int n, v, s;
    std::cin >> n >> v;
    std::vector<int> slacks(n);
    for(int i = 0; i < n; i++) {
        std::cin >> s;
        slacks[i] = s;
    }

    auto sol = Solution();
    std::cout << sol.selectSlacks(slacks, v) << std::endl;
    return 0;
}