#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (A[i] != A[j] && A[j] != A[k] && A[i] != A[k] && A[i] + A[j] > A[k])  ans++;
            }
        }
    }
    cout << ans;
}
