#include<bits/stdc++.h>
using namespace std;
int n, u, v;
vector<int> a(100005,0);
int maxSum(){
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + a[i];
    }
    deque<int> dq;
    int mx = INT_MIN;
    for (int i = u; i <= n; ++i) {
        if (!dq.empty() && dq.front() < i - v) {
            dq.pop_front();
        }
        if (!dq.empty()) {
            mx = max(mx, p[i] - p[dq.front()]);
        }
        while (!dq.empty() && p[dq.back()] >= p[i - u + 1]) {
            dq.pop_back();
        }
        dq.push_back(i - u + 1);
    }
    return mx;
}

int main() {

    cin >> n >> u >> v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << maxSum() << "\n";

    return 0;
}
