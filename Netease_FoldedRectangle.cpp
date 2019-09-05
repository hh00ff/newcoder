//
// Created by hfq on 9/4/19.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int foldedRectangle(std::vector<int>& x1, std::vector<int>& x2, std::vector<int>& y1, std::vector<int>& y2) {
        // For each point of intersection, calculate the folded rectangles.
        std::vector<int> xa, ya;
        xa.reserve(2 * x1.size());
        ya.reserve(2 * y1.size());
        xa.insert(xa.end(), x1.begin(), x1.end());
        xa.insert(xa.end(), x2.begin(), x2.end());
        ya.insert(ya.end(), y1.begin(), y1.end());
        ya.insert(ya.end(), y2.begin(), y2.end());
        int res = 1;
        int tmpnum;
        for(auto& x : xa) {
            for(auto& y : ya) {
                tmpnum = 0;
                for(int i = 0; i < x1.size(); i++) {
                    if(x > x1[i] && y > y1[i] && x <= x2[i] && y <= y2[i]) {
                        tmpnum++;
                    }
                }
                res = tmpnum > res ? tmpnum : res;
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    std::vector<int> x1(n), x2(n), y1(n), y2(n);
    for(int i = 0; i < n; i++) {
        std::cin >> x1[i];
    }
    for(int i = 0; i < n; i++) {
        std::cin >> y1[i];
    }
    for(int i = 0; i < n; i++) {
        std::cin >> x2[i];
    }
    for(int i = 0; i < n; i++) {
        std::cin >> y2[i];
    }

    auto sol = Solution();
    std::cout << sol.foldedRectangle(x1, x2, y1, y2) << std::endl;
    return 0;
}