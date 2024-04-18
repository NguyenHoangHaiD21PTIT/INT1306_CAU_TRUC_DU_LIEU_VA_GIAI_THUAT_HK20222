#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a[n];
        for(int i = 0;i<n;i++) cin>>a[i];
        int res = -1;
        for(int i = 0;i<n;i++){
            if(a[i]>a[i + 1]) res = i + 1;
        }
        if(res!=-1){
            cout<<res<<endl;
        } else {
            if(a[0] <= a[n - 1]) cout << 0 << endl;
            else cout << n << endl;
        }
    }
}