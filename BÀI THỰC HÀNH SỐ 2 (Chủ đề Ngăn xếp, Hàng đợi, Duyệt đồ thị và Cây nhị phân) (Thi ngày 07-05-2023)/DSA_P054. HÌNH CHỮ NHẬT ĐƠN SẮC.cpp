#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll kq(ll a[], ll n){
    ll l[n], r[n];
    stack<ll>st1, st2;
    for(long long i = n - 1; i >= 0;i--){
        while(!st1.empty() && a[i] <= a[st1.top()]) st1.pop();
        if(st1.empty()) r[i] = n - 1;
        else r[i] = st1.top() - 1;
        st1.push(i);
    }
    for(ll i = 0; i < n; i++){
        while(!st2.empty() && a[i] <= a[st2.top()]) st2.pop();
        if(st2.empty()) l[i] = 0;
        else l[i] = st2.top() + 1;
        st2.push(i);
    }
    ll res = -1;
    for(ll i = 0; i < n; i++) res = max(res, 1LL * (r[i] - l[i] + 1) * a[i]);
    return res;
}
int main(){
	ll m, n; cin >> m >> n;
	ll a[n], b[n];
	for(int i = 0; i <n; i++) cin >> a[i], b[i] = m - a[i];
	cout << max (kq(a, n), kq(b, n)) << endl;
}
