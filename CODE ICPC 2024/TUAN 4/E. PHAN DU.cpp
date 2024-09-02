#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, k;
    cin>>n>>k;
    long long ans = 0;
    for(long long b = 1;b<=n;b++){
        if(k==0) ans+=n;
        else{
            if(b>k) ans+=(n/b) * (b - k);
            ans+=max(0LL, n%b - k + 1);
        }
    }
    cout<<ans;
}