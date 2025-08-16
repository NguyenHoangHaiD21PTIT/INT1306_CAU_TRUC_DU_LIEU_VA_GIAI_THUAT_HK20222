#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; long long C;
    cin >> N >> C;
    vector<long long> wei(N);
    for (int i = 0; i < N; i++) cin >> wei[i];
    sort(wei.begin(), wei.end());
    int i = 0, j = N - 1;
    int cnt = 0;
    while (i <= j) {
        if (i != j && wei[i] + wei[j] <= C) {
            i++;
            j--;
        } else {
            j--;
        }
        cnt++;
    }
    cout << cnt;
}
