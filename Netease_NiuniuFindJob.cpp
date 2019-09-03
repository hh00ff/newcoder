//
// Created by hfq on 9/3/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findJobs(std::vector<std::pair<int, int>>& jobs, std::vector<std::pair<int, int>>& applicants) {
        std::vector<int> res(applicants.size(), 0);
        int curmax = 0, curjob = 0, curap = 0;
        sort(jobs.begin(), jobs.end(),
                [&](std::pair<int, int> a, std::pair<int, int> b) -> int {return a.first < b.first;});
        sort(applicants.begin(), applicants.end(),
                [&](std::pair<int, int> a, std::pair<int, int> b) -> int {return a.first < b.first;});
        for(int i = 0; i < jobs.size(); i++) {
            curmax = std::max(curmax, jobs[i].second);
            jobs[i].second = curmax;
        }

        while(curjob < jobs.size() && curap < applicants.size()) {
            if(applicants[curap].first >= jobs[curjob].first) {
                curjob++;
            }
            else {
                res[applicants[curap].second] = jobs[curjob-1].second;
                curap++;
            }
        }

        while(curap < applicants.size()) {
            res[applicants[curap++].second] = jobs.back().second;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> jobs(n+1), applicants(m);
    jobs[0] = std::make_pair(0, 0);
    for(int i = 1; i <=n; i++) {
        std::cin >> jobs[i].first >> jobs[i].second;
    }
    for(int i = 0; i < m; i++) {
        std::cin >> applicants[i].first;
        applicants[i].second = i;
    }
    auto sol = Solution();
    auto&& res = sol.findJobs(jobs, applicants);
    for(int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }
    return 0;
}
