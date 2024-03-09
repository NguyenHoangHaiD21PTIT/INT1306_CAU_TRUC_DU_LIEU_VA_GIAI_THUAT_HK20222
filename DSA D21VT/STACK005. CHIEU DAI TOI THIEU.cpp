#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<char>st;
		for(char x: s){
			if(x!='B'&&x!='D'){
				st.push(x);
			} else {
				int check = 0;
				if(!st.empty()){
					if(x=='B' && st.top()=='A'){
						st.pop();
						check = 1;
					} else if(x=='D' && st.top()=='C') {
						st.pop();
						check = 1;
					}			 
				}
				if(!check) st.push(x);
			}
		}
		cout<<st.size()<<endl;
	}
}