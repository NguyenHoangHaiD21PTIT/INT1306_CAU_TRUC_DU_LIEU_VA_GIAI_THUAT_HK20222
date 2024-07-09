#include<bits/stdc++.h>
using namespace std;

int main(){
    long long x; long long ans = -1;
    while(cin>>x) ans = max(ans, x);
    cout<<ans;
}