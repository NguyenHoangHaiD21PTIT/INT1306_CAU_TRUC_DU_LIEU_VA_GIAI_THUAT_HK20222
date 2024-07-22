#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; int M;
    cin >> s; cin >> M;
    int n = s.length();
    vector<int> reverse_count(n + 2, 0); 
    for (int i = 0; i < M; i++) {
        int ai;
        cin >> ai;
        reverse_count[ai]++;
        if (n - ai + 2 <= n + 1) reverse_count[n - ai + 2]--;
    }
    int count = 0;
    for (int i = 1; i <= n / 2; i++) {
        count += reverse_count[i];
        if (count % 2 == 1) swap(s[i - 1], s[n - i]);
    }
    cout << s << endl;
}