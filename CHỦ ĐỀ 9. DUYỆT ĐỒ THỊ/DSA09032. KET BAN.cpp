#include<bits/stdc++.h>
using namespace std;

int dem = 0;//dem so TPLT
vector<int> ke[100005];
int visited[100005]={};
vector<int>lt[100005];//lt[i] la vector luu cac dinh trong tplt thu i

void DFS(int u){
    visited[u]=1;
    lt[dem].push_back(u);
    for(int i: ke[u]){
        if(visited[i]==0) DFS(i);
    }
}
    
int main(){
	int t;
	cin>>t;
	while(t--){
		dem = 0;
		memset(visited,0,sizeof(visited));
	    int dinh, canh;
	    cin>>dinh>>canh;
	    for(int i=1;i<=dinh;i++){
	    	ke[i].clear();
	    	lt[i].clear();
		}
	    while(canh--){
	        int dau, cuoi;
	        cin>>dau>>cuoi;
	        ke[dau].push_back(cuoi);
	        ke[cuoi].push_back(dau);
	    }
	    
	    //1. Dem so TPLT va gan
	    for(int i=1;i<=dinh;i++){
	        if(visited[i]==0){
	            dem++;
	            DFS(i);
	        }
	    }
	    
	   	vector<int>v;
	   	for(int i=1;i<=dem;i++) v.push_back(lt[i].size());
	   	sort(v.begin(),v.end(), greater<int>());
	   	cout<<v[0]<<endl;
	}
}   
	