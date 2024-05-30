#include<bits/stdc++.h>
using namespace std;

int par[100005], sze[100005];

int find(int x){
	if(x==par[x]) return x;
	return par[x] = find(par[x]);
}

bool Union(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y) return false;
	if(sze[x]<sze[y]) swap(x,y);
	par[y] = x;
	sze[x]+=sze[y];
	return true;	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int dinh, canh;
		cin>>dinh>>canh;
		//Make_set
		for(int i=1;i<=dinh;i++){
			par[i] = i;
			sze[i] = 1;
		}
		vector<pair<int,int>>v;
		while(canh--){
			int x, y;
			cin>>x>>y;
			v.push_back({x, y});
		}
		int check = 0; //check = 0: Kiem tra xem co chu trinh hay khong: k co la 0
		for(auto i: v){
			if(!Union(i.first, i.second)){
				check = 1;
				break;
			}
		}
		if(check) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
