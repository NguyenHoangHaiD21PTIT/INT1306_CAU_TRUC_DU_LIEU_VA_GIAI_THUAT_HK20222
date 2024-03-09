#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		cin>>s;
		int i=s.size()-1;
		while(i>=0&&s[i]=='0'){
			s[i]='1';
			i--;
		}
		if(i!=-1){
			s[i]='0';
		} 
		cout<<s<<endl;
	}
}