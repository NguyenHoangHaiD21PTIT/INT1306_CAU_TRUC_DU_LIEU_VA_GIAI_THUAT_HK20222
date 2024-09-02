#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, a[101], x[101];
set<int> ans;

void nhap() {
	ans.clear();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(x, 0, sizeof(x));
}

void process() {
	int sum = 0;
	vector<int> b;
	b.push_back(-1);
	for (int i = 1; i <= n; i++) {
		if (x[i]) {
			sum += a[i];
		}
		else {
			b.push_back(a[i]);
		}
	}
	if (sum > 0) {
		int dp[sum + 1];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= b.size() - 1; i++) {
			for (int j = sum; j >= b[i]; j--) {
				if (dp[j - b[i]] == 1) dp[j] = 1;
			}
		}
		if (dp[sum]) {
			ans.insert(sum);
		}
	}
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) {
			process();
		}
		else Try(i + 1);
	}
}

int main(){
	int t;
	t = 1;
	while(t--) {
		nhap();
		Try(1);
		cout << ans.size() << endl;
		for (int x : ans) {
			cout << x << " ";
		}
		cout << endl;
 	}
	return 0;
}
