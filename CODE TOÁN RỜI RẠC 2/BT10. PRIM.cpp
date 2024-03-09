#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct edge{
    int dau, cuoi, trso;
};

int n, a[15][15], used[15]={0}, x;

void PRIM(int a[][15], int u){
	vector<edge>v;//vector luu danh sach canh
	//used[x] = 1 nghia la x thuoc tap V(MST) va 0 la thuoc V
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j] && i < j) v.push_back({i, j, a[i][j]});
        }
    }
    
    //Buoc 1: Khoi tao
    int d = 0;//Chieu dai cay khung
    vector<pair<int,int>>MST;
    used[u] = 1; //Chuyen dinh khoi tao vao V(MST)
    
    //Buoc 2: Lap
    while(MST.size()<n-1){
        //Moi lan chon ra canh co chieu dai ngan nhat, 1 dinh da xet va dinh kia chua xet
        int t = 1e9; //Trong so cua canh ngan nhat tai thoi diem do 
        int x, y; //Diem dau va diem cuoi cua canh ngan nhat
        for(auto i: v){
            if(((used[i.dau]==0&&used[i.cuoi]==1)||(used[i.cuoi]==0&&used[i.dau]==1))&&i.trso<t){
                t = i.trso;
                x = i.dau, y= i.cuoi;
            }
        }
        //Dua canh (x,y) vao tap canh
        MST.push_back({x,y});
        //Tang chieu dai cay khung
        d+=t;
        if(used[x]==0) used[x] = 1;
        else used[y] = 1;
    }
    
    //Buoc 3: Tra lai ket qua
    cout<<"dH = "<<d<<endl;
    for(auto i: MST) cout<<i.first<<" "<<i.second<<endl;
}

int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    PRIM(a,x);
}