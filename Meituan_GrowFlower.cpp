//
// Created by hfq on 9/11/19.
//
#include <iostream>
#include <vector>

class Solution {
public:
    int calcDays(const std::vector<int>& nums) {
        std::vector<int> vStack;
        int res = 0, tmp = 0;
        for(auto& num : nums) {
            if(vStack.empty()) {
                vStack.push_back(num);
            }
            else {
                while(!vStack.empty() && num <= vStack.back()) {
                    tmp = vStack.back();
                    vStack.pop_back();
                    res += vStack.empty() ? tmp - num : tmp - std::max(vStack.back(), num);
                }
                vStack.push_back(num);
            }
        }
        res += vStack.back();
        return res;
    }
};

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(auto& num : nums) {
        std::cin >> num;
    }
    auto sol = Solution();
    std::cout << sol.calcDays(nums) << std::endl;
    return 0;
}