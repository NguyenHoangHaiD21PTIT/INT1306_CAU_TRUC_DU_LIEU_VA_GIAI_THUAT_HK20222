#include<bits/stdc++.h>
using namespace std;

int par[100005], sze[100005] = {};

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		if (sze[x] < sze[y]) swap(x, y);
		par[y] = x;
		sze[x] += sze[y];
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int dinh, canh;
		cin >> dinh >> canh;
		//Make_set
		for (int i = 1; i <= dinh; i++) {
			par[i] = i;
			sze[i] = 1;
		}
		while (canh--) {
			int x, y;
			cin >> x >> y;
			Union(x, y);
		}
		int cnt = 0;
		for (int i = 1; i <= dinh; i++) {
			if (i == par[i]) cnt++;
		}
		cout << cnt << endl;
	}
}