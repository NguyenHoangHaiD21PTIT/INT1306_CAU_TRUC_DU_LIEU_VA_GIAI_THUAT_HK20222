#include<bits/stdc++.h>
using namespace std;
long long f[35][35];

void prepare(){
    for(int i=0;i<=30;i++){
        for(int j=0;j<=30;j++){
            if(i==0)f[i][j]=1;
            if(j==0)f[i][j]=f[i-1][1];
            if(i&&j)f[i][j]=f[i-1][j+1]+f[i][j-1];
        }
    }
}
int main(){
    prepare();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<f[n][0]<<endl;
    }
}
