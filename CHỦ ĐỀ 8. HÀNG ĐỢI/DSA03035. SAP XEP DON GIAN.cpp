#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n + 5], f[100005] = {}, res = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        f[a[i]] = f[a[i] - 1] + 1;
        res = max(res, f[a[i]]);
    }
    cout<<n - res<<endl;
}
