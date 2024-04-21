#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main()
{
	ll n, k;
	cin >> n >> k;
	priority_queue<ll, vector<ll>, greater<ll>>pq;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		pq.push(x);
	}
	ll tmp = k;
	ll tien = 0;
	while (pq.size() > 1) {
		ll sum = 0, lon = 0, nho = 0;
		if (pq.size() >= k) {
			while (tmp--) {
				if (tmp == k - 1) nho = pq.top();
				if (tmp == 0) lon = pq.top();
				sum += pq.top();
				pq.pop();
			}
		} else {
			ll sz = pq.size();
			while (!pq.empty()) {
				if (pq.size() == sz) nho = pq.top();
				if (pq.size() == 1) lon = pq.top();
				sum += pq.top();
				pq.pop();
			}
		}
		tmp = k;
		tien += lon - nho;
		pq.push(sum);
	}
	cout << pq.top() << "\n" << tien;
	return 0;
}