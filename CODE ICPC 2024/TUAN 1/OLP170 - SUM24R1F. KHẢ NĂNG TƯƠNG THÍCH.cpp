#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    int a[n][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) cin >> a[i][j];
    }
    map<long long, int> f[6]; //Ví dụ tổ hợp món 23456 có 5 bạn -> f[5][23456] = 5
    for (int i = 0; i < n; ++i) { //Duyệt mỗi bạn
        for (int mask = 0; mask < (1 << 5); mask++) { //Mỗi bạn duyệt từng tập con
            vector<int> s;
            for (int j = 0; j < 5; ++j){
                if (mask & (1 << j)) s.push_back(a[i][j]);
            }
            sort(s.begin(), s.end());
            long long h = 0;
            for (int x : s) h = h * 1000003 + x;
            f[s.size()][h]++;
        }
    }
    long long tot = 1LL * n * (n - 1) / 2, same = 0;
    for (int k = 1; k <= 5; ++k){
        for (auto &it : f[k]) {
            long long c = 1LL * it.second * (it.second - 1) / 2;
            if (k % 2) same += c;
            else same -= c;
        }
    }
    cout << tot - same;
}
