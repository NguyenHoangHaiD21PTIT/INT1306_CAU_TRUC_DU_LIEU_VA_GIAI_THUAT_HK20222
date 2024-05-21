#include <bits/stdc++.h>
using namespace std;

int cnt, ok, pos[30] = {};//pos[i] = j tức là dấu hỏi thứ i ở index j
string s;


void kt(){
    cnt = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i]=='?'){
            pos[cnt+1] = i;
            cnt++;
            s[i] = '0';
        }
    }
}

void sinh(){
    int i = cnt;//số dấu hỏi
    while(i>=1&&s[pos[i]]=='1'){
        s[pos[i]]='0';
        i--;
    }
    if(i==0) ok = 0;
    else s[pos[i]]='1';
}

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        memset(pos, 0, sizeof(pos));
        s = "";
        //loại dấu cách
        string s1;
        getline(cin, s1);
        for(char x: s1){
            if(x!=' ') s+=x;
        }
        kt();
        ok=1;
        while(ok==1){
            cout<<s<<endl;
            sinh();
        }
    }
}