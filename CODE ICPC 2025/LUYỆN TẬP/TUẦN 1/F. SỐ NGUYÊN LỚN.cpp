#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while (t --){
		long long a, res = 0; string b;
		cin >> a >> b;
		for(char x: b) res = (res * 10 + x - '0') % a; //b%a;
		long long ans = __gcd(a, res);
		cout << ans << endl;
	}
}