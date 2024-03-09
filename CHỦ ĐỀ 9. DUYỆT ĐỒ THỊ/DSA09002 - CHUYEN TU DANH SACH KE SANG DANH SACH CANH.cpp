#include<bits/stdc++.h>
using namespace std;

int main(){
	int dinh;
	cin>>dinh;
	vector<pair<int,int>>v;
	cin.ignore();
	for(int i =1;i<=dinh;i++){
		string s;
		getline(cin, s);
		stringstream ss(s);
		string token;
		while(ss>>token){
			int x = stoi(token);
			if(i<x){
				v.push_back({i,x});
			}
		}
	}
	for(auto i: v){
		cout<<i.first<<" "<<i.second<<endl;
	}
}