#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<char>st;
    for(char x: s){
        if(st.empty()) st.push(x);
        else{
            if((st.top()=='1' && x=='0') || (st.top()=='0' && x=='1')) st.pop();
            else st.push(x);
        }
    }
    cout<<s.size() - st.size();
}