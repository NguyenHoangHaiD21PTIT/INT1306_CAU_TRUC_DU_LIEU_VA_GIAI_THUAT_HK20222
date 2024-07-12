#include <bits/stdc++.h>
using namespace std;

int solve(string s){
    stack<char>st;
    int res = 0, cur = 0;
    for(char x: s){
        if(x=='('){
            st.push(x);
            cur++;
            res = max(res, cur);
        } else if (x==')'){
            if(st.empty()) return -1;
            st.pop();
            cur--;
        }
    }
    if(!st.empty()) return -1;
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
}
