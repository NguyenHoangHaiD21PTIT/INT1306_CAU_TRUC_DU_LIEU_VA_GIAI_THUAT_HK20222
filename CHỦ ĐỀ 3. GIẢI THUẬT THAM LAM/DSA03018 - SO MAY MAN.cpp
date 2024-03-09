#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int check = 0, x, y;
		//4x + 7y = n
		for(y = n/7;y>=0;y--){
			int tmp = n - 7*y; //tmp = 4x
			if(tmp%4==0){
				check = 1;
				x = tmp/4;
				break;
			}
		}
		if(!check){
			cout<<-1;
		} else {
			for(int i=0;i<x;i++) cout<<4;
			for(int i=0;i<y;i++) cout<<7;
		}
		cout<<endl;
	}
}