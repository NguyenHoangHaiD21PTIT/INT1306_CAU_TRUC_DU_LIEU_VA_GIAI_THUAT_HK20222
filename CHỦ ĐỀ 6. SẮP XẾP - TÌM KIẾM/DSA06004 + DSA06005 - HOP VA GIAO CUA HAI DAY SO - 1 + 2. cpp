#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		set<int>s1;//luu mang a
		set<int>s2;//luu mang b
		set<int>s3;//luu mang a hop b
		while(n--){
			int x;
			cin>>x;
			s1.insert(x);
			s3.insert(x);
		}
		while(m--){
			int y;
			cin>>y;
			s2.insert(y);
			s3.insert(y);
		}
		for(auto x:s3){
			cout <<x<<" ";
		}
		cout <<endl;
		for(auto x:s1){
			if(s2.find(x)!=s2.end()){
				cout<<x<<" ";
			}
		}
		cout<<endl;
	}
}
