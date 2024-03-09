#include<bits/stdc++.h>
using namespace std;

vector<string>v;
void gen(){ //sinh ra cac xau np do dai < 15 va bat dau bang 2 chu so
	//Buoc 1: Khoi tao
	queue<string>q;
	q.push("6"); q.push("8");
	v.push_back("6"); v.push_back("8");
	//Buoc 2: Lap
	while(1){
		string x = q.front();
		q.pop();
		if(x.size()==15) break;
		string x1 = x + "6";
		string x2 = x + "8";
		q.push(x1); q.push(x2);
		v.push_back(x1); v.push_back(x2);
	}
}

int main(){
	gen();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string>tmp;
		for(auto i: v){
			if(i.size()==n+1) break;
			tmp.push_back(i);
		}
		cout<<tmp.size()<<endl;
		for(int i = tmp.size()-1;i>=0;i--) cout<<tmp[i]<<" ";
		cout<<endl;
	}
}