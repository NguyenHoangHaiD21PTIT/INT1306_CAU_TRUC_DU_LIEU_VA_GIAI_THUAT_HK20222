#include<bits/stdc++.h>
using namespace std;

//Mang a: Mang dung de sinh to hop, a[i] = x thi phan tu tai vi tri x-1 duoc loi ra
//VD: 1 3 5 --> Loi a1 a3 a5

int n, k, a[100], ok;//ok: con sinh duoc

void kt(){ //khoi tao cau hinh dau tien
	for(int i=0;i<k;i++){
		a[i] = i+1;
	}
}

void sinh(){
	// Tim vi tri dau tien chua bang GTLN = n - k + (i+1)
	int i = k-1;
	while(i>=0&&a[i]==n - k + (i+1)){
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		a[i]++;
		for(int j = i+1;j<k;j++){
			a[j] = a[j-1] + 1;
		}
	}
}

int main(){
	int n1;
	cin>>n1;
	cin>>k;
	map<string,int>mp;
	vector<string>v;
	while(n1--){
		string s;
		cin>>s;
		mp[s]++;
	}
	for(auto i: mp){
		v.push_back(i.first);
	}
 	n = mp.size();
	kt();
	ok=1;
	while(ok==1){
		for(int i=0;i<k;i++){
			int pos = a[i] - 1;
			cout<<v[pos]<<" ";
		}
		cout<<endl;
		sinh();
	}
}
