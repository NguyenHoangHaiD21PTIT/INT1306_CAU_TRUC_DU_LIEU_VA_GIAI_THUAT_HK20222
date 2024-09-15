#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    ll m;
    cin >> m;
    m = m * 2;
    int res = 0;
    for(ll i = 1;i*i<=m;i++)
        if(m%i==0){
            if ((i + (m / i - 1)) % 2 == 0) {
                if (i * i == m) res += 1; else res += 2;
            }
        }
    cout<<res;

}

