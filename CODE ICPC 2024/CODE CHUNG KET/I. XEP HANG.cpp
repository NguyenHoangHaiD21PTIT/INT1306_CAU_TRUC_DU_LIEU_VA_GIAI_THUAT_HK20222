#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> t1(N), t2(N);
        for (int i = 0; i < N; ++i) cin >> t1[i];
        for (int i = 0; i < N; ++i) cin >> t2[i];
        unordered_map<int, int> pos;
        for (int i = 0; i < N; ++i) pos[t1[i]] = i;
        vector<int> ind;
        for (int i = 0; i < N; ++i) ind.push_back(pos[t2[i]]);
        vector<int> lis;
        for (int id: ind) {
            auto it = lower_bound(lis.begin(), lis.end(), id);
            if (it == lis.end()) lis.push_back(id);
            else *it = id;
        }
        cout << N - lis.size() << endl;
    }
}