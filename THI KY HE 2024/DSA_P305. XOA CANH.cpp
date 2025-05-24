#include<bits/stdc++.h>
using namespace std;

int par[100005], sze[100005], cnt[100005];//cnt[i]: cạnh thứ i bị liêt kê i lần trong tập cạnh xoá
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
    int n, m, q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
		par[i] = i;
		sze[i] = 1;
	}
	
	//Danh sách cạnh
	vector<pair<int, int>>edge(m + 2);
	vector<bool>deleted(m + 2, false);
	for(int i = 1;i<=m;i++) cin >> edge[i].first >> edge[i].second;
	
	//Danh sách truy vấn {STT cạnh, đỉnh}
	vector<pair<int, int>>truyVan(q);
	for(int i = 0;i<q;i++){
	    cin >> truyVan[i].first >> truyVan[i].second;
	    deleted[truyVan[i].first] = true;
	}
	//Đếm số lần cạnh bị xoá bị liệt kê
	for(int i = 0;i<q;i++) cnt[truyVan[i].first]++;//đếm số lần cạnh bị xoá xuất hiện trong tập truy vấn
	
	//Thêm các cạnh không bị xoá
	for(int i = 1;i<=m;i++){
	    if(deleted[i]==false) Union(edge[i].first, edge[i].second);
	}
	
	vector<int>ans;
	for(int i = q - 1;i>=0;i--){
	    int stt = truyVan[i].first; //STT cạnh cần xoá
	    int x = truyVan[i].second; //Đỉnh check số phần tử cùng TPLT
	    ans.push_back(sze[find(x)]);
	    int a = edge[stt].first, b = edge[stt].second;
	    if(cnt[stt]==1) Union(a, b);
	    cnt[stt]--;
	}
	
	reverse(ans.begin(), ans.end());
	for(int x: ans) cout<<x<<endl;
}
//Lưu ý: Bài trường mình thi là phiên bản cao hơn của bài sau: https://marisaoj.com/problem/137
//21 test case
