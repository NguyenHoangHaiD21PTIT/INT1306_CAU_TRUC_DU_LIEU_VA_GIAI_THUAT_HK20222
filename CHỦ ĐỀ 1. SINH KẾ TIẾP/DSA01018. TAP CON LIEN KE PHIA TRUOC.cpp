#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int a[k];
        for(int i = 0;i<k;i++) cin>>a[i];
        int pos = k - 1;
        while(pos>=1 && a[pos - 1]==a[pos] - 1) pos--;
        if(pos||(pos==0&&a[0]!=1)){
            a[pos]--;
            for(int i = pos + 1;i<k;i++) a[i] = n - k + (i + 1);
            for(int i = 0;i<k;i++) cout<<a[i]<<" ";
        } else {
            for(int i = 0;i<k;i++) cout<<n - k + (i + 1)<<" ";
        }
        cout<<endl;
    }
}
