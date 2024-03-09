#include<bits/stdc++.h>
using namespace std;

//PRIM
int used[10005]; //used[i] = 1: i thuoc tap canh cua cay khung

struct edge{
	int x, y, w;
};

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(used, 0, sizeof(used));
		int dinh, canh;
		cin>>dinh>>canh;
		vector<edge>v;
		while(canh--){
			int a, b, c;
			cin>>a>>b>>c;
			v.push_back({a, b, c});
		}
		
		//Buoc 1: Khoi tao
		long long d = 0;
		vector<pair<int, int>>mst;
		used[1] = 1;
		
		//Buoc 2: Lap
		while(mst.size()<dinh-1){
			//Chon ra canh co chieu dai ngan nhat, 1 dinh da dung, 1 dinh chua dung
			int t = INT_MAX; //Trong so canh be nhat tai thoi diem do
			int a, b; //Diem dau va cuoi cua canh co trong so be nhat luc do
			for(auto i: v){
				if(((used[i.x]==0&&used[i.y]==1)||(used[i.y]==0&&used[i.x]==1))&&i.w<t){
					t = i.w;
					a = i.x; b = i.y;
				}
			}
			mst.push_back({a, b});
			d+=t;
			if(used[a]==0){
				used[a] = 1;
			} else if (used[b]==0){
				used[b] = 1;
			}	
		}
		cout<<d<<endl;
	}
}