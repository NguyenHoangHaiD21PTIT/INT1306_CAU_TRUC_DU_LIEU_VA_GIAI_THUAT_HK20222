#include<bits/stdc++.h>
using namespace std;

int n, K, a[100], ok;

void kt(){
    for(int i = 0; i < n; i++) a[i] = 0;
}

void sinh(){
    int i = n - 1;
    while(i >= 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == -1) ok = 0;
    else a[i] = 1;
}

bool check(){
    int res = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) cnt++;
        else{
            res = max(res, cnt);
            cnt = 0;
        }
    }
    res = max(res, cnt); 
    return res == K;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin >> n >> K;
        kt();
        ok = 1;
        vector<string>v;
        while(ok){
            if(check()){
                string s = "";
                for(int i = 0; i < n; i++) s+= to_string(a[i]) + " ";
                v.push_back(s);
            }
            sinh();
        }
        cout<<v.size()<<endl;
        for(string x: v) cout<<x<<endl;
        cout<<endl;
    }
}
