#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            vp.push_back({abs(val - x), val});
        }
        stable_sort(vp.begin(), vp.end());
        for (auto p : vp) {
            cout << p.second << " ";
        }
        cout << endl;
    }
    return 0;
}
