#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadends_set(deadends.begin(), deadends.end());
        if (deadends_set.find("0000") != deadends_set.end()) return -1;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> visited{"0000"};
        
        while (!q.empty()) {
            pair<string, int> p= q.front();
            q.pop();
            string state = p.first;
            int moves = p.second;
            if (state == target) return moves;
            vector<int> tmp = {-1, 1}; // Chỉnh sửa này
            for (int i = 0; i < 4; i++) {
                char oriDigit = state[i];
                int oriNum = oriDigit - '0';
                int tmp1 = oriNum;//lưu số cũ
                for(int j : tmp){
                    tmp1+=j;
                    if(tmp1==-1) tmp1 = 9;
                    if(tmp1==10) tmp1 = 0;
                    state[i] = tmp1 + '0';
                    if (visited.find(state) == visited.end() && deadends_set.find(state) == deadends_set.end()) {
                        q.push({state, moves + 1});
                        visited.insert(state);
                    }
                    tmp1 = oriNum;
                }
                state[i] = oriDigit;
            }
        }  
        return -1;
    }
};

int main() {
    vector<string> deadends1 = {"0201","0101","0102","1212","2002"};
    string target1 = "0202";
    Solution sol1;
    cout << "Example 1: " << sol1.openLock(deadends1, target1) << endl;  // Output: 6

    vector<string> deadends2 = {"8888"};
    string target2 = "0009";
    Solution sol2;
    cout << "Example 2: " << sol2.openLock(deadends2, target2) << endl;  // Output: 1

    vector<string> deadends3 = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target3 = "8888";
    Solution sol3;
    cout << "Example 3: " << sol3.openLock(deadends3, target3) << endl;  // Output: -1

    return 0;
}