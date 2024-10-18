#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, M, c1, c2;
    cin >> N >> M >> c1 >> c2;
    vector<long long> S1, S2;
    S1.resize(N);
    S2.resize(M);
    for (long long i = 0; i < N; i++) cin >> S1[i];
    for (long long i = 0; i < M; i++) cin >> S2[i];
    sort(S1.begin(), S1.end());
    sort(S2.begin(), S2.end());
    long long i = 0, j = 0, min_dist = abs(c1 - c2) + abs(S1[0] - S2[0]);
    long long count = 0;
    while (i < N && j < M) {
        long long dist = abs(c1 - c2) + abs(S1[i] - S2[j]);
        if (dist < min_dist) {
            min_dist = dist;
            count = 1;
        } else if (dist == min_dist) count++;
        if (S1[i] < S2[j]) i++;
        else if (S1[i] > S2[j]) j++;
        else {
            i++;
            j++;
        }
    }
    cout << min_dist << " " << count << endl;
}
