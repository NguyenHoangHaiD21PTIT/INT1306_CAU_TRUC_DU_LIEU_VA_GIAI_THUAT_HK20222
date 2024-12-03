#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		ll l[N], h[N];
		l[0] = 0; h[0] = 0;
		for (int i = 1; i <= n; i++) cin >> l[i];
		ll sumArray[N] = { 0 };
		vector<ll> sum; sum.push_back(0);
		cin >> h[1]; sum.push_back(h[1]); sumArray[1] = h[1];
		stack<pair<ll, ll>> st;
		st.push({h[1], 1});
		for (int i = 2; i <= n; i++) {
			cin >> h[i];
			sumArray[i] = sumArray[i - 1] + h[i];
			while (!st.empty() && st.top().first < h[i]) st.pop();
			if (st.empty()) {
				sum.push_back(h[i] * l[i] - sumArray[i - 1]);
			} else {
				ll idx = st.top().second;
				sum.push_back(sum.back() + h[i] * (l[i] - l[idx] - 1) - (sumArray[i - 1] - sumArray[idx]));
			}
			st.push({ h[i] , i });
		}
		int q;
		cin >> q;
		while (q--) {
			ll k; cin >> k;
			auto x = lower_bound(sum.begin(), sum.end(), k);
			if (x == sum.end()) cout << sum.size() << endl;
			else cout << x - sum.begin() - 1 << endl;
		}
	}
}
