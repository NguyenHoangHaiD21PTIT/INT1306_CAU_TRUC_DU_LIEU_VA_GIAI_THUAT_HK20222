#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		cin>>s;
		int check=1;
	    for(int i = 0;i<s.size();i++){
	    	if(s[i]!='0'&&s[i]!='1'&&s[i]!='2'){
	    		check = 0;
	    		break;
			}
		}
		if(check==1){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
}