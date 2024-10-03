#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int v1[n], v2[n];
        for(int i = 0;i<n;i++) cin>>v1[i];
        for(int i = 0;i<n;i++) cin>>v2[i];
        int cnt =0;
        for(int i = n-1; i>=0;i--){
            if(v1[i]== v2[n-cnt-1]) cnt++;
        }
        cout<<n - cnt<<endl;
    }
}
