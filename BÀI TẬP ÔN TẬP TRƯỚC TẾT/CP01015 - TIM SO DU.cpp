#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int r;
		if(s.size()==1){
			r=(s[0]-'0')%4;
		} else {
			r=((s[s.size()-2]-'0')*10+(s[s.size()-1]-'0'))%4;
		}
		if(r==0){
			cout<<4<<endl;
		} else {
			cout<<0<<endl;
		}
	}
}