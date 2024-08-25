#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a, b, c, d;
    cin>>a>>b>>c>>d;
    if(c > d) swap(c, d);
    long long tongchan = 0, tongle = 0;
    for(int i = a;i<=b;i+=2) tongchan+=i;
    for(int i = c;i<=d;i+=2) tongle+=i;
    cout<<abs(tongchan - tongle) * 2;
}