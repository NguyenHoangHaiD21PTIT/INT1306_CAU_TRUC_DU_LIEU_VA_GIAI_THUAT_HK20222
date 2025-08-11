#include <bits/stdc++.h>
using namespace std;

const int L1[10] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6}; // Chọn tâm phải, quay phải - R2
const int R1[10] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9}; // Chọn tâm trái, quay phải - R1
const int R2[10] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9}; // chọn tâm trái, quay trái - L1
const int L2[10] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8}; // Chọn tâm phải, quay trái - L2
/*
 0 1 2                                            3 0 2
3 4 5 6 <Chọn 4 làm tâm quay, rồi quay phải> --> 7 4 1 6
 7 8 9                                            8 5 9

 0 1 2                                            0 2 6
3 4 5 6 <Chọn 5 làm tâm quay, rồi quay TRÁI> --> 3 1 5 9
 7 8 9                                            7 4 8 

 0 1 2                                            0 4 1
3 4 5 6 <Chọn 5 làm tâm quay, rồi quay PHẢI> --> 3 8 5 2
 7 8 9                                            7 9 6 
*/
string mv(const string &s, const int p[10]) {
    string res(10,'0');
    for (int i = 0; i < 10; i++) res[i] = s[p[i]];
    return res;
}

int solve(const string &st, const string &tg) {
    unordered_map<string, int> dist; // dist [x] = khoảng cách từ st đến x
    queue<pair<string, int> > ql, qr; // queue trái, queue phải
    dist[st] = 0;
    ql.push({st, 0});
    qr.push({tg, 0});
    // BFS từ st
    while (!ql.empty()) {
        auto [cur, d] = ql.front(); ql.pop();
        if (d == 14) continue;
        for (auto &perm : {L1, R1}) {
            string nxt = mv(cur, perm);
            if (!dist.count(nxt)) {
                dist[nxt] = d + 1;
                ql.push({nxt, d + 1});
            }
        }
    }
    // BFS từ tg
    int res = INT_MAX;
    while (!qr.empty()) {
        auto [cur, d] = qr.front(); qr.pop();
        if (dist.count(cur)) res = min(res, d + dist[cur]);
        // cur đã có trong dist --> Từ st đi đến tg phải qua cur, ngược lại tg đến st cũng phải qua cur
        // st (quay phải) --> cur (quay trái) -->tg
        if (d == 14) continue;
        for (auto &perm : {L2, R2}) qr.push({mv(cur, perm), d + 1});
    }
    return res;
}


int main() {
    string s;
    for (int i = 0, x; i < 10; i++) {
        cin >> x;
        s += char('0' + x);
    }
    cout << solve(s, "1238004765") << "\n";
}
