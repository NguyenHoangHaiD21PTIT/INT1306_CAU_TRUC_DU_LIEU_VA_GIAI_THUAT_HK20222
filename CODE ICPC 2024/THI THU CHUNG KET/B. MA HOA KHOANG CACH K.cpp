#include <bits/stdc++.h>
using namespace std;
char p[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."; 
int ma(char s) {
    if (s >= 'A' && s <= 'Z') return s - 'A';
    else if (s == '_') return 26;
    else return 27;
}
int main() {
    while (true) {
        int k; cin >> k;
        string s;
        if (k == 0) break;
        cin >> s;
        string res = "";
        for (char x : s) res += p[(ma(x) + k) % 28];
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
}
