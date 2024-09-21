#include<bits/stdc++.h>
using namespace std;
int cnt[1000001], a[500005];
int main(){
    int n; cin>>n;
    int a[n];
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int res = 1000006, ans = -1;
    for(int i = 1;i<=n;i++){
        if(cnt[a[i]]==1){  
            if(a[i]<res){
                res = a[i];
                ans = i;
            }
        }
    }
    cout<<ans;
}