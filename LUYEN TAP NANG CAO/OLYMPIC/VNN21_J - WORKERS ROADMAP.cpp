#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;

vector<pair<ll, ll>>p;

ll check(ll ngay) {
	ll sp = 0;
	for (ll i = 0; i < n; i++) {
		ll nghi = ngay / (p[i].second + 1);
		sp += p[i].first * (ngay - nghi);
	}
	return sp;
}

int main()
{
	cin >> n >> m;
	for (ll i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		p.push_back({a, b});
	}
	ll l = 1, r = m, res = m;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid) >= m) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << res << endl;
	return 0;
}