//
// Created by hfq on 9/3/19.
//

#include <iostream>
#include <string>

class Solution {
public:
    char findDirection(std::string& s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'L') {
                count--;
            }
            else {
                count++;
            }
        }
        count = (count % 4 + 4) % 4;
        switch(count) {
            case 0 :
                return 'N';
            case 1:
                return 'E';
            case 2:
                return 'S';
            case 3:
                return 'W';
        }
    }
};

int main(int argc, char** argv) {
    int n;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    auto sol = Solution();
    std::cout << sol.findDirection(s) << std::endl;
    return 0;
}