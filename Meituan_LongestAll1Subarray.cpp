//
// Created by hfq on 9/10/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestLen(std::vector<int>& nums, int k) {
        int n = nums.size();
        nums.push_back(0);
        int maxLen = 0;
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                k--;
            }
            if(k < 0) {
                while(j < n && nums[j] == 1) {
                    j++;
                }
                j++;
                k++;
            }
            maxLen = std::max(i - j + 1, maxLen);
        }
        return maxLen;
    }
};

int main(int argc, char** argv) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    auto sol = Solution();
    std::cout << sol.longestLen(nums, k) << std::endl;
    return 0;
}
