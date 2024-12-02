#include<bits/stdc++.h>
using namespace std;

bool check123(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != 1 && digit != 2 && digit != 3) return false;
        num /= 10;
    }
    return true;
}

int main() {
    const int MAX_N = 100000;
    vector<int> num123;
    for (int i = 1; i <= MAX_N; i++) {
        if (check123(i)) num123.push_back(i);
    }
    vector<int> dp(MAX_N + 1, MAX_N + 1);
    dp[0] = 0;
    for (int i = 1; i <= MAX_N; i++) {
        for (int x: num123) {
            if (x > i) break;
            dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << dp[N] << endl;
    }
}
