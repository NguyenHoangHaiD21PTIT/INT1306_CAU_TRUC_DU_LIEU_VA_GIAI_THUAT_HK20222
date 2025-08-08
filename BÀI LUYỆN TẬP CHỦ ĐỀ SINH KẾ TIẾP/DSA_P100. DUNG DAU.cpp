#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    set<string> st;
    while (n--) {
        string s; cin >> s;
        st.insert(s);
    }
    string s2; cin >> s2;
    vector<string> v;
    for (auto &x : st) {
        if (x != s2) v.push_back(x);
	}
	cout << s2 << ' ';
    for (auto &x : v) cout << x << ' ';
    cout << '\n';
    while (next_permutation(v.begin(), v.end())) {
        cout << s2 << ' ';
        for (auto &x : v) cout << x << ' ';
        cout << '\n';
    }
}
