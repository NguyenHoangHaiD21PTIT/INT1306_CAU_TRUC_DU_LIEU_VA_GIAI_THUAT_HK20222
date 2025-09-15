#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> A(N);
    int sumA = 0, mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sumA += A[i];
        mn = min(mn, A[i]);
        mx = max(mx, A[i]);
    }
    int tot = (mn + mx) * (mx - mn + 1) / 2;
    cout << tot - sumA;
}
