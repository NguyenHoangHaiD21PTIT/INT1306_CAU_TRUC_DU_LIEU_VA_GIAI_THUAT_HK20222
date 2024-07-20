#include <bits/stdc++.h>
using namespace std;
//Hướng giải: Mảng hiệu
int main(){
    int n, q;
    cin>>n>>q;
    int a[100005] = {};
    while(q--){
        int x, y;
        cin>>x>>y;
        a[x]++; a[y + 1]--;
    }
    for(int i = 1;i<=n;i++) a[i]+=a[i - 1];
    for(int i = 1;i<=n;i++) cout<<a[i]%2<<" ";
}