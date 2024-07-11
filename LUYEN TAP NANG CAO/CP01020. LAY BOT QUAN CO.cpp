#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        if(n%(m + 1)==0) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}