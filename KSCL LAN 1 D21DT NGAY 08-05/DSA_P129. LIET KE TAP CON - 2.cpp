#include<bits/stdc++.h>
using namespace std;

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
	cin>>n>>k;
	kt();
	ok=1;
    set<string>res;
	vector<string>v;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		v.push_back(s);
	}
	while(ok==1){
        string tmp = "";
		for(int i=0;i<k;i++){
			int pos = a[i] - 1;
			tmp+=v[pos];
		}
		res.insert(tmp);
		sinh();
	}
    for(string x: res) cout<<x<<endl;
}

