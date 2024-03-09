#include <bits/stdc++.h>
using namespace std;

string s;
int a[100], n, ok;
using ll = long long;

void kt(){
	for(int i=0;i<n;i++) a[i] = 0;
}

void sinh(){
	int i = n-1;
	while(i>=0&&a[i]==1){
		a[i] = 0;
		i--;
	}
	if(i==-1) ok = 0;
	else a[i] = 1;
}

int check(ll n){
	double x = pow(n, 1/3.0);
	ll x1 = (ll) x;
	if(x1*x1*x1==n||(x1+1)*(x1+1)*(x1+1)==n) return 1;
	else return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		n = s.size();
		kt();
		ok = 1;
		ll res = -1; //so lon nhat
		vector<string>v;
		while(ok==1){
			ll ans = 0;
			for(int i=0;i<n;i++){
				if(a[i]) ans = ans*10 + (s[i]-'0');
			}
			if(check(ans)) res = max(res,ans);
			sinh();
		}
		if(res<=0) cout<<-1<<endl;
		else cout<<res<<endl;
	}
}