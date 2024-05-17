#include<bits/stdc++.h>
using namespace std;
int n, a[10005];
void inOrder(int i){
    if(i>=n) return;
    inOrder(2*i + 1);
    cout<<a[i]<<" ";
    inOrder(2*i + 2);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++) cin>>a[i];
        inOrder(0);
        cout<<endl;
    }
}