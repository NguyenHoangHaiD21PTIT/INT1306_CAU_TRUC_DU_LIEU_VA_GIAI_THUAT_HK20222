#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>v;
		set<int>s;
		while(n--){
			int x;
			cin>>x;
			s.insert(x);
		}
		for(auto i: s){
			v.push_back(i);
		}
		if(v.size()==1){
			cout<<-1<<endl;
		} else {
			cout<< v[0]<<" "<<v[1]<<endl;
		}
	}
}
			
		
			
		
