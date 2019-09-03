//
// Created by hfq on 2019/8/31.
//
#include <iostream>
#include <string>

class Solution {
public:
    Solution(int n, int m) {
        numa = n;
        numz = m;
    }

    std::string dictionary(int k) {
        std::string res(numa + numz, 'a');
        long long comb;
        for(int i = 0; i < res.size(); i++) {

            if(k == 1) {
                for(int j = i + numa; j < i + numa + numz; j++) {
                    res[j] = 'z';
                }
                break;
            }

            comb = combination(res.size()-i-1, numz, k);
            if(comb > 0 && k > comb) {
                res[i] = 'z';
                numz--;
                k -= comb;
            }
            else {
                numa--;
            }
        }
        return res;
    }

    long long combination(int n, int m, int k) {
        if(m > n) {
            return -1;
        }
        if(m > n / 2) {
            m = n - m;
        }
        long long res = 1;
        for(int i = 0; i < m; i++) {
            res *= n-i;
            res /= i + 1;
            if(res > k) {
                return -1;
            }
        }
        return res;
    }

    int numa;
    int numz;
};

int main(int argc, char** argv) {
    int n = 0, m = 0, k = 0;
    std::cin >> n >> m >> k;
    auto sol = Solution(n, m);

    long long comb = sol.combination(n + m, n, k);
    if(comb != -1 && comb < k) {
        std::cout << -1 << std::endl;
    }
    else {
        auto&& res = sol.dictionary(k);
        std::cout << res << std::endl;
    }
    return 0;
}
