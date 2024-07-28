#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    int maxSteps = 0;
    for (int i = 0; i < N; ++i) {
        int steps = 0;
        long long value = A[i];
        while (value % 2 == 0) {
            value /= 2;
            ++steps;
        }
        maxSteps += steps;
    }
    cout << maxSteps << endl;
}