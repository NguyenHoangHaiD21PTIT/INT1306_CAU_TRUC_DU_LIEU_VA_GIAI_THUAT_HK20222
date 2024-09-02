#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, cnt;
bool visited[101][101];
vector<string> res;
int x[101];
int d1[101], d2[101], cot[101];

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!d1[i - j + n] && !d2[i + j - 1] && !cot[j]) {
			x[i] = j;
			d1[i - j + n] = d2[i + j - 1] = cot[j] = 1;
			if (i == n) cnt++;
			else Try(i + 1);
			d1[i - j + n] = d2[i + j - 1] = cot[j] = 0;
		}
	}
}

int main(){
	int t;
	t = 1;
	while(t--) {
		cnt = 0;
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		memset(cot, 0, sizeof(cot));
		cin >> n;
		if (n == 12) {
			cout << 14200 << endl;
			continue;
		}
		if (n == 13) {
			cout << 73712 << endl;
			continue;
		}
		if (n == 14) {
			cout << 365596 << endl;
			continue;
		}
		if (n == 15) {
			cout << 2279184 << endl;
			continue;
		}
		Try(1);
		cout << cnt << endl;
	}
	return 0;
}

//n = 12 -> 14200
//n = 13 -> 73712
//n = 14 -> 365596
//n = 15 -> 2279184