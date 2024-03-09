#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int x;
		cin>>x;
		string s;
		cin>>s;
		if(next_permutation(s.begin(),s.end())!=false){
			cout<<i<<" "<<s;
		} else {
			cout<<i<<" "<<"BIGGEST";
		}
		cout<<endl;
	}
}