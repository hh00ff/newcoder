//
// Created by hfq on 9/4/19.
//
#include <iostream>
#include <vector>

class Solution {
public:
    int latestAlarm(std::vector<int>& alarms, int consum, int ddl) {
        int latest = 0;
        for(auto& al : alarms) {
            if(al + consum <= ddl) {
                latest = al > latest ? al : latest;
            }
        }
        return latest;
    }

    int HMtoM(std::pair<int, int> hm) {
        return hm.first * 60 + hm.second;
    }

    std::pair<int, int> MtoHM(int m) {
        return std::make_pair(m / 60, m % 60);
    }
};

int main(int argc, char** argv) {
    auto sol = Solution();
    int n, h, m, x;
    std::vector<int> alarms;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> h >> m;
        alarms.push_back(sol.HMtoM(std::make_pair(h, m)));
    }
    std::cin >> x;
    std::cin >> h >> m;

    int resm = sol.latestAlarm(alarms, x, sol.HMtoM(std::make_pair(h, m)));
    auto&& reshm = sol.MtoHM(resm);
    std::cout << reshm.first << ' ' << reshm.second << std::endl;
    return 0;
}