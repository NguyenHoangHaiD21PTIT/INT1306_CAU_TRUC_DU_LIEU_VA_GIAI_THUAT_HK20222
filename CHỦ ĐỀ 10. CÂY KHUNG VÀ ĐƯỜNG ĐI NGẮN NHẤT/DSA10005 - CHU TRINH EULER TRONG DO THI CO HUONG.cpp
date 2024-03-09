#include<bits/stdc++.h>
using namespace std;

int deg_ra[1005], deg_vao[1005];

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(deg_ra,0,sizeof(deg_ra));
		memset(deg_vao,0,sizeof(deg_vao));
		int dinh, canh;
		cin>>dinh>>canh;
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			deg_ra[dau]++;
			deg_vao[cuoi]++;
		}
		int check = 1;
		for(int i=1;i<=dinh;i++){
			if(deg_ra[i]!=deg_vao[i]){
				check = 0;
				break;
			}
		}
		cout<<check<<endl; 
	}
}