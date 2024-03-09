#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};

void DFS(int u){
	visited[u]=1;
	for(int i: ke[u]){
		if(visited[i]==0){
			DFS(i);
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(visited,0,sizeof(visited));
	    //1. Chuyen sang DS ke
	    int dinh, canh;
	    cin>>dinh>>canh;
	    for(int i=1;i<=dinh;i++){
			ke[i].clear();
		}
	    while(canh--){
	        int dau, cuoi;
	        cin>>dau>>cuoi;
	        ke[dau].push_back(cuoi);
	        ke[cuoi].push_back(dau);
	    }
	    for(int i=1;i<=dinh;i++){
	        sort(ke[i].begin(),ke[i].end());
	    }
	    //2. Dem so TPLT ca do thi
	    int cntgoc=0;
	    for(int i=1;i<=dinh;i++){
	        if(visited[i]==0){
	            cntgoc++;
	            DFS(i);
	        }
	    }
	    vector<int>ans;
	    //3/ Duyet het tat ca cac dinh, xem khi loai dinh ay di thi do thi co may TPLT
	    for(int i=1;i<=dinh;i++){
	        memset(visited,0,sizeof(visited));
	        visited[i]=1;//Cam DFS den dinh i <-> Loai dinh i khoi do thi
	        int cntsau=0;//So TPLT sau khi loai dinh i
	        for(int j=1;j<=dinh;j++){
	            if(visited[j]==0){
	                cntsau++;
	                DFS(j);
	            }
	        }
	        if(cntsau>cntgoc){//SO TPLT tang len --> dinh i la dinh tru
	            ans.push_back(i);
	        }
		}
		cout<<ans.size()<<endl;
		for(int i: ans){
			cout<<i<<" ";
		}
		cout<<endl;
    }
}
    