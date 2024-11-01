#include <bits/stdc++.h>
using namespace std;
int main() {
    long n, k;
    vector<long> A(25, 0);  
    vector<long> B(60005, 0);
    long long S = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        B[i] = x.length();
    }
    for (int i = 2; i <= 20; i++) A[i] = 0;
    if (k < n) {
        for (int i = k; i >= 1; i--) A[B[i]]++;
    } else {
        for (int i = n; i >= 1; i--) A[B[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        A[B[i + k]]++;
        S += A[B[i]] - 1;
        A[B[i]]--;
    }
    cout << S << endl;
}
