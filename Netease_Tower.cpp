//
// Created by hfq on 9/6/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> calcMove(std::vector<std::pair<int, int>>& nums, int k) {
        int curUnstable = 0;
        std::vector<std::vector<int>> res(k+1, std::vector<int>(2, 0));
        for(int i = 0; i < k; i++) {
            std::sort(nums.begin(), nums.end(),
                    [&](std::pair<int, int> a, std::pair<int, int> b) -> int {return a.first < b.first;});
            curUnstable = nums.back().first - nums[0].first;
            if(curUnstable == 0 || curUnstable == 1) {
                res[0][0] = curUnstable;
                res[0][1] = i;
                return res;
            }
            nums[0].first++;
            nums.back().first--;
            res[i+1][0] = nums.back().second;
            res[i+1][1] = nums[0].second;
        }
        std::sort(nums.begin(), nums.end(),
                  [&](std::pair<int, int> a, std::pair<int, int> b) -> int {return a.first < b.first;});
        curUnstable = nums.back().first - nums[0].first;
        res[0][0] = curUnstable;
        res[0][1] = k;
        return res;
    }
};

int main(int argc, char** argv) {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> nums(n);
    for(int i = 0; i < n; i++) {
        std::cin >> nums[i].first;
        nums[i].second = i + 1;
    }
    auto sol = Solution();
    auto&& res = sol.calcMove(nums, k+1);
    std::cout << res[0][0] << ' ' << res[0][1] << std::endl;
    for(int i = 0; i < res[0][1]; i++) {
        std::cout << res[i+1][0] << ' ' << res[i+1][1] << std::endl;
    }
    return 0;
}
