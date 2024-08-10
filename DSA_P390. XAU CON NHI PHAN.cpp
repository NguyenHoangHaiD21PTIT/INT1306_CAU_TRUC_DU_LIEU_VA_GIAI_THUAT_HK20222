#include <bits/stdc++.h>
using namespace std;

int n, ok;
string s;

void kt(){
    s = string(n, '0');
}

void sinh(){
    int i = n - 1;
    while(i>=0&&s[i]=='1'){
        s[i] = '0';
        i--;
    }
    if(i==-1) ok = 0;
    else s[i] = '1';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        string q; cin>>q;
        kt();
        ok = 1;
        int cnt = 0;
        while(ok==1){
            if(s.find(q)!=string::npos) cnt++;
            sinh();
        }
        cout<<cnt<<endl;
    }
}