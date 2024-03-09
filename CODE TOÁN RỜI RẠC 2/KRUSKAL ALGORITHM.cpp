#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int par[15]={}, sze[15]={};

struct edge{
    int x, y, w;
};

bool cmp(edge a, edge b){
    return a.w<b.w;
}

int find(int x){
    if(x==par[x]) return x;
    return par[x] = find(par[x]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return false;
    if(sze[a]<sze[b]) swap(a,b);
    par[b] = a;
    sze[a]+=sze[b];
    return true;
}

int main(){
    int n;
    cin>>n;
    int a[15][15];
    vector<edge>v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]&&i<j) v.push_back({i, j, a[i][j]});
        }
    }
    stable_sort(v.begin(), v.end(), cmp);
    cout<<"Danh sach canh sau khi da sap xep: "<<endl;
    for(auto i: v) cout<<i.x<<" "<<i.y<<" "<<i.w<<endl;
    int d = 0;
    vector<pair<int,int>>mst;
    //Make_set
    for(int i=1;i<=n;i++){
        par[i] = i;
        sze[i] = 1;
    }
    for(auto i: v){
        if(mst.size()==n-1) break;
        cout<<"Canh xet: ("<<i.x<<","<<i.y<<") ";
        if(Union(i.x, i.y)){
        	cout<<"Khong tao thanh chu trinh. ";
            mst.push_back({i.x,i.y});
            d+=i.w;
            cout<<"dH = "<<d<<endl;
        } else {
        	cout<<"Tao thanh chu trinh"<<endl;
		}
    }
    cout<<"dH = "<<d<<endl;
    for(auto i: mst) cout<<i.first<<" "<<i.second<<endl;
}
/*
13 
0 2 1 3 0 0 0 0 0 0 0 0 0
2 0 2 0 0 5 5 0 0 0 0 0 0
1 2 0 4 0 5 0 0 0 0 0 0 0
3 0 4 0 5 5 0 0 0 0 0 0 0
0 0 0 5 0 6 0 0 0 6 0 0 0
0 5 5 5 6 0 6 6 6 6 0 0 0
0 5 0 0 0 6 0 6 0 0 0 0 0
0 0 0 0 0 6 6 0 7 0 0 7 7
0 0 0 0 0 6 0 7 0 7 7 0 0
0 0 0 0 6 6 0 0 7 0 7 7 0
0 0 0 0 0 0 0 0 7 7 0 8 0
0 0 0 0 0 0 0 7 0 7 8 0 8
0 0 0 0 0 0 0 7 0 0 0 8 0 */