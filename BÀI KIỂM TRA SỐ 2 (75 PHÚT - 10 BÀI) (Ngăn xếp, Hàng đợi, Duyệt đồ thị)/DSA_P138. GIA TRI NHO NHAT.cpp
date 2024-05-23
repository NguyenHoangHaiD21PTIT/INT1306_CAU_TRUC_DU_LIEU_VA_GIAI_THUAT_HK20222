#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    int a[n + 1];
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a + 1, a + n + 1);
    int ans = 0, pos = n/k + 1;
    a[0] = a[1];
    for(int i = 1;i<=n;i++){
        if(i==pos){
            pos+=n/k;
            continue;
        }
        ans+=a[i] - a[i - 1];
    }
    cout<<ans<<endl;
}
