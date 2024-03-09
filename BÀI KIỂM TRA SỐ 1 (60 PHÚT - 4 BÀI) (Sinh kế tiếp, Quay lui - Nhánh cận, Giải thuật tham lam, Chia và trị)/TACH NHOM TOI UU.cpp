#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	int res = 1;
	for (auto &x : a) cin >> x;
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] > k) res++;
	}
	cout << res;
}