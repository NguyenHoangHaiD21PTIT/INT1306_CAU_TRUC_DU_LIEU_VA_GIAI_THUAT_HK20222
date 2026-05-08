#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(string s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

ll cal(ll x, ll y, string op) {
    if (op == "+") return x + y;
    if (op == "-") return x - y;
    if (op == "*") return x * y;
    if (op == "/") return x / y;
    return 0; 
}

void solve() {
	int n; cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	stack<ll> st;
	for (int i = n - 1; i >= 0; --i) {
		if (!check(v[i])) st.push(stoll(v[i]));
		else {
			ll x1 = st.top(); st.pop(); 
			ll x2 = st.top(); st.pop(); 
			st.push(cal(x1, x2, v[i]));
		}
	}
	cout << st.top() << "\n";
}

int main() {
	int t; cin >> t;
	while (t--) solve();
}
