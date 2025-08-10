#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<pair<int, int>> sal(n); 
    set<int> salLev;  
    for (int i = 0; i < n; ++i) {
        cin >> sal[i].first >> sal[i].second;
        salLev.insert(sal[i].first);
        salLev.insert(sal[i].second);
    }
    int ans = 0;  
    for (int muc: salLev) {
        int res = 0;
        for (auto khoang: sal) {
            if (muc < khoang.first) res += x;
            else if (muc <= khoang.second) res += y;
            else res += z;
        } 
        ans = max(ans, res);
    }  
    cout << ans << endl;
}
