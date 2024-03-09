#include<bits/stdc++.h>
using namespace std;

string s; char c;
int k, ok;

void kt(){ //khoi tao cau hinh dau tien
	s = string(k, 'A');
}

void sinh(){
	// Tim vi tri dau tien chua bang GTLN = n
	int i = k-1;
	while(i>=0&&s[i]==c){
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		s[i]++;
		for(int j = i+1;j<k;j++){
			s[j] = 'A';
		}
	}
}

int main(){
	cin>>c;
	cin>>k;
	kt();
	ok=1;
	while(ok==1){
		cout<<s<<endl;
		sinh();
	}	
}