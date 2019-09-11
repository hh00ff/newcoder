//
// Created by hfq on 9/11/19.
//
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minPrice(const std::vector<int>& nums, int x) {
        int n = nums.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(x+1, 0));
        for(int j = 0; j <= x; j++) {
            if(nums[0] >= j) {
                dp[0][j] = nums[0];
            }
            else {
                dp[0][j] = -1;
            }
        }
        int curPrice = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= x; j++) {
                // use nums[i]
                if(nums[i] >= j) {
                    curPrice = nums[i];
                }
                else {
                    curPrice = dp[i-1][j-nums[i]];
                    if(curPrice <= 0) {
                        curPrice = -1;
                    }
                    else {
                        curPrice += nums[i];
                    }
                }

                // not use nums[i]
                if(dp[i-1][j] <= 0) {
                    dp[i][j] = curPrice;
                }
                else {
                    if(curPrice > 0) {
                        dp[i][j] = std::min(dp[i-1][j], curPrice);
                    }
                    else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[n-1][x];
    }
};


int main(int argc, char** argv) {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> nums(n);
    for(auto& num : nums) {
        std::cin >> num;
    }
    auto sol = Solution();
    std::cout << sol.minPrice(nums, x) << std::endl;
    return 0;
}