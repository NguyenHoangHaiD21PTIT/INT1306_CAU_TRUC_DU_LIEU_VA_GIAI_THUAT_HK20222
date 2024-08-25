#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> a;

void ktao() {
	int x = 3, curr = 3;
	a.push_back(x);
	while (x < 1e9) {
		x = x * 2 + 1 + curr;
		curr++;
		a.push_back(x);
	}
}

int find(int n, int k) {
	if (k <= 3) return k;
	if (a[n - 1] < k && k < (a[n] - a[n - 1])) {
		if (k == (a[n - 1] + 1)) return 1;
		else return 2;
	}
	else if (k < a[n-1]) return find(n - 1, k);
	else if(k > a[n] - a[n-1]) return find(n - 1, k - a[n] + a[n-1]);
}

int main() {
	ktao();
	int k;
	cin >> k;
	int idx = find(a.size() - 1, k);
	if (idx == 1) cout << 'a' << endl;
	else cout << 'c' << endl;
}