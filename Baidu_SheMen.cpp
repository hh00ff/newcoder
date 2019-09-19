//
// Created by hfq on 9/17/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int calcScore(std::vector<std::pair<int, int>>& gates, std::vector<int>& balls) {
        std::sort(gates.begin(), gates.end(),
                [&](std::pair<int, int> a, std::pair<int, int> b) {return a.first < b.first;});
        std::sort(balls.begin(), balls.end());
        std::vector<std::pair<int, int>> newgates;
        int curbeg = 0, curend = 0;
        for(int i = 0; i < gates.size(); i++) {
            if(gates[i].first <= curend) {
                if(gates[i].second > curend) {
                    curend = gates[i].second;
                }
                continue;
            }
            else {
                newgates.emplace_back(curbeg, curend);
                curbeg = gates[i].first;
                curend = gates[i].second;
            }

        }
        newgates.emplace_back(curbeg, curend);
        int i = 0, j = 0, score = 0;
        while(i < balls.size()) {
            if(j == newgates.size()) {
                break;
            }
            if(newgates[j].first <= balls[i] && newgates[j].second >= balls[i]) {
                score++;
                i++;
            }
            else {
                j++;
            }
        }
        return score;
    }
};

int main(int argc, char** argv) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> gates(n);
    std::vector<int> balls(m);
    for(int i = 0; i < n; i++) {
        std::cin >> gates[i].first >> gates[i].second;
    }
    for(int i = 0; i < m; i++) {
        std::cin >> balls[i];
    }
    auto sol = Solution();
    std::cout << sol.calcScore(gates, balls) << std::endl;
    return 0;
}