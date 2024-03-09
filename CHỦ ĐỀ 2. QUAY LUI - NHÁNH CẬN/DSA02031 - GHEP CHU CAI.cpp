#include<bits/stdc++.h>
using namespace std;

//Mang a: Mang dung de sinh hoan vi, a[i] = x thi phan tu tai vi tri x-1 cua xau s duoc loi ra
//VD: 12345 --> Loi s0s1s2s3s4

int n, a[100];//ok: con sinh duoc

void kt(){ //khoi tao cau hinh dau tien cua hoan vi
	for(int i=0;i<n;i++){
		a[i] = i+1;
	}
}

int ng_am(char c){ //kiem tra nguyen am
	if(c=='A'||c=='E'){
		return 1;
	} else {
		return 0;
	}
}

int check(string s){
	for(int i=1;i<s.size()-1;i++){
		if(ng_am(s[i-1])==0&&ng_am(s[i])==1&&ng_am(s[i+1])==0) return 0;
	}
	return 1;
}

int main(){
	
	//Tao xau ban dau
	char c;
	cin>>c;
	char c1='A';
	string s="";
	while(c1<=c){
		s=s+c1;
		c1++;
	}
	n = s.size();
	if(check(s)==1) cout<<s<<endl;
	
	//Sinh
	kt();
	while(next_permutation(a,a+n)!=false){
		string tmp="";
		for(int i=0;i<n;i++){
			int val = a[i] - 1;
			tmp = tmp + s[val];
		}
		if(check(tmp)==1) cout<<tmp<<endl;
	}
}