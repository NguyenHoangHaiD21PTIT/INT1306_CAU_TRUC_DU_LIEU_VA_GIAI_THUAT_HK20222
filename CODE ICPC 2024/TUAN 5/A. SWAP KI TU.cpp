#include <bits/stdc++.h>
using namespace std;
bool check(string S, string T) {
    unordered_map<char, char> mp1, mp2;
    for (int i = 0; i < S.size(); i++) {
        char s = S[i], t = T[i];
        if ((mp1.count(s) && mp1[s] != t) ||(mp2.count(t) && mp2[t] != s)) return false;
        mp1[s] = t;mp2[t] = s;
    }
    return true;
}
int main() {
    string S, T;
    cin >> S >> T;
    if (check(S, T)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
