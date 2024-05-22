#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	stack<int>st;
	for(int i = 0;i<s.size();i++){
		if(s[i]=='(') st.push(i);
		if(s[i]==')'){
			if(!st.empty()) st.pop();
			else s[i]='*';
		}
	}
	while(!st.empty()){
		s[st.top()] = '*';
		st.pop();
	}
	string res = "";
	for(char x: s){
		if(x!='*') res+=x;
	}
	cout<<res;
}