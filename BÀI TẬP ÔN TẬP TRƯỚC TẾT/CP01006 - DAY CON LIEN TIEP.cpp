#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		long long tong=0, tongmax=-1e9;//tong: tong cua doan con dang xet
		int check=0;//Kiem tra dieu kien co so khong am chua
	    for(int i=0;i<n;i++){
	    	if(a[i]>=0){
	    		check=1;
	    		break;
	        }
	    }
	    for(int i=0;i<n;i++){
	    	tong=tong+a[i];
	    	tongmax=max(tongmax,tong);
	    	if(tong<0){
	    		tong=0;
	    	}
	    }
	    if(check==0){
	    	cout<<-1<<endl;
	    } else {
	    	cout<<tongmax<<endl;
	    }
	}
}
	    	
			
