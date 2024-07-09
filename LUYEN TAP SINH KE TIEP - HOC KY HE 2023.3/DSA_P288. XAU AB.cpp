#include<bits/stdc++.h>
using namespace std;
int n, ok;
string s;

void kt(){
    s = string(n, 'A');
}

void sinh(){
    int i = s.size() - 1;
    while(i>=0&&s[i]=='B'){
        s[i] = 'A';
        i--;
    }
    if(i==-1) ok = 0;
    else s[i] = 'B';
}

int main(){
    cin>>n;
    kt();
    ok = 1;
    int cnt = 1;
    while(ok==1){
        if(cnt!=1&&cnt!=pow(2, n)) cout<<s<<endl;
        cnt++;
        sinh();
    }
}