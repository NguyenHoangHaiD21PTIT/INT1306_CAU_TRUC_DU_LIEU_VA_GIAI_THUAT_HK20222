#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll tongCS(ll x){
    ll ans = 0;
    while(x){
        ans+=x%10;
        x/=10;
    }
    return ans;
}

ll f[1000005];
int main(){
    for(int i = 1;i<=1000000;i++) f[i] = f[i - 1] + tongCS(i);
    int t;
    cin>>t;
    while(t--){
        ll x, y;
        cin>>x>>y;
        cout<<f[y] - f[x - 1]<<endl;
    }
}