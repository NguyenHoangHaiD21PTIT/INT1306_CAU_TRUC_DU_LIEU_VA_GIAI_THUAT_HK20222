#include<bits/stdc++.h>
using namespace std;
vector<int>ke[1005];
int color[1005];
bool BFS(int u){
    queue<int>q;
    q.push(u);
    color[u] = 0;//tô màu đỏ
    //0: đỏ, 1: xanh 
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int x: ke[v]){
            if(color[x]==-1){//Nếu đỉnh kề với đỉnh đang xét chưa được tô màu
                color[x] = 1 - color[v];
                q.push(x);
            } else if (color[x] == color[v]){ //Nếu đỉnh ấy đã được thăm rồi
                return false;
            }
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int dinh, canh;
        cin>>dinh>>canh;
        for(int i=1;i<=dinh;i++) ke[i].clear();
        while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
            ke[cuoi].push_back(dau);
		}
        memset(color, -1, sizeof(color));
        int check = 1;//đồ thị đúng là 2 phía
        for(int i = 1;i<=dinh;i++){
            if(color[i]==-1){//Khởi điểm thành phần liên thông mới
                if(!BFS(i)){
                    check = 0;
                    break;
                }
            }
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}