//
// Created by hfq on 9/5/19.
//
#include <iostream>
#include <vector>


int main(int argc, char** argv) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums(n, 0);
    int min = 0x7FFFFFFF, tmp = 0;
    for(int i = 0; i < m; i++) {
        std::cin >> tmp;
        if(tmp > n) {
            return 0;
        }
        nums[tmp - 1]++;
    }
    for(int i = 0; i < n; i++) {
        min = nums[i] < min ? nums[i] : min;
    }

    std::cout << min << std::endl;
    return 0;
}
