#include<bits/stdc++.h>
using namespace std;

int main(){
	queue<int>qe;
	int q; //so truy van;
	cin>>q;
	int n;
	while(q--){
		string s;
		cin>>s;
		if(s=="PUSH"){
			cin>>n;
			qe.push(n);
		} else if (s=="POP"){
			if(qe.size()!=0) qe.pop();
		} else if (s=="PRINTFRONT"){
			if(qe.size()==0){
				cout<<"NONE"<<endl;
			} else {
				int x = qe.front();
				cout<<x<<endl;
			}
		}
	}
}