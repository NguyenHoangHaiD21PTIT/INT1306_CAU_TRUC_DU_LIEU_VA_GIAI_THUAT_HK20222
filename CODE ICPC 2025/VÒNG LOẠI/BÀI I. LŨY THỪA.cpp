#include<bits/stdc++.h>

#define ll long long
using namespace std;

map<ll,ll> mp;
ll res_gcd = 0;
int mxn = 10000005;
vector<ll> a;
vector<bool> b(mxn, true);

void seive(){
    b[0] = b[1] = false;
    for(ll i = 2; i < sqrt(mxn); i++){
        if(b[i] == true){
            for(ll j = i*i; j < mxn; j+= i) b[j] = false;
        }
    }
}

void ptich(ll x){
    ll temp = 0;
    ll gioihan;
    if(x > 1e15) gioihan = cbrt(x);
    else gioihan = sqrt(x);
    for(int i = 2; i <= gioihan; i++){
        while(x%i == 0){
            temp++;
            x /= i;
        }
        if(temp){
            mp[i] = temp;
            res_gcd = __gcd(res_gcd, temp);
            temp = 0;
        }
        
    }
    if(x != 1){
        mp[x]++;
        res_gcd = __gcd(res_gcd, mp[x]);
    } 
}

ll tinh1(ll ans){
    ll res = 1;
    for(auto i : mp){
        res *= (i.second / ans + 1);
    }
    return res;
}

ll tinh2(ll ans){
    ll res = 1;
    for(auto i : mp){
        res *= pow(i.first, i.second/ans);
    }
    return res;
}

int main(){
    seive();
    ll x;
    cin >> x;
    if(x > 1e15){
        ll temp = sqrt(x);
        if(temp < mxn){
        if(b[temp] == true) cout << temp << endl;
        return 0;}
    }
    if(x == 1){
        cout << 1 << endl;
        return 0;
    }
    ptich(x);
    
   
    for(ll i = 1; i <= res_gcd; i++){
        if(res_gcd % i == 0){
            ll ans = res_gcd/i;
            ll temp1 = tinh1(ans);
            if(ans == temp1){
                cout << tinh2(ans);
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
// 45/46 (WA)