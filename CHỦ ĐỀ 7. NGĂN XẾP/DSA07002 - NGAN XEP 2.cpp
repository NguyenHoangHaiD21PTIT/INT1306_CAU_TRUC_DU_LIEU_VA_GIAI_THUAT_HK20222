#include<bits/stdc++.h>
using namespace std;

int main(){
	stack<int>st;
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n;
		if(s=="PUSH"){
			cin>>n;
			st.push(n);
		} else if (s=="POP"){
			if(st.size()!=0) st.pop();
		} else if (s=="PRINT"){
			if(st.size()==0){
				cout<<"NONE"<<endl;
			} else {
				int x = st.top();
				cout<<x<<endl;
			}
		}
	}
}