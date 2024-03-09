#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, s, m;
		cin>>n>>s>>m;
		int check = 0;
		for(int i=1;i<=(s-s/7);i++){ //s - s/7: So ngay mua duoc toi da
			if(i*n>=s*m){
				check = 1;
				cout<<i<<endl;
				break;
			}
		}
		if(!check) cout<<-1<<endl;
	}
}