#include<bits/stdc++.h>
using namespace std;

int main(){
	deque<int>dq;
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		if(s=="PUSHFRONT"){
			int x; cin>>x;
			dq.push_front(x);
		} else if (s=="PRINTFRONT"){
			if(!dq.empty()) cout<<dq.front()<<endl;
			else cout<<"NONE"<<endl;
		} else if (s=="POPFRONT"){
			if(!dq.empty()) dq.pop_front();
		} else if (s=="PUSHBACK"){
			int y; cin>>y;
			dq.push_back(y);
		} else if (s=="PRINTBACK"){
			if(!dq.empty()) cout<<dq.back()<<endl;
			else cout<<"NONE"<<endl;
		} else if (s=="POPBACK"){
			if(!dq.empty()) dq.pop_back();
		}
	}
}