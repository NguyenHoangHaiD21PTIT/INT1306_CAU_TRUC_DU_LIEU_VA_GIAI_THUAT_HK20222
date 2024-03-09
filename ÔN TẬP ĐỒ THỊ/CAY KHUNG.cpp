//Su dung cau truc du lieu DSU.
#include<bits/stdc++.h>
using namespace std;

struct edge{
	int dau, cuoi, trso;
};

int parent[1005]={};//par[i] la dai dien cua tap hop i thuoc
int size[1005]={};//size[i] la kich thuoc cua tap hop i thuoc
vector<edge>v;

bool cmp(edge a, edge b){
	return a.trso<b.trso;
}

//tr2. Ham find
int find(int v){
	if(v==parent[v]){
		return v;
	}
	return parent[v] = find(parent[v]);
}

//tr3. Union: Kiem tra 2 dinh co cung thuoc tap hop hay khong, cung thi khong gop
bool Union(int a, int b){
	a = find(a);
    b = find(b);
    if(a==b){
    	return false;
	} else {
		//Luon gop tap be hon vao tap to hon
		if(size[a]<size[b]){
			swap(a,b);
		}
		parent[b]=a;
		size[a]+=size[b];
		return true;
	}
}

int main(){
	int dinh, canh;
	cin>>dinh>>canh;
	while(canh--){
		int x, y, w;
		cin>>x>>y>>w;
		v.push_back({x,y,w});
	}
	//2. sx ds canh
	sort(v.begin(),v.end(), cmp);
	//Trien khai thuat toan Kruskal
	//tr1. Make set
	for(int i=1;i<=dinh;i++){
		parent[i]=i;
		size[i]=1;
	}
	//1. Khoi tao cay khung trong
	vector<edge>ans;
	int d = 0;//tong trong so cay khung can tim
	//3. Lap
	for(int i = 0;i<canh;i++){
		if(ans.size()==dinh-1){ 
			break;
		}
		//a. Lay aln luot tung canh de duyet
		edge e = v[i];
		//b, kiem tra k tao chu trinh
		if(Union(e.dau,e.cuoi)==true){
			ans.push_back(e);
			d+=e.trso;
		}
	}
	//4. Tra lai ket qua
	if(ans.size()!=dinh-1){
		cout<<"Khong the tao cay khung";
	} else {
		cout<<d<<endl;
		for(auto i: ans){
			cout<<i.dau<<" "<<i.cuoi<<" "<<i.trso<<endl;
		}
	}
}