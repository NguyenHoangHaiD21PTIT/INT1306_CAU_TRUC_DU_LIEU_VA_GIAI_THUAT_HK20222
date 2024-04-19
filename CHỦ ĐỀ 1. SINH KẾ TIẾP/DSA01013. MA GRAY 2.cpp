#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s, res = "";
        cin>>s;
        res = s[0];
        for(int i = 1;i<s.size();i++){
            if(res[res.size()-1]!=s[i]) res+="1";
            else res+="0";
        }
        cout<<res<<endl;
    }
}