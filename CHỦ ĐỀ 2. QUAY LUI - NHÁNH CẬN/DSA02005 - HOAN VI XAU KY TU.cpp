#include<bits/stdc++.h>
using namespace std;

string s;

void kt(){
	sort(s.begin(),s.end());
}

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		cin>>s;
		kt();
		cout<<s<<" ";
		while(next_permutation(s.begin(),s.end())!=false){
			cout<<s<<" ";
		}
		cout<<endl;
	}
}