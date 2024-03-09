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
	    
	   	//Voi moi tplt ma size>=3, ta phai xem moi dinh trong do co so dinh ke nhu nhau hay khong
	   	int check = 1;
	   	for(int i=1;i<=dem;i++){
	   		if(lt[i].size()>=3){
		   	 	int check1 = 1;
		   	 	for(int j=0;j<lt[i].size()-1;j++){
		   	 		if(ke[lt[i][j]].size()!=ke[lt[i][j+1]].size()){
		   	 			check1 = 0;
		   	 			break;
					}
				}
				if(check1==0){
					check = 0;
					break;
				}
			}
		}  
		if(check) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}   
	