//
// Created by hfq on 2019/8/28.
//
#include <iostream>
#include <vector>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    int traversalofGraph(std::vector<ListNode*>& adjlists, int curval, std::unordered_set<int>& visited) {
        int depth = 0, curdepth=0;
        ListNode* curnode = adjlists[curval-1];
        visited.insert(curval);
        while(curnode != nullptr) {
            if(visited.find(curnode->val) == visited.end()) {
                curdepth = traversalofGraph(adjlists, curnode->val, visited);
                depth = curdepth > depth ? curdepth : depth;
            }
            curnode = curnode->next;
        }
        return depth + 1;
    }
};

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    std::vector<ListNode*> adjlists(n, nullptr);
    int x, y;
    ListNode* curnode;
    bool dup;
    std::unordered_set<int> visited;

    for(int i = 0; i < n-1; i++) {
        std::cin >> x >> y;
        curnode = adjlists[x-1];
        dup = false;
        if(curnode != nullptr) {
            while(curnode->next != nullptr) {
                if(curnode->val == y) {
                    dup = true;
                    break;
                }
                curnode = curnode->next;
            }
            if(!dup) {
                curnode->next = new ListNode(y);
            }
        }
        else {
            adjlists[x-1] = new ListNode(y);
        }

        curnode = adjlists[y-1];
        dup = false;
        if(curnode != nullptr) {
            while(curnode->next != nullptr) {
                if(curnode->val == x) {
                    dup = true;
                    break;
                }
                curnode = curnode->next;
            }
            if(!dup) {
                curnode->next = new ListNode(x);
            }
        }
        else {
            adjlists[y-1] = new ListNode(x);
        }
    }

    auto sol = Solution();
    int depth = sol.traversalofGraph(adjlists, 1, visited);
    std::cout << 2 * (n - 1) - depth + 1<< std::endl;
    return 0;
}