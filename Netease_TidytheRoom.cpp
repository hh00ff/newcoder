//
// Created by hfq on 9/5/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minSteps(std::vector<std::vector<double>>& points) {
        return minStepsCore(points, 0);
    }

    int minStepsCore(std::vector<std::vector<double>>& points, int pind) {
        if(pind == 4) {
            if(check(points)) {
                return 0;
            }
            else {
                return -13;
            }
        }

        int minstep = -13, curstep = 0;
        for(int i = 0; i < 4; i++) {
            curstep = i + minStepsCore(points, pind+1);
            if(curstep >= 0) {
                if(minstep >= 0) {
                    minstep = std::min(curstep, minstep);
                }
                else {
                    minstep = curstep;
                }
            }
            turn(points[pind]);
        }
        return minstep;
    }

    bool check(std::vector<std::vector<double>> points) {
        std::sort(points.begin(), points.end(), cmp);
        double d1 = distance(points[0], points[1]);
        double d2 = distance(points[0], points[2]);
        double d3 = distance(points[1], points[3]);
        double d4 = distance(points[2], points[3]);
        return isEqual(d1, d2) && isEqual(d2, d3) && isEqual(d3, d4) && !isEqual(d1, 0) &&
                isPerpendicular(points[0], points[1], points[2]);

    }

    static bool isEqual(const double a, const double b) {
        return fabs(a - b) < 0.00001;
    }

    static int cmp(const std::vector<double>& point1, const std::vector<double>& point2) {
        if(!isEqual(point2[0], point1[0])) {
            return point2[0] > point1[0];
        }
        return point1[1] < point2[1];
    }

    double distance(const std::vector<double>& point1, const std::vector<double>& point2) {
        return sqrt(pow(point1[0]-point2[0], 2) + pow(point1[1]-point2[1], 2));
    }

    bool isPerpendicular(const std::vector<double>& point1, const std::vector<double>& point2,
            const std::vector<double>& point3) {
        double v1x = point2[0] - point1[0];
        double v1y = point2[1] - point1[1];
        double v2x = point3[0] - point1[0];
        double v2y = point3[1] - point1[1];
        return isEqual(fabs(v1x * v2x + v1y * v2y), 0);
    }

    void turn(std::vector<double>& point) {
        point[0] -= point[2];
        point[1] -= point[3];
        std::swap(point[0], point[1]);
        point[0] = -point[0];
        point[0] += point[2];
        point[1] += point[3];
    }
};

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    std::vector<std::vector<double>> points(4, std::vector<double>(4, 0));
    auto sol = Solution();
    std::vector<int> res(n, 0);
    int tmp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                std::cin >> points[j][k];
            }
        }
        tmp = sol.minSteps(points);
        res[i] = tmp >= 0 ? tmp : -1;
    }

    for(int i = 0; i < n; i++) {
        std::cout << res[i] << std::endl;
    }
    return 0;
}