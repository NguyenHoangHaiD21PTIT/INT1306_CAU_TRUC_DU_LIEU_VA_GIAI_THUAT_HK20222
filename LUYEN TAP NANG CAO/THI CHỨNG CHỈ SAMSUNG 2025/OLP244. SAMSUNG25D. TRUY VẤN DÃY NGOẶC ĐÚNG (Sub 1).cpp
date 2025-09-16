#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q; string s;
    cin >> n >> q >> s;
    s = " " + s; 
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) swap(s[l], s[r]);
        else {
            stack<char> st;
            bool ok = true;
            for (int i = l; i <= r; i++) {
                if (s[i] == '(') st.push(s[i]);
                else {
                    if (st.empty()) { 
                        ok = false; 
                        break; 
                    }
                    st.pop();
                }
            }
            if (!st.empty()) ok = false;
            if (ok) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
