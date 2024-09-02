#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    unordered_map<string, int> freq;  
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());  
        freq[s]++;  
    }
    long long res = 0;
    for (auto pair : freq) {
        int cnt = pair.second;
        res += 1LL * cnt * (cnt - 1) / 2;  
    }
    cout << res << endl;
}
