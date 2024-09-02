#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    int count = 0;
    int min_value = P[0];
    for (int i = 0; i < N; i++) {
        if (P[i] <= min_value) {
            count++;
            min_value = P[i]; 
        }
    }
    cout << count << endl;
}
