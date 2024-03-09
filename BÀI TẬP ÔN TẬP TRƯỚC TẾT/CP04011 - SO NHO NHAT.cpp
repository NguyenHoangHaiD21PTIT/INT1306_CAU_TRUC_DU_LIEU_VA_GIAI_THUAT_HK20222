#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int s, d;//s: tong cs, d: so cs
		cin>>s>>d;
		if(s>9*d||s==0&&d>=2){
			cout<<-1;
		} else {
			vector<int>b(d);
			int tmp = s;
			tmp--;
			for(int i=d-1;i>0;i--){
				if(tmp>=9){
					b[i] = 9;
					tmp-=9;
				} else if(tmp!=0){
					b[i]=tmp;
					tmp=0;	
				} else {
					b[i]=tmp;
				}
			}
			b[0] = tmp+1;
			for(int i: b){
				cout<<i;
			}
		}
		cout<<endl;
	}
}