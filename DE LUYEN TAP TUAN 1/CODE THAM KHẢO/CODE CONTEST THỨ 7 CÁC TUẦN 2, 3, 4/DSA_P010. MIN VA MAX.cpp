#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) l[i] = 0;
        else l[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) r[i] = n - 1;
        else  r[i] = st.top() - 1;
        st.push(i);
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) res = max(res, (long long)a[i] * (r[i] - l[i] + 1));
    cout << res;
}
