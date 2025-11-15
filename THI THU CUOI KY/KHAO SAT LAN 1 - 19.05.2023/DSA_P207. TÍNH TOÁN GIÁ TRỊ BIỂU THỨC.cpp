#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(string s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

ll cal(ll op1, ll op2, string op) {
    if (op == "+") return op1 + op2;
    if (op == "-") return op1 - op2;
    if (op == "*") return op1 * op2;
    if (op == "/") return op1 / op2;
    return 0; 
}

void solve() {
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    stack<ll> st;
    bool p = check(v[0]); 
    int start = p ? n - 1 : 0, en = p ? -1 : n, step = p ? -1 : 1;
    for (int i = start; i != en; i += step) {
        if (!check(v[i])) st.push(stoll(v[i]));
		else {
            ll x1 = st.top(); st.pop(); 
            ll x2 = st.top(); st.pop(); 
			if (!p) swap(x1, x2);
            st.push(cal(x1, x2, v[i]));
        }
    }
    cout << st.top() << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
