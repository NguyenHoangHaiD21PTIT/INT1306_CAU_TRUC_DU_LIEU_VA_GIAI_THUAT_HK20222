#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int s, d;//s: tong chu so, d: so chu so
		cin>>s>>d;
		if(s>9*d||(s==0&&d>1)){
			cout<<-1<<endl;
		} else {
			vector<int>be(d);
			s--;
			for(int i=d-1;i>=1;i--){
				if(s>=9){
					be[i] = 9;
					s-=9;
				} else if (s >0){
					be[i] = s;
					s=0;
				} else {
					be[i] = s;
				}
			}
			be[0] = s+1;
			for(int i=0;i<be.size();i++){
				cout<<be[i];
			}
		}
		cout<<endl;
	}
}