//
// Created by hfq on 9/3/19.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int minLamps(std::string& road) {
        int numLamp = 0, noUse = 0;
        for(int i = 0; i < road.size(); i++) {
            if(noUse) {
                noUse--;
                continue;
            }
            else {
                if(road[i] == '.') {
                    numLamp++;
                    noUse = 2;
                }
            }
        }
        return numLamp;
    }
};

int main(int argc, char** argv) {
    int t, n;
    std::string s;
    std::cin >> t;
    std::vector<int> res;
    auto sol = Solution();

    for(int i = 0; i < t; i++) {
        std::cin >> n;
        std::cin >> s;
        res.push_back(sol.minLamps(s));
    }

    for(int i = 0; i < t; i++) {
        std::cout << res[i] << std::endl;
    }
    return 0;
}