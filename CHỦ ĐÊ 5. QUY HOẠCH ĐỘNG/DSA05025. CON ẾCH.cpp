#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll f[60];
int main(){
	f[0] = 1; f[1] = 1; f[2] = 2;
	for(int i = 3; i <= 52; i++) f[i] = f[i - 1] + f[i - 2] + f[i - 3];
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		cout << f[n] << endl;
	}
}
