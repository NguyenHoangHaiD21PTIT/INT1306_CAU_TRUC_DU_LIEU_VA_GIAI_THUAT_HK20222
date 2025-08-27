#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int len = 1; len <= n; len++) {
        multiset<int> ms;
        int best = 0;
        for (int i = 0; i < len; i++) ms.insert(a[i]);
        best = max(best, *ms.begin());
        for (int i = len; i < n; i++) {
            ms.erase(ms.find(a[i - len]));
            ms.insert(a[i]);
            best = max(best, *ms.begin());
        }
        cout << best << " ";
    }
}
