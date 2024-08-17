#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, res, test, sum1, k, d;
vector<int> a[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        k = 0;
        int d = 1, c = m;
        while (d <= c) {
            int mid = (d + c) >> 1;
            if (a[mid][a[mid].size() - 1] < x) c = mid - 1, k = mid;
                else d = mid + 1;
        }
        if (!k) a[++m].push_back(x);
        else a[k].push_back(x);
    }
    cout << m << endl;
    for (int i = 1; i <= m; ++i) {
        for (auto v: a[i]) cout << v << ' ';
        cout << endl;
    }
}
