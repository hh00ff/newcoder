//
// Created by hfq on 9/4/19.
//

#include <iostream>
#include <algorithm>

class Solution {
public:
    long long countPairs(int n, int k) {
        if(n < 1 || k < 0 || k > n - 1) {
            return 0;
        }
        long long count = 0;
        for(int i = std::max(1, k); i <= n; i++) {
            count += n / i * (i - k);
            if(n % i >= k)
                if(k)
                    count += n % i - k + 1;
                else
                    count += n % i;
        }
        return count;
    }
};

int main(int argc, char** argv) {
    int n, k;
    std::cin >> n >> k;
    auto sol = Solution();
    std::cout << sol.countPairs(n, k) << std::endl;
    return 0;
}