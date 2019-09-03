//
// Created by hfq on 2019/8/28.
//

#include <iostream>
#include <vector>

class Solution {
public:
    long waterFlowers(long n, double x1, double y1, double x2, double y2, std::vector<double>& xf, std::vector<double>& yf) {
        double r1p2 = 0;
        double r2p2 = 0;
        double tmp1 = 0;
        double tmp2 = 0;
        for(int i = 0; i < n; i++) {
            tmp1 = (x1 - xf[i]) * (x1 - xf[i]) + (y1 - yf[i]) * (y1 - yf[i]);
            tmp2 = (x2 - xf[i]) * (x2 - xf[i]) + (y2 - yf[i]) * (y2 - yf[i]);
            if(tmp1 <= r1p2 || tmp2 <= r2p2) {
                continue;
            }
            if(tmp1 <= tmp2) {
                r1p2 = tmp1 > r1p2 ? tmp1 : r1p2;
            }
            else {
                r2p2 = tmp2 > r2p2 ? tmp2 : r2p2;
            }
        }
        return (long)(r1p2 + r2p2);
    }
};

int main(int argc, char** argv) {
    int n;
    double x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    std::vector<double> xf(n, 0);
    std::vector<double> yf(n, 0);
    for(int i = 0; i < n; i++) {
        std::cin >> xf[i] >> yf[i];
    }
    auto sol = Solution();
    std::cout << sol.waterFlowers(n, x1, y1, x2, y2, xf, yf) << std::endl;
}
