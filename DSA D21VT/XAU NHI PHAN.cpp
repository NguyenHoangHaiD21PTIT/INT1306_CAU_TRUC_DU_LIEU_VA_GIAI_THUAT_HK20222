#include <bits/stdc++.h>
using namespace std;

int n, ok;
string s;

int count(string s) {
    int count = 0;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == '0' && s[i + 1] == '1') count++;
    }
    return count;
}

void kt(){
    s = string(n, '0');
}

void sinh(){
    int i = s.size() -1;
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
        if(n<4){
            cout<<-1;
            continue;
        }
        ok= 1;
        kt();
        while(ok==1){
            if(count(s)==2) cout<<s<<" ";
            sinh();
        }
        cout<<endl;
    }
}