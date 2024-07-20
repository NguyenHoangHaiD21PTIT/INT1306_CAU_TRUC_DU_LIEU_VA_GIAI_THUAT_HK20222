#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int t;
	cin>>t;
	while(t--){
		ll p;
		cin>>p;
		if(p==1){
			cout<<1<<endl;
			continue;
		}
		stack<int>st;
		for(int i = 9;i>=2;i--){
			if(p%i==0){
				while(p%i==0){
					st.push(i);
					p/=i;
				}
			}
		}
		if(p!=1) cout<<-1;
		else{
			while(!st.empty()){
				cout<<st.top();
				st.pop();
			}
		}
		cout<<endl;
	}
}
