#include <bits/stdc++.h>
using namespace std;

int a[100], ok;
string s;
vector<pair<int, int>>a1;
set<string>tmp;

void kt(){
    for(int i = 0;i<a1.size();i++) a[i] = 0;
}

void sinh(){
    int i = a1.size() - 1;
    while(a[i]==1&&i>=0){
        a[i] = 0;
        i--;
    }
    if(i==-1) ok = 0;
    else a[i] = 1;
}

int main() {
    cin >> s;
    stack<int> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(i);
        } else if(s[i] == ')') {
            a1.push_back({st.top(), i});
            st.pop();
        }
    }
    kt();
    ok = 1;
    sinh();
    while(ok == 1) {
        string q = s;
        for(int i = 0; i < a1.size(); i++) {
            if(a[i] == 1) q[a1[i].first] = q[a1[i].second] = ' ';
        }
        string q1 = "";
        for(char x : q) {
            if(x != ' ') q1 += x;
        }
        tmp.insert(q1);
        sinh();
    }
    for(string o: tmp) cout<<o<<endl;
}
