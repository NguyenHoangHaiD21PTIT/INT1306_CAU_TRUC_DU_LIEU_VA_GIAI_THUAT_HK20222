#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		int x = stoi(s);
		cout<<x<<endl;
		while(next_permutation(s.begin(),s.end())!=false){
			int x = stoi(s);
            		cout<<x<<endl;
		}
	}
}
