#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int P[n + 5];
    for (int i = 1; i <= n; ++i) cin >> P[i];
    vector<int> R(n + 2, n + 1);
    stack<int> st;
    for (int i = n; i >= 1; --i) {
        while (!st.empty() && P[st.top()] <= P[i]) st.pop();
        if (!st.empty()) R[i] = st.top();
        st.push(i);
    }
    vector<int> L(n + 2, 0);
    st = stack<int>();
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && P[st.top()] <= P[i]) st.pop();
        if (!st.empty()) L[i] = st.top();
        st.push(i);
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (L[i] == 0 && R[i] == n + 1) continue;
        int far = L[i] - 1;
        int far2 = R[i] + 1;
        if (L[i] == 0) far = 0;
        if (R[i] == n + 1) far2 = n + 1;
        if (far > 0 && P[far] < P[i]) {
            while (far > 0 && P[far] < P[i]) far = L[far];
        }
        if (far2 < n + 1 && P[far2] < P[i]) {
            while (far2 < n + 1 && P[far2] < P[i]) far2 = R[far2];
        }
        sum += (long long) P[i] * (L[i] - far) * (R[i] - i);
        sum += (long long) P[i] * (far2 - R[i]) * (i - L[i]);
    }
    cout << sum << endl;
}