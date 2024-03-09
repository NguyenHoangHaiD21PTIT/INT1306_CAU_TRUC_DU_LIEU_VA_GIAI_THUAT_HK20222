#include<bits/stdc++.h>
using namespace std;
int main(){
	int t ; 
	cin>> t ;
	while(t--){
		string s ; 
		cin>>s ;
		int cnt=1;
		for(int i=0;i<s.size();i++){
			if(s[i]==s[i+1]){
				cnt++;
			} else {
				cout<<s[i]<<cnt;
				cnt=1;
			}
		}
		cout<<endl;
	}
}

