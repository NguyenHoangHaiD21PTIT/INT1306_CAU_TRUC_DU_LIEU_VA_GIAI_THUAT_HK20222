#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    int pos = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            pos = i;
            break;
        }
    }
    int steps = 0;
    int left = pos, right = pos;
    while (left > 0) {
        steps++;
        left = max(0, left - K + 1);
    }
    while (right < N - 1) {
        steps++;
        right = min(N - 1, right + K - 1);
    }
    cout << steps << endl;
}
