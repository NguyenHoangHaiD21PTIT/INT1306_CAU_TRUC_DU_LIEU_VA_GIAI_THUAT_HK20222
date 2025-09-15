#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    if (A[0] != B[0] || A[N-1] != B[N-1]) {
        cout << "No\n";
        return 0;
    }
    if (N <= 2) { 
        cout << (A == B ? "Yes\n" : "No\n");
        return 0;
    }
    vector<ll> dA, dB;
    for (int j = 0; j < N-1; ++j) {
        dA.push_back(A[j+1] - A[j]);
        dB.push_back(B[j+1] - B[j]);
    }
    sort(dA.begin(), dA.end());
    sort(dB.begin(), dB.end());
    cout << (dA == dB ? "Yes\n" : "No\n");
}
/*Đặt d[i] cũ = A[i + 1] - A[i], d[i - 1] cũ = A[i] - A[i - 1]
A[i] mới = A[i - 1] + A[i + 1] - A[i]
d[i - 1] mới = A[i] mới - A[i - 1] = A[i + 1] - A[i] = d[i] cũ
d[i] mới = A[i + 1] - A[i] mới = A[i + 1] - (A[i - 1] + A[i + 1] - A[i]) = A[i] - A[i - 1] = d[i - 1] cũ
*/
