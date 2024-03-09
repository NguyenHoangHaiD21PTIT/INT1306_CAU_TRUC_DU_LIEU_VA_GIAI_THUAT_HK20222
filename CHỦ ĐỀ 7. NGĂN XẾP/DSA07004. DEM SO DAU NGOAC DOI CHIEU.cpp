#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<char>st;//stack nay luu nhung dau ngoac khong co dau tuong ung
		for(int i=0;i<s.size();i++){
			if(s[i] =='('){
				st.push(s[i]);
			} else {
				if(!st.empty()&&st.top()=='(') st.pop();
				else st.push(s[i]);
			}
		}
		int dong = 0, mo = 0;
		while(!st.empty()){
			char x = st.top();
			if(x=='(') mo++;
			else dong++;
			st.pop();
		}
		int res = dong/2 + mo/2 + dong%2 + mo%2;
		cout<<res<<endl;
	}
}
/*
4
))((
((((
(((())
)(())((( */