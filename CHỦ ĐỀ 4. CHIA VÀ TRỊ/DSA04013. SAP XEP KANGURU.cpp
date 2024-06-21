#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i = 0;i<n;i++) cin>>a[i];
        sort(a.begin(), a.end(), greater<int>());
        int i = 0, j = n/2, cnt = 0;
        while(i<n/2&&j<n){
            if(a[i]>=a[j]*2) cnt++, i++, j++;
            else j++;
        }
        cout<<n - cnt<<endl;
    }
}
