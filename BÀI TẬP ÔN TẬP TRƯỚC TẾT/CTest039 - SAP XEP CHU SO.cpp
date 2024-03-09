#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		int pos = -1e9;
		for(int i=0;i<s.size();i++){
			if(s[i]!='0'){
				pos = i;
				break;
			}
		}
		if(pos==-1e9){
			cout<<0;
		} else {
			for(int i = pos;i<s.size();i++){
				cout<<s[i];
			}
		}
		cout<<endl;
	}
}