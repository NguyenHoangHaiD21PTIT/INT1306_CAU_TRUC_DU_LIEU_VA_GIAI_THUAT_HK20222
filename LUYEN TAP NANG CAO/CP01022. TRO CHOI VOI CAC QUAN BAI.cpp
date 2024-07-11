#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        int res = a ^ b ^ c;
        if(!res) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}