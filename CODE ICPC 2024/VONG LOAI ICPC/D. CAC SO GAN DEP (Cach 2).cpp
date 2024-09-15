#include <bits/stdc++.h>
#define fi first 
#define se second  
#define pii pair<int,int> 
#define ll long long
using namespace std;

const int MAX = 1e5;
vector<ll> Number(100001, 0);

ll gen(int n) {
	string s = to_string(Number[n]);
	int len = s.size();
	s = "0" + s;
	for (int i = len; i >= 0; i--) {
		while (s[i] == '9' && i) {
			i--;
		}
		if (i == 0) {
			s[i] = '1';
		}
		else if(i == 1){
			int n1 = s[i] - '0', n2 = s[i + 1] - '0';
			if (abs(n1 + 1 - n2) <= 1) {
				n1++;
				s[i] = n1 + '0';
			}
			else continue;
		}
		else {
			int n1 = s[i] - '0', n2 = s[i - 1] - '0';
			if (abs(n1 + 1 - n2) <= 1) {
				n1++;
				s[i] = n1 + '0';
			}
			else continue;
		}
		for (int j = i + 1; j <= len; j++) {
			int k = s[j - 1] - '0' - 1;
			if (k <= 0) k = 0;
			s[j] = k + '0';
		}
		break;
	}
	return stoll(s);
}



int main() {
	int n;
	cin >> n;
	for (ll i = 1; i <= 12; i++) {
		Number[i] = i;
	}
	for (int i = 12; i <= n; i++) {
		Number[i] = gen(i-1);
	}
	/*for (int i = 1; i <= n; i++)*/ cout << Number[n] << endl;
}
