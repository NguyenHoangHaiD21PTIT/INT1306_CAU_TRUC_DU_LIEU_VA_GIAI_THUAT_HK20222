#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll f[100];

void pre(){
	f[1] = 1; f[2] = 1;
	for(int i = 3; i <= 92; i++) f[i] = f[i - 2] + f[i - 1];
}

char find(int n, ll k){
	if(n == 1) return '0';
	if(n == 2) return '1';
	if(k <= f[n - 2]) return find(n - 2,k);
	else return find(n - 1, k - f[n - 2]);
}

int main(){
	int t; cin >> t;
	pre();
	while(t--){
		int n; ll k;
		cin >> n >> k;
		cout << find(n, k) << endl;
	}
}
