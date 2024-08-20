#include<bits/stdc++.h>
using namespace std;

int par[100005], s[100005], sum[100005];

int find(int x){
    if(x==par[x]) return x;
    par[x] = find(par[x]);
    return par[x];
}

bool Union(int x, int y){
    x = find(x); y = find(y);
    if(x==y) return false;
    if(s[x]<s[y]) swap(x, y);
    s[x]+=s[y];
    par[y] = x;
    sum[x]+=sum[y];
    return true;
}

int main(){
    int n, q;
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        par[i] = i;
        s[i] = 1;
        sum[i] = i;
    }
    for(int i = 1;i<=q;i++){
        int type; cin>>type;
        if(type==1){
            int x, y;
            cin>>x>>y;
            Union(x, y);
        } else {
            int z, tong = 0;
            cin>>z;
            cout<<sum[find(z)]<<endl;
        }
    }
}
