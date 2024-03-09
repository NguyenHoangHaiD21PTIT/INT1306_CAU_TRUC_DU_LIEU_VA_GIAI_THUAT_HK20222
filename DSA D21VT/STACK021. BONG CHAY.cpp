#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		for(int i = 0;i<s.size();i++){
			if(s[i]==',') s[i]=' ';
		}
		stringstream ss(s);
		string token;
		vector<string>v;
		stack<long long>st;
		while(ss>>token) v.push_back(token);
		for(int i = 0;i<v.size();i++){
			if(v[i]=="C"){
				st.pop();
			} else if (v[i]=="D") {
				st.push(st.top()*2);
			} else if (v[i]=="+"){
				long x = st.top(); st.pop();
				long y = st.top(); st.pop();
				long z = x + y;
				st.push(y); st.push(x); st.push(z);
			} else {
				st.push(stoi(v[i]));
			}
		}
		long tong = 0;
		while(!st.empty()){
			tong+=st.top();
			st.pop();
		}
		cout<<tong<<endl; 
	}
}
