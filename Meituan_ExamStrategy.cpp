//
// Created by hfq on 9/11/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxScore(const std::vector<std::vector<int>>& ques) {
        int n = ques.size();
        const int maxTime = 120;
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(maxTime+1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= maxTime; j++) {
                if(j < ques[i-1][0]) {
                    dp[i][j] = dp[i-1][j];
                }
                else if(j < ques[i-1][2]) {
                    dp[i][j] = std::max(dp[i-1][j-ques[i-1][0]] + ques[i-1][1], dp[i-1][j]);
                }
                else {
                    dp[i][j] = std::max(dp[i-1][j-ques[i-1][0]] + ques[i-1][1],
                            std::max(dp[i-1][j], dp[i-1][j-ques[i-1][2]] + ques[i-1][3]));
                }
            }
        }
        return dp[n][maxTime];
    }
};

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> ques(n, std::vector<int>(4));
    for(auto& q : ques) {
        for(auto& x : q) {
            std::cin >> x;
        }
    }
    auto sol = Solution();
    std::cout << sol.maxScore(ques) << std::endl;
    return 0;
}