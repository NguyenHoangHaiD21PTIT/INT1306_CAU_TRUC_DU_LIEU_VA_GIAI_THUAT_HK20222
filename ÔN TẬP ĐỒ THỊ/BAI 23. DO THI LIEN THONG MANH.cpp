#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
vector<int>daoke[1005];
int visited[1005]={};
stack<int>topo;

//1. Tao ra thu tu topo: Dinh nao DFS xong truoc thi day vao stack
void DFS1(int x){
    visited[x]=1;
    for(int i: ke[x]){
        if(visited[i]==0){
            DFS1(i);
        }
    }
    topo.push(x);
}

void DFS2(int x){
    visited[x]=1;
//    cout<<x<<" ";
    for(int i: daoke[x]){
        if(visited[i]==0){
            DFS2(i);
        }
    }
}

int main(){
    int dinh, canh;
    cin>>dinh>>canh;
    while(canh--){
        int dau, cuoi;
        cin>>dau>>cuoi;
        ke[dau].push_back(cuoi);//luu ds ke do thi ban dau
        daoke[cuoi].push_back(dau);//luu ds ke do thi dao nguoc
    }
    //1/ Tao thu tu sx topo
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=dinh;i++){
        if(visited[i]==0){
            DFS1(i);
        }
    }
    //2. Day lan luot dinh stack ra va duyet
    int cnt =0;
    memset(visited,0,sizeof(visited));
    while(topo.size()!=0){
        int x = topo.top();
        topo.pop();
        if(visited[x]==0){
            DFS2(x);
            cnt++;
            //cout<<endl;
        }
    }
    if(cnt==1){
        cout<<1;
    } else {
        cout<<0;
    }
}