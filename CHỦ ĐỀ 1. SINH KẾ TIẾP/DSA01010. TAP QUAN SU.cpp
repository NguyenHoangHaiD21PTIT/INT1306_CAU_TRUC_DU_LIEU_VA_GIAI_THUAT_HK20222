#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int a[k], b[k];
        for(int i = 0;i<k;i++){
            cin>>a[i];
            b[i] = a[i];
        }
        int pos = k - 1;
        while(pos >=0&& a[pos]==n - k + pos + 1) pos--;
        if(pos==-1){
            cout<<k<<endl;
        } else {
            a[pos]++;
            for(int i = pos + 1;i<k;i++) a[i] = a[i - 1] + 1;
            int cnt = 0;
            for(int i = 0;i<k;i++){
                for(int j = 0;j<k;j++){
                    if(a[i]==b[j]) cnt++;
                }
            }
            cout<<k - cnt<<endl;
        }
    }
}