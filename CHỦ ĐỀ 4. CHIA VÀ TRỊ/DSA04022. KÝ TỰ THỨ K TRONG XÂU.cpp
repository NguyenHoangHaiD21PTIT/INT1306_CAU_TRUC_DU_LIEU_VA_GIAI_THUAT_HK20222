#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll f[100];

ll find(ll n, ll k){
	if(k == 1) return 1;
	ll res = pow(2, n - 1);
	if(k == res) return n;
	else if (k < res) return find(n - 1,k);
	else return find(n - 1, k - res);
}

int main(){
	int t; cin >> t;
	while(t--){
		ll n, k; cin >> n >> k;
		cout << (char)('A' + find(n, k) - 1) << endl;
	}
}
