#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD  = 1e9 + 7;

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		priority_queue<ll, vector<ll>, greater<ll>>pq;
		ll ans = 0;
		while(n--){
			ll x; cin>>x;
			x%=MOD; pq.push(x);
		}
		while(pq.size()>=2){
			ll x1 = pq.top()%MOD; pq.pop();
			ll x2 = pq.top()%MOD; pq.pop();
			ll x = (x1 + x2)%MOD;
			pq.push(x);
			ans+=x1+x2;
			ans%=MOD;
		}
		cout<<ans<<endl;
	}
}