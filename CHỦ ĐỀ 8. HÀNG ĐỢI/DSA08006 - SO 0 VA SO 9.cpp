#include<bits/stdc++.h>
using namespace std;

int n, ok;//n: so chu so toi da de chua duoc boi so min tao tu 0 va 9 cua 100
string s;
//Idea: Sinh toan bo cac xau nhi phan (0,9) co n chu so

void kt(){
	s = string(n,'0');
}

void sinh(){
	int i = n-1;
	while(i>=0&&s[i]=='9'){
		s[i] = '0';
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		s[i] = '9';
	}
}

int main(){
	//1. Sinh tat cac cac xau nhi phan (0,9)
	vector<string>so;//cac so chi gom 0 va 9
	long long boi[120];//boi[i] la boi nho nhat cua i
	n = 18;
	kt();
	ok=1;
	while(ok==1){
		so.push_back(s);
		sinh();
	}
	so.erase(so.begin());//Xoa di so 0
	
	//2. Duyet tat ca cac so de tim boi nho nhat tu 1 den 100
	for(int i=1;i<=100;i++){
		for(int j=0;j<so.size();j++){
			long long x = stoll(so[j]);
			if(x%i==0){
				boi[i] = x;
				break;
			}
		}
	}
	
	//3. In
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		cout<<boi[x]<<endl;
	}
}