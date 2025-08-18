#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int j = 0; j < M; ++j) cin >> B[j];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = INT_MAX, i = 0, j = 0;
    while (i < N && j < M) {
        int dif = llabs(A[i] - B[j]);
        ans = min (dif, ans);       
        if (A[i] < B[j]) ++i;
        else ++j;
    }
    cout << ans;
}
