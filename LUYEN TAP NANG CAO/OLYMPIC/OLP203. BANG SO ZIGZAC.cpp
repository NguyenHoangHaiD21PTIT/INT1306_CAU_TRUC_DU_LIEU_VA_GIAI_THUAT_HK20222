#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll val(ll h, ll c){
	return h * (h - 1) / 2 + (c - 1) * (c + h * 2) / 2 + 1;
}
int main(){
    ll x, y, z; cin>>x>>y>>z;
    cout<<val(x, y)<<endl;
    ll l = 1, r = 1e9;
    while(l<=r){
        ll mid = (l + r) / 2;
		ll start = val(mid, 1), end = start + mid - 1;
		if(start <= z and z <= end){
			ll j = 1 + (z - start);
			ll i = mid - j + 1;
			cout<<i << ' ' << j;
			return 0;
		}
		if(start > z) r = mid - 1;
		else l = mid + 1;
    }
}
