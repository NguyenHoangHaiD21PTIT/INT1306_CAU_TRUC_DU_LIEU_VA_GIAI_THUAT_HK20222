#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	stack<char> st; 
    int mx = 0; 
    for (char c : s) { 
        if (c == '(') { 
            st.push(c); 
        } else if (c == ')') {
            mx = max((int)st.size(), mx);
            if(st.empty()) st.pop(); 
        }
    }
    cout<<mx;
}
/*
()()
()(()())
(1+(2*3)+((8)/4))+1
(1)+((2))+(((3))) */