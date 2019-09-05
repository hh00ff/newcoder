//
// Created by hfq on 9/5/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findPile(std::vector<int>& piles, std::vector<std::pair<int, int>>& queries) {
        std::vector<int> res(queries.size(), 0);
        int sum = 0;
        std::sort(queries.begin(), queries.end(),
                [&](std::pair<int, int> a, std::pair<int, int> b)->int {return a.first < b.first;});
        int i = 0, j = 0;
        while(i < piles.size()) {
            while(queries[j].first > sum && queries[j].first <= sum + piles[i]) {
                res[queries[j].second] = i + 1;
                j++;
            }
            sum += piles[i];
            i++;
        }
        return res;
    }
};

int main(int argc, char** argv) {
    int n, m;
    std::cin >> n;
    std::vector<int> piles(n);
    for(int i = 0; i < n; i++) {
        std::cin >> piles[i];
    }
    std::cin >> m;
    std::vector<std::pair<int, int>> queries(m);
    for(int i = 0; i < m; i++) {
        std::cin >> queries[i].first;
        queries[i].second = i;
    }
    auto sol = Solution();
    auto&& res = sol.findPile(piles, queries);
    for(int i = 0; i < m; i++) {
        std::cout << res[i] << std::endl;
    }
    return 0;
}