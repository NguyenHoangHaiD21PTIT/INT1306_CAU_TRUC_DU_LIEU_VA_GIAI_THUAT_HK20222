#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	stack<char>st;
	for(int i = s.size()- 1;i>=0;i--){
		if(st.empty()) st.push(s[i]);
		else{
			if(!st.empty()&&abs(s[i]-st.top())==32) st.pop();
			else st.push(s[i]);
		}
	}
	string res = "";
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	cout<<res<<endl;
}