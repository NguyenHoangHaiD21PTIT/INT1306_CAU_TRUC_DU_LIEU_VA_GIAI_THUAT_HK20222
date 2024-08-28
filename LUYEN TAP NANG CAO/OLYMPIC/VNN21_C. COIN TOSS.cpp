#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long res = 0;
        string l = "", r = "";
        for(int i = 0;i<s.size();i++){
            l+=s[i];
            r = s[s.size() - i - 1] + r;
            if(l==r) res+=pow(2, i + 1);
        }
        cout<<res<<endl;
    }
}